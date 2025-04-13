#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *fileLayout = new QHBoxLayout();
    fileEdit = new QLineEdit(this);
    fileEdit->setPlaceholderText("Select CSV file...");
    browseButton = new QPushButton("Browse...", this);
    fileLayout->addWidget(fileEdit);
    fileLayout->addWidget(browseButton);

    QHBoxLayout *filterLayout = new QHBoxLayout();
    regionEdit = new QLineEdit(this);
    regionEdit->setPlaceholderText("Enter region (optional)");
    columnEdit = new QLineEdit(this);
    columnEdit->setPlaceholderText("Column number (1-5)");
    filterLayout->addWidget(new QLabel("Region:"));
    filterLayout->addWidget(regionEdit);
    filterLayout->addWidget(new QLabel("Column:"));
    filterLayout->addWidget(columnEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    loadButton = new QPushButton("Load Data", this);
    calculateButton = new QPushButton("Calculate Metrics", this);
    buttonLayout->addWidget(loadButton);
    buttonLayout->addWidget(calculateButton);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(7);
    tableWidget->setHorizontalHeaderLabels({
        "Year", "Region", "Natural Growth",
        "Birth Rate", "Death Rate",
        "Demographic Weight", "Urbanization"
    });
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QHBoxLayout *resultLayout = new QHBoxLayout();
    resultLayout->addWidget(new QLabel("Min:"));
    minLabel = new QLabel("N/A");
    resultLayout->addWidget(minLabel);
    resultLayout->addWidget(new QLabel("Max:"));
    maxLabel = new QLabel("N/A");
    resultLayout->addWidget(maxLabel);
    resultLayout->addWidget(new QLabel("Median:"));
    medianLabel = new QLabel("N/A");
    resultLayout->addWidget(medianLabel);

    mainLayout->addLayout(fileLayout);
    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(tableWidget);
    mainLayout->addLayout(resultLayout);

    setCentralWidget(centralWidget);

    connect(browseButton, &QPushButton::clicked, this, &MainWindow::on_browseButton_clicked);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::on_loadButton_clicked);
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);

    init_context(&context);
}

void MainWindow::on_browseButton_clicked() {
    QString file = QFileDialog::getOpenFileName(
        this,
        "Open CSV File",
        "",
        "CSV Files (*.csv);;All Files (*)"
        );

    if (!file.isEmpty()) {
        fileEdit->setText(file);
    }
}

void MainWindow::on_loadButton_clicked() {
    QString filePath = fileEdit->text();
    if (filePath.isEmpty()) {
        showError("Please select a CSV file first");
        return;
    }

    QString region = regionEdit->text().trimmed();
    const char* regionPtr = region.isEmpty() ? nullptr : region.toUtf8().constData();

    free_context(&context);
    if (load_data(&context, filePath.toUtf8().constData(), regionPtr) != 0) {
        showError(context.error);
        return;
    }

    QMessageBox::information(
        this,
        "Load Complete",
        QString("Total rows: %1\nError rows: %2\nValid rows: %3")
            .arg(context.total_rows)
            .arg(context.error_rows)
            .arg(context.valid_rows)
        );

    updateTable();
}

void MainWindow::on_calculateButton_clicked() {
    if (!context.filtered_data) {
        showError("No data loaded. Please load data first");
        return;
    }

    bool ok;
    int column = columnEdit->text().toInt(&ok);
    if (!ok || column < 1 || column > 5) {
        showError("Invalid column number. Please enter value between 1 and 5");
        return;
    }

    double min, max, median;
    calculate_metrics(&context, column, &min, &max, &median);

    minLabel->setText(QString::number(min));
    maxLabel->setText(QString::number(max));
    medianLabel->setText(QString::number(median));
}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, "Error", message);
}

void MainWindow::updateTable() {
    tableWidget->setRowCount(0);
    if (!context.filtered_data) return;

    Iterator it = get_iterator(context.filtered_data);
    int row = 0;

    while (DemographicData* data = next(&it)) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(data->year)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(data->region));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(data->natural_population_growth)));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(data->birth_rate)));
        tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(data->death_rate)));
        tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(data->general_demographic_weight)));
        tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(data->urbanization)));
        row++;
    }
}

MainWindow::~MainWindow() {
    free_context(&context);
}
