#ifndef EDITELEMENT_H
#define EDITELEMENT_H

#include <QDialog>

namespace Ui {
class editelement;
}

class editelement : public QDialog
{
    Q_OBJECT

public:
    explicit editelement(QWidget *parent = 0,
        QString name_of_detail = "",
        QString classification = "",
        QString properties = "",
        QString size = "",
        QString manufacture = "",
        QString price = "");

    ~editelement();

        QString getNameOfDetail();
        QString getClassification();
        QString getProperties();
        QString getSize();
        QString getManufacture();
        QString getPrice();

private:
    Ui::editelement *ui;
};

#endif // EDITELEMENT_H
