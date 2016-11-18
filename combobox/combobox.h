#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class combobox;
}

class combobox : public QMainWindow
{
    Q_OBJECT

public:
    explicit combobox(QWidget *parent = 0);
    ~combobox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::combobox *ui;
};

#endif // COMBOBOX_H
