#include "converterwidget.h"
#include "design.h"
#include "converter.h"
#include <cstdlib>

ConverterWidget::ConverterWidget(QWidget *parent) : QWidget(parent) {
    setupUI(this);

    inputField = getInputField(this);
    fromBaseComboBox = getFromBaseComboBox(this);
    toBaseComboBox = getToBaseComboBox(this);
    convertButton = getConvertButton(this);
    outputField = getOutputField(this);
    errorLabel = getErrorLabel(this);

    setupConnections();
}

void ConverterWidget::setupConnections() {
    connect(convertButton, &QPushButton::clicked, [this]() {
        QString inputText = inputField->text();
        int fromBase = fromBaseComboBox->currentData().toInt();
        int toBase = toBaseComboBox->currentData().toInt();

        char *result = (char *)malloc(100 * sizeof(char));
        if (!result) {
            errorLabel->setText("Ошибка выделения памяти.");
            return;
        }

        const char *input = inputText.toStdString().c_str();
        const char *error = convertNumber(input, fromBase, toBase, result);

        if (error) {
            errorLabel->setText(error);
            outputField->clear();
        } else {
            outputField->setText(result);
            errorLabel->clear();
        }

        free(result);
    });
}
