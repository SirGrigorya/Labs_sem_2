#include <QApplication>
#include "converterwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ConverterWidget *window = new ConverterWidget();
    window->show();

    return app.exec();
}
