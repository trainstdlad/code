#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFile>
#include <QMouseEvent>
#include"database.h"
#include<QTableView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void main_line();
    void on_create_triggered();
    void on_open_triggered();
    void on_save_triggered();
    void on_save_as_triggered();
    void on_search_triggered();
    void on_merge_triggered();
    void on_add_triggered();
    void on_edit_triggered();
    void on_del_triggered();
    void on_close_triggered();
    void on_exit_triggered();
    void on_info_triggered();   
    void clearTable();
    void on_action_triggered();
    void on_table_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QLabel* StatusBar_;
    DataBase obj_;
    QFile curfile_;
};

#endif // MAINWINDOW_H
