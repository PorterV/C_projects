#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

extern "C"{
#include "../lib/polish_notation.h"
#include <string.h>
}

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_lbr_clicked();

    void on_pushButton_rbr_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_acos_clicked();

    void on_pushButton_asin_clicked();

    void on_pushButton_atan_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_graph_clicked();

    void on_pushButton_equal_clicked();

    void on_credit_anu_clicked();

    void on_credit_dif_clicked();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
