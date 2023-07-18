#include "Calculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator calculator;
    calculator.setWindowTitle("Claulator");
    calculator.resize(230, 200);
    calculator.show();
    return a.exec();
}
