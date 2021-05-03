/********************************************************************************
** Form generated from reading UI file 'mudarsaida.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUDARSAIDA_H
#define UI_MUDARSAIDA_H

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

class Ui_MudarSaida
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *lbsaidaid;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBoxIdOrigem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MudarSaida)
    {
        if (MudarSaida->objectName().isEmpty())
            MudarSaida->setObjectName(QString::fromUtf8("MudarSaida"));
        MudarSaida->resize(174, 105);
        verticalLayout = new QVBoxLayout(MudarSaida);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MudarSaida);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lbsaidaid = new QLabel(MudarSaida);
        lbsaidaid->setObjectName(QString::fromUtf8("lbsaidaid"));

        horizontalLayout->addWidget(lbsaidaid);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(MudarSaida);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBoxIdOrigem = new QSpinBox(MudarSaida);
        spinBoxIdOrigem->setObjectName(QString::fromUtf8("spinBoxIdOrigem"));
        spinBoxIdOrigem->setMinimum(-99);

        horizontalLayout_2->addWidget(spinBoxIdOrigem);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(MudarSaida);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MudarSaida);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MudarSaida, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MudarSaida, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MudarSaida);
    } // setupUi

    void retranslateUi(QDialog *MudarSaida)
    {
        MudarSaida->setWindowTitle(QCoreApplication::translate("MudarSaida", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MudarSaida", "Sa\303\255da:", nullptr));
        lbsaidaid->setText(QCoreApplication::translate("MudarSaida", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MudarSaida", "Id da origem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MudarSaida: public Ui_MudarSaida {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUDARSAIDA_H
