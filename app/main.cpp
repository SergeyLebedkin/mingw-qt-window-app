#include <QtWidgets/QApplication>
#include "widgets/MainWindow.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // create main window
    MainWindow* mw = new MainWindow();
    mw->show();

    return app.exec();
}