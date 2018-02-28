#include "login.h"
#include "ui_login.h"
#include "QPixmap"
#include "letschat.h"
#include "showresult.h"
#include "proto.h"
#include "qcryptographichash.h"
#include "qudpsocket.h"
#include "qdebug.h"


LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);


    //给label设置背景图片,并设定图片大小
    QString *logoPath = new QString("/home/celery/picture/talk.jpeg");
    QPixmap *pix = new QPixmap(*logoPath);
    ui->logoLabel->setPixmap(*pix);

    int w = ui->logoLabel->width();
    int h = ui->logoLabel->height();
    *pix = pix->scaled(w,h);
    ui->logoLabel->setPixmap(*pix);


    //布署udp socket,并指定槽函数

    socket = new QUdpSocket();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readDataHandler()));


}


//槽函数,用于读取socket接收到的数据
 void LogIn::readDataHandler()
 {
     letsChat *letchat;
     showResult *showresult;

     //接收server回馈消息

     struct denglu_st dl;
     socket->readDatagram((char *)&dl,sizeof(dl));

     switch(dl.status)
     {
        case DENGLU_STATUS_OK:
         // 登陆信息有效启动letsChat
            letchat = new letsChat();
            letchat->setAttribute(Qt::WA_DeleteOnClose);
            letchat->show();
            close();
            break;

        case DENGLU_STATUS_ERROR:
         // 登陆信息无效启动showRuselt
            showresult = new showResult();
            showresult->setAttribute(Qt::WA_DeleteOnClose);
            showresult->setresultMsg(QString("登陆失败"));
            showresult->setokButton(QString("再试一次"));
            showresult->setcancelButton(QString("算了吧"));
            showresult->show();
            close();
            break;
     default:
         break;
     }
 }


LogIn::~LogIn()
{
    delete ui;
}

//"登陆"按钮的单击槽函数
void LogIn::on_pushButton_clicked()
{
 //将登陆信息打包发送给server

    struct denglu_st dl;

    QString name = ui->nameLineEdit->text();
    QString pw = ui->pwLineEdit->text();

     QByteArray ba = pw.toLatin1();
    ba = QCryptographicHash::hash(ba,QCryptographicHash::Md5);

    const char *p = ba.toHex().data();
    const char *u = name.toLatin1().data();

    /**************************************************************/
    //  const char *u = name.toStdString().c_str();
    /**************************************************************/

    qsnprintf(dl.uname,SIZE,u);
    qsnprintf(dl.password,SIZE,p);

    QHostAddress *addr = new QHostAddress(QString(DEFAULT_SERVER_IP));

    socket->writeDatagram((const char *)&dl,sizeof(dl),*addr,DENGLU_SERVER_PORT);

 }





