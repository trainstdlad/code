#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_swap_clicked();

    void on_copyLeftRight_clicked();

    void on_copyRightLeft_clicked();

    void on_clearStrLeft_clicked();

    void on_clearStrRight_clicked();

    void on_clearAll_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
