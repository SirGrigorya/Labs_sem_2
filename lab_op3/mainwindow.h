#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <qboxlayout.h>
#include <qcombobox.h>
#include "entry.h"
#include "graph_widget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void chooseFile();
    void loadData();
    void calculateMetrics();

private:
    void updateTable();
    void updateStats();
    void showInfoMessage();
    void showError(const QString& message);

    friend void setupUi(MainWindow* window);
    friend void setupFileLayout(MainWindow* window, QHBoxLayout* fileLayout);
    friend void setupInputLayout(MainWindow* window, QHBoxLayout* inputLayout);
    friend void setupButtonLayout(MainWindow* window, QHBoxLayout* buttonLayout);
    friend void setupTableWidget(MainWindow* window);
    friend void setupStatLayout(MainWindow* window, QHBoxLayout* statLayout);

    AppContext context;
    QString selectedFile;

    StatisticsResult lastStats;

    QLineEdit *regionInput;
    QComboBox* columnInputCombo;
    QPushButton *chooseFileButton;
    QPushButton *loadButton;
    QPushButton *calcButton;
    QTableWidget *table;
    QLabel *fileLabel;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLabel *medianLabel;

    GraphWidget* graphWidget;
};

#endif // MAINWINDOW_H
