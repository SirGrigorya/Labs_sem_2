#ifndef DESIGN_H
#define DESIGN_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>

// Настройка интерфейса
void setupUI(QWidget *window);

// Получение виджетов
QLineEdit *getInputField(QWidget *window);
QComboBox *getFromBaseComboBox(QWidget *window);
QComboBox *getToBaseComboBox(QWidget *window);
QPushButton *getConvertButton(QWidget *window);
QLineEdit *getOutputField(QWidget *window);
QLabel *getErrorLabel(QWidget *window);

#endif // DESIGN_H
