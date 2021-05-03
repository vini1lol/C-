#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow),
     X(),
     inclLivro(NULL),
     inclCD(NULL),
     inclDVD(NULL),
     total_itens(NULL)
{
    ui->setupUi(this);

    //Criar as janelas para incluir itens
    inclLivro = new incluirLivro(this);
    inclCD = new incluircd(this);
    inclDVD = new incluirdvd(this);

    //Barra de status
    statusBar()->insertWidget(0,new QLabel("Toral de itens"));
    total_itens = new QLabel(this);
    total_itens->setNum(0);
    statusBar()->insertWidget(1,total_itens);

    //Conectar sinal do incruir com o main
    connect(inclLivro, &incluirLivro::signIncluirLivro,
            this,&MainWindow::slotIncluirLivro);
    connect(inclCD, &incluircd::signIncluirCD,
            this,&MainWindow::slotIncluirCD);
    connect(inclDVD, &incluirdvd::signIncluirDVD,
            this,&MainWindow::slotIncluirDVD);

    //Alterando a cor de fundo dos titulos das tabelas
    ui->label_livro->setStyleSheet("background:lightgray");
    ui->label_cd->setStyleSheet("background:lightgray");
    ui->label_dvd->setStyleSheet("background:lightgray");

    //Alterando a cor dos cabecalhos das tabelas
    ui->tableLivro->setStyleSheet("QHeaderView::section{background-color:lightgray}");
    ui->tableCD->setStyleSheet("QHeaderView::section{background-color:lightgray}");
    ui->tableDVD->setStyleSheet("QHeaderView::section{background-color:lightgray}");

    //Ajustando o tamanho das colunas
    //tabela livros
    ui->tableLivro->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableLivro->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableLivro->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    //tabela CDs
    ui->tableCD->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableCD->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableCD->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    //tabela DVDs
    ui->tableDVD->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableDVD->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableDVD->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    //Definindo cabeçalhos
    //tebela livros
    ui->tableLivro->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Preço"<<"Autor");
    //tabela CDs
    ui->tableCD->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Preço"<<"N Faixas");
    //tabela DVDs
    ui->tableDVD->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Preço"<<"Duração");

}

//exibir a lista de livros
void MainWindow::exibirListaLivro(){
    ui->tableLivro->clearContents();
    int a =X.getNumLivro();
    ui->tableLivro->setRowCount(a);
    QTableWidgetItem* prov;
    Livro l;
    for(int i=0;i<a;i++)
    {
        l=X.getLivro(i);
        for(int j=0;j<3;j++)
        {
            prov = new QTableWidgetItem;
            switch (j) {
                case 0: prov->setText(QString::fromStdString(l.getNome()));break;
                case 1: prov->setText(QString::number(l.getPreco()));break;
                case 2: prov->setText(QString::fromStdString(l.getAutor()));break;
            }
            prov->setTextAlignment(Qt::AlignCenter);
            ui->tableLivro->setItem(i,j,prov);
        }
    }
    int aux;
    aux=X.getNumCD()+X.getNumDVD()+X.getNumLivro();
    total_itens->setNum(aux);
    statusBar()->insertWidget(1,total_itens);
}
//exibir a lista de CDs
void MainWindow::exibirListaCD(){
    ui->tableCD->clearContents();
    int a =X.getNumCD();
    ui->tableCD->setRowCount(a);
    QTableWidgetItem* prov;
    CD l;
    for(int i=0;i<a;i++)
    {
        l=X.getCD(i);
        for(int j=0;j<3;j++)
        {
            prov = new QTableWidgetItem;
            switch (j) {
                case 0: prov->setText(QString::fromStdString(l.getNome()));break;
                case 1: prov->setText(QString::number(l.getPreco()));break;
                case 2: prov->setText(QString::number(l.getNumFaixas()));break;
            }
            prov->setTextAlignment(Qt::AlignCenter);
            ui->tableCD->setItem(i,j,prov);
        }
    }
    int aux;
    aux=X.getNumCD()+X.getNumDVD()+X.getNumLivro();
    total_itens->setNum(aux);
    statusBar()->insertWidget(1,total_itens);
}
//exibir a lista de DVDs
void MainWindow::exibirListaDVD(){
    ui->tableDVD->clearContents();
    int a =X.getNumDVD();
    ui->tableDVD->setRowCount(a);
    QTableWidgetItem* prov;
    DVD l;
    for(int i=0;i<a;i++)
    {
        l=X.getDVD(i);
        for(int j=0;j<3;j++)
        {
            prov = new QTableWidgetItem;
            switch (j) {
                case 0: prov->setText(QString::fromStdString(l.getNome()));break;
                case 1: prov->setText(QString::number(l.getPreco()));break;
                case 2: prov->setText(QString::number(l.getDuracao()));break;
            }
            prov->setTextAlignment(Qt::AlignCenter);
            ui->tableDVD->setItem(i,j,prov);
        }
    }
    int aux;
    aux=X.getNumCD()+X.getNumDVD()+X.getNumLivro();
    total_itens->setNum(aux);
    statusBar()->insertWidget(1,total_itens);
}
//exibir todo estoque
void MainWindow::exibirListaLoja(){
    exibirListaLivro();
    exibirListaCD();
    exibirListaDVD();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Ações do menu de Arquivo

//Ler um arquivo de estoque
void MainWindow::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Ler estoque",
                                                    QString(),
                                                    "Text Files (*.txt);");
    if (!fileName.isEmpty()) {
      QFile file(fileName);
      if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
      }
      X.ler(fileName.toStdString());
      exibirListaLoja();
      file.close();
    }
}

