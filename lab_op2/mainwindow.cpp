#include "mainwindow.h"
#include "filters.h"

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
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QHBoxLayout *fileLayout = new QHBoxLayout;
    chooseFileButton = new QPushButton("Выбрать файл");
    fileLabel = new QLabel("Файл не выбран");
    fileLayout->addWidget(chooseFileButton);
    fileLayout->addWidget(fileLabel);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    regionInput = new QLineEdit();
    columnInput = new QLineEdit();
    regionInput->setPlaceholderText("Название региона");
    columnInput->setPlaceholderText("Номер колонки (1-5)");
    inputLayout->addWidget(regionInput);
    inputLayout->addWidget(columnInput);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    loadButton = new QPushButton("Load Data");
    calcButton = new QPushButton("Calculate Metrics");
    buttonLayout->addWidget(loadButton);
    buttonLayout->addWidget(calcButton);

    table = new QTableWidget();
    table->setColumnCount(COLUMN_COUNT);
    table->setHorizontalHeaderLabels({
        "Year", "Region", "Nat.Pop.Growth", "Birth Rate",
        "Death Rate", "Dem.Weight", "Urbanization"
    });
    table->horizontalHeader()->setStretchLastSection(true);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout *statLayout = new QHBoxLayout;
    minLabel = new QLabel("Min: ");
    maxLabel = new QLabel("Max: ");
    medianLabel = new QLabel("Median: ");
    statLayout->addWidget(minLabel);
    statLayout->addWidget(maxLabel);
    statLayout->addWidget(medianLabel);

    mainLayout->addLayout(fileLayout);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(table, 1);
    mainLayout->addLayout(statLayout);

    setCentralWidget(central);
    setWindowTitle("CSV Visualizer");

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
    bool fileSelected = false;

    if (!path.isEmpty()) {
        selectedFile = path;
        fileLabel->setText(path);
        fileSelected = true;
    }

    if (!fileSelected) {
        fileLabel->setText("Файл не выбран");
    }
}

void MainWindow::loadData() {
    free_context(&context);
    init_context(&context);

    bool success = false;

    if (!selectedFile.isEmpty()) {
        success = load_csv_file(&context, selectedFile.toStdString().c_str());
        if (success) {
            updateTable();
            showInfoMessage();
        }
    }

    if (!success) {
        showError(selectedFile.isEmpty() ? "Файл не выбран" : context.last_error);
    }
}

void MainWindow::updateTable() {
    table->setRowCount(0);
    QString region = regionInput->text();
    int row = 0;

    for (int i = 0; i < context.data.size; ++i) {
        DataEntry *e = &context.data.entries[i];
        if (!is_region_match(e, region.toStdString().c_str())) continue;

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

void MainWindow::showInfoMessage() {
    QString message = QString("Всего строк: %1\nОшибочных: %2\nУспешно считано: %3")
                          .arg(context.total_lines)
                          .arg(context.error_lines)
                          .arg(context.valid_lines);
    QMessageBox::information(this, "Загрузка завершена", message);
}

void MainWindow::showError(const QString& message) {
    QMessageBox::critical(this, "Ошибка", message);
}

void MainWindow::calculateMetrics() {
    QString region = regionInput->text();
    bool ok = false;
    int column = columnInput->text().toInt(&ok);
    bool success = false;

    if (ok && column >= COLUMN_INDEX_MIN && column <= COLUMN_INDEX_MAX) {
        success = calculate_metrics(&context, region.toStdString().c_str(), column);
        if (success) {
            minLabel->setText(QString("Min: %1").arg(context.min));
            maxLabel->setText(QString("Max: %1").arg(context.max));
            medianLabel->setText(QString("Median: %1").arg(context.median));
        }
    }

    if (!success) {
        showError(!ok ? "Неверный номер колонки" : context.last_error);
    }
}
