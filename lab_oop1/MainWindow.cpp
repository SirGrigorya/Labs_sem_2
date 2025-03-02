#include "MainWindow.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "ConvexPolygon.h"
#include "Errors.h"
#include <QMessageBox>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), textEdit(new QTextEdit(this)) {

    setWindowTitle("Фигуры");
    setCentralWidget(textEdit);

    // Создание меню
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *addMenu = menuBar->addMenu("Добавить фигуру");
    addMenu->addAction("Круг", this, &MainWindow::addCircle);
    addMenu->addAction("Прямоугольник", this, &MainWindow::addRectangle);
    addMenu->addAction("Треугольник", this, &MainWindow::addTriangle);
    addMenu->addAction("Многоугольник", this, &MainWindow::addConvexPolygon);

    QMenu *showMenu = menuBar->addMenu("Показать");
    showMenu->addAction("Список фигур", this, &MainWindow::showFigures);
    showMenu->addAction("Площади фигур", this, &MainWindow::showAreas);
    showMenu->addAction("Сумма площадей", this, &MainWindow::showTotalArea);

    QMenu *sortMenu = menuBar->addMenu("Сортировка");
    sortMenu->addAction("По площади", this, &MainWindow::sortFigures);

    QMenu *deleteMenu = menuBar->addMenu("Удалить");
    deleteMenu->addAction("По номеру", this, &MainWindow::deleteFigure);
    deleteMenu->addAction("По площади", this, &MainWindow::deleteFiguresByArea);
}

MainWindow::~MainWindow() {}

// Добавление круга
void MainWindow::addCircle() {
    try {
        bool ok;
        double x = QInputDialog::getDouble(this, "Круг", "X центра:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double y = QInputDialog::getDouble(this, "Круг", "Y центра:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double radius = QInputDialog::getDouble(this, "Круг", "Радиус:", 1, 0, 1000, 2, &ok);
        if (!ok) return;

        memoryManager.addFigure(std::make_shared<Circle>("Круг", x, y, radius));
        updateTextEdit();
    } catch (const ShapeError& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

// Добавление прямоугольника
void MainWindow::addRectangle() {
    try {
        bool ok;
        double x1 = QInputDialog::getDouble(this, "Прямоугольник", "X верх. левого:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double y1 = QInputDialog::getDouble(this, "Прямоугольник", "Y верх. левого:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double x2 = QInputDialog::getDouble(this, "Прямоугольник", "X ниж. правого:", 1, -1000, 1000, 2, &ok);
        if (!ok) return;
        double y2 = QInputDialog::getDouble(this, "Прямоугольник", "Y ниж. правого:", 1, -1000, 1000, 2, &ok);
        if (!ok) return;

        memoryManager.addFigure(std::make_shared<Rectangle>("Прямоугольник", x1, y1, x2, y2));
        updateTextEdit();
    } catch (const ShapeError& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

// Добавление треугольника
void MainWindow::addTriangle() {
    try {
        bool ok;
        double x1 = QInputDialog::getDouble(this, "Треугольник", "X1:", 0, -1000, 1000, 2, &ok); // -1000 и 1000 - диапазон корректных данных
        if (!ok) return;
        double y1 = QInputDialog::getDouble(this, "Треугольник", "Y1:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double x2 = QInputDialog::getDouble(this, "Треугольник", "X2:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double y2 = QInputDialog::getDouble(this, "Треугольник", "Y2:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double x3 = QInputDialog::getDouble(this, "Треугольник", "X3:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;
        double y3 = QInputDialog::getDouble(this, "Треугольник", "Y3:", 0, -1000, 1000, 2, &ok);
        if (!ok) return;

        memoryManager.addFigure(std::make_shared<Triangle>("Треугольник", x1, y1, x2, y2, x3, y3));
        updateTextEdit();
    } catch (const ShapeError& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

// Добавление многоугольника
void MainWindow::addConvexPolygon() {
    try {
        bool ok;
        int vertexCount = QInputDialog::getInt(this, "Многоугольник", "Введите количество вершин:", 3, 3, 100, 1, &ok);
        if (!ok) return;

        std::vector<std::pair<double, double>> vertices;
        for (int i = 0; i < vertexCount; ++i) {
            double x = QInputDialog::getDouble(this, "Многоугольник", QString("Введите X вершины %1:").arg(i + 1), 0, -1000, 1000, 2, &ok);
            if (!ok) return;
            double y = QInputDialog::getDouble(this, "Многоугольник", QString("Введите Y вершины %1:").arg(i + 1), 0, -1000, 1000, 2, &ok);
            if (!ok) return;
            vertices.push_back({x, y});
        }

        memoryManager.addFigure(std::make_shared<ConvexPolygon>("Многоугольник", vertices));
        updateTextEdit();
    } catch (const ShapeError& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}

// Обновление текстового поля
void MainWindow::updateTextEdit() {
    QString text;
    auto figures = memoryManager.getFigures();
    for (size_t i = 0; i < figures.size(); ++i) {
        text += QString("%1. %2\n").arg(i + 1).arg(QString::fromStdString(figures[i]->getInfo()));
    }
    textEdit->setText(text);
}

// Показать площади
void MainWindow::showAreas() {
    QString text;
    auto figures = memoryManager.getFigures();
    for (size_t i = 0; i < figures.size(); ++i) {
        text += QString("%1. Площадь: %2\n")
                    .arg(i + 1)
                    .arg(figures[i]->getArea());
    }
    textEdit->setText(text);
}

// Сумма площадей
void MainWindow::showTotalArea() {
    double total = 0;
    auto figures = memoryManager.getFigures();
    for (const auto& figure : figures) {
        total += figure->getArea();
    }
    QMessageBox::information(this, "Сумма", QString("Общая площадь: %1").arg(total));
}

// Сортировка по площади
void MainWindow::sortFigures() {
    auto figures = memoryManager.getFigures();
    std::sort(figures.begin(), figures.end(),
              [](const auto& a, const auto& b) { return a->getArea() < b->getArea(); });
    memoryManager.clear();
    for (const auto& figure : figures) {
        memoryManager.addFigure(figure);
    }
    updateTextEdit();
}

// Удалить по номеру
void MainWindow::deleteFigure() {
    bool ok;
    int index = QInputDialog::getInt(this, "Удаление", "Номер:", 1, 1, memoryManager.getFigureCount(), 1, &ok);
    if (!ok) return;
    memoryManager.removeFigure(index - 1);
    updateTextEdit();
}

// Удалить по площади
void MainWindow::deleteFiguresByArea() {
    bool ok;
    double threshold = QInputDialog::getDouble(this, "Удаление", "Площадь >", 0, 0, 1e6, 2, &ok);
    if (!ok) return;
    memoryManager.removeFiguresWithAreaGreaterThan(threshold);
    updateTextEdit();
}

void MainWindow::showFigures() {
    QString text;
    auto figures = memoryManager.getFigures();
    for (size_t i = 0; i < figures.size(); ++i) {
        text += QString("%1. %2\n").arg(i + 1).arg(QString::fromStdString(figures[i]->getInfo()));
    }
    textEdit->setText(text);
}
