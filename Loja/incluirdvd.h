#ifndef INCLUIRDVD_H
#define INCLUIRDVD_H

#include <QDialog>

namespace Ui {
class incluirdvd;
}

class incluirdvd : public QDialog
{
    Q_OBJECT

public:
    explicit incluirdvd(QWidget *parent = nullptr);
    ~incluirdvd();

private slots:
    void on_buttonBox_accepted();

signals:
    void signIncluirDVD(QString nome, QString preco, QString duracao);

private:
    Ui::incluirdvd *ui;
};

#endif // INCLUIRDVD_H
