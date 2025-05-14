#include "task.h"

#include <QApplication>
#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Task mainWindow;
    mainWindow.show();
    return app.exec();
}
