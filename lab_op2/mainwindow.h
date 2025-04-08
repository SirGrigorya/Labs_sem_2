#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include "entry.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();
    void on_loadButton_clicked();
    void on_calculateButton_clicked();

private:
    // Виджеты ввода
    QLineEdit *fileEdit;
    QLineEdit *regionEdit;
    QLineEdit *columnEdit;

    // Кнопки
    QPushButton *browseButton;
    QPushButton *loadButton;
    QPushButton *calculateButton;

    // Таблица данных
    QTableWidget *tableWidget;

    // Метки для результатов
    QLabel *minLabel;
    QLabel *maxLabel;
    QLabel *medianLabel;

    Context context;
    void showError(const QString &message);
    void updateTable();
};
#endif // MAINWINDOW_H
