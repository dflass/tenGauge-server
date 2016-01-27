#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);

    boat = new boatServer;

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any,1455)) {
        QMessageBox::critical(this, tr("Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    connect(tcpServer, SIGNAL (newConnection()), this, SLOT(sendData()));

    connect(&sliderData, SIGNAL(timeout()), this, SLOT(setValues()));        //on timeout, run testingtime

    test.start(40);
    sliderData.start(5);

}

server::~server()
{
    delete ui;
}


void server::sendData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16) 0;
    out << boat->getdata();
    out.device()->seek(0);
    out << (quint16) (block.size() - sizeof(quint16));

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    clientConnection->write(block);
    clientConnection->disconnectFromHost();
}

void server::setValues()
{
    boat->setrpm1(rpm1slide);
    boat->setfuel1(fuel1slide);
    boat->setoil1(oil1slide);
    boat->settemp1(temp1slide);
    boat->setbat1(bat1slide);
    boat->setrpm2(rpm2slide);
    boat->setfuel2(fuel2slide);
    boat->setoil2(oil2slide);
    boat->settemp2(temp2slide);
    boat->setbat2(bat2slide);
}

void server::on_horizontalSlider_valueChanged(int value)
{    rpm1slide = value;}

void server::on_horizontalSlider_2_valueChanged(int value)
{    fuel1slide = value;}

void server::on_horizontalSlider_3_valueChanged(int value)
{    oil1slide = value;}

void server::on_horizontalSlider_4_valueChanged(int value)
{    temp1slide = value;}

void server::on_horizontalSlider_5_valueChanged(int value)
{    bat1slide = value;}

void server::on_horizontalSlider_6_valueChanged(int value)
{    rpm2slide = value;}

void server::on_horizontalSlider_7_valueChanged(int value)
{    fuel2slide = value;}

void server::on_horizontalSlider_8_valueChanged(int value)
{    oil2slide = value;}

void server::on_horizontalSlider_9_valueChanged(int value)
{    temp2slide = value;}

void server::on_horizontalSlider_10_valueChanged(int value)
{    bat2slide = value;}
