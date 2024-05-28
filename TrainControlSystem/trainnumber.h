#ifndef TRAINNUMBER
#define TRAINNUMBER
#include <QWidget>
#include<QTimer>
namespace Ui {
class TrainNumber;
}

class TrainNumber : public QWidget
{
    Q_OBJECT

public:
    explicit TrainNumber(QWidget *parent = 0);
    ~TrainNumber();

protected:
    void displayTrainNumber();
    void onTimer();

private:
    QTimer *t_timer;

};
#endif // TRAINNUMBER

