#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::on_pushButton_1_clicked()
{
    ui->example->insertPlainText("1");
}


void Calculator::on_pushButton_2_clicked()
{
    ui->example->insertPlainText("2");
}


void Calculator::on_pushButton_3_clicked()
{
    ui->example->insertPlainText("3");
}


void Calculator::on_pushButton_4_clicked()
{
    ui->example->insertPlainText("4");
}


void Calculator::on_pushButton_5_clicked()
{
    ui->example->insertPlainText("5");
}


void Calculator::on_pushButton_6_clicked()
{
    ui->example->insertPlainText("6");
}


void Calculator::on_pushButton_7_clicked()
{
    ui->example->insertPlainText("7");
}


void Calculator::on_pushButton_8_clicked()
{
    ui->example->insertPlainText("8");
}


void Calculator::on_pushButton_9_clicked()
{
    ui->example->insertPlainText("9");
}


void Calculator::on_pushButton_0_clicked()
{
    ui->example->insertPlainText("0");
}

void Calculator::on_pushButton_lbr_clicked()
{
    ui->example->insertPlainText("(");
}


void Calculator::on_pushButton_rbr_clicked()
{
    ui->example->insertPlainText(")");
}


void Calculator::on_pushButton_add_clicked()
{
    ui->example->insertPlainText("+");
}


void Calculator::on_pushButton_sub_clicked()
{
    ui->example->insertPlainText("-");
}


void Calculator::on_pushButton_div_clicked()
{
    ui->example->insertPlainText("/");
}


void Calculator::on_pushButton_mul_clicked()
{
    ui->example->insertPlainText("*");
}


void Calculator::on_pushButton_mod_clicked()
{
    ui->example->insertPlainText("mod()");
}


void Calculator::on_pushButton_sqrt_clicked()
{
    ui->example->insertPlainText("sqrt()");
}


void Calculator::on_pushButton_cos_clicked()
{
    ui->example->insertPlainText("cos()");
}


void Calculator::on_pushButton_sin_clicked()
{
    ui->example->insertPlainText("sin()");
}


void Calculator::on_pushButton_tan_clicked()
{
    ui->example->insertPlainText("tan()");
}


void Calculator::on_pushButton_acos_clicked()
{
    ui->example->insertPlainText("acos()");
}


void Calculator::on_pushButton_asin_clicked()
{
    ui->example->insertPlainText("asin()");
}


void Calculator::on_pushButton_atan_clicked()
{
    ui->example->insertPlainText("atan()");
}


void Calculator::on_pushButton_pow_clicked()
{
    ui->example->insertPlainText("pow()");
}


void Calculator::on_pushButton_log_clicked()
{
    ui->example->insertPlainText("log()");
}


void Calculator::on_pushButton_ln_clicked()
{
    ui->example->insertPlainText("ln()");
}


void Calculator::on_pushButton_x_clicked()
{
    ui->example->insertPlainText("x");
}


void Calculator::on_pushButton_graph_clicked()
{
    double x_min = ui->value_x_min->value();
    double x_max = ui->value_x_max->value();
    double y_min = ui->value_y_min->value();
    double y_max = ui->value_y_max->value();
    QString tmp = ui->example->toPlainText();
    char example[512] = {'\0'};
    strncpy(example, tmp.toLocal8Bit().data(), 255);
    QVector<double> x(1000), y(1000);
    double del = (fabs(x_max - x_min)) / 1000.0;
    int j = 0;
    bool normal = true;
    for(double i = x_min; i < x_max; i+= del, j++) {
        double result = 0;
        x[j] = i;
        if(s21_polish_notation(example, &result, i) != -1) {
            y[j] = result;
        } else {
            normal = false;
            break;
        }
    }
    if(normal){
        ui->plot->addGraph();
        ui->plot->graph(0)->setData(x,y);
        ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
        ui->plot->xAxis->setRange(x_min, x_max);
        ui->plot->yAxis->setRange(y_min, y_max);
        ui->plot->replot();
    } else {
        QMessageBox::warning(this, "Ошибка: некорректные значения",
                                       "Ошибка: некорректные значения\n"
                                       "Отредактируйте значения!");
    }
}


void Calculator::on_pushButton_equal_clicked()
{
    QString tmp = ui->example->toPlainText();
    char example[512] = {'\0'};
    strncpy(example, tmp.toLocal8Bit().data(), 255);
    double solution = 0;
    double x = ui->value_x->value();
    int error = s21_polish_notation(example, &solution, x);
    if(error != -1) {
        ui->solution->setPlainText(QString::number(solution,'f',6));
    } else {
        ui->solution->setPlainText("Error");
    }
}


void Calculator::on_credit_anu_clicked()
{
    double sum = ui->credit_sum->value();
    int per = ui->credit_period->value();
    double proc = ui->credit_proc->value();
    double res_mouth = 0;
    double res_per = 0;
    double res_total = 0;
    int res = s21_credit_annuity(sum, per, proc, &res_mouth,&res_per, &res_total);
    if(res != -1) {
        ui->credit_per->setPlainText(QString::number(res_per, 'f', 2));
        ui->credit_mouth->setPlainText(QString::number(res_mouth, 'f', 2));
        ui->credit_total->setPlainText(QString::number(res_total,'f',2));
    }
}


void Calculator::on_credit_dif_clicked()
{
    double sum = ui->credit_sum->value();
    int per = ui->credit_period->value();
    double proc = ui->credit_proc->value();
    double res_mouth_min = 0;
    double res_per = 0;
    double res_total = 0;
    double res_mouth_max = 0;
    int res = s21_credit_differ(sum, per, proc, &res_mouth_max, &res_mouth_min, &res_per, &res_total);
    if(res != -1) {
        ui->credit_per->setPlainText(QString::number(res_per, 'f', 2));
        ui->credit_mouth->setPlainText("Минимальный платеж за период:"+QString::number(res_mouth_min, 'f', 2)+"\nМаксимальный платеж за период:"+QString::number(res_mouth_max,'f',2));
        ui->credit_total->setPlainText(QString::number(res_total,'f',2));
    }
}

