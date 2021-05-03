#ifndef MUDARSAIDA_H
#define MUDARSAIDA_H

#include <QDialog>

namespace Ui {
class MudarSaida;
}

class MudarSaida : public QDialog
{
    Q_OBJECT

public:
    explicit MudarSaida(QWidget *parent = nullptr);
    ~MudarSaida();

    void setSaida(int id);

private slots:
    void on_buttonBox_accepted();

signals:
    void signalMudasa(int Idsaida,int id);

private:
    Ui::MudarSaida *ui;
    int Idsaida;
};

#endif // MUDARSAIDA_H
