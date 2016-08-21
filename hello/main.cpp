#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *Label = new QLabel("Hello Qt!");
    Label->show();    

    return app.exec();
}
