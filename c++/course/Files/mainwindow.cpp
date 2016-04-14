#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFileDialog>
#include<QStatusBar>
#include"search.h"
#include"editelement.h"
#include<QTableView>
#include<QStyle>
#include<QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   setWindowTitle("The Course");
   StatusBar_=new QLabel(this);
   statusBar()->addWidget(StatusBar_);
   ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::main_line(){
    QStringList heading;
    heading<<"Name"<<"Classification"<<"Properties"<<"Size"<<"Manufacturer"<<"Price";
    ui->table->setColumnCount(6);
    ui->table->setHorizontalHeaderLabels(heading);
    ui->table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->table->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
}

void MainWindow::on_create_triggered(){
    if(curfile_.openMode()!=QIODevice::NotOpen){
        QMessageBox::warning(this,"Error", "You should close the working file",QMessageBox::Ok);
        return;
    }
    else{
        QString filename=QFileDialog::getSaveFileName(this,"New file","");
        if(filename.isEmpty())
            return;
        filename.append(".txt");
        curfile_.setFileName(filename);
        QString namefile=QFileInfo(filename).baseName();
        if(!curfile_.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this,"Error","Can't be open"+namefile,QMessageBox::Ok);
            return;
        }
        main_line();
        statusBar()->showMessage("File "+namefile+" created");
    }
}

void MainWindow::on_open_triggered(){
    if(curfile_.openMode()==QIODevice::NotOpen){
        QString filename=QFileDialog::getOpenFileName(this,"Open","","*.txt");
        if(filename.isEmpty())
            return;
            curfile_.setFileName(filename);
            QString namefile=QFileInfo(filename).baseName();
            if(!curfile_.open(QIODevice::ReadWrite)){
                QMessageBox::critical(this,"Error","Can't be open file"+namefile,QMessageBox::Ok);
            return;
            }
            obj_.readData(curfile_);
            main_line();
            obj_.fill(*ui->table);
            statusBar()->showMessage("File "+namefile+" open");
    }
    else{
        QMessageBox::warning( this,"Open "," If you want to open a new file, you should close the working file ", QMessageBox::Ok);
        return;
    }
}

void MainWindow::on_save_triggered(){
    if(curfile_.openMode()==QIODevice::NotOpen){
        QMessageBox::critical(this,"Error","Open file",QMessageBox::Ok);
        return;
    }
    else{
        obj_.saveData(curfile_);
        QString namefile=QFileInfo(curfile_.fileName()).baseName();
        statusBar()->showMessage("File "+namefile+" saved");
    }
}

void MainWindow::on_save_as_triggered(){
        if(curfile_.openMode()==QIODevice::NotOpen){
            QMessageBox::critical(this,"Error","Open file",QMessageBox::Ok);
            return;
        }
        else{
            QString filename=QFileDialog::getSaveFileName(this,"Save as",""  );
            filename.append(".txt");
            curfile_.setFileName(filename);
            obj_.saveData(curfile_);
            QString namefile=QFileInfo(curfile_.fileName()).baseName();
            statusBar()->showMessage("File "+namefile+" saved");
        }
}

void MainWindow::on_search_triggered(){
    if(curfile_.openMode()==QIODevice::NotOpen){
        QMessageBox::warning(this,"Search","You have not selected file",QMessageBox::Ok);
        return;
    }
    else{
        ui->table->clearSelection();
        search* wordsearch = new search(this);
        wordsearch->setWindowTitle("Search of records");
        if(wordsearch->exec()==QDialog::Accepted){
            QString findstr=wordsearch->FindValue();
            obj_.findData(findstr, *ui->table);
            statusBar()->showMessage("Search finished");
        }
    }
}

void MainWindow::on_merge_triggered(){
    if(curfile_.openMode()==QIODevice::NotOpen){
        QMessageBox::critical(this,"Error","File can't be merge. Open file",QMessageBox::Ok);
        return;
    }
    QFile tfp;
    QString filename=QFileDialog::getOpenFileName(this,"Open","","*.txt");
    if(filename.isEmpty())
        return;
    tfp.setFileName(filename);
    QString namefile=QFileInfo(filename).baseName();
    if(!tfp.open(QIODevice::ReadWrite)){
        QMessageBox::critical(this,"Error", "Can't be open file "+namefile,QMessageBox::Ok);
        return;
    }
    obj_.readData(tfp);
    clearTable();
    main_line();
    obj_.fill(*ui->table);
    tfp.close();
    QString namefilebase=QFileInfo(curfile_.fileName()).baseName();
    statusBar()->showMessage("File "+namefilebase+" and "+namefile+" merged");
}

