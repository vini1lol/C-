/********************************************************************************
** Form generated from reading UI file 'novo.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVO_H
#define UI_NOVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Novo
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxEntrada;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxSaida;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxPorta;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Novo)
    {
        if (Novo->objectName().isEmpty())
            Novo->setObjectName(QString::fromUtf8("Novo"));
        Novo->resize(178, 142);
        verticalLayout = new QVBoxLayout(Novo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Novo);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBoxEntrada = new QSpinBox(Novo);
        spinBoxEntrada->setObjectName(QString::fromUtf8("spinBoxEntrada"));

        horizontalLayout->addWidget(spinBoxEntrada);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Novo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxSaida = new QSpinBox(Novo);
        spinBoxSaida->setObjectName(QString::fromUtf8("spinBoxSaida"));

        horizontalLayout_2->addWidget(spinBoxSaida);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Novo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxPorta = new QSpinBox(Novo);
        spinBoxPorta->setObjectName(QString::fromUtf8("spinBoxPorta"));

        horizontalLayout_3->addWidget(spinBoxPorta);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(Novo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Novo);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Novo, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Novo, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Novo);
    } // setupUi

    void retranslateUi(QDialog *Novo)
    {
        Novo->setWindowTitle(QCoreApplication::translate("Novo", "Novo Circuito", nullptr));
        label->setText(QCoreApplication::translate("Novo", "N\303\272mero de entrdas", nullptr));
        label_2->setText(QCoreApplication::translate("Novo", "N\303\272mero de saidas", nullptr));
        label_3->setText(QCoreApplication::translate("Novo", "N\303\272mero de portas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Novo: public Ui_Novo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVO_H
