#include "ui_mainwindow.h"
#include "traininfo.cpp"
#include "trainnumber.h"
#include <QTimer>

TrainNumber::TrainNumber(QWidget *parent) : QWidget(parent)
{
    //ui(new Ui::MainWindow);

   //ui->setupUi(this);

    t_timer = new QTimer(this);

    // Connect the QTimer signal to the onTimer() slot function
    connect(t_timer, &QTimer::timeout, this, &TrainNumber::onTimer);

    t_timer->start(1000); // Update every second
}


TrainNumber::~TrainNumber()
{
    delete t_timer;
}
void TrainNumber::displayTrainNumber(){
    TrainInfo t;
    t.trainNumber;
    update();

}
void TrainNumber::onTimer() {
        // Update the distance display
        displayTrainNumber();
}
