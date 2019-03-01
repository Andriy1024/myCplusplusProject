#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QDir>
#include <QTextStream>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Головне вікно");
    C = new QTreeWidgetItem(1);
    C->setText(0,"C++");
    ui->treeWidget->addTopLevelItem(C);
    Qt = new QTreeWidgetItem(1);
    Qt->setText(0,"Qt");
    ui->treeWidget->addTopLevelItem(Qt);
    read_tree_widget();
    read_tree_path();
    int id1 = QFontDatabase::addApplicationFont(":/new/Vodafone.ttf");
    int id2 = QFontDatabase::addApplicationFont(":/new/Ubuntu.ttf");
    QString family1 = QFontDatabase::applicationFontFamilies(id1).at(0);
    QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
    QFont vodafone(family1);
    QFont ubuntu(family2);
    ubuntu.setPixelSize(19);
    ui->label->setFont(ubuntu);
    ubuntu.setPixelSize(15);
    ui->pushButton_open->setFont(ubuntu);
    ui->pushButton_add->setFont(ubuntu);
    ui->pushButton_delete->setFont(ubuntu);
    ui->pushButton_web->setFont(ubuntu);
    ubuntu.setPixelSize(17);
    ui->treeWidget->setFont(ubuntu);
    ubuntu.setPixelSize(15);
    ui->statusBar->setFont(ubuntu);
    authorization = false;
    pass = "1234";
    trayIcon = new QSystemTrayIcon(this);
    QIcon trayImage(":/new/ico.ico");
    trayIcon->setIcon(trayImage);
    trayIcon->setToolTip("Довідник C++/QT");
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(tr("Розгорнути вікно"), this);
    QAction * quitAction = new QAction(tr("Вихід"), this);
    QIcon viewWindowicon(":/new/deploy.png");
    QIcon quiticon(":/new/quit.png");
    quitAction->setIcon(quiticon);
    viewWindow->setIcon(viewWindowicon);
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(on_action_quit_triggered()));
    menu->addAction(viewWindow);
    menu->addAction(quitAction);
    trayIcon->setContextMenu(menu);
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));



}


