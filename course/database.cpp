#include"database.h"
#include"vector.h"
#include<QString>
#include<QDebug>
#include"sstream"
#include<QTableWidget>
#include<cstring>

using std::string;

DataBase::DataBase(){
}

void DataBase::fill(QTableWidget& table){
    int N=0;
    it_=contain_.begin();
    for(it_=contain_.begin();it_!=contain_.end();++it_){
        table.insertRow(N);
        table.setItem(N,0, new QTableWidgetItem(it_->name_of_detail.c_str()));
        table.setItem(N,1, new QTableWidgetItem(it_->classification.c_str()));
        table.setItem(N,2, new QTableWidgetItem(it_->properties.c_str()));
        table.setItem(N,3, new QTableWidgetItem(it_->size.c_str()));
        table.setItem(N,4, new QTableWidgetItem(it_->manufacturer.c_str()));
        table.setItem(N,5, new QTableWidgetItem(it_->price.c_str()));
        N++;
    }
}

void DataBase::AddData(details add){
    contain_.push_back(add);
}

void DataBase::clearBase(){
    contain_.clear();
}


void DataBase::readData(QFile& file){
    QTextStream stream(&file);
    QString str;
    QStringList field;
    details tmp;
    while(!stream.atEnd()){
        str=stream.readLine();
        str=str.simplified();
        field=str.split("|");
        tmp.name_of_detail=field[0].toStdString();
        tmp.classification=field[1].toStdString();
        tmp.properties=field[2].toStdString();
        tmp.size=field[3].toStdString();
        tmp.manufacturer=field[4].toStdString();
        tmp.price=field[5].toStdString();
        contain_.push_back(tmp);
    }
}

void DataBase::editData(int index, details izmen){
    contain_[index].name_of_detail=izmen.name_of_detail;
    contain_[index].classification=izmen.classification;
    contain_[index].properties=izmen.properties;
    contain_[index].size=izmen.size;
    contain_[index].manufacturer=izmen.manufacturer;
    contain_[index].price=izmen.price;
}

void DataBase::saveData(QFile& file){
    QString str("");
    it_=contain_.begin();
    for(it_=contain_.begin(); it_!=contain_.end();++it_){
        str.append(it_->name_of_detail.c_str());
        str.append("|");
        str.append(it_->classification.c_str());
        str.append("|");
        str.append(it_->properties.c_str());
        str.append("|");
        str.append(it_->size.c_str());
        str.append("|");
        str.append(it_->manufacturer.c_str());
        str.append("|");
        str.append(it_->price.c_str());
        str.append("\n");
    }
    file.close();
    file.open(QIODevice::WriteOnly);
    QByteArray ar;
    ar.append(str);
    file.write(ar);
}

void DataBase::findData(QString find, QTableWidget& table){
    it_=contain_.begin();
    int N=0;
    for(it_=contain_.begin();it_!=contain_.end();++it_){
        if(QString::fromStdString(it_->name_of_detail).contains(find,Qt::CaseInsensitive))
            table.setCurrentCell(N,0,QItemSelectionModel::Select);
        if(QString::fromStdString(it_->classification).contains(find,Qt::CaseInsensitive))
            table.setCurrentCell(N,1,QItemSelectionModel::Select);
        if(QString::fromStdString(it_->properties).contains(find,Qt::CaseInsensitive))
            table.setCurrentCell(N,2,QItemSelectionModel::Select);
        if(QString::fromStdString(it_->size).contains(find,Qt::CaseInsensitive))
            table.setCurrentCell(N,3,QItemSelectionModel::Select);
        if(QString::fromStdString(it_->manufacturer).contains(find,Qt::CaseInsensitive))
            table.setCurrentCell(N,4,QItemSelectionModel::Select);
        if(QString::fromStdString(it_->price).contains(find,Qt::CaseInsensitive))
            table.setCurrentCell(N,5,QItemSelectionModel::Select);
        N++;
    }
}
void DataBase::removeData(int index){
    contain_.remove(index);
}


