#ifndef INCLUIRLIVRO_H
#define INCLUIRLIVRO_H

#include <QDialog>

namespace Ui {
class incluirLivro;
}

class incluirLivro : public QDialog
{
    Q_OBJECT

public:
    explicit incluirLivro(QWidget *parent = nullptr);
    ~incluirLivro();

private slots:
    void on_buttonBox_accepted();

signals:
    void signIncluirLivro(QString nome, QString preco, QString autor);

private:
    Ui::incluirLivro *ui;
};

#endif // INCLUIRLIVRO_H
