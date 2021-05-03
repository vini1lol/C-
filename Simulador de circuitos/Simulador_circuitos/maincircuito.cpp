#include "maincircuito.h"
#include "ui_maincircuito.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include "bool3S.h"

MainCircuito::MainCircuito(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainCircuito),
      C(),
      total_portas(NULL),
      total_entradas(NULL),
      total_saidas(NULL),
      nv(NULL),
      mp(NULL),
      sa(NULL)
{
    ui->setupUi(this);

    //Criar as janelas
    nv = new Novo(this);
    mp = new MudarPorta(this);
    sa = new MudarSaida(this);

    //Staturbar entradas
    statusBar()->insertWidget(0,new QLabel("Nº entradas: "));
    total_entradas = new QLabel(this);
    total_entradas->setNum(0);
    statusBar()->insertWidget(1,total_entradas);
    //Staturbar saidas
    statusBar()->insertWidget(2,new QLabel("Nº saidas: "));
    total_saidas = new QLabel(this);
    total_saidas->setNum(0);
    statusBar()->insertWidget(3,total_saidas);
    //Staturbar entradas
    statusBar()->insertWidget(4,new QLabel("Nº portas: "));
    total_portas = new QLabel(this);
    total_portas->setNum(0);
    statusBar()->insertWidget(5,total_portas);

    //Conectar sinais com o main
    connect(nv, &Novo::signNovo,
            this,&MainCircuito::slotNovo);
    connect(mp, &MudarPorta::signMudarPorta,
            this,&MainCircuito::slotMudarPorta);
    connect(sa, &MudarSaida::signalMudasa,
            this,&MainCircuito::slotMudarsaida);


    //Mudar cor de fundo dos labels
    ui->lbportas->setStyleSheet("background:lightgray");
    ui->lbcircuito->setStyleSheet("background:lightgray");
    ui->lbsaidas->setStyleSheet("background:lightgray");
    ui->lbtabela->setStyleSheet("background:lightgray");

    //Definindo cabeçalhos
    //tebela Portas
    ui->Portas->setHorizontalHeaderLabels(QStringList()<<"Tipo"<<"Nº entradas"<<"ENTR 1"<<"ENTR 2"<<"ENTR 3"<<"ENTR 4");
    //tabela Saidas
    ui->Saidas->setHorizontalHeaderLabels(QStringList()<<"ORG SAIDA");

    //Ajustando o tamanho das colunas
    //tabela Protas
    for(int i=0;i<6;i++)
    {
        ui->Portas->horizontalHeader()->setSectionResizeMode(i,QHeaderView::ResizeToContents);
    }
    //tabela Saidas
    ui->Saidas->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tabelaverdade->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

}

MainCircuito::~MainCircuito()
{

    delete ui;
}

//Exibir Circuito

void MainCircuito::exibirCircuito()
{
    ui->Portas->clearContents();
    ui->Saidas->clearContents();
    ui->tabelaverdade->clearContents();
    int a =C.getNumPorts();
    int b =C.getNumOutputs();
    int inp =C.getNumInputs();
    ui->Portas->setRowCount(a);
    ui->Saidas->setRowCount(b);

    ui->tabelaverdade->setColumnCount(b+inp);
    ui->tabelaverdade->setRowCount(pow(3,inp)+1);
    ui->tabelaverdade->setSpan(0,0,1,inp);
    ui->tabelaverdade->setSpan(0,inp,1,b);

    QTableWidgetItem* prov;

    prov=new QTableWidgetItem;
    prov->setText("Entrada");
    prov->setTextAlignment(Qt::AlignCenter);
    ui->tabelaverdade->setItem(0,0,prov);

    prov=new QTableWidgetItem;
    prov->setText("Saida");
    prov->setTextAlignment(Qt::AlignCenter);
    ui->tabelaverdade->setItem(0,inp,prov);

    for(int i=0;i<a;i++)
    {
        prov  = new QTableWidgetItem;
        prov->setText(QString::fromStdString(C.getNamePort(i+1)));
        prov->setTextAlignment(Qt::AlignCenter);
        ui->Portas->setItem(i,0,prov);
        prov  = new QTableWidgetItem;
        prov->setText(QString::number(C.getNumInputsPort(i+1)));
        prov->setTextAlignment(Qt::AlignCenter);
        ui->Portas->setItem(i,1,prov);
        for(int j=0;j<(int)C.getNumInputsPort(i+1);j++)
        {
            prov  = new QTableWidgetItem;
            prov->setText(QString::number(C.getId_inPort(i+1,j)));
            prov->setTextAlignment(Qt::AlignCenter);
            ui->Portas->setItem(i,j+2,prov);
        }
    }

    for(int i=0;i<b;i++)
    {
        prov= new QTableWidgetItem;
        prov->setText(QString::number(C.getIdOutput(i+1)));
        prov->setTextAlignment(Qt::AlignCenter);
        ui->Saidas->setItem(i,0,prov);
    }

    total_entradas->setNum((int)C.getNumInputs());
    statusBar()->insertWidget(1,total_entradas);
    total_saidas->setNum((int)C.getNumOutputs());
    statusBar()->insertWidget(3,total_saidas);
    total_portas->setNum((int)C.getNumPorts());
    statusBar()->insertWidget(5,total_portas);

}

