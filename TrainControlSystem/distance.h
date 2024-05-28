#ifndef DISTANCE
#define DISTANCE

#include <QWidget>
#include<QTimer>
#include"distance.h"
#include<ui_mainwindow.h>


class Distance: public QWidget
{
    Q_OBJECT

public:
    explicit Distance(QWidget*parent = 0);
    ~Distance();
public slots:
   // void myfunction();

protected:
    void paintEvent(QPaintEvent *event) override;
    void onTimer();
    double getCurrentDistance();
    void updateDistanceDisplay(double distance);

private:
    int m_distance;
    QTimer *n_timer;
};

#endif // DISTANCE

