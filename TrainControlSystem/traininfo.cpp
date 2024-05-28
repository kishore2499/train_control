#include "traininfo.h"
#include "ui_traininfo.h"

TrainInfo::TrainInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainInfo)
{
    ui->setupUi(this);
}

TrainInfo::~TrainInfo()
{
    delete ui;
}

void TrainInfo::on_buttonBox_accepted()

{

 trainNumber= ui->lineEdit_TrainNumber ->text();
//settext(ui->lineEdit_TrainNumber ->text(),true);
show();
QString PermiitedSpeed  = ui->lineEdit_PermittedSpeed ->text();

hide();
}



void TrainInfo::on_buttonBox_rejected()
{
hide();
}

//void TrainInfo::on_buttonBox_objectNameChanged(const QString &objectName)
//{


