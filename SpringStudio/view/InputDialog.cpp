#include "InputDialog.h"
#include "ui_InputDialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::setTip(const std::string &tip)
{
    ui->label->setText(QString::fromStdString(tip));
}

void InputDialog::on_pushButton_clicked()
{

}
