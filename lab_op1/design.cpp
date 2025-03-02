#include "design.h"

QLineEdit *inputField = nullptr;
QComboBox *fromBaseComboBox = nullptr;
QComboBox *toBaseComboBox = nullptr;
QPushButton *convertButton = nullptr;
QLineEdit *outputField = nullptr;
QLabel *errorLabel = nullptr;

void setupUI(QWidget *window) {
    QFormLayout *layout = new QFormLayout(window);

    inputField = new QLineEdit(window);
    layout->addRow("Введите число:", inputField);

    fromBaseComboBox = new QComboBox(window);
    fromBaseComboBox->addItem("Десятичная (10)", 10);
    fromBaseComboBox->addItem("Двоичная (2)", 2);
    fromBaseComboBox->addItem("Шестнадцатеричная (16)", 16);
    layout->addRow("Из системы:", fromBaseComboBox);

    toBaseComboBox = new QComboBox(window);
    toBaseComboBox->addItem("Десятичная (10)", 10);
    toBaseComboBox->addItem("Двоичная (2)", 2);
    toBaseComboBox->addItem("Шестнадцатеричная (16)", 16);
    layout->addRow("В систему:", toBaseComboBox);

    convertButton = new QPushButton("Перевести", window);
    layout->addRow(convertButton);

    outputField = new QLineEdit(window);
    outputField->setReadOnly(true);
    layout->addRow("Результат:", outputField);

    errorLabel = new QLabel(window);
    errorLabel->setStyleSheet("color: red;");
    layout->addRow(errorLabel);
}

QLineEdit *getInputField(QWidget *window) { return inputField; }
QComboBox *getFromBaseComboBox(QWidget *window) { return fromBaseComboBox; }
QComboBox *getToBaseComboBox(QWidget *window) { return toBaseComboBox; }
QPushButton *getConvertButton(QWidget *window) { return convertButton; }
QLineEdit *getOutputField(QWidget *window) { return outputField; }
QLabel *getErrorLabel(QWidget *window) { return errorLabel; }
