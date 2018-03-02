#include "letschat.h"
#include "ui_letschat.h"
#include "qtreewidget.h"

letsChat::letsChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::letsChat)
{
    ui->setupUi(this);
}

void letsChat::myLetsChatShow(QString uname)
{
    myuname = uname;

    QTreeWidgetItem *item = new QTreeWidgetItem(ui->friendList);

    item->setIcon(0,QIcon("/home/celery/picture/myhead.jpg"));
    item->setText(0,QString(myuname));

    ui->friendUname->setText(QString("MyChat"));

    show();
}

letsChat::~letsChat()
{
    delete ui;
}


//friendlist的双击槽函数
void letsChat::on_friendList_doubleClicked(const QModelIndex &index)
{
  //获取鼠标目前双击的对象

    QTreeWidgetItem *item =  ui->friendList->currentItem();





}



//发送按钮的单击槽函数
void letsChat::on_pushButton_4_clicked()
{
    QString p = ui->typeText->toPlainText();

    ui->historyText->append(p);

    ui->typeText->clear();

}


