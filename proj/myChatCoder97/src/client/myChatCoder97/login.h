#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include <QUdpSocket>

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();

private slots:
    void on_pushButton_clicked();
    void readDataHandler();

private:
    QUdpSocket *socket;
    Ui::LogIn *ui;
};

#endif // LOGIN_H
