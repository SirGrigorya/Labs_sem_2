#include "entrypoint.h"
#include "design.h"
#include "converter.h"
#include "memory.h"

void runApplication() {
    // Создаем главное окно в динамической памяти
    QWidget *window = new QWidget();
    setupUI(window);

    // Получаем виджеты
    QLineEdit *inputField = getInputField(window);
    QComboBox *fromBaseComboBox = getFromBaseComboBox(window);
    QComboBox *toBaseComboBox = getToBaseComboBox(window);
    QPushButton *convertButton = getConvertButton(window);
    QLineEdit *outputField = getOutputField(window);
    QLabel *errorLabel = getErrorLabel(window);

    // Подключение обработчика кнопки
    QObject::connect(convertButton, &QPushButton::clicked, [=]() {
        const char *input = inputField->text().toStdString().c_str();
        int fromBase = fromBaseComboBox->currentData().toInt();
        int toBase = toBaseComboBox->currentData().toInt();

        char *result = allocateMemory(100);
        const char *error = convertNumber(input, fromBase, toBase, result);

        if (error) {
            errorLabel->setText(error); // Выводим ошибку
            outputField->clear();      // Очищаем результат
        } else {
            outputField->setText(result);
            errorLabel->clear();
        }

        deallocateMemory(result);
    });

    window->show();
}
