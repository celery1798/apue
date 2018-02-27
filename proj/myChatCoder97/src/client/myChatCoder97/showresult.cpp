#include "showresult.h"
#include "ui_showresult.h"

showResult::showResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showResult)
{
    ui->setupUi(this);

}

void showResult::setresultMsg(QString msg)
{
   ui->resultMsg->setText(msg);
}

void showResult::setokButton(QString msg)
{
    ui->okButton->setText(msg);
}

void showResult::setcancelButton(QString msg)
{
    ui->cancelButton->setText(msg);
}

showResult::~showResult()
{
    delete ui;
}