//Salvar um arquivo de estoque
void MainWindow::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::
        getSaveFileName(this,
                        "Salvar estoque",
                        QString(),
                        "Text Files (*.txt);");

    if (!fileName.isEmpty()) {
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
      } else {
        X.salvar(fileName.toStdString());
        file.close();
      }
    }
}

//Sair
void MainWindow::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

//Ações do menu de item

//incluir livro
void MainWindow::on_actionIncluir_Livro_triggered()
{
    inclLivro->show();
}
//incluir CD
void MainWindow::on_actionIncluir_CD_triggered()
{
    inclCD->show();
}
//incluir DVD
void MainWindow::on_actionIncluir_DVD_triggered()
{
    inclDVD->show();
}

//Excluir em dois cliques

//Excluir livro
void MainWindow::on_tableLivro_cellDoubleClicked(int row, int column)
{
    ui->tableLivro->removeRow(row);
    if(row>=0 && unsigned(row)<X.getNumLivro())
    {
        X.excluirLivro(row);
        exibirListaLivro();
    }
}
//Excluir CD
void MainWindow::on_tableCD_cellDoubleClicked(int row, int column)
{
    ui->tableCD->removeRow(row);
    if(row>=0 && unsigned(row)<X.getNumCD())
    {
        X.excluirCD(row);
        exibirListaCD();
    }
}
//Excluir DVD
void MainWindow::on_tableDVD_cellDoubleClicked(int row, int column)
{
    ui->tableDVD->removeRow(row);
    if(row>=0 && unsigned(row)<X.getNumDVD())
    {
        X.excluirDVD(row);
        exibirListaDVD();
    }
}

//slots de inclusão

//incluir Livro
void MainWindow::slotIncluirLivro(QString nome, QString preco, QString autor)
{
    Livro l(nome.toStdString(),round(preco.toFloat()*100.0),autor.toStdString());
    if(l.getNome()!="" && l.getPreco()!=0 && l.getAutor()!="")
    {
        X.incluirLivro(l);
        exibirListaLivro();
    }
    else
    {
       QMessageBox::critical(this,"Livro invalido",QString("Não foi possivel cadastrar o livro\n")+
                             "Nome"+nome+"\nPreco"+preco+"\nAutor"+autor);
    }
}
//incluir CD
void MainWindow::slotIncluirCD(QString nome, QString preco, QString numfaixas)
{
    CD c(nome.toStdString(),round(preco.toFloat()*100.0),round(numfaixas.toFloat()));
    if(c.getNome()!="" && c.getPreco()!=0 && c.getNumFaixas()!=0)
    {
        X.incluirCD(c);
        exibirListaCD();
    }
    else
    {
       QMessageBox::critical(this,"CD invalido",QString("Não foi possivel cadastrar o CD\n")+
                             "Nome"+nome+"\nPreco"+preco+"\nNumero de faixas"+numfaixas);
    }
}
//incluir DVD
void MainWindow::slotIncluirDVD(QString nome, QString preco, QString duracao)
{
    DVD d(nome.toStdString(),round(preco.toFloat()*100.0),round(duracao.toFloat()));
    if(d.getNome()!="" && d.getPreco()!=0 && d.getDuracao()!=0)
    {
        X.incluirDVD(d);
        exibirListaDVD();
    }
    else
    {
       QMessageBox::critical(this,"DVD invalido",QString("Não foi possivel cadastrar o DVD\n")+
                             "Nome"+nome+"\nPreco"+preco+"\nDuracao"+duracao);
    }
}
