#ifndef OPENITEM_H
#define OPENITEM_H

#include <QDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QFontDatabase>
#include <QCloseEvent>
namespace Ui {
class openitem;
}

class openitem : public QDialog
{
    Q_OBJECT

public:
    explicit openitem(QWidget *parent = 0);
    ~openitem();
    void setpath(QString path,QString title);

private slots:
    void on_pushButton_clicked();
    void on_example_clicked();

signals:
    void file(openitem*,int);

private:
    Ui::openitem *ui;
    QString exemple;
protected:
    void closeEvent(QCloseEvent * event);
};

#endif // OPENITEM_H
