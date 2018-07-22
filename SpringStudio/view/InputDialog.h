#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

    void setTip(const std::string &tip);

private slots:
    void on_pushButton_clicked();

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
