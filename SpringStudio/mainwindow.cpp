#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>
#include <functional>
#include <thread>

#include <QDir>
#include <QThreadPool>
#include <QFileDialog>
#include <QMessageBox>
#include <QRect>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include <QInputDialog>

#include <Qsci/qscilexerpython.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qsciapis.h>
#include <Qsci/qscicommandset.h>
#include <Qsci/qscicommand.h>

#include "utils/FileUtils.h"
#include "SpringInterpreterThread.h"
#include "SpringLibrarySpecificationForm.h"

#include "WorkspaceView.h"

#include "utils/email/EmailHelper.h"

using namespace spr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    appName("Spring Studio"),
    programState(PROGRAM_STATE_EDIT)
{
    ui->setupUi(this);
    ui->frame_editor->setVisible(false);


    this->setAcceptDrops(true);
    this->setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);


    initMenuAndToolbar();
    initEditor();
    initWorkspace();
    initOutputWindow();
    initFileList();
    initUICmd();

    setDockNestingEnabled(true);

    currentDir = QDir::currentPath();
    currentDir = "E:\\Spring\\test_code/";
    showFiles(currentDir);

    runtimeController = new SpringRuntimeController();
}

MainWindow::~MainWindow()
{
    delete runtimeController;
    delete ui;
}


/**
 * @brief 初始化菜单栏和工具条
 */
void MainWindow::initMenuAndToolbar()
{
    ui->menuView->addAction(ui->dockWidget_files->toggleViewAction());
    ui->menuView->addAction(ui->dockWidget_workspace->toggleViewAction());
    ui->menuView->addAction(ui->dockWidget_output->toggleViewAction());
}


/**
 * @brief 初始化代码编辑器
 */
void MainWindow::initEditor()
{
    editor = ui->frame_editor;

    //设置词法高亮规则
//    QsciLexerPython *textLexer = new QsciLexerPython;//创建一个词法分析器
    QsciLexerCPP *textLexer = new QsciLexerCPP;//创建一个词法分析器
    editor->setLexer(textLexer);//给QsciScintilla设置词法分析器

    //行号提示
    editor->setMarginType(0,QsciScintilla::NumberMargin );//设置编号为0的页边显示行号。
    editor->setMarginLineNumbers(0, true);//对该页边启用行号
    editor->setMarginWidth(0, "00");
    editor->setMarginSensitivity(0, true);

    // 设置自动缩进
    editor->setAutoIndent(true);

    // 自动补全
    QsciAPIs *apis = new QsciAPIs(textLexer);
    std::vector<std::string> keywords = SpringKeywords::getKeywords();
    for(auto word : keywords)
    {
        apis->add(QString::fromStdString(word));
    }
    apis->prepare();

    editor->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源，自动补全所有地方出现的
    editor->setAutoCompletionCaseSensitivity(false);   //设置自动补全大小写敏感
    editor->setAutoCompletionThreshold(1);    //设置每输入一个字符就会出现自动补全的提示

    //设置显示字体、字号与编码方式
    editor->setFont(QFont("宋体", 13));
    editor->setUtf8(true);
//    editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);//设置编码为UTF-8

    // 设置代码折叠样式
    editor->setFolding(QsciScintilla::BoxedTreeFoldStyle );

    // 设置当前行的样式
    editor ->setCaretLineVisible(true);
    editor ->setCaretLineBackgroundColor(QColor(176, 255, 255));

    // 括号匹配
    editor->setBraceMatching(QsciScintilla::BraceMatch::SloppyBraceMatch);

    // 记号定义
    editor->markerDefine(QsciScintilla::RightArrow, DEBUG_MARKER_INDEX);
    editor->setMarkerBackgroundColor(QColor("#ffff11"), DEBUG_MARKER_INDEX);

    editor->markerDefine(QsciScintilla::Circle, BREAKPOINT_MARKER_INDEX);
    editor->setMarkerBackgroundColor(QColor("#ff1111"), BREAKPOINT_MARKER_INDEX);

    editor->markerDefine(QsciScintilla::Rectangle, ERROR_MARKER_INDEX);
    editor->setMarkerBackgroundColor(QColor("#ff11ff"), ERROR_MARKER_INDEX);

    // 设置callTip
    editor->setCallTipsVisible(true);
    editor->setCallTipsStyle(QsciScintilla::CallTipsContext);

    // 设置记号样式：添加背景
    editor->setMarginType(1, QsciScintilla::SymbolMargin);
    editor->setMarginLineNumbers(1, false);
    editor->setMarginWidth(1, 20);
    editor->setMarginSensitivity(1, true);
    editor->setMarginMarkerMask(1, 0x07);

    editor->setEolVisibility(false);
    editor->setEolMode(QsciScintilla::EolWindows);

    connect(editor, SIGNAL(linesChanged()), this, SLOT(onLinesChanged()));
    connect(editor, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    connect(editor, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onCursorPositionChanged(int,int)));
    connect(editor, SIGNAL(marginClicked(int,int,Qt::KeyboardModifiers)), this, SLOT(onEditorMarginClicked(int,int,Qt::KeyboardModifiers)));
}


