
#ifndef DATABASE_H
#define DATABASE_H
#include<QTableWidget>
#include<QString>
#include<QFile>
#include<cstring>
#include"vector.h"

using std::string;

class DataBase{
public:
    struct details{
        string name_of_detail;
        string classification;
        string properties;
        string size;
        string manufacturer;
        string price;
    };
    DataBase();
    void fill(QTableWidget& table);
    void AddData(details add);
    void clearBase();
    void readData(QFile& file);
    void editData(int index,details edt);
    void saveData(QFile& file);
    void findData(QString find,QTableWidget& table);
    void removeData(int index);
    details returnIndex(int index){return contain_[index];}
private:
    Vector <details> contain_;
    Vector <details> ::iterator it_;
};
#endif // DATABASE_H


