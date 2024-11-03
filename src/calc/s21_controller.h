#ifndef CONTROLLER_H
#define CONTROLLER_H

// #include <QString>
#include "credit.h"
#include "s21_model.h"

namespace s21 {

class Controller {
 public:
  Controller() {
    s21_calc Example;
    CreditCalc credit;
  };
  CreditCalc credit;

  double Calculate(std::string str, double x);
  void CreditCalculatorAyntient(double creditSumm, int timeCredit,
                                double percent);
  void CreditCalculatorDifferent(double creditSumm, int timeCredit,
                                 double percent);

 private:
  s21_calc Example;
  //    CreditCalc credit;
};
}  // namespace s21
#endif  // CONTROLLER_H
