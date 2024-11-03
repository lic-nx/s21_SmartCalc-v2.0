#include "creditcalc.h"

#include "ui_creditcalc.h"

creditCAlc::creditCAlc(QWidget *parent)
    : QWidget(parent), ui(new Ui::creditCAlc) {
  ui->setupUi(this);
}

creditCAlc::~creditCAlc() { delete ui; }

void creditCAlc::on_pushButton_clicked() {
  this->close();
  emit firstWindow();
}

void creditCAlc::on_pushButton_2_clicked() {
  double summ = ui->sum_credit->value();
  int period = ui->time->value();
  double proc = ui->procent->value();

  if (ui->credit_type->currentText() == "аннуитетный") {
    control.CreditCalculatorAyntient(summ, period, proc);
  }

  if (ui->credit_type->currentText() == "дифференцированный") {
    control.CreditCalculatorDifferent(summ, period, proc);
  }

  ui->textBrowser->setText(QString::fromStdString(control.credit.monthly_pay));
  ui->result_overpay->setText(QString::number(control.credit.overpay, 'f', 2));
  ui->result_total_pay->setText(
      QString::number(control.credit.totalpay, 'f', 2));
}