void MainWindow::on_add_triggered(){
    if(curfile_.openMode()==QIODevice::NotOpen){
        QMessageBox::warning(this,"Add Record", "You have not selected file",QMessageBox::Ok);
        return;
    }
    else{
        editelement* input=new editelement(this);
        input->setWindowTitle("Add Record");
        DataBase::details add;
        if(input->exec()==QDialog::Accepted){
            add.name_of_detail=input->getNameOfDetail().toStdString();
            add.classification=input->getClassification().toStdString();
            add.properties=input->getProperties().toStdString();
            add.size=input->getSize().toStdString();
            add.manufacturer=input->getManufacture().toStdString();
            add.price=input->getPrice().toStdString();
            obj_.AddData(add);
            clearTable();
            main_line();
            obj_.fill(*ui->table);
            statusBar()->showMessage("Record added ");
        }
    }
}

void MainWindow::on_edit_triggered(){
    int row=ui->table->currentRow();
    if(row != -1){
        DataBase::details izmen = obj_.returnIndex(row);
        editelement* editel = new editelement(this,izmen.name_of_detail.c_str(),
        izmen.classification.c_str(), izmen.properties.c_str(), izmen.size.c_str(),
        izmen.manufacturer.c_str(),izmen.price.c_str());
        editel->setWindowTitle("Edit");
            if(editel->exec() == QDialog::Accepted){
                izmen.name_of_detail = editel->getNameOfDetail().toStdString();
                izmen.classification = editel->getClassification().toStdString();
                izmen.properties = editel->getProperties().toStdString();
                izmen.size = editel->getSize().toStdString();
                izmen.manufacturer = editel->getManufacture().toStdString();
                izmen.price = editel->getPrice().toStdString();
                obj_.editData(row,izmen);
                clearTable();
                main_line();
                obj_.fill(*ui->table);
                statusBar()->showMessage("Record edited");
            }
    }
}

void MainWindow::on_del_triggered(){
    int row=ui->table->currentRow();
    if(row!=-1){
        int soobshenie = QMessageBox::question(this,"Warning","Do you want to delete this record?",QMessageBox::Ok,QMessageBox::Cancel);
        if(soobshenie == QMessageBox::Ok){
            obj_.removeData(row);
            clearTable();
            main_line();
            obj_.fill(*ui->table);
            statusBar()->showMessage("Record deleted");
        }
    else{
    }
    }
}

void MainWindow::on_close_triggered(){
    if(curfile_.openMode()!=QIODevice::NotOpen){
        int soobshenie = QMessageBox::question(this,"Close","Do you want to close this file?",QMessageBox::Ok,QMessageBox::Cancel);
        if(soobshenie == QMessageBox::Ok){
            curfile_.close();
            clearTable();
            ui->table->setColumnCount(0);
            obj_.clearBase();
            QString namefile=QFileInfo(curfile_.fileName()).baseName();
            statusBar()->showMessage("File "+namefile+" close");
        }
    }
}

void MainWindow::clearTable(){
    ui->table->clear();
    ui->table->setRowCount(0);
}

void MainWindow::on_exit_triggered(){
    int message = QMessageBox::question(this,"Question ","Do you want to quit?",QMessageBox::Ok,QMessageBox::Cancel);
    if(message == QMessageBox::Ok){
        qApp->exit();
    }
    else{
    }
}

void MainWindow::on_info_triggered(){
    QMessageBox::about(this,"About the course","Курсовая работа по дисциплине ООП.\n""На тему: База данных(Класс, характеризующий радиодетали)\n"
                       "Студентки группы ИКПИ43\n""Каюковой Юлии\n""2016 год");
}

void MainWindow::on_action_triggered(){
}

void MainWindow::on_table_activated(const QModelIndex &index){
}
