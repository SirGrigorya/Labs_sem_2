#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include "entry.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void chooseFile();
    void loadData();
    void calculateMetrics();

private:
    void updateTable();
    void showInfoMessage();
    void showError(const QString& message);

    AppContext context;

    QString selectedFile;

    QLineEdit *regionInput;
    QLineEdit *columnInput;
    QPushButton *chooseFileButton;
    QPushButton *loadButton;
    QPushButton *calcButton;

    QTableWidget *table;

    QLabel *fileLabel;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLabel *medianLabel;
};

#endif // MAINWINDOW_H
