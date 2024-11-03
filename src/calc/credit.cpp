#include "credit.h"

using namespace s21;

void CreditCalc::zeroing() {
  monthly_pay = "";
  monthly_payment.clear();  // ежемесячный платеж
  overpay = 0;              // переплата
  totalpay = 0;             // общая выплата
}

void CreditCalc::annuityLoan(double creditSumm, int timeCredit,
                             double percent) {
  double mounth_prosent = percent / 1200;  // ежемесячный процент
  double k =
      (mounth_prosent * pow((1 + mounth_prosent), timeCredit)) /
      (pow((1 + mounth_prosent), timeCredit) - 1);  // аннуитетного коэффициента
  this->monthly_pay = std::to_string(k * creditSumm);
  this->totalpay = timeCredit * k * creditSumm;
  this->overpay = this->totalpay - creditSumm;
}

void CreditCalc::differentiatedCredit(double creditSumm, int timeCredit,
                                      double percent) {
  double coust = creditSumm / (timeCredit);
  double rest = creditSumm;
  this->totalpay = 0;
  double moynth_pay = 0;
  while (timeCredit != 0) {
    moynth_pay =
        std::ceil((coust + (rest * percent) / 1200) * 10000000) / 10000000;
    this->totalpay += moynth_pay;
    this->monthly_pay.append(std::to_string(timeCredit) + " " +
                             std::to_string(moynth_pay) + "\n");
    rest = rest - coust;
    timeCredit -= 1;
  }
  this->overpay = this->totalpay - creditSumm;
}
