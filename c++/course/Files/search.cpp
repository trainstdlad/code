#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search){
    ui->setupUi(this);
}

QString search::FindValue(){
    return ui->search_line->text();
}
search::~search(){
    delete ui;
}
