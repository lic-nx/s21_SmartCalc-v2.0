#ifndef S21_CALC_H_
#define S21_CALC_H_

#include <iostream>

#include "stack.h"

namespace s21 {

class s21_calc {
 public:
  s21_calc(): str(""){}
  s21_calc(std::string str):  str(str){}
  std::string ret_res();

  void insert_str(std::string str);

  void checker(char x);
  void checker2(char x);
  void checkChars(char i, int len);

  void validator();
  int check_s(int i, int j);
  int check_a(int i, int j);
  int check_m(int i, int j);
  // void changeSimble(int j, int i, int dots);

  int add_number(int j);

  void Chet();

  void RetPrior(char symb) ;

  int is_digit(int i, float x);
  double pol_notation(float x);

  // int checker(char x);

 private:
  dictionary massDictionary[17]{
      {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2},   {'^', 3}, {'c', 4},
      {'s', 4}, {'t', 4}, {'C', 4}, {'S', 4},   {'T', 4}, {'q', 4},
      {'m', 2}, {'l', 4}, {'L', 4}, {'(', 100}, {')', 0}};
  dictionary ret;
  symbolicStack symbolic_stack;
  stack _stack;
  int len;
  std::string str = "";
  std::string res = "";
};

}  // namespace s21

#endif  // S21_CALC_H_
