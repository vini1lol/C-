#include "novo.h"
#include "ui_novo.h"


Novo::Novo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Novo)
{
    ui->setupUi(this);
}

Novo::~Novo()
{
    delete ui;
}

void Novo::on_buttonBox_accepted()
{
    int NE(ui->spinBoxEntrada->value());
    int NS(ui->spinBoxSaida->value());
    int NP(ui->spinBoxPorta->value());

    emit signNovo(NE,NS,NP);
}
