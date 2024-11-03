#ifndef S21_CREDITCALC_H
#define S21_CREDITCALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace s21 {
class s21_CreditCalc {
 public:
  s21_CreditCalc() {
    cretitSumm = 0;
    timeCredit = 0;
    percent = 0;
  };
  s21_CreditCalc(double cretitSumm, int timeCredit, int percent);
  std::string annuityLoan(double *mounthPayment, double *allPay);
  void differentiatedCredit(double *SumDifinMounth, double *procentSumm,
                            double *totalPayout);

 private:
  double cretitSumm;
  int timeCredit;
  int percent;
};
};  // namespace s21

#endif  // S21_CREDITCALC_H
