#include "setup_ui.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QHeaderView>
#include <qcombobox.h>

#define COLUMN_COUNT 7

void setupFileLayout(MainWindow* window, QHBoxLayout* fileLayout) {
    window->chooseFileButton = new QPushButton("Выбрать файл");
    window->fileLabel = new QLabel("Файл не выбран");
    fileLayout->addWidget(window->chooseFileButton);
    fileLayout->addWidget(window->fileLabel);
}

void setupInputLayout(MainWindow* window, QHBoxLayout* inputLayout) {
    window->regionInput = new QLineEdit();
    window->regionInput->setPlaceholderText("Название региона");

    window->columnInputCombo = new QComboBox();
    window->columnInputCombo->addItem("Nat.Pop.Growth", 1);
    window->columnInputCombo->addItem("Birth Rate", 2);
    window->columnInputCombo->addItem("Death Rate", 3);
    window->columnInputCombo->addItem("Dem.Weight", 4);
    window->columnInputCombo->addItem("Urbanization", 5);

    inputLayout->addWidget(window->regionInput);
    inputLayout->addWidget(window->columnInputCombo);
}

void setupButtonLayout(MainWindow* window, QHBoxLayout* buttonLayout) {
    window->loadButton = new QPushButton("Load Data");
    window->calcButton = new QPushButton("Calculate and Draw");
    buttonLayout->addWidget(window->loadButton);
    buttonLayout->addWidget(window->calcButton);
}

void setupTableWidget(MainWindow* window) {
    window->table = new QTableWidget();
    window->table->setColumnCount(COLUMN_COUNT);
    window->table->setHorizontalHeaderLabels({
        "Year", "Region", "Nat.Pop.Growth", "Birth Rate",
        "Death Rate", "Dem.Weight", "Urbanization"
    });
    window->table->horizontalHeader()->setStretchLastSection(true);
    window->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    window->table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    window->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void setupStatLayout(MainWindow* window, QHBoxLayout* statLayout) {
    window->minLabel = new QLabel("Min: ");
    window->maxLabel = new QLabel("Max: ");
    window->medianLabel = new QLabel("Median: ");
    statLayout->addWidget(window->minLabel);
    statLayout->addWidget(window->maxLabel);
    statLayout->addWidget(window->medianLabel);
}

void setupUi(MainWindow* window) {
    QWidget *central = new QWidget(window);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QHBoxLayout *fileLayout = new QHBoxLayout;
    setupFileLayout(window, fileLayout);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    setupInputLayout(window, inputLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    setupButtonLayout(window, buttonLayout);

    setupTableWidget(window);

    QHBoxLayout *statLayout = new QHBoxLayout;
    setupStatLayout(window, statLayout);

    mainLayout->addLayout(fileLayout);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(window->table, 1);
    mainLayout->addLayout(statLayout);

    window->graphWidget = new GraphWidget();
    window->graphWidget->setMinimumHeight(600);
    mainLayout->addWidget(window->graphWidget);

    window->setCentralWidget(central);
    window->setWindowTitle("CSV Visualizer");
}
