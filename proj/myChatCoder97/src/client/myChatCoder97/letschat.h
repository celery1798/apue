#ifndef LETSCHAT_H
#define LETSCHAT_H

#include <QDialog>

namespace Ui {
class letsChat;
}

class letsChat : public QDialog
{
    Q_OBJECT

public:
    explicit letsChat(QWidget *parent = 0);
    void myLetsChatShow(QString uname);
    ~letsChat();

private slots:
    void on_friendList_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    QString myuname;
    Ui::letsChat *ui;
};

#endif // LETSCHAT_H