MainWindow::~MainWindow()
{
    write_tree_widget();
    write_tree_path();
    delete ui;
}
void MainWindow::read_tree_widget()
{
    QFile mFile(qApp->applicationDirPath()+"/c_tree_widget.txt");
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path c_tree_widget  not correct");
    }else{
    QTextStream stream(&mFile);
    QString line;
     do
       {
         line = stream.readLine();
         if(!line.isNull()) {
             QTreeWidgetItem *item = new QTreeWidgetItem(1);
             item->setText(0,line);
             C->addChild(item);
         }
        } while (!line.isNull());
    mFile.flush();
    mFile.close();
    }

    QFile mFile2(qApp->applicationDirPath()+"/qt_tree_widget.txt");

    if(!mFile2.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path qt_tree_widget not correct");
        return;
    }
    QTextStream stream2(&mFile2);
    QString line2;
     do
       {
         line2 = stream2.readLine();
         if(!line2.isNull()) {
             QTreeWidgetItem *item2 = new QTreeWidgetItem(1);
             item2->setText(0,line2);
             Qt->addChild(item2);
         }
        } while (!line2.isNull());
    mFile2.flush();
    mFile2.close();
}
void MainWindow::write_tree_widget()
{
    QFile mFile1(qApp->applicationDirPath()+"/c_tree_widget.txt");
    if(!mFile1.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path c_tree_widget not correct");
    }else{
    QTextStream stream1(&mFile1);
    for(int i(0); i < C->childCount();i++)
    {
        QString w1 (C->child(i)->text(0));
        stream1 << (w1 +"\n");
    }
    mFile1.close();
    }

    QFile mFile2(qApp->applicationDirPath()+"/qt_tree_widget.txt");
    if(!mFile2.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path qt_tree_widget not correct");
    }else{
    QTextStream stream2(&mFile2);
    for(int i(0); i < Qt->childCount();i++)
    {
        QString w2 (Qt->child(i)->text(0));
        stream2 << (w2 +"\n");
    }
    mFile2.close();
    }
}
void MainWindow::read_tree_path()
{
    QFile mFile(qApp->applicationDirPath()+"/c_tree_path.txt");

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path c_tree_path not correct");
    }else{
    QTextStream stream(&mFile);
    QString line;
     do
       {
         line = stream.readLine();
         if(!line.isNull()) {
             list.append(line);
         }
        } while (!line.isNull());
    mFile.flush();
    mFile.close();
    }

    QFile mFile2(qApp->applicationDirPath()+"/q_tree_path.txt");

    if(!mFile2.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path q_tree_path not correct");
        return;
    }
    QTextStream stream2(&mFile2);
    QString line2;
     do
       {
         line2 = stream2.readLine();
         if(!line2.isNull()) {
             Qlist.append(line2);
         }
        } while (!line2.isNull());
    mFile2.flush();
    mFile2.close();
}
void MainWindow::write_tree_path()
{
    QFile mFile2(qApp->applicationDirPath()+"/c_tree_path.txt");
    if(!mFile2.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path c_tree_path not correct");
    }else{
    QTextStream stream2(&mFile2);
    for(int i(0); i < list.count();i++)
    {
          stream2 << (list.at(i)+"\n");
    }
    mFile2.close();
    }

    QFile mFile3(qApp->applicationDirPath()+"/q_tree_path.txt");
    if(!mFile3.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Path q_tree_path not correct");
    }else{
    QTextStream stream3(&mFile3);
    for(int i(0); i < Qlist.count();i++)
    {
          stream3 << (Qlist.at(i)+"\n");
    }
    mFile3.close();
    }
}
void MainWindow::OPENitem()
{
    if (ui->treeWidget->selectedItems().isEmpty())
          QMessageBox::information(this,"Error","Виберіть пункт із змісту");
    else{
       QTreeWidgetItem *item = ui->treeWidget->currentItem();
       if(item->parent()){
           if(item->parent()->text(0) == "C++"){
                 int *a = new int(ui->treeWidget->currentIndex().row());
                 ui->statusBar->showMessage("Ви вибрали: "+item->text(0));
                 if(*a < list.count()){
                     o = new openitem();
                     QObject::connect(o,SIGNAL(file(openitem*,int)),this,SLOT(showfile(openitem*,int)));
                     o->setpath((qApp->applicationDirPath()+"/html_files"+list.at(*a)),item->text(0));
                                      }
                 else{
                     QMessageBox::information(this,"Error","Такої сторінки для С++ ще не існує");
                     }
       }
           else  if(item->parent()->text(0) == "Qt"){
               int *a = new int(ui->treeWidget->currentIndex().row());
               ui->statusBar->showMessage("Ви вибрали: "+item->text(0));
               if(*a < Qlist.count()){
                   o = new openitem();
                   QObject::connect(o,SIGNAL(file(openitem*,int)),this,SLOT(showfile(openitem*,int)));
                   o->setpath((qApp->applicationDirPath()+"/html_files"+Qlist.at(*a)),item->text(0));
                                    }
               else{
                   QMessageBox::information(this,"Error","Такої сторінки для Qt ще не існує");
                   }
           }
       }
       else{
           if(item->text(0) == "C++"){
               ui->statusBar->showMessage("Ви вибрали: C++");
               o = new openitem();
               QObject::connect(o,SIGNAL(file(openitem*,int)),this,SLOT(showfile(openitem*,int)));
               o->setpath((qApp->applicationDirPath()+"/html_files"+"/C++.html"),item->text(0));
           }
           else if(item->text(0) == "Qt"){
               ui->statusBar->showMessage("Ви вибрали: Qt");
               o = new openitem();
               QObject::connect(o,SIGNAL(file(openitem*,int)),this,SLOT(showfile(openitem*,int)));
               o->setpath((qApp->applicationDirPath()+"/html_files"+"/Qt.html"),item->text(0));
           }
       }
    }
}
void MainWindow::on_pushButton_open_clicked()//Вибрати
{
     OPENitem();
}
void MainWindow::showfile(openitem* p,int a){
    if(a == 1){
        p->show();
    }else{
        ui->statusBar->showMessage("Такого файлу не існує");
        delete p;
    }
}

void MainWindow::on_pushButton_add_clicked()//Добавити
{
    if(authorization){
        additem();
    }else{
        ui->statusBar->showMessage("Увійти");
        sign_in *a = new sign_in();
        a->getpass(&pass);
        a->show();
        QObject::connect(a,SIGNAL(rightpass()),this,SLOT(additem()));
    }
}
void MainWindow::additem()
{
    ui->statusBar->showMessage("Добавити");
    i = new newItem(this);
    i->show();
    QObject::connect(i,SIGNAL(returntext(QString&,QString&,int)),this,SLOT(setnewitem(QString&,QString&,int)));
}
 void MainWindow::setnewitem(QString &str,QString &str2,int a)
 {
     if(a == 0){
        QTreeWidgetItem *item = new  QTreeWidgetItem(1);
        item->setText(0,str);
        C->addChild(item);
        list.append("/"+str2);
        ui->statusBar->showMessage("Добавлено "+str+" в розділ С++");
     } else if(a == 1){
        QTreeWidgetItem *item = new  QTreeWidgetItem(1);
        item->setText(0,str);
        Qt->addChild(item);
        Qlist.append("/"+str2);
        ui->statusBar->showMessage("Добавлено "+str+" в розділ Qt");
     }
 }

