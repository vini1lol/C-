#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "loja.h"
#include "incluirlivro.h"
#include "incluircd.h"
#include "incluirdvd.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tableLivro_cellDoubleClicked(int row, int column);

    void on_tableCD_cellDoubleClicked(int row, int column);

    void on_tableDVD_cellDoubleClicked(int row, int column);

    void on_actionSair_triggered();

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionIncluir_Livro_triggered();

    void on_actionIncluir_CD_triggered();

    void on_actionIncluir_DVD_triggered();

    //slots para conectar main com incluir
    void slotIncluirLivro(QString nome, QString preco, QString autor);

    void slotIncluirCD(QString nome, QString preco, QString numfaixas);

    void slotIncluirDVD(QString nome, QString preco, QString duracao);

private:
    Ui::MainWindow *ui;
    Loja X;
    incluirLivro* inclLivro;
    incluircd* inclCD;
    incluirdvd* inclDVD;
    QLabel* total_itens;

    void exibirListaLivro();
    void exibirListaCD();
    void exibirListaDVD();
    void exibirListaLoja();

};
#endif // MAINWINDOW_H
