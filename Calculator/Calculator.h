#pragma once

#include <QtWidgets>
#include "ui_Calculator.h"
#include<QStack>
#include<QWidget>
class QLCDNumber;
class QPushButton;
class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
    QPushButton* createButton(const QString& name);
    void calculate();
private:
    Ui::CalculatorClass ui;
    QString Displaylcd;
    QStack<QString> m_stack;
    QLCDNumber* m_plcd;
public slots :
    void slotButtonClicked();
};
