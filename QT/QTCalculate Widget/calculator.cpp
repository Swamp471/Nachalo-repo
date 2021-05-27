#include "calculator.h"
#include <QGridLayout>
#include <QRegularExpression>

Calculator::Calculator(QWidget *parent) : QWidget(parent)
{
    lcd = new QLCDNumber(this);
    lcd->setSegmentStyle(QLCDNumber::Flat);

    QChar buttonNames[4][4] = {
        {'7','8','9','/'},
        {'4','5','6','*'},
        {'1','2','3','-'},
        {'0','.','=','+'}
    };

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(lcd,0,0,1,4);
    layout->addWidget(createButton("CE"), 1,3);
    for(int i=0; i<4; ++i)
        for (int j=0; j<4; ++j){
            layout->addWidget(createButton(buttonNames[i][j]), i+2, j);
        }

    setLayout(layout);

}

void Calculator::slotButtonClicked()
{
    QString buttonName = ((QPushButton*)sender())->text();
    if (buttonName == "CE"){
        stack.clear();
        display = "";
        lcd->display("0");
        return;
    }
    if (buttonName.contains(QRegularExpression("[0-9]")) || buttonName == '.'){
        display += buttonName;
        lcd->display(display);
    }
    else {
        if (stack.count() >= 2){
            stack.push(QString().setNum(lcd->value()));
            calculate();
            stack.clear();
            stack.push(QString().setNum(lcd->value()));
            if (buttonName != "=") stack.push(buttonName);
            }
        else {
            stack.push(QString().setNum(lcd->value()));
            stack.push(buttonName);
            display = "";
            lcd->display("0");
        }
    }

}

QPushButton *Calculator::createButton(const QString &name)
{
    QPushButton* button = new QPushButton(name, this);
    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
    return button;
}

void Calculator::calculate()
{
    double operand2 = stack.pop().toDouble();
    QString operation = stack.pop();
    double operand1 = stack.pop().toDouble();
    double result = 0;
    if(operation == "+") result = operand1 + operand2;
    else if (operation == "-") result = operand1 - operand2;
    else if (operation == "*") result = operand1 * operand2;
    else if (operation == "/") result = operand1 / operand2;

    lcd->display(result);
    emit signalResult(QString::number(result));
}
