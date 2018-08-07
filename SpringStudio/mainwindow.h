#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QTableWidgetItem>

#include <Qsci/qsciscintilla.h>

#include "Spring.h"
#include "SpringRuntimeController.h"

#include <windows.h>

namespace Ui {
class MainWindow;
}

class SpringInterpreterThread;
class WorkspaceView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void sendEmail(QString m);

    QString getUsedMemory(DWORD pid);
private slots:
    void on_action_run_triggered();
    void on_actionOpen_triggered();

    void onShowSpringLibInfo(std::vector<std::string> libNames);

    void dropEvent(QDropEvent *e);
    void dragEnterEvent(QDragEnterEvent*event);//拖动进入事件
    void mouseMoveEvent(QMouseEvent *e);

    //! 响应双击文件事件
    void onFileListDClicked(QModelIndex i);

    //! 响应编辑器行数变化，需根据行数修改测百年宽度
    void onLinesChanged();

    //! 响应鼠标位置变化
    void onCursorPositionChanged(int line, int index);

    //! 响应点击编辑器侧边，增/删断点
    void onEditorMarginClicked(int margin, int line, Qt::KeyboardModifiers state);

    //! 解释器执行结束
    void onFinish();

    //! 解释器执行出错
    void onError(int lineno, std::string msg);

    //! 解释器发出打印的命令
    void onPrint(QString msg);

    //! 解释器发出清空的命令
    void onClearOutput();

    //! 解释器暂停时发来通知
    void onPause(int lineno);

    //! 解释器被终止时发来通知
    void onStop(int lineno);

    //! 显示图像
//    void onShowChart(spr::Container c);

    void on_action_save_triggered();

    void on_action_clear_output_triggered();

    //! 新建文件
    void on_action_new_file_triggered();

    //! 清空工作区
    void on_action_clear_data_triggered();

    void on_action_step_continue_triggered();

    void on_action_stop_triggered();

    void on_action_pause_triggered();

    void on_action_toolbar_icon_triggered();

    void on_action_toolbar_icon_bottom_text_triggered();

    void on_action_toolbar_icon_right_text_triggered();

    void on_action_toolbar_text_triggered();

    //! 放大输出窗口字体
    void onZoomInOutputWindow();

    //! 缩小输出窗口字体
    void onZoomOutOutputWindow();

    void input(std::string tip, std::string & inputStr);

    void on_action_open_cmd_triggered();

private:

    enum ProgramState{
        PROGRAM_STATE_EDIT,
        PROGRAM_STATE_RUNNING,
        PROGRAM_STATE_DEBUG
    };

    enum PrintMsgType{
        PROGRAM_MSG,
        DEBUG_MSG,
        ERROR_TIP
    };

    Ui::MainWindow *ui;
    QsciScintilla *editor;
    WorkspaceView * workspaceView;

    QString currentDir, currentFileName;
    QString appName;
    ProgramState programState;
    SpringInterpreterThread * th;
    spr::Spring * springInterpreter;
    spr::SpringRuntimeController *runtimeController;

    const int ERROR_MARKER_INDEX = 2;
    const int DEBUG_MARKER_INDEX = 1;
    const int BREAKPOINT_MARKER_INDEX = 0;


    void initMenuAndToolbar();
    void initEditor();
    void initWorkspace();
    void initOutputWindow();
    void initFileList();

    void initUICmd();


    void showFiles(QString dir);
    bool saveCodeFile(QString &codePath, QString &error);

    void showWorkspace();

    void printMsg(QString msg, PrintMsgType t = PROGRAM_MSG);

};

#endif // MAINWINDOW_H