/**
 * @brief 初始化工作区
 */
void MainWindow::initWorkspace()
{
    workspaceView = new WorkspaceView(this);
    ui->gridLayout_workspace->addWidget(workspaceView);
}

/**
 * @brief 初始化输出窗口
 */
void MainWindow::initOutputWindow()
{

}

void MainWindow::initFileList()
{
    connect(ui->listWidget_files, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(onFileListDClicked(QModelIndex)));
}

void MainWindow::initUICmd()
{
//    Global::buildinFunctionHelper.registerFunction("zoomIn", [&](){
//        QMetaObject::invokeMethod(this,"onZoomInOutputWindow", Qt::BlockingQueuedConnection);
//        return "";
//    });
//    Global::buildinFunctionHelper.registerFunction("zoomOut", [&](){
//        QMetaObject::invokeMethod(this,"onZoomOutOutputWindow", Qt::BlockingQueuedConnection);
//        return "";
//    });
//    Global::buildinFunctionHelper.registerFunction("open", [&](){
//        QMetaObject::invokeMethod(this,"on_actionOpen_triggered", Qt::BlockingQueuedConnection);
//        return "";
//    });
}

void MainWindow::showFiles(QString dir)
{
    if(!dir.endsWith('/') && !dir.endsWith('\\'))
        dir += '/';

    currentDir = dir;
    this->setWindowTitle(appName + " - " + currentDir);
    ui->listWidget_files->clear();
    QList<QString> fileNames = FileUtils::getAllFiles(currentDir, true);
    for(auto f : fileNames)
        ui->listWidget_files->addItem(f);
}

bool MainWindow::saveCodeFile(QString &codePath, QString &error)
{
    QString code = editor->text();
    codePath = currentDir + currentFileName;

    if(!FileUtils::removeFile(codePath)){
        error = "移除旧文件出错，请检查该文件是否正在被使用。\n" + codePath;
        return false;
    }

    if(!FileUtils::toFile(codePath, code)){
        error = "保存文件出错，请检查存储空间是否足够。\n" + codePath;
        return false;
    }
    return true;
}

void MainWindow::onTextChanged()
{
//    ui->statusBar->clearMessage();

//    Global::clearBreakPoints();
//    editor->markerDeleteAll();
}

void MainWindow::onLinesChanged()
{
    editor->setMarginWidth(0, QString::number(editor->lines()*10));
    runtimeController->clearBreakPoints();

    int lineno = -2;
    while (lineno != -1) {
        lineno = editor->markerFindNext(lineno+1, 0x01);
        if(lineno != -1)
            runtimeController->toggleBreakPoint(lineno+1);
    }
}

void MainWindow::onCursorPositionChanged(int line, int index)
{
//    QString current = "行 " + QString::number(line) ;
    //    ui->statusBar->showMessage(currentFileName + ": " + QString::number(editor->lines()) + "行 " + current);
}

void MainWindow::onEditorMarginClicked(int margin, int line, Qt::KeyboardModifiers state)
{
    auto m = editor->markersAtLine(line);
    if(m%2 == 0){
        // 偶数，本行无断点
        editor->markerAdd(line, BREAKPOINT_MARKER_INDEX);
    }else{
        // 奇数，本行已有断点
        editor->markerDelete(line, BREAKPOINT_MARKER_INDEX);
    }
    // 这里要加1，因为在编辑器里，行数是从0开始计算的，而在Flexer里行数从1开始计算
    runtimeController->toggleBreakPoint(line+1);
    return;
}


/**
 * @brief 程序运行结束
 */
void MainWindow::onFinish()
{
//    QString m = getUsedMemory(GetCurrentProcessId());
//    sendEmail(m);

    printMsg(QString("结束"), DEBUG_MSG);
//    showWorkspace();

    programState = PROGRAM_STATE_EDIT;
    editor->setReadOnly(false);

    editor->markerDeleteAll(DEBUG_MARKER_INDEX);
}


