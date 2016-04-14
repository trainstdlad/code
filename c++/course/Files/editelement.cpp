#include "editelement.h"
#include "ui_editelement.h"

editelement::editelement(QWidget *parent, QString name_of_detail, QString classification, QString properties, QString size,
                         QString manufacture, QString price)

    :QDialog(parent),
    ui(new Ui::editelement){
        ui->setupUi(this);
        ui->name_of_detail->setText(name_of_detail);
        ui->classification->setText(classification);
        ui->properties->setText(properties);
        ui->size->setText(size);
        ui->manufacture->setText(manufacture);
        ui->price->setText(price);
}

editelement::~editelement(){
    delete ui;
}

QString editelement::getNameOfDetail(){
    return ui->name_of_detail->text();
}

QString editelement::getClassification(){
    return ui->classification->text();
}

QString editelement::getProperties(){
    return ui->properties->text();
}

QString editelement::getSize(){
    return ui->size->text();
}

QString editelement::getManufacture(){
    return ui->manufacture->text();
}

QString editelement::getPrice(){
    return ui->price->text();
}


