#ifndef TRAININFO_H
#define TRAININFO_H

#include <QDialog>

namespace Ui {
class TrainInfo;
}

class TrainInfo : public QDialog
{
    Q_OBJECT

public:
    explicit TrainInfo(QWidget *parent = 0);
    QString trainNumber;
    ~TrainInfo();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    //void on_buttonBox_helpRequested();

   // void on_buttonBox_objectNameChanged(const QString &objectName);

private:
    Ui::TrainInfo *ui;
};

#endif // TRAININFO_H
