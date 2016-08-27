#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>

class MySerial:public QSerialPort{
    Q_OBJECT
public:
    MySerial();
    ~MySerial();
    QStringList serialBufferSplit;
    QString serialValue;
public slots:
    void readSerial();
private:
    QByteArray serialData;
    QString serialBuffer;

};

#endif // MYSERIAL_H
