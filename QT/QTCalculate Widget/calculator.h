#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QStack>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = nullptr);

signals:
    void signalResult(QString result);

private slots:
    void slotButtonClicked();

private:
    QLCDNumber *lcd;
    QStack<QString> stack;
    QString display;

    QPushButton* createButton(const QString& name);
    void calculate();

};

#endif // CALCULATOR_H
