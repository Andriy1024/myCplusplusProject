#include "newitem.h"
#include "ui_newitem.h"
#include <QFontDatabase>
#include <QMessageBox>
newItem::newItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newItem)
{
    ui->setupUi(this);
    int id2 = QFontDatabase::addApplicationFont(":/new/Ubuntu.ttf");
    QString family2 = QFontDatabase::applicationFontFamilies(id2).at(0);
    QFont ubuntu(family2);
    ubuntu.setPixelSize(15);
    ui->pushButton->setFont(ubuntu);
    ui->pushButton_2->setFont(ubuntu);
    ui->label->setFont(ubuntu);
    ui->label_2->setFont(ubuntu);
    ui->label_3->setFont(ubuntu);
    ui->lineEdit->setFont(ubuntu);
    ui->nameofnewitem->setFont(ubuntu);
    ubuntu.setPixelSize(16);
    ui->radioButton->setFont(ubuntu);
    ui->radioButton_2->setFont(ubuntu);
    ui->pushButton_2->setShortcut(tr("Esc"));
}

newItem::~newItem()
{
    delete ui;
}

void newItem::on_pushButton_clicked()
{
    nameitem = ui->nameofnewitem->text();
    path = ui->lineEdit->text();
    if(!(nameitem.isEmpty())){
        if(!(path.isEmpty())){
            if(ui->radioButton->isChecked()){
               returntext(nameitem,path,0);
               hide();
               this->~newItem();
             } else if(ui->radioButton_2->isChecked()){
               returntext(nameitem,path,1);
               hide();
               this->~newItem();
            }else{ QMessageBox::information(this,"Error","Enter C++ or Qt");}
        }
        else{QMessageBox::information(this,"Error","Enter name of file");}
    }
    else{
        QMessageBox::information(this,"Error","Enter name");
    }
}

void newItem::on_pushButton_2_clicked()
{
    hide();
    this->~newItem();
}
void newItem::closeEvent(QCloseEvent * event)
{
    event->ignore();
    hide();
    this->~newItem();
}
