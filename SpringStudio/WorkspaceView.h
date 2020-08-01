#ifndef WORKSPACEVIEW_H
#define WORKSPACEVIEW_H

#include <QDialog>

#include "Spring.h"

#include <vector>

namespace Ui {
class WorkspaceView;
}

class WorkspaceView : public QDialog
{
    Q_OBJECT

public:
    explicit WorkspaceView(QWidget *parent = 0);
    ~WorkspaceView();

    void clear();
    void showWorkspace(spr::SpringSymbolTable *symbolTable);
    void showContainer(const std::string &symbol, spr::SpringObjectPtr &c);
private slots:
    void onCellDoubleClicked(int row, int column);

private:
    Ui::WorkspaceView *ui;
    bool isInit;

    void initTable();
};

#endif // WORKSPACEVIEW_H
