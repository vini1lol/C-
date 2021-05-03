#ifndef MUDARPORTA_H
#define MUDARPORTA_H

#include <QDialog>

namespace Ui {
class MudarPorta;
}

class MudarPorta : public QDialog
{
    Q_OBJECT

public:
    explicit MudarPorta(QWidget *parent = nullptr);
    ~MudarPorta();

    void setPort(int idporta);

private slots:
    void on_buttonBox_accepted();


signals:
    void signMudarPorta(int idporta,QString nome,int Nentradas,int id1,int id2,int id3,int id4);

private:
    Ui::MudarPorta *ui;
    int idport;
};

#endif // MUDARPORTA_H
