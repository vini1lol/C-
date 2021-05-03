#ifndef MAINCIRCUITO_H
#define MAINCIRCUITO_H

#include <QMainWindow>
#include "ui_maincircuito.h"
#include "novo.h"
#include "mudarporta.h"
#include "mudarsaida.h"
#include "circuito.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainCircuito; }
QT_END_NAMESPACE

class MainCircuito : public QMainWindow
{
    Q_OBJECT

public:
    MainCircuito(QWidget *parent = nullptr);
    ~MainCircuito();

private slots:
    void slotNovo(int NE,int NS,int NP);
    void slotMudarPorta(int idporta,QString nome,int Nentradas,int id1,int id2,int id3,int id4);
    void slotMudarsaida(int idsaida,int id);

    void on_actionNovo_triggered();
    void on_actionLer_triggered();
    void on_actionSalvar_triggered();
    void on_actionGerar_Tabela_triggered();

    void on_Portas_cellDoubleClicked(int row, int column);

    void on_Saidas_cellDoubleClicked(int row, int column);

signals:
    void sgnalMup(int a);

private:
    Ui::MainCircuito *ui;
    Novo* nv;
    MudarPorta* mp;
    MudarSaida* sa;
    Circuit C;
    QLabel* total_saidas;
    QLabel* total_entradas;
    QLabel* total_portas;

    void exibirCircuito();
};
#endif // MAINCIRCUITO_H
