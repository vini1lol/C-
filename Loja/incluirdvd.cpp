#include "incluirdvd.h"
#include "ui_incluirdvd.h"

incluirdvd::incluirdvd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incluirdvd)
{
    ui->setupUi(this);
}

incluirdvd::~incluirdvd()
{
    delete ui;
}

void incluirdvd::on_buttonBox_accepted()
{
    QString nome(ui->lineEdit_nome->text());
    QString preco(ui->lineEdit_preco->text());
    QString duracao(ui->lineEdit_duracao->text());

    emit signIncluirDVD(nome,preco,duracao);
}
