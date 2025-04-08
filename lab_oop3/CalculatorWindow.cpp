#include "CalculatorWindow.h"
#include <QApplication>

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent), calculated(false) {
    setupUI();
}

CalculatorWindow::~CalculatorWindow() {}

void CalculatorWindow::setupUI() {
    centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);

    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet("font-size: 24px;");
    layout->addWidget(display, 0, 0, 1, 4);

    addButton("7", 1, 0);
    addButton("8", 1, 1);
    addButton("9", 1, 2);
    addButton("/", 1, 3);

    addButton("4", 2, 0);
    addButton("5", 2, 1);
    addButton("6", 2, 2);
    addButton("*", 2, 3);

    addButton("1", 3, 0);
    addButton("2", 3, 1);
    addButton("3", 3, 2);
    addButton("-", 3, 3);

    addButton("0", 4, 0);
    addButton(".", 4, 1);
    addButton("=", 4, 2);
    addButton("+", 4, 3);

    addButton("(", 5, 0);
    addButton(")", 5, 1);
    addButton("C", 5, 2);
    addButton("Del", 5, 3);

    setCentralWidget(centralWidget);
    setWindowTitle("Calculator");
    resize(300, 400);
}

void CalculatorWindow::addButton(const QString& text, int row, int col, int rowSpan, int colSpan) {
    QPushButton *button = new QPushButton(text);
    button->setStyleSheet("font-size: 18px;");
    layout->addWidget(button, row, col, rowSpan, colSpan);

    if (text == "=") {
        connect(button, &QPushButton::clicked, this, &CalculatorWindow::calculate);
    } else if (text == "C") {
        connect(button, &QPushButton::clicked, this, &CalculatorWindow::clear);
    } else if (text == "Del") {
        connect(button, &QPushButton::clicked, this, &CalculatorWindow::backspace);
    } else {
        connect(button, &QPushButton::clicked, this, &CalculatorWindow::handleButtonClick);
    }
}

void CalculatorWindow::handleButtonClick() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (calculated) {
        display->clear();
        calculated = false;
    }
    display->setText(display->text() + button->text());
}

void CalculatorWindow::calculate() {
    QString expression = display->text();
    if (expression.isEmpty()) return;

    std::string result = facade.calculate(expression.toStdString());
    display->setText(QString::fromStdString(result));
    calculated = true;
}

void CalculatorWindow::clear() {
    display->clear();
    calculated = false;
}

void CalculatorWindow::backspace() {
    if (calculated) {
        display->clear();
        calculated = false;
    } else {
        QString text = display->text();
        text.chop(1);
        display->setText(text);
    }
}
