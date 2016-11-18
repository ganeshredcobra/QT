#include "combobox.h"
#include "ui_combobox.h"

combobox::combobox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::combobox)
{
    ui->setupUi(this);
    // Fill the items of the ComboBox
    for(int i = 0; i < 10; i++)
    {
        ui->comboBox->addItem("item " + QString::number(i));
    }
}

combobox::~combobox()
{
    delete ui;
}

void combobox::on_pushButton_clicked()
{
    QMessageBox::information(this, "Item Selection",
                                 ui->comboBox->currentText());
}
