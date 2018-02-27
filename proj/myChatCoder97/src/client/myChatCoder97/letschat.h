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
    ~letsChat();

private:
    Ui::letsChat *ui;
};

#endif // LETSCHAT_H
