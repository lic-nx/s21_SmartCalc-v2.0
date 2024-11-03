#include "stack.h"
using namespace s21;

stack::stack() { member = new stack_member(); }
stack::~stack() {
  while (member->next != nullptr) {
    popDouble();
  }
  popDouble();
  // member->next = nullptr;
}

void stack::pushDouble(double x) {  // положить новый элемент
  stack_member* buf = new stack_member(x);
  buf->next = this->member;
  member = buf;
  count += 1;
  // проверить на утечки
}
double stack::get_value() { return member->value; }
double stack::popDouble() {  // возвращает удаляемое значение
  if (this->member == nullptr) {
    // Стек пуст, возвращаем NAN или выбрасываем исключение
    return nan("");
  }
  double val = this->member->value;
  stack_member* buf = this->member;
  this->member = buf->next;
  delete buf;

  count -= 1;
  return val;
}

stack_member::stack_member(double x) {
  value = x;
  next = nullptr;
}
stack_member::~stack_member() {
  next = nullptr;
  delete next;
}
stack_member::stack_member() { next = nullptr; }

dictionary::dictionary() {
  symbol = 0;
  prioritet = -1;
}
dictionary::dictionary(char sy, int pr) {
  symbol = sy;
  prioritet = pr;
}

symbolicStack_member::symbolicStack_member() { this->next = nullptr; }
symbolicStack_member::symbolicStack_member(dictionary x) {
  symbol = x.symbol;
  prioritet = x.prioritet;
  next = nullptr;
}
symbolicStack_member::~symbolicStack_member() {
  next = nullptr;
  delete next;
}

symbolicStack::symbolicStack() { member = new symbolicStack_member(); }
symbolicStack::~symbolicStack() {
  while (member->next != nullptr) {
    popChar();
  }
  popChar();
}
char symbolicStack::get_symbol() { return member->symbol; }
int symbolicStack::get_prioritet() { return member->prioritet; }
void symbolicStack::pushChar(dictionary x) {
  count += 1;
  symbolicStack_member* buf = new symbolicStack_member(x);
  buf->next = this->member;
  member = buf;
}

int symbolicStack::popChar() {
  if (member == nullptr) {
    // Стек пуст, возвращаем специальное значение или выбрасываем исключение
    return -1;  // Или другое значение, указывающее на ошибку
  }

  int val = member->symbol;
  symbolicStack_member* buf = member;
  member = member->next;
  delete buf;
  count -= 1;
  return val;
}
