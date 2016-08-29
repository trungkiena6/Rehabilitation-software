#include "serialtest2.h"
#include <QtSerialPort/QtSerialPort>
#include <QFile>

QSerialPort *serial;
//QChart *m_chart;
//QLineSeries *m_series;
//QChartView *chartView;
QFile *file;
QString *serial_buff=new QString("");
int flag_error=0;
int count=0;

SerialTest2::SerialTest2()
{
     setupSerialPort();
     setupSaveFile();
     file->open(QFile::ReadWrite);
}

SerialTest2::~SerialTest2()
{
    serial->close();
    file->write("end");
    file->close();
}


void SerialTest2::save_file(const QPoint &newPoint)
{
    QTextStream in_1(file);
    QDir::setCurrent("/home/hung303mc/JRDProject/JrdGui");
        //in<<newPoint.x() <<newPoint.y();
    QString str_data = QString::number(newPoint.x()) + " " + QString::number(newPoint.y()) + '\n';
    in_1<< str_data;
    //file->write(str_data);
}

void SerialTest2::m_serial_test()
{
    serial->write("ok");
    //    qDebug()<<serial->readAll();
}

void SerialTest2::sendCommand(int mode)
{
    qDebug() << mode;
    switch (mode) {
    case ENABLE_PLAYER:
        serial->write("e\n");
        break;
    case DISABLE_PLAYER:
        serial->write("f\n");
        break;
    case RUN_PLAYER:
        serial->write("c\n");
        break;
    case RUN_MODE1:
        serial->write("w1\n");
        break;
    case RUN_MODE3:
        serial->write("w3\n");
        break;
    case STOP_PLAYER:
        qDebug() <<"pressed stop button";
        serial->write("d\n");
        break;
    default:
        break;
    }
}





void SerialTest2::testQtchart()
{


}

void SerialTest2::setupSerialPort()
{
    serial=new QSerialPort(this);
    serial->setPortName("ttyACM0");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
    qDebug() << "serial ok";
    //serial->write("e\n");


//    char *ptr_data={'e','\n'};
//    serial->write(ptr_data,2);


//    char s_data;
//    s_data='e';
//    serial->write(&s_data);
//    s_data='\n';
//    serial->write(&s_data);

}

void SerialTest2::setupSaveFile()
{

    file=new QFile;
    file->setFileName("output.txt");
    QDir::setCurrent("/home/nhattan/Qt_project/Serial_test_2/");

    if(file->open(QFile::ReadWrite))
    {
        QTextStream in(file);
        in<<"Begin";
        //        QString line = in.readAll();

    }
    else {
        qDebug() << "open file fail";
    }

    file->close();
}

void SerialTest2::serialReceived()
{
    QString mystring;

    mystring=serial->readAll();
    //qDebug()<<mystring << " "<<mystring.indexOf("\r\n") <<" "<<mystring.count();

    //chi tinh toi truong hop duy nhat
    if(mystring.indexOf("\r\n")==-1)
    {
        serial_buff->append(mystring);
        //        if(serial_buff->indexOf("\r\n")==-1)
        flag_error=1;
    }
    else
    {
        if(flag_error)
            serial_buff->append(mystring);
        else{
            *serial_buff=mystring;
            flag_error=0;
        }
    }

    if(serial_buff->indexOf("\r\n")!=-1)
    {
        //    init flag
        QPoint m_point=QPoint(count++,serial_buff->toInt());
        serialValue = serial_buff->toInt();
        qDebug() << serialValue;
       // update_chart(m_point);
        //qDebug()<<mystring << " "<<mystring.indexOf("\r\n") <<" "<<mystring.count();
        //qDebug()<<*serial_buff << " "<<serial_buff->indexOf("\r\n") <<" "<<serial_buff->count()<<m_point;
        //save_file(m_point);
        //    qDebug()<<mystring;
        serial_buff->clear();
    }

}

void SerialTest2::on_pushButton_clicked()
{
    serial->write("e\n");
    qDebug()<<"start";
}

void SerialTest2::on_stopButton_clicked()
{
    serial->write("f\n");
    qDebug()<<"stop";
}
