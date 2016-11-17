#include "combobox.h"
#include "ui_combobox.h"

combobox::combobox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::combobox)
{
    ui->setupUi(this);
}

combobox::~combobox()
{
    delete ui;
}
