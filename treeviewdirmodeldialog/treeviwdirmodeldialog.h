#ifndef TREEVIWDIRMODELDIALOG_H
#define TREEVIWDIRMODELDIALOG_H

#include <QDialog>
#include <QDirModel>
#include <QTreeView>
#include <QInputDialog>
#include <QFileSystemModel>
#include <QDebug>

namespace Ui {
class treeviwdirmodeldialog;
}

class treeviwdirmodeldialog : public QDialog
{
    Q_OBJECT

public:
    explicit treeviwdirmodeldialog(QWidget *parent = 0);
    ~treeviwdirmodeldialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::treeviwdirmodeldialog *ui;
    QDirModel *model;
};

#endif // TREEVIWDIRMODELDIALOG_H
