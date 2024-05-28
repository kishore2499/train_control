#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "speedometer.h"
#include "distance.h"
#include <QHBoxLayout>
#include <QPixmap>
#include <traininfo.h>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include "traininfo.h"
#include "distance.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    Speedometer *speedometer = new Speedometer(this);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(speedometer);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);

    Distance *distance= new Distance(this);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(distance);
    setCentralWidget(new QWidget );
   centralWidget()->setLayout(lay);



    ui->setupUi(this);
    QPixmap pix("C:/Users/b2018353/Pictures/Quest.jpg");
    ui->label_pic->setPixmap(pix);

    TrainInfo t;
    QString text=t.trainNumber;

    text="a";
   // getchar(trainNumber ->text(),true);
    ui->label_train->setText(text);

    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));

    timer = new QTimer(this);

        connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));

                timer->start(1000);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   // TrainInfo traininfo;
     //       traininfo.setModal(true);
   //      traininfo.exec();

ui->statusBar->showMessage("Train Control System is Connnect");



   // hide();// its use to hide the pop-up window when we working on another

   TrainInfo *t= new TrainInfo(this);
   t->show();

}

void MainWindow::myfunction()
{
   QTime time = QTime::currentTime();

       QString time_text =time.toString("hh:mm:ss");

       ui->label_date->setText(time_text);
}



