#ifndef BOATSERVER
#define BOATSERVER

#include <QObject>

class boatServer: public QObject
{
public:
    boatServer(QObject *parent=0) : QObject(parent)
    {
        rpm1 = 0;
        rpm2 = 0;
        fuel1 = 0;
        fuel2 = 0;
        oil1 = 0;
        oil2 = 0;
        temp1 = 120;
        temp2 = 120;
        bat1 = 10;
        bat2 = 10;
    }

    int rpm1;
    int rpm2;
    int fuel1;
    int fuel2;
    int oil1;
    int oil2;
    int temp1;
    int temp2;
    int bat1;
    int bat2;



    int getrpm1() {return rpm1;}
    int getrpm2() {return rpm2;}
    int getfuel1() {return fuel1;}
    int getfuel2() {return fuel2;}
    int getoil1() {return oil1;}
    int getoil2() {return oil2;}
    int gettemp1() {return temp1;}
    int gettemp2() {return temp2;}
    int getbat1() {return bat1;}
    int getbat2() {return bat2;}

    void setrpm1(int value) {rpm1=value;}
    void setrpm2(int value) {rpm2=value;}
    void setfuel1(int value) {fuel1=value;}
    void setfuel2(int value) {fuel2=value;}
    void setoil1(int value) {oil1=value;}
    void setoil2(int value) {oil2=value;}
    void settemp1(int value) {temp1=value;}
    void settemp2(int value) {temp2=value;}
    void setbat1(int value) {bat1=value;}
    void setbat2(int value) {bat2=value;}

    QString getdata()
    {
        QString data = QString::number(getrpm1()) + "|" + QString::number(getfuel1()) + "|" + QString::number(getoil1()) + "|" + QString::number(gettemp1()) + "|" + QString::number(getbat1()) + "|" + QString::number(getrpm2()) + "|" + QString::number(getfuel2()) + "|" + QString::number(getoil2()) + "|" + QString::number(gettemp2()) + "|" + QString::number(getbat2());
        return data;

    }
};

#endif // BOATSERVER