void MainWindow::on_pushButton_delete_clicked()//Видалити Button
{
    if(authorization)
    {
        deleteitem();
    }
    else{
        ui->statusBar->showMessage("Увійти");
        sign_in *a = new sign_in();
        a->getpass(&pass);
        a->show();
        QObject::connect(a,SIGNAL(rightpass()),this,SLOT(deleteitem()));
    }
}
void MainWindow::deleteitem()
{
    if (ui->treeWidget->selectedItems().isEmpty())
          QMessageBox::information(this,"Error","Виберіть пункт із змісту");
    else{
          QMessageBox::StandardButton del = QMessageBox::question(this,"Видалення","Ви дійсно хочете видалити "+ui->treeWidget->currentItem()->text(0)+" ?",QMessageBox::Yes|QMessageBox::No);
    if(del == QMessageBox::Yes){
      QTreeWidgetItem *item = ui->treeWidget->currentItem();
      if(item->parent()){
          if(item->parent()->text(0) == "C++"){
             ui->statusBar->showMessage("Видалено "+item->text(0));
             list.removeAt(ui->treeWidget->currentIndex().row());
             delete item->parent()->takeChild(item->parent()->indexOfChild(item));
          }
          else if(item->parent()->text(0) == "Qt"){
             ui->statusBar->showMessage("Видалено "+item->text(0));
             Qlist.removeAt(ui->treeWidget->currentIndex().row());
             delete item->parent()->takeChild(item->parent()->indexOfChild(item));
          }

      } else {
          QMessageBox::information(this,"Error","Цього елементу не можна видалити");
          ui->statusBar->showMessage("Розділ "+item->text(0)+" видалити не можна.");
          //item = treeWidget->takeTopLevelItem(x);
          //if(item)delete item;
             }
      }
    }
}

void MainWindow::on_pushButton_web_clicked()
{
    QUrl url("https://andriy1024.github.io/index.html");
    QDesktopServices::openUrl(url);
    ui->statusBar->showMessage("Web-site");
}
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item)
{
    ui->statusBar->showMessage(item->text(0));
    if(!item->parent()){
        if(item->isExpanded()){
            ui->treeWidget->collapseItem(item);
        }else{
             ui->treeWidget->expandItem(item);
        }
    }
}
void MainWindow::on_treeWidget_itemDoubleClicked()
{
        OPENitem();
}
void MainWindow::on_select2_triggered()
{
        OPENitem();
}
void MainWindow::log_in()
{
     setWindowTitle("Довідник C++/Qt Admin");
     ui->statusBar->showMessage("Admin");
     authorization  = true;
}
void MainWindow::log_out()
{
     setWindowTitle("Довідник C++/Qt User");
     ui->statusBar->showMessage("User");
     authorization  = false;
}
void MainWindow::on_action_login_triggered()
{
    sign_in *a = new sign_in();
    a->getpass(&pass);
    a->show();
    ui->statusBar->showMessage("Увійти");
    QObject::connect(a,SIGNAL(rightpass()),this,SLOT(log_in()));
}

void MainWindow::on_action_logout_triggered()
{
    log_out();
}

void MainWindow::on_action_quit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_add2_triggered()
{
    if(authorization){
        additem();
    }else{
        ui->statusBar->showMessage("Увійти");
        sign_in *a = new sign_in();
        a->getpass(&pass);
        a->show();
        QObject::connect(a,SIGNAL(rightpass()),this,SLOT(additem()));
    }
}

void MainWindow::on_delete2_triggered() // Видалити Action
{
    if(authorization)
    {
        deleteitem();
    }
    else{
        ui->statusBar->showMessage("Увійти");
        sign_in *a = new sign_in();
        a->getpass(&pass);
        a->show();
        QObject::connect(a,SIGNAL(rightpass()),this,SLOT(deleteitem()));
    }
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    ui->statusBar->showMessage("Закрити");
    QMessageBox::StandardButton reply = QMessageBox::question(this," ","Бажаєте згорнути програму в фоновий режим ?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
    if(this->isVisible()){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Довідник С++/Qt",
                              tr("Додаток згорнуто в трей. Для того щоб, "
                                     "развернути вікно додатку, клацніть по іконці додатку в треї"),
                              icon,
                              2000);
    }
    }else{
        QApplication::quit();
    }
}

/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:

            if(!this->isVisible()){
                this->show();
                ui->statusBar->showMessage("Головне вікно довідника C++/Qt");
            } else {
                this->hide();
            }

        break;
    default:
        break;
    }
}

void MainWindow::on_action_collapse_triggered()// Згорнути Action
{
    if(this->isVisible()){
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Довідник С++/Qt",
                              tr("Додаток згорнуто в трей. Для того щоб, "
                                     "развернути вікно додатку, клацніть по іконці додатку в треї"),
                              icon,
                              2000);
    }
}

void MainWindow::on_pushButton_help_clicked()
{

}

void MainWindow::on_help2_triggered()
{
    o = new openitem();
    QObject::connect(o,SIGNAL(file(openitem*,int)),this,SLOT(showfile(openitem*,int)));
    o->setpath(qApp->applicationDirPath()+"/html_files/help.html","Довідка: про програму");
}

void MainWindow::on_me_triggered()
{
    o = new openitem();
    QObject::connect(o,SIGNAL(file(openitem*,int)),this,SLOT(showfile(openitem*,int)));
    o->setpath(qApp->applicationDirPath()+"/html_files/me.html","Довідка: про автора");
}