void MainWindow::sendEmail(QString m){

    QString senderAddr = "1354270485@qq.com";
    QString senderPassword = "zhangyunweizzz";
    QString receiverAddr = "1354270485@qq.com";
    QString theme = "计算结束，当前内存：" + m;
    QString content = theme;

    // 这里用来测试 发送邮件
    EmailHelper h;
    EmailHelper::SendEmailResult r =
            h.sendEmail_QQ(senderAddr, senderPassword, receiverAddr, theme, content);

    if(!r.success){
        std::string result = r.errorTip.toStdString();
        qDebug()<<"发送邮件失败：" << QString::fromStdString(result);
    }
}

/**
  * @author yuliuchuan
  * @date 2015-04-10
  * 查询程序占用内存。
  * 思路：通过调用外部命令'tasklist /FI "PID EQ pid"'。
  * 将返回的字符串首先替换掉','，
  * 然后用正则表达式匹配已KB为单位表示内存的字符串，
  * 最后换算为MB为单位返回。
  */
QString MainWindow::getUsedMemory(DWORD pid)
{
    char pidChar[25];
    //将DWORD类型转换为10进制的char*类型
    _ultoa(pid,pidChar,10);

    //调用外部命令
    QProcess p;
    p.start("tasklist /FI \"PID EQ " + QString(pidChar) + " \"");
    p.waitForFinished();
    //得到返回结果
    QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
    //关闭外部命令
    p.close();

    //替换掉","
    result = result.replace(",","");
    //匹配 '数字+空格+K'部分。
    QRegExp rx("(\\d+)(\\s)(K)");
    //初始化结果
    QString usedMem("");
    if(rx.indexIn(result) != -1){
        //匹配成功
        usedMem = rx.cap(0);
    }
    //截取K前面的字符串，转换为数字，供换算单位使用。
    usedMem = usedMem.left(usedMem.length() - 1);
    //换算为MB的单位
    return QString::number(usedMem.toDouble() / 1024) + " MB";
}

/**
 * @brief 程序运行出错
 * @param lineno
 * @param msg
 */
void MainWindow::onError(int lineno, std::string msg)
{
    programState = PROGRAM_STATE_EDIT;
    editor->setReadOnly(false);

    editor->markerAdd(lineno-1, ERROR_MARKER_INDEX); // 搞不清楚这里为什么要减2
    printMsg(QString::fromStdString(msg), ERROR_TIP);
}

void MainWindow::onPrint(QString msg)
{
    printMsg(msg);
}

void MainWindow::onClearOutput()
{
    ui->textEdit_output->clear();
}

void MainWindow::onPause(int lineno)
{
    programState = PROGRAM_STATE_DEBUG;
    editor->markerDeleteAll(DEBUG_MARKER_INDEX);
    editor->markerAdd(lineno-1, DEBUG_MARKER_INDEX);
    editor->setCursorPosition(lineno-1, 0);
    showWorkspace();

    printMsg(QString("已暂停在第%1行").arg(lineno), DEBUG_MSG);
}

void MainWindow::onStop(int lineno)
{
//    printMsg(QString("已从第%1行停止").arg(lineno), DEBUG_MSG);
}

//void MainWindow::onShowChart(spr::Container c)
//{
//    QChart * chart = new QChart();


//    for(size_t paramId = 0; paramId < c.list.size(); paramId = paramId + 2)
//    {
//        auto param = c.list[paramId];
//        if(paramId + 1 < c.list.size()){
//            auto paramY = c.list[paramId + 1];

//            QLineSeries * series = new QLineSeries();
//            series->setName("aaaa");

//            for(size_t pointId = 0; pointId < param.list.size(); pointId++)
//            {
//                double x = param.list[pointId].value;
//                double y;
//                if(pointId < paramY.list.size())
//                    y = paramY.list[pointId].value;
//                else
//                    y = 0;

//                series->append(x, y);
//            }
//            chart->addSeries(series);
//        }else{
//            QLineSeries * series = new QLineSeries();

//            for(size_t pointId = 0; pointId < param.list.size(); pointId++)
//            {
//                double x = pointId + 1;
//                double y = param.list[pointId].value;
//                series->append(x, y);
//            }
//            chart->addSeries(series);
//        }
//    }

//    chart->legend()->show();
//    chart->createDefaultAxes();
//    chart->setTitle("Summer");

//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);
//    chartView->show();


//    ////////////////////////
////    QChart *chart = new QChart();

////    QLineSeries * series = new QLineSeries();
////    series->setName("aaaa");
////    series->append(1, 6);
////    series->append(2, 4);
////    series->append(3, 8);
////    chart->addSeries(series);