//Ações do menu de Circuito

//Novo Circuito
void MainCircuito::on_actionNovo_triggered()
{
    nv->show();
}

//Ler Circuito
void MainCircuito::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Ler Circuito",
                                                    QString(),
                                                    "Text Files (*.txt);");
    if (!fileName.isEmpty()) {
      QFile file(fileName);
      if (!file.open(QIODevice::ReadOnly)) {
        QString texto("Erro ao ler um circuito a partir do arquivo:\n"+fileName);
        string aux= texto.toStdString();
        const char* p= aux.c_str();
        QMessageBox::critical(this, tr("Error"), tr(p));
        return;
      }
      if(!C.ler(fileName.toStdString())){
          QString texto("Erro ao ler um circuito a partir do arquivo:\n"+fileName);
          string aux= texto.toStdString();
          const char* p= aux.c_str();
          QMessageBox::critical(this, tr("Error"), tr(p));
          return;
      }
      exibirCircuito();
      file.close();
    }
}

//Salvar Circuito
void MainCircuito::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::
        getSaveFileName(this,
                        "Salvar Circuito",
                        QString(),
                        "Text Files (*.txt);");

    if (!fileName.isEmpty()) {
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("O circuito não está completamente definido\nNão pode ser salvo"));
        return;
      } else {
        C.salvar(fileName.toStdString());
        file.close();
      }
    }
}

//Meu Simular

void MainCircuito::on_actionGerar_Tabela_triggered()
{
    if(C.valid())
    {
        vector<bool3S> inputs(C.getNumInputs());
        int i,j,k=1;
        // Comeca com todas as entradas indefinidas
        for (j=0; j<(int)C.getNumInputs(); j++) inputs[j] = bool3S::UNDEF;

        do
        {
            C.setInput(inputs);
            C.simular(inputs);
            // Impressao das entradas
            //cout << "ENTRADAS: ";
            int inp = (int)C.getNumInputs();
            QTableWidgetItem* prov;
            for (i=0; i<inp; i++)
            {
                char a =toChar(C.getInput(-i-1));
                QString aux(a);
                prov = new QTableWidgetItem;
                prov->setText(aux);
                prov->setTextAlignment(Qt::AlignCenter);
                ui->tabelaverdade->setItem(k,i,prov);
            }

            // Impressao das saidas
            //cout << "SAIDAS: ";
            for (i=0; i<(int)C.getNumOutputs(); i++)
            {
                char a =toChar(C.getOutput(i+1));
                QString aux(a);
                prov = new QTableWidgetItem;
                prov->setText(aux);
                prov->setTextAlignment(Qt::AlignCenter);
                ui->tabelaverdade->setItem(k,i+inp,prov);
            }

            // Determina qual entrada deve ser incrementada na proxima linha
            // Incrementa a ultima possivel que nao for TRUE
            // Se a ultima for TRUE, faz essa ser UNDEF e tenta incrementar a anterior
            j = C.getNumInputs()-1;
            while (inputs[j]==bool3S::TRUE && j>=0)
            {
                inputs[j]++;
                j--;
            };
            // Incrementa a input selecionada
            if (j>=0) inputs[j]++;
            k++;
        } while (j>=0);

    }else {
        QMessageBox::critical(this, tr("Error"), tr("O circuito não está completamente definido\nNão pode ser simulado"));
    }
}

//Slots

void MainCircuito::slotNovo(int NE,int NS,int NP)
{
    C.realloc(NE,NS,NP);
    exibirCircuito();
}

void MainCircuito::slotMudarPorta(int idporta,QString nome,int Nentradas,int id1,int id2,int id3,int id4)
{
    int id=0;
    C.setPort(idporta,nome.toStdString(),Nentradas);
    for(int i=0;i<Nentradas;i++)
    {
        switch (i) {
        case 0:
            id=id1;
            break;
        case 1:
            id=id2;
            break;
        case 2:
            id=id3;
            break;
        case 3:
            id=id4;
            break;
        }
        C.setId_inPort(idporta,i,id);
    }
    exibirCircuito();
}

void MainCircuito::slotMudarsaida(int idsaida,int id)
{
    C.setIdOutput(idsaida,id);
    exibirCircuito();
}

void MainCircuito::on_Portas_cellDoubleClicked(int row, int column)
{
    int a =row+1;
    mp->setPort(a);
    mp->show();
}



void MainCircuito::on_Saidas_cellDoubleClicked(int row, int column)
{
    sa->setSaida(row+1);
    sa->show();
}
