#ifndef SERIALTEST2_H
#define SERIALTEST2_H

#include <QWidget>
#include <QtSerialPort/QtSerialPort>

#define ENABLE_PLAYER 1
#define DISABLE_PLAYER 2
#define RUN_PLAYER 3
#define RUN_MODE1 4
#define RUN_MODE3 5
#define STOP_PLAYER 6

namespace Ui {
class SerialTest2;
}

//class QSerialPort


class SerialTest2 : public QWidget
{
    Q_OBJECT

public:
    SerialTest2();
    ~SerialTest2();
    void update_chart(const QPoint &newPoint);
    void save_file(const QPoint &newPoint);
    void m_serial_test();
    void sendCommand(int mode);
    int serialValue;

private:
    Ui::SerialTest2 *ui;
    QSerialPort *serial;

    void testQtchart();
    void setupSerialPort();
    void setupSaveFile();


private slots:
    void serialReceived();
    void on_pushButton_clicked();
    void on_stopButton_clicked();
};

#endif // SERIALTEST2_H
