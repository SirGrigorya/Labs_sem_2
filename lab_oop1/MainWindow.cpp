#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Связь кнопок со слотами
    connect(ui->addButton, &QPushButton::clicked,
            this, &MainWindow::onAddButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked,
            this, &MainWindow::onDeleteButtonClicked);
}

void MainWindow::onAddButtonClicked() {
    // Диалог ввода параметров
    QString type = QInputDialog::getText(this, "Добавить фигуру", "Тип (круг/прямоугольник/треугольник):");

    try {
        if (type == "круг") {
            double x = QInputDialog::getDouble(this, "Круг", "X центра:");
            double y = QInputDialog::getDouble(this, "Круг", "Y центра:");
            double r = QInputDialog::getDouble(this, "Круг", "Радиус:");
            shapes.append(new Circle("Круг", x, y, r));
        }
        // Аналогично для других фигур

        updateShapesList();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

void MainWindow::updateShapesList() {
    ui->listWidget->clear();
    for (const Shape* shape : shapes) {
        ui->listWidget->addItem(shape->getInfo());
    }
    ui->totalLabel->setText(
        QString("Сумма периметров: %1").arg(
            std::accumulate(shapes.begin(), shapes.end(), 0.0,
                            [](double sum, Shape* s) { return sum + s->perimeter(); })
            ));
}

// Остальные методы...
