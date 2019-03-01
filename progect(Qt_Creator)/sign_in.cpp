#include "sign_in.h"
#include "ui_sign_in.h"
#include <QFontDatabase>
#include<QMessageBox>
sign_in::sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    int id2 = QFontDatabase::addApplicationFont(":/new/Ubuntu.ttf");
    QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
    QFont ubuntu(family2);
    ubuntu.setPixelSize(15);
    ui->ok->setFont(ubuntu);
    ui->cancel->setFont(ubuntu);
    ui->label->setFont(ubuntu);
    ui->lineEdit->setFont(ubuntu);
    ui->cancel->setShortcut(tr("Esc"));
}

sign_in::~sign_in()
{
    delete ui;
}

void sign_in::on_ok_clicked()
{
    temp = ui->lineEdit->text();
    if(temp.isEmpty()){
        QMessageBox::information(this,"Error","Enter password");
    }else{
        if(temp == password){
            rightpass();
            hide();
            this->destroy();
        }
        else{
            QMessageBox::information(this,"Error","Пароль не правильний");
        }
    }
}

void sign_in::on_cancel_clicked()
{
    hide();
    this->destroy();
}
void sign_in::closeEvent(QCloseEvent * event)
{
    event->ignore();
    hide();
    this->~sign_in();
}
