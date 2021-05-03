/********************************************************************************
** Form generated from reading UI file 'maincircuito.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCIRCUITO_H
#define UI_MAINCIRCUITO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainCircuito
{
public:
    QAction *actionNovo;
    QAction *actionLer;
    QAction *actionSalvar;
    QAction *actionGerar_Tabela;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *lbcircuito;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbportas;
    QTableWidget *Portas;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbsaidas;
    QTableWidget *Saidas;
    QVBoxLayout *verticalLayout_3;
    QLabel *lbtabela;
    QTableWidget *tabelaverdade;
    QMenuBar *menubar;
    QMenu *menuCircuito;
    QMenu *menuSimular;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainCircuito)
    {
        if (MainCircuito->objectName().isEmpty())
            MainCircuito->setObjectName(QString::fromUtf8("MainCircuito"));
        MainCircuito->resize(800, 600);
        actionNovo = new QAction(MainCircuito);
        actionNovo->setObjectName(QString::fromUtf8("actionNovo"));
        actionLer = new QAction(MainCircuito);
        actionLer->setObjectName(QString::fromUtf8("actionLer"));
        actionSalvar = new QAction(MainCircuito);
        actionSalvar->setObjectName(QString::fromUtf8("actionSalvar"));
        actionGerar_Tabela = new QAction(MainCircuito);
        actionGerar_Tabela->setObjectName(QString::fromUtf8("actionGerar_Tabela"));
        centralwidget = new QWidget(MainCircuito);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lbcircuito = new QLabel(centralwidget);
        lbcircuito->setObjectName(QString::fromUtf8("lbcircuito"));
        lbcircuito->setLayoutDirection(Qt::LeftToRight);
        lbcircuito->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbcircuito);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbportas = new QLabel(centralwidget);
        lbportas->setObjectName(QString::fromUtf8("lbportas"));
        lbportas->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbportas);

        Portas = new QTableWidget(centralwidget);
        if (Portas->columnCount() < 6)
            Portas->setColumnCount(6);
        Portas->setObjectName(QString::fromUtf8("Portas"));
        Portas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Portas->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Portas->setTabKeyNavigation(false);
        Portas->setSelectionMode(QAbstractItemView::SingleSelection);
        Portas->setSelectionBehavior(QAbstractItemView::SelectRows);
        Portas->setColumnCount(6);
        Portas->verticalHeader()->setVisible(true);

        verticalLayout->addWidget(Portas);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbsaidas = new QLabel(centralwidget);
        lbsaidas->setObjectName(QString::fromUtf8("lbsaidas"));
        lbsaidas->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbsaidas);

        Saidas = new QTableWidget(centralwidget);
        if (Saidas->columnCount() < 1)
            Saidas->setColumnCount(1);
        Saidas->setObjectName(QString::fromUtf8("Saidas"));
        Saidas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Saidas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        Saidas->setTabKeyNavigation(false);
        Saidas->setSelectionMode(QAbstractItemView::SingleSelection);
        Saidas->setSelectionBehavior(QAbstractItemView::SelectRows);
        Saidas->setColumnCount(1);

        verticalLayout_2->addWidget(Saidas);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lbtabela = new QLabel(centralwidget);
        lbtabela->setObjectName(QString::fromUtf8("lbtabela"));
        lbtabela->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lbtabela);

        tabelaverdade = new QTableWidget(centralwidget);
        if (tabelaverdade->columnCount() < 2)
            tabelaverdade->setColumnCount(2);
        tabelaverdade->setObjectName(QString::fromUtf8("tabelaverdade"));
        tabelaverdade->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabelaverdade->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabelaverdade->setTabKeyNavigation(false);
        tabelaverdade->setSelectionMode(QAbstractItemView::SingleSelection);
        tabelaverdade->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabelaverdade->setColumnCount(2);
        tabelaverdade->horizontalHeader()->setVisible(false);
        tabelaverdade->horizontalHeader()->setHighlightSections(true);
        tabelaverdade->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tabelaverdade);


        horizontalLayout_2->addLayout(verticalLayout_3);

        MainCircuito->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainCircuito);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuCircuito = new QMenu(menubar);
        menuCircuito->setObjectName(QString::fromUtf8("menuCircuito"));
        menuSimular = new QMenu(menubar);
        menuSimular->setObjectName(QString::fromUtf8("menuSimular"));
        MainCircuito->setMenuBar(menubar);
        statusbar = new QStatusBar(MainCircuito);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainCircuito->setStatusBar(statusbar);

        menubar->addAction(menuCircuito->menuAction());
        menubar->addAction(menuSimular->menuAction());
        menuCircuito->addAction(actionNovo);
        menuCircuito->addAction(actionLer);
        menuCircuito->addAction(actionSalvar);
        menuSimular->addAction(actionGerar_Tabela);

        retranslateUi(MainCircuito);

        QMetaObject::connectSlotsByName(MainCircuito);
    } // setupUi

    void retranslateUi(QMainWindow *MainCircuito)
    {
        MainCircuito->setWindowTitle(QCoreApplication::translate("MainCircuito", "Simulador de Circuitos Digitais", nullptr));
        actionNovo->setText(QCoreApplication::translate("MainCircuito", "Novo...", nullptr));
        actionLer->setText(QCoreApplication::translate("MainCircuito", "Ler...", nullptr));
        actionSalvar->setText(QCoreApplication::translate("MainCircuito", "Salvar...", nullptr));
        actionGerar_Tabela->setText(QCoreApplication::translate("MainCircuito", "Gerar Tabela...", nullptr));
        lbcircuito->setText(QCoreApplication::translate("MainCircuito", "Circuito", nullptr));
        lbportas->setText(QCoreApplication::translate("MainCircuito", "Portas e conex\303\265es", nullptr));
        lbsaidas->setText(QCoreApplication::translate("MainCircuito", "Sa\303\255das", nullptr));
        lbtabela->setText(QCoreApplication::translate("MainCircuito", "Tabela Verdade", nullptr));
        menuCircuito->setTitle(QCoreApplication::translate("MainCircuito", "Circuito", nullptr));
        menuSimular->setTitle(QCoreApplication::translate("MainCircuito", "Simular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainCircuito: public Ui_MainCircuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCIRCUITO_H
