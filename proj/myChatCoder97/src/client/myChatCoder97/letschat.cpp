#include "letschat.h"
#include "ui_letschat.h"

letsChat::letsChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::letsChat)
{
    ui->setupUi(this);
}

letsChat::~letsChat()
{
    delete ui;
}
