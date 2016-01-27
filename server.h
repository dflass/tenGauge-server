#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include "boatServer.h"

#include <QTimer>

class QTcpServer;
class QNetworkSession;

namespace Ui {
class server;
}

class server : public QMainWindow
{
    Q_OBJECT

public:
    boatServer *boat;

    explicit server(QWidget *parent = 0);
    ~server();

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_horizontalSlider_4_valueChanged(int value);
    void on_horizontalSlider_5_valueChanged(int value);
    void on_horizontalSlider_6_valueChanged(int value);
    void on_horizontalSlider_7_valueChanged(int value);
    void on_horizontalSlider_8_valueChanged(int value);
    void on_horizontalSlider_9_valueChanged(int value);
    void on_horizontalSlider_10_valueChanged(int value);

    void sendData();
    void setValues();


private:


    int rpm1slide;
    int fuel1slide;
    int oil1slide;
    int temp1slide;
    int bat1slide;

    int rpm2slide;
    int fuel2slide;
    int oil2slide;
    int temp2slide;
    int bat2slide;

    QString engineData;
    QTcpServer *tcpServer;
    QNetworkSession *networkSession;

    QTimer sliderData;

    QTimer test;

    Ui::server *ui;
};

#endif // SERVER_H
