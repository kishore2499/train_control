#include "distance.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<QDebug>
#include<QTimer>
#include"distance.h"
Distance::Distance(QWidget *parent) : QWidget(parent)
{
  //  ui(new Ui::MainWindow)

   //ui->setupUi(this);

    m_distance = 0;
    n_timer = new QTimer(this);

    // Connect the QTimer signal to the onTimer() slot function
    connect(n_timer, &QTimer::timeout, this, &Distance::onTimer);

    n_timer->start(1000); // Update every second

}

Distance::~Distance()
{
    delete n_timer;
}


double Distance::getCurrentDistance() {
    // Generate a random distance value between 0 and 99
    return qrand() % 1000;
}
void Distance::updateDistanceDisplay(double distance) {
    // Updatedistance value
   m_distance= distance;

    // Trigger a repaint of the widget
    update();
}

void Distance::onTimer() {
  // Do something when the timer signal is emitted
    double currentDistance = getCurrentDistance();

        // Update the speedometer display
        updateDistanceDisplay(currentDistance);
}

void Distance::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
   painter.setRenderHint(QPainter::Antialiasing);

   int width = this->width();
   int height = this->height();
   int side = qMin(width, height);

   // Draw the circle
   QRectF innerRect(side / 10.0, side / 10.0, -side / 10.0, -side / 10.0);
   painter.drawEllipse(innerRect);

    // Draw the distance value
    painter.setFont(QFont("Arial", side / 5.0, QFont::Bold));
    painter.drawText(innerRect, Qt::AlignCenter, QString::number(m_distance));
}
