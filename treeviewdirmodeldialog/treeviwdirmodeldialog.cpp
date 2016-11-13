#include "treeviwdirmodeldialog.h"
#include "ui_treeviwdirmodeldialog.h"

treeviwdirmodeldialog::treeviwdirmodeldialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::treeviwdirmodeldialog)
{
    ui->setupUi(this);
    // Create and populate our model

    QFileSystemModel *m_FsModel = new QFileSystemModel();
    m_FsModel->setRootPath("/tmp");

    model = new QDirModel(this);

    // Enable modifying file system
    model->setReadOnly(false);


    QTreeView *v = ui->treeView;
    v->setModel(m_FsModel);
    QModelIndex idx = m_FsModel->index("/home/ganesh/Downloads");
    v->setRootIndex(idx);
    //v.show();
    // Tie TreeView with DirModel
    // QTreeView::setModel(QAbstractItemModel * model)
    // Reimplemented from QAbstractItemView::setModel().
    //ui->treeView->setModel(m_FsModel);
}

treeviwdirmodeldialog::~treeviwdirmodeldialog()
{
    delete ui;
}

void treeviwdirmodeldialog::on_pushButton_clicked()
{
    //Get Name
    QModelIndex index = ui->treeView->currentIndex();
    QFileSystemModel* model = (QFileSystemModel*)ui->treeView->model();
    if(!index.isValid()) return;
    QString fileInfo = model->fileName(index);
    QString filepath = model->filePath(index);
    qDebug() <<fileInfo<<" "<<filepath ;
    if(fileInfo.endsWith(".png")||fileInfo.endsWith(".jpg"))
    {
        qDebug() <<"An Image";
        QImage image(filepath);
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
    else
        qDebug() <<"Not an Image";
}
void treeviwdirmodeldialog::on_pushButton_2_clicked()
{
    //Delete Name

}
