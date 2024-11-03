#ifndef S21_STACK_H_
#define S21_STACK_H_

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace s21 {

class stack_member {
 public:
  double value;
  class stack_member* next = nullptr;
  stack_member();
  stack_member(double x);
  ~stack_member();
};

class stack {
 public:
  stack_member* member;
  int count = 0;
  stack();
  ~stack();
  void pushDouble(double x);
  double get_value();
  double popDouble();
};

class dictionary {
 public:
  char symbol;
  int prioritet;
  dictionary();
  dictionary(char sy, int pr);
};

class symbolicStack_member {
 public:
  char symbol = '+';
  int prioritet = 0;
  symbolicStack_member* next = nullptr;
  symbolicStack_member();
  symbolicStack_member(dictionary x);
  ~symbolicStack_member();
};

class symbolicStack {  // надо придумать как удалять
 public:
  int count = 0;
  symbolicStack_member* member;
  symbolicStack();
  ~symbolicStack();
  char get_symbol();
  int get_prioritet();
  void pushChar(dictionary x);
  int popChar();
};

#endif  // S21_STACK_H_
}
