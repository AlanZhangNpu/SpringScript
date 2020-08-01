#include "WorkspaceView.h"
#include "ui_WorkspaceView.h"

#include "./core/object/SpringObject.h"
#include "./core/object/SpringStandardType.h"
#include "./core/object/SpringSymbolTable.h"
#include "SpringRuntimeEnvironment.h"

#include <QDebug>

using namespace spr;

WorkspaceView::WorkspaceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkspaceView),
    isInit(false)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

WorkspaceView::~WorkspaceView()
{
    delete ui;
}

void WorkspaceView::clear()
{
    ui->tableWidget->setRowCount(0);

}

void WorkspaceView::onCellDoubleClicked(int row, int column)
{
//    auto symbol = ui->tableWidget->item(row, 0)->text().toStdString();
//        spr::SpringObjectPtr c = spr::Spring::runtimeEnvironment.symbolTable->get(symbol);
////        spr::SpringObjectPtr c = spr::Spring::runtimeEnvironment.springSymbolTable.get(symbol);

//    WorkspaceView *form = new WorkspaceView();
//    form->setAttribute(Qt::WA_DeleteOnClose);
//    form->setWindowModality(Qt::ApplicationModal);
//    form->show();
//    form->showContainer(symbol, c);
}

void WorkspaceView::initTable()
{
    if(!isInit){
        // 显示表头
        QStringList horizontalHeader;
        horizontalHeader << QString("name") << QString("type") << QString("value");
        ui->tableWidget->setColumnCount(horizontalHeader.size());
        ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);
        ui->tableWidget->setColumnWidth(0,80);
        ui->tableWidget->setColumnWidth(1,80);
        ui->tableWidget->setColumnWidth(2,80);

        // 点击事件
        connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(onCellDoubleClicked(int,int)));

        isInit = true;
    }
}

void WorkspaceView::showWorkspace(spr::SpringSymbolTable* symbolTable)
{
    initTable();

    std::map<std::string, SpringObjectPtr> symbols = symbolTable->getAll();

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(symbols.size());
    int rowId = 0;
    for (auto sym : symbols)
    {
        ui->tableWidget->setItem(rowId, 0, new QTableWidgetItem(QString::fromStdString(sym.first)));
        ui->tableWidget->setItem(rowId, 1, new QTableWidgetItem(QString::fromStdString(sym.second->getTypeString())));
        ui->tableWidget->setItem(rowId, 2, new QTableWidgetItem(QString::fromStdString(sym.second->getPrintString())));
        rowId++;
    }
}

void WorkspaceView::showContainer(const std::string &symbol, spr::SpringObjectPtr &c)
{
    this->setWindowTitle(QString::fromStdString(symbol + " - " + c->getTypeString()));
    ui->tableWidget->setRowCount(0);

    if(c->isBool() || c->isInt() || c->isDouble() || c->isString() || c->isFunction()){
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(c->getPrintString())));
        return;
    }

    if(c->isList()){
        auto list = c->toListPointer()->getAll();
        ui->tableWidget->setRowCount(list.size());
        ui->tableWidget->setColumnCount(1);
        for(unsigned i=0; i<list.size(); i++){
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(list[i]->getPrintString())));
        }
        return;
    }

//    if(c.isMatrix()){

//        ui->tableWidget->setRowCount(c.matrix.n_rows);
//        ui->tableWidget->setColumnCount(c.matrix.n_cols);

//        for(int row = 0; row < c.matrix.n_rows; row++)
//            for(int col = 0; col < c.matrix.n_cols; col++)
//                ui->tableWidget->setItem(row, col,
//                                         new QTableWidgetItem(QString::number(c.matrix(row, col))));
//        return;
//    }

}
