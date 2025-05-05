#include "mainwindow.h"
#include "app_runner.h"
#include "filters.h"
#include "setup_ui.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>

#define COLUMN_COUNT 7
#define COLUMN_INDEX_MIN 1
#define COLUMN_INDEX_MAX 5

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    init_context(&context);

    connect(chooseFileButton, &QPushButton::clicked, this, &MainWindow::chooseFile);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadData);
    connect(calcButton, &QPushButton::clicked, this, &MainWindow::calculateMetrics);
}

MainWindow::~MainWindow() {
    free_context(&context);
}

void MainWindow::chooseFile() {
    QString path = QFileDialog::getOpenFileName(this, "Выбрать CSV", "", "CSV (*.csv)");
    if (path.isEmpty()) {
        fileLabel->setText("Файл не выбран");
    } else {
        selectedFile = path;
        fileLabel->setText(path);
    }
}

void MainWindow::loadData() {
    bool success = false;

    success = run_app(&context, APP_RUN_LOAD, selectedFile.toStdString().c_str(), 0);

    if (success) {
        updateTable();
        showInfoMessage();
    } else {
        showError(selectedFile.isEmpty() ? "Файл не выбран" : context.last_error);
    }
}

void MainWindow::calculateMetrics() {
    QString region = regionInput->text();
    bool ok = false;
    int column = columnInput->text().toInt(&ok);

    if (!ok || column < COLUMN_INDEX_MIN || column > COLUMN_INDEX_MAX) {
        showError("Неверный номер колонки");
        return;
    }

    bool success = run_app(&context, APP_RUN_CALCULATE, region.toStdString().c_str(), column);

    if (success) {
        bool statsSuccess = calculate_statistics(context.data, region.toStdString().c_str(), column, &lastStats);
        if (statsSuccess) {
            updateStats();
        } else {
            showError(context.last_error);
        }
    } else {
        showError(context.last_error);
    }
}


void MainWindow::updateTable() {
    table->setRowCount(0);
    QString region = regionInput->text();
    int row = 0;

    if (context.data) {
        for (int i = 0; i < context.data->size; ++i) {
            DataEntry *e = &context.data->entries[i];
            if (!is_region_match(e, region.toStdString().c_str())) {
                continue;
            }

            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(QString::number(e->year)));
            table->setItem(row, 1, new QTableWidgetItem(e->region));
            table->setItem(row, 2, new QTableWidgetItem(QString::number(e->natural_population_growth)));
            table->setItem(row, 3, new QTableWidgetItem(QString::number(e->birth_rate)));
            table->setItem(row, 4, new QTableWidgetItem(QString::number(e->death_rate)));
            table->setItem(row, 5, new QTableWidgetItem(QString::number(e->general_demographic_weight)));
            table->setItem(row, 6, new QTableWidgetItem(QString::number(e->urbanization)));
            ++row;
        }
    }
}

void MainWindow::updateStats() {
    minLabel->setText(QString("Min: %1").arg(lastStats.min));
    maxLabel->setText(QString("Max: %1").arg(lastStats.max));
    medianLabel->setText(QString("Median: %1").arg(lastStats.median));
}


void MainWindow::showInfoMessage() {
    QString message = QString("Всего строк: %1\nОшибочных: %2\nУспешно считано: %3")
                          .arg(get_total_lines(&context))
                          .arg(get_error_lines(&context))
                          .arg(get_valid_lines(&context));
    QMessageBox::information(this, "Загрузка завершена", message);
}

void MainWindow::showError(const QString& message) {
    QMessageBox::critical(this, "Ошибка", message);
}
