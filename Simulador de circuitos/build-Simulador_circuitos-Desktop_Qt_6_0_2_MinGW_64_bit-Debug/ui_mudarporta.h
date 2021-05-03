/********************************************************************************
** Form generated from reading UI file 'mudarporta.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUDARPORTA_H
#define UI_MUDARPORTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MudarPorta
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lbNumPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxEntrada;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBoxId1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spinBoxId2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *spinBoxId3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *spinBoxId4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MudarPorta)
    {
        if (MudarPorta->objectName().isEmpty())
            MudarPorta->setObjectName(QString::fromUtf8("MudarPorta"));
        MudarPorta->resize(200, 269);
        verticalLayout = new QVBoxLayout(MudarPorta);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MudarPorta);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lbNumPort = new QLabel(MudarPorta);
        lbNumPort->setObjectName(QString::fromUtf8("lbNumPort"));

        horizontalLayout->addWidget(lbNumPort);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(MudarPorta);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(MudarPorta);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(MudarPorta);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxEntrada = new QSpinBox(MudarPorta);
        spinBoxEntrada->setObjectName(QString::fromUtf8("spinBoxEntrada"));
        spinBoxEntrada->setMinimum(-99);

        horizontalLayout_3->addWidget(spinBoxEntrada);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(MudarPorta);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBoxId1 = new QSpinBox(MudarPorta);
        spinBoxId1->setObjectName(QString::fromUtf8("spinBoxId1"));
        spinBoxId1->setMinimum(-99);

        horizontalLayout_4->addWidget(spinBoxId1);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(MudarPorta);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        spinBoxId2 = new QSpinBox(MudarPorta);
        spinBoxId2->setObjectName(QString::fromUtf8("spinBoxId2"));
        spinBoxId2->setMinimum(-99);

        horizontalLayout_5->addWidget(spinBoxId2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(MudarPorta);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        spinBoxId3 = new QSpinBox(MudarPorta);
        spinBoxId3->setObjectName(QString::fromUtf8("spinBoxId3"));
        spinBoxId3->setMinimum(-99);

        horizontalLayout_6->addWidget(spinBoxId3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(MudarPorta);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        spinBoxId4 = new QSpinBox(MudarPorta);
        spinBoxId4->setObjectName(QString::fromUtf8("spinBoxId4"));
        spinBoxId4->setMinimum(-99);

        horizontalLayout_7->addWidget(spinBoxId4);


        verticalLayout->addLayout(horizontalLayout_7);

        buttonBox = new QDialogButtonBox(MudarPorta);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MudarPorta);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MudarPorta, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MudarPorta, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MudarPorta);
    } // setupUi

    void retranslateUi(QDialog *MudarPorta)
    {
        MudarPorta->setWindowTitle(QCoreApplication::translate("MudarPorta", "Modificar porta", nullptr));
        label->setText(QCoreApplication::translate("MudarPorta", "Porta:", nullptr));
        lbNumPort->setText(QCoreApplication::translate("MudarPorta", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MudarPorta", "Tipo de porta", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MudarPorta", "NT", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MudarPorta", "AN", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MudarPorta", "NA", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MudarPorta", "XO", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MudarPorta", "NX", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MudarPorta", "OR", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MudarPorta", "NO", nullptr));

        label_3->setText(QCoreApplication::translate("MudarPorta", "N\302\272 de entradas", nullptr));
        label_4->setText(QCoreApplication::translate("MudarPorta", "Id da entrada 1:", nullptr));
        label_5->setText(QCoreApplication::translate("MudarPorta", "Id da entrada 2:", nullptr));
        label_6->setText(QCoreApplication::translate("MudarPorta", "Id da entrada 3:", nullptr));
        label_7->setText(QCoreApplication::translate("MudarPorta", "Id da entrada 4:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MudarPorta: public Ui_MudarPorta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUDARPORTA_H
