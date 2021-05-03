#include "incluircd.h"
#include "ui_incluircd.h"

incluircd::incluircd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incluircd)
{
    ui->setupUi(this);
}

incluircd::~incluircd()
{
    delete ui;
}

void incluircd::on_buttonBox_accepted()
{
    QString nome(ui->lineEdit_nome->text());
    QString preco(ui->lineEdit_preco->text());
    QString nFaixa(ui->lineEdit_NFaixas->text());

    emit signIncluirCD(nome,preco,nFaixa);
}
