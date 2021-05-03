#include "mudarporta.h"
#include "ui_mudarporta.h"

MudarPorta::MudarPorta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MudarPorta)
{
    ui->setupUi(this);

}

void MudarPorta::setPort(int idporta)
{
    idport=idporta;
    ui->lbNumPort->setText(QString::number(idport));
}

MudarPorta::~MudarPorta()
{
    delete ui;
}

void MudarPorta::on_buttonBox_accepted()
{
    QString nome(ui->comboBox->currentText());
    int Nentradas(ui->spinBoxEntrada->value());
    int id1(ui->spinBoxId1->value());
    int id2(ui->spinBoxId2->value());
    int id3(ui->spinBoxId3->value());
    int id4(ui->spinBoxId4->value());

    emit signMudarPorta(idport,nome,Nentradas,id1,id2,id3,id4);
}
