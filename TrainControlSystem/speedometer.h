// speedometer.h
#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QWidget>
#include <QTimer>


class Speedometer : public QWidget
{
    Q_OBJECT

public:
    explicit Speedometer(QWidget *parent = 0);
    ~Speedometer();
public slots:
   // void myfunction();

protected:
    void paintEvent(QPaintEvent *event) override;
    void onTimer();
    double getCurrentSpeed();
    void updateSpeedometerDisplay(double speed);

private:
    int m_speed;
    QTimer *m_timer;
};

#endif // SPEEDOMETER_H





//#ifndef SPEEDOMETER_H
//#define SPEEDOMETER_H

//#pragma once

//#include <QWidget>
//#include <QLabel>
//#include <QVBoxLayout>
//#include <QTimer>
//namespace Ui {
////class Speedometer;
//}

//class Speedometer : public QWidget {
//  Q_OBJECT

//public:
//  Speedometer(QWidget *parent = 0);

//private:
//  // Ui::Speedometer *ui;
//  int speed_;
//  QLabel *label_speed;

//private slots:

//  void updateSpeed();
//};


//#endif // SPEEDOMETER_H
