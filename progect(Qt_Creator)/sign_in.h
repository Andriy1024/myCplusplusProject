#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>
#include <QCloseEvent>
namespace Ui {
class sign_in;
}

class sign_in : public QDialog
{
    Q_OBJECT

public:
    explicit sign_in(QWidget *parent = 0);
    ~sign_in();
    void getpass(QString *pass){
        password = *pass;
    }

private:
    Ui::sign_in *ui;
    QString password;
    QString temp;
signals:
    void rightpass();
private slots:
    void on_ok_clicked();
    void on_cancel_clicked();
protected:
    void closeEvent(QCloseEvent * event);
};

#endif // SIGN_IN_H
