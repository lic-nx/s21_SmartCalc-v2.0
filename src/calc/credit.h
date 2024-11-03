#ifndef CREDIT_H_
#define CREDIT_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <list>

namespace s21 {
class CreditCalc {
 public:
  CreditCalc(){};
  CreditCalc(double creditSumm, int timeCredit, double percent);
  void zeroing();  // обнуление параметров
  void annuityLoan(double creditSumm, int timeCredit, double percent);
  void differentiatedCredit(double creditSumm, int timeCredit, double percent);
  std::list<double> monthly_payment;  // ежемесячный платеж
  std::string monthly_pay;
  double overpay;   // переплата
  double totalpay;  // общая выплата
 private:
  //      double creditSumm;
  //      int timeCredit;
  //      double percent;
};
};  // namespace s21

// void annuityLoan(double *mounthPayment, double *allPay);

// void differentiatedCredit(double *SumDifinMounth, double *procentSumm,
//                           double *totalPayout);

#endif  // CREDIT_H_
