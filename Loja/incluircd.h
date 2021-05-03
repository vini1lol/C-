#ifndef INCLUIRCD_H
#define INCLUIRCD_H

#include <QDialog>

namespace Ui {
class incluircd;
}

class incluircd : public QDialog
{
    Q_OBJECT

public:
    explicit incluircd(QWidget *parent = nullptr);
    ~incluircd();

private slots:
    void on_buttonBox_accepted();

signals:
    void signIncluirCD(QString nome, QString preco, QString n_faixas);
private:
    Ui::incluircd *ui;
};

#endif // INCLUIRCD_H
