#include "myserial.h"
#include <QDebug>

MySerial::MySerial()
{
    serialBuffer = "";
    bool port_is_available = false;

    // check com port
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        //qDebug() << "port is available"<< endl;
        port_is_available = true;
        setPortName(serialPortInfo.portName());
    }
    // setting com port if available
    if(port_is_available){
        open(QSerialPort::ReadOnly);
        setBaudRate(QSerialPort::Baud9600);
        setDataBits(QSerialPort::Data8);
        setFlowControl(QSerialPort::NoFlowControl);
        setParity(QSerialPort::NoParity);
        setStopBits(QSerialPort::OneStop);
        QObject::connect(this,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }
}

MySerial::~MySerial()
{
    if(isOpen()){
        close();
    }
}

void MySerial::readSerial()
{
    serialData = readAll();
    serialBuffer += QString::fromStdString(serialData.toStdString());
    //qDebug() << serialBuffer;

    serialBufferSplit = serialBuffer.split("\r\n");

    if(serialBufferSplit.length()>=2){
        serialValue = serialBufferSplit[0];
        //qDebug() << "serial buffer split" << serialBufferSplit;
        serialBuffer = "";
    }
}
