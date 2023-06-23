#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

// Evaluates the arithmetic expression and returns the result
double evalExpression(const QString& expression)
{
    return 0.0; // Placeholder implementation
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Calculator");

    // Create the display widget
    QLineEdit *display = new QLineEdit(&window);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setText("");

    // Create the calculator buttons
    QPushButton *buttons[16];
    const char *buttonLabels[16] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+"
    };

    QGridLayout *gridLayout = new QGridLayout(&window);
    gridLayout->addWidget(display, 0, 0, 1, 4);

    for (int i = 0; i < 16; ++i) {
        buttons[i] = new QPushButton(buttonLabels[i], &window);
        buttons[i]->setFixedSize(40, 40);
        gridLayout->addWidget(buttons[i], (i / 4) + 1, (i % 4));
    }

    window.setLayout(gridLayout);

    // Connect the calculator buttons to slots
    QObject::connect(buttons[0], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "7");
    });

    QObject::connect(buttons[1], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "8");
    });

    QObject::connect(buttons[2], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "9");
    });

    QObject::connect(buttons[3], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "/");
    });

    QObject::connect(buttons[4], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "4");
    });

    QObject::connect(buttons[5], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "5");
    });

    QObject::connect(buttons[6], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "6");
    });

    QObject::connect(buttons[7], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "*");
    });

    QObject::connect(buttons[8], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "1");
    });

    QObject::connect(buttons[9], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "2");
    });

    QObject::connect(buttons[10], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "3");
    });

    QObject::connect(buttons[11], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "-");
    });

    QObject::connect(buttons[12], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "0");
    });

    QObject::connect(buttons[13], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + ".");
    });

    QObject::connect(buttons[14], &QPushButton::clicked, [&display]() {
        QString result = QString::number(evalExpression(display->text()));
        display->setText(result);
    });

    QObject::connect(buttons[15], &QPushButton::clicked, [&display]() {
        display->setText(display->text() + "+");
    });

    window.show();

    return app.exec();
}
