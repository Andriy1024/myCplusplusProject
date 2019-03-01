#ifndef NEWITEM_H
#define NEWITEM_H

#include <QDialog>
#include <QCloseEvent>
namespace Ui {
class newItem;
}

class newItem : public QDialog
{
    Q_OBJECT

public:
    explicit newItem(QWidget *parent = 0);
    ~newItem();
    QString nameitem;
    QString path;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::newItem *ui;
protected:
    void closeEvent(QCloseEvent * event);
signals:
    void returntext(QString &str,QString &str2,int a);
};

#endif // NEWITEM_H
