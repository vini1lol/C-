#ifndef NOVO_H
#define NOVO_H

#include <QDialog>

namespace Ui {
class Novo;
}

class Novo : public QDialog
{
    Q_OBJECT

public:
    explicit Novo(QWidget *parent = nullptr);
    ~Novo();

private slots:
    void on_buttonBox_accepted();

signals:
    void signNovo(int NE,int NS,int NP);


private:
    Ui::Novo *ui;
};

#endif // NOVO_H