////    series = new QLineSeries();
////    series->setName("bbb");
////    series->append(1, 1);
////    series->append(2, 3);
////    series->append(3, 3);
////    chart->addSeries(series);

////    chart->legend()->show();
////    chart->createDefaultAxes();
////    chart->setTitle("Simple line chart example");
////    QChartView *chartView = new QChartView(chart);
////    chartView->setRenderHint(QPainter::Antialiasing);
////    chartView->show();
//}

/**
 * @brief 运行按钮
 */
void MainWindow::on_action_run_triggered()
{
    switch (programState) {
    case PROGRAM_STATE_RUNNING:
        // 什么都不做
        runtimeController->pause();
        break;

    case PROGRAM_STATE_DEBUG:
        // 执行继续命令
        programState = PROGRAM_STATE_RUNNING;
        editor->markerDeleteAll(DEBUG_MARKER_INDEX);

        runtimeController->continueRun();
        break;

    case PROGRAM_STATE_EDIT:
    {
        QString error, codePath;
        if(!saveCodeFile(codePath, error)){
            printMsg(error, ERROR_TIP);
            return;
        }

        editor->setReadOnly(true);
        editor->markerDeleteAll(ERROR_MARKER_INDEX);

        programState = PROGRAM_STATE_RUNNING;
        runtimeController->start();

        springInterpreter = Spring::getInstance();
        th = new SpringInterpreterThread(this, codePath, springInterpreter);
        springInterpreter->init(th, runtimeController);
        QThreadPool::globalInstance()->start(th);
        break;
    }
    default:
        break;
    }
}

void MainWindow::showWorkspace()
{
    workspaceView->showWorkspace(springInterpreter->getSymbolTable());
}

void MainWindow::printMsg(QString msg, MainWindow::PrintMsgType t)
{
    msg = msg.toHtmlEscaped();
    msg.replace("\n", "<br/>");
    msg.replace(" ", "&nbsp;");

    QString content;

    if(t == ERROR_TIP || t == DEBUG_MSG)
        content = QString("<p><font color=\"%1\">%2</font></p>").arg("red").arg(msg);
    else
        content = QString("<p><font color=\"%1\">%2</font></p>").arg("black").arg(msg);

    ui->textEdit_output->append(content);

    // 滚动到最后一行
    QTextCursor cursor=ui->textEdit_output->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEdit_output->setTextCursor(cursor);
}

