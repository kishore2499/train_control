//( speedometer.(cpp
#include "speedometer.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<QDebug>
#include<QTimer>


Speedometer::Speedometer(QWidget *parent) : QWidget(parent)
{
  //  ui(new Ui::MainWindow)

   //ui->setupUi(this);

    m_speed = 0;
    m_timer = new QTimer(this);

    // Connect the QTimer signal to the onTimer() slot function
    connect(m_timer, &QTimer::timeout, this, &Speedometer::onTimer);

    m_timer->start(1000); // Update every second
}


Speedometer::~Speedometer()
{
    delete m_timer;
}


double Speedometer::getCurrentSpeed() {
    // Generate a random speed value between 0 and 99
    return qrand() % 100;
}
void Speedometer::updateSpeedometerDisplay(double speed) {
    // Update the speedometer value
    m_speed = speed;

    // Trigger a repaint of the widget
    update();
}

void Speedometer::onTimer() {
  // Do something when the timer signal is emitted
    double currentSpeed = getCurrentSpeed();

        // Update the speedometer display
        updateSpeedometerDisplay(currentSpeed);
}
void Speedometer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // Draw the speedometer using QPainter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the outer circle
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);
    QRectF outerRect((width - side) / 2.0, (height - side) / 2.0, side, side);
    painter.drawEllipse(outerRect);

    // Draw the inner circle
    QRectF innerRect = outerRect.adjusted(side / 10.0, side / 10.0, -side / 10.0, -side / 10.0);
    painter.drawEllipse(innerRect);

    // Draw the speed value
    painter.setFont(QFont("Arial", side / 5.0, QFont::Bold));
    painter.drawText(innerRect, Qt::AlignCenter, QString::number(m_speed));
}

