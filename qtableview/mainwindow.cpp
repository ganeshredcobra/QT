#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns

    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    QImage image("mypix.jpg");
    QStandardItem *item = new QStandardItem();
    item->setData(QVariant(QPixmap::fromImage(image)), Qt::DecorationRole);
    model->setItem(0, 0, item);

    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}