void MainWindow::onFileListDClicked(QModelIndex i)
{
    ui->label->setVisible(false);
    ui->frame_editor->setVisible(true);

    QString filePath = this->currentDir + i.data().toString();
    QString content;
    if(!FileUtils::readFile(filePath, content))
        printMsg(QString("读取文件失败：%1").arg(filePath), DEBUG_MSG);
    else{
        currentFileName = i.data().toString();
        editor->setText(content);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString dir =
            QFileDialog::getExistingDirectory(
                this,
                tr("Open Directory"), "/home",
                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.isEmpty())
        return;
    showFiles(dir);
}

void MainWindow::onShowSpringLibInfo(std::vector<std::string> libNames)
{
//    SpringLibrarySpecificationForm *form = new SpringLibrarySpecificationForm();
//    form->setAttribute(Qt::WA_DeleteOnClose);
//    form->setWindowModality(Qt::ApplicationModal);
//    form->show();
//    form->setRuntimeLibraryNames(libNames);
}

void MainWindow::dropEvent(QDropEvent *e)
{
//    QList<QUrl> urls = e->mimeData()->urls();
//    if(urls.isEmpty())
//        return;

//    std::vector<std::string> libraries;
//    foreach(QUrl url, urls)
//        libraries.push_back(url.toLocalFile().toStdString());

//    SpringLibrarySpecificationForm *form = new SpringLibrarySpecificationForm();
//    form->setAttribute(Qt::WA_DeleteOnClose);
//    form->setWindowModality(Qt::ApplicationModal);
//    form->show();
//    form->setExternLibraryPaths(libraries);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(!event->mimeData()->urls()[0].fileName().right(3).compare("dll"))
        event->acceptProposedAction();
    else
        event->ignore();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
//    qDebug()<<mapToGlobal(e->pos());
}

void MainWindow::on_action_save_triggered()
{
    QString error, codePath;
    if(!saveCodeFile(codePath, error))
        printMsg(error, ERROR_TIP);
    else
        printMsg(QString("文件已经保存(%1)").arg(codePath));
}

void MainWindow::on_action_clear_output_triggered()
{
    ui->textEdit_output->clear();
}

void MainWindow::on_action_new_file_triggered()
{
    QDesktopWidget *desktop = QApplication::desktop();
    QRect screen = desktop->screenGeometry();
    int screenWidth = screen.width();
    int screenHeight = screen.height();

    QVector<QPoint> points;

    points.push_back(QPoint(0,0));
    points.push_back(QPoint(screenWidth,0));
    points.push_back(QPoint(0,screenHeight-300));
    points.push_back(QPoint(screenWidth,screenHeight-300));

    for(int i = 0; i < points.size()-1; i++){
        QPoint start = points[i];
        QPoint end = points[i+1];

        int x = start.x();
        int y = start.y();
        int steps = 20;
        for(int j=0; j <= steps; j++){
            int x = start.x() + (end.x() - start.x())*j/steps;
            int y = start.y() + (end.y() - start.y())*j/steps;

            QPoint center = mapToGlobal(QPoint(x, y));
            QCursor::setPos(center);
            QThread::msleep(1);
        }

    }

//    for(int i=0; i<screenHeight/2; i+=20){
//        QPoint center = mapToGlobal(QPoint(screenWidth/2, i));
//        QCursor::setPos(center);
//        QThread::msleep(1);
//    }



//    onShowSpringLibInfo();

//    const std::vector<Container> paramList;
//    Container returnParam;
//    Global::buildinFunctionHelper.call("ttt", paramList, Global::symbolTable, *(Global::springIOHelper), returnParam);

//    qDebug()<<
//    std::function<void(int, int)> f = [](int x1, int x2){
//        qDebug()<<x1 <<x2;
//    };
//    std::function<void(double, int, int)> f2 = std::bind(f, 2, 1);
//    f2(1,2,2);

//    std::thread t(mmm);
//    t.join();
}

void MainWindow::on_action_clear_data_triggered()
{
//    showWorkspace();
}

void MainWindow::on_action_step_continue_triggered()
{
    runtimeController->continueRunOneStep();
}

void MainWindow::on_action_stop_triggered()
{
    runtimeController->stop();
}

void MainWindow::on_action_pause_triggered()
{
    runtimeController->pause();
}

void MainWindow::on_action_toolbar_icon_triggered()
{
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    ui->toolBar_2->setToolButtonStyle(Qt::ToolButtonIconOnly);
    ui->toolBar_3->setToolButtonStyle(Qt::ToolButtonIconOnly);
}

void MainWindow::on_action_toolbar_icon_bottom_text_triggered()
{
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolBar_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolBar_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void MainWindow::on_action_toolbar_icon_right_text_triggered()
{
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolBar_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolBar_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
}

void MainWindow::on_action_toolbar_text_triggered()
{
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->toolBar_2->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->toolBar_3->setToolButtonStyle(Qt::ToolButtonTextOnly);
}

void MainWindow::onZoomInOutputWindow()
{
    QFont f = ui->textEdit_output->font();
    if(f.pointSize() < 20)
        f.setPointSize(f.pointSize() + 1);
    ui->textEdit_output->setFont(f);
}

void MainWindow::onZoomOutOutputWindow()
{
    QFont f = ui->textEdit_output->font();
    if(f.pointSize() > 1)
        f.setPointSize(f.pointSize() - 1);
    ui->textEdit_output->setFont(f);
}

void MainWindow::input(std::string tip, std::string &inputStr)
{
    QString text =
            QInputDialog::getText(this,
                                  tr("输入对话框"),
                                  QString::fromStdString(tip));
    inputStr = text.toStdString();
}

void MainWindow::on_lineEdit_cmd_returnPressed()
{
    if(programState != PROGRAM_STATE_EDIT)
        return;

    QString cmd = ui->lineEdit_cmd->text().trimmed();
    if(cmd.isEmpty())
        return;

    if(!cmd.endsWith(";"))
        cmd += ";";

    ui->lineEdit_cmd->clear();
    printMsg(">>" + cmd);

    QString tempFile = QDir::tempPath();
    if(!tempFile.endsWith("\\") && !tempFile.endsWith("/"))
        tempFile += "/";
    tempFile += "cmd.sp";

    FileUtils::toFile(tempFile, cmd);
    runtimeController->start();
    th = new SpringInterpreterThread(this, tempFile, springInterpreter);
    QThreadPool::globalInstance()->start(th);
}

void MainWindow::on_action_open_cmd_triggered()
{
    ui->lineEdit_cmd->setFocus();
}
