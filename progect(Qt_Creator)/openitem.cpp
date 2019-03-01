#include "openitem.h"
#include "ui_openitem.h"
#include <QMessageBox>
#include <QPushButton>
#include <QProcess>


openitem::openitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openitem)
{
    ui->setupUi(this);
    int id1 = QFontDatabase::addApplicationFont(":/new/Vodafone.ttf");
    int id2 = QFontDatabase::addApplicationFont(":/new/Ubuntu.ttf");
    QString family1 = QFontDatabase::applicationFontFamilies(id1).at(0);
    QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
    QFont vodafone(family1);
    QFont ubuntu(family2);
    ui->textBrowser->setFont(vodafone);
    ubuntu.setPixelSize(15);
    ui->pushButton->setFont(ubuntu);
    ui->example->setFont(ubuntu);
    ui->example->setDisabled(true);
    ui->example->hide();
}

openitem::~openitem()
{
    delete ui;
}

void openitem::on_pushButton_clicked()
{
    hide();
    this->destroy();
}
void  openitem::setpath(QString path,QString title){
    this->setWindowTitle(title);
    if(title == "Діалогові вікна"){
        ui->example->show();
        ui->example->setDisabled(false);
        exemple = qApp->applicationDirPath() + "/ex_dialog";
    }else if(title == "Створення меню в Qt"){
        ui->example->show();
        ui->example->setDisabled(false);
        exemple = qApp->applicationDirPath() + "/ex_menu";
    }else if(title == "Робота з файлами"){
        ui->example->show();
        ui->example->setDisabled(false);
        exemple = qApp->applicationDirPath() + "/ex_qfile";
    }else if(title == "Сигнали і слоти"){
        ui->example->show();
        ui->example->setDisabled(false);
        exemple = qApp->applicationDirPath() + "/ex_signals";
    }else if(title == "Знайомство з Qt Designer"){
        ui->example->show();
        ui->example->setDisabled(false);
        exemple = qApp->applicationDirPath() + "/ex_log_in";
    }else if(title == "Клас часу QTime"){
        ui->example->show();
        ui->example->setDisabled(false);
        exemple = qApp->applicationDirPath() + "/ex_Qtimer";
    }
    QFile mFile(path);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"Error","Файлу для цієї теми не існує");
        file(this,0);

    }else{
        QTextStream stream(&mFile);
        QString buffer = stream.readAll();
        ui->textBrowser->setHtml(buffer);
        mFile.flush();
        mFile.close();
        file(this,1);
    }
}
void openitem::closeEvent(QCloseEvent * event)
{
    event->ignore();
    hide();
    this->~openitem();
}


void openitem::on_example_clicked()
{
        QProcess process(this);
        process.startDetached(exemple);
}
