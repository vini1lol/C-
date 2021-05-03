#include "incluirlivro.h"
#include "ui_incluirlivro.h"
#include <QString>

incluirLivro::incluirLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incluirLivro)
{
    ui->setupUi(this);
}

incluirLivro::~incluirLivro()
{
    delete ui;
}

void incluirLivro::on_buttonBox_accepted()
{
    QString nome(ui->LineEdit_nome->text());
    QString preco(ui->lineEdit_preco->text());
    QString autor(ui->lineEdit_autor->text());

    emit signIncluirLivro(nome,preco,autor);
}
