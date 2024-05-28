#ifndef MAINWINDOW_H
#define MAINWINDOW_H


//#include "QcGaugewidget.h"
 //QcGaugeWidget * mSpeedGauge;
 //QcNeedleItem *mSpeedNeedle;

#include <QMainWindow>
#include <traininfo.h>
#include <Qtimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();



    void myfunction();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

};

#endif // MAINWINDOW_H
