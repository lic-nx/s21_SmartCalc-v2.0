#include "s21_controller.h"
// #include "ui_mainwindow.h"

using namespace s21;

double Controller::Calculate(std::string str, double x) {
  Example.insert_str(str);
  Example.validator();
  return Example.pol_notation(x);
}
void Controller::CreditCalculatorAyntient(double creditSumm, int timeCredit,
                                          double percent) {
  this->credit.zeroing();
  this->credit.annuityLoan(creditSumm, timeCredit, percent);
}

void Controller::CreditCalculatorDifferent(double creditSumm, int timeCredit,
                                           double percent) {
  this->credit.zeroing();
  this->credit.differentiatedCredit(creditSumm, timeCredit, percent);
}
