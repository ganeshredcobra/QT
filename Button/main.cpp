#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *Button = new QPushButton("Quit");
    QObject::connect(Button,SIGNAL(clicked()),&app,SLOT(quit()));
    Button->show();

    return app.exec();
}
