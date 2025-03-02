#include <QApplication>
#include "entrypoint.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Запуск программы через единую точку входа
    runApplication();

    return app.exec();
}
