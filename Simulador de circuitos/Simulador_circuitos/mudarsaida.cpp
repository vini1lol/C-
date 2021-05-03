#include "mudarsaida.h"
#include "ui_mudarsaida.h"

MudarSaida::MudarSaida(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MudarSaida)
{
    ui->setupUi(this);
}

MudarSaida::~MudarSaida()
{
    delete ui;
}
void MudarSaida::setSaida(int id)
{
    Idsaida=id;
    ui->lbsaidaid->setText(QString::number(id));
}
void MudarSaida::on_buttonBox_accepted()
{
    int id = ui->spinBoxIdOrigem->value();
    emit signalMudasa(Idsaida,id);
}
