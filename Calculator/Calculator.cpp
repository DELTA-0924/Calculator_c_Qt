#include "Calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    m_plcd = new QLCDNumber(12);
    m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd->setMinimumSize(120, 50);
    QChar aButtons[4][4] = { {'7','8','9','/'},
                           {'4', '5', '6', '*'},
                           {'1', '2', '3', '-'},
                           { '0','.','=','+' }
    };
    //Layout setup(Создание компоновак)
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(m_plcd, 0, 0, 1, 4);
    ptopLayout->addWidget(createButton("CE"), 1, 3);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ptopLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);
    setLayout(ptopLayout);
}
QPushButton* Calculator::createButton(const QString& name) {
    QPushButton* btn=new QPushButton(name);
    connect(btn,SIGNAL(clicked()),SLOT(slotButtonClicked()));
    return btn;
}
void Calculator::slotButtonClicked() {
    QString str = ((QPushButton*)sender())->text();
    if (str == "CE") {
        m_stack.clear();
          Displaylcd = "";
        m_plcd->display("0");
        return;
    }
    
    if (str.contains(QRegularExpression("[0-9]")))
    {
        Displaylcd += str;
        m_plcd->display(Displaylcd.toDouble());
    }
    else if (str == ".") {
        Displaylcd += str;
        m_plcd->display(Displaylcd);
    }
    else {
        if (m_stack.count() >= 2) {
            m_stack.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stack.clear();
            m_stack.push(QString().setNum(m_plcd->value()));
            if (str != "=") {
                m_stack.push(str);
                Displaylcd = "";
            }
        }
        else {
            m_stack.push(QString().setNum(m_plcd->value()));
            m_stack.push(str);
            Displaylcd = "";
        }
    }
}
void Calculator::calculate() {
    qreal value2 = m_stack.pop().toFloat();
    QString operation = m_stack.pop();
    qreal value1 = m_stack.pop().toFloat();
    qreal result = 0;
    if (operation == "*") {
        result = value1 * value2;
    }
     if (operation == "/")
    {
        result = value1 / value2;
    }
     if (operation == "+") {
        result = value1 + value2;
    }
     if (operation == "-") {
        result = value1 - value2;
    }
    m_plcd->display(result);
}
Calculator::~Calculator()
{}
