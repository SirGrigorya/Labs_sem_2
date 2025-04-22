#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QString>
#include "CalculatorFacade.h"

class CalculatorWindow : public QMainWindow {
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void handleButtonClick();
    void calculate();
    void clear();
    void backspace();

private:
    void setupUI();
    void addButton(const QString& text, int row, int col, int rowSpan = 1, int colSpan = 1);

    QLineEdit *display;
    QWidget *centralWidget;
    QGridLayout *layout;
    CalculatorFacade facade;
    bool calculated;
};

#endif // CALCULATORWINDOW_H
