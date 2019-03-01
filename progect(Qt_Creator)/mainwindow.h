#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newitem.h"
#include "openitem.h"
#include "sign_in.h"
#include <QTreeWidget>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void read_tree_widget();
    void write_tree_widget();
    void read_tree_path();
    void write_tree_path();

private slots:
    void on_pushButton_open_clicked();
    void on_pushButton_add_clicked();
    void setnewitem(QString &str, QString &str2,int a);
    void showfile(openitem*,int);
    void on_pushButton_delete_clicked();
    void on_pushButton_web_clicked();
     void on_treeWidget_itemClicked(QTreeWidgetItem *item);
    void on_treeWidget_itemDoubleClicked();
    void on_select2_triggered();
    void log_in();
    void log_out();
    void on_action_login_triggered();
    void additem();
    void deleteitem();
    void on_action_logout_triggered();
    void on_action_quit_triggered();
    void on_add2_triggered();
    void on_delete2_triggered();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_action_collapse_triggered();
    void on_pushButton_help_clicked();

    void on_help2_triggered();

    void on_me_triggered();

private:
    Ui::MainWindow *ui;
    QList<QString> list;
    QList<QString> Qlist;
    newItem *i;
    openitem *o;
    QTreeWidgetItem *C;
    QTreeWidgetItem *Qt;
    void OPENitem();
    QString pass;
    bool authorization;
    QSystemTrayIcon         * trayIcon;
protected:
    void closeEvent(QCloseEvent * event);
};

#endif // MAINWINDOW_H
