#include "s21_model.h"

using namespace s21;

std::string s21_calc::ret_res() { return str; }

void s21_calc::insert_str(std::string str) {
  if (str.size() > 0) {
    this->str = str;
    this->len = str.length();
    this->res = "";
  } else {
    throw "the string cannot be empty";
  }
}

void s21_calc::checker(char x) {
  if (strchr("-+/*^)", x))
    throw "char is not in -+/*^)";  // если есть знак то возвращаем да
}

void s21_calc::checker2(char x) {
  if (strchr("*/^m", x))
    throw "char is not in */^m)";  // если есть знак то возвращаем да
}
void s21_calc::checkChars(char i, int len) {
  if (i >= len - 1) {
    throw "char is out of range";
  }
  checker(str[i + 1]);
  checker2(str[i - 1]);
}

int s21_calc::check_s(int i, int j) {
  if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
    i += 2;
  } else if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't' &&
             str[i + 4] == '(') {
    res[j] = 'q';
    i += 3;
  } else {
    throw "err: wrong sin or sqrt";
  }
  return i;
}

int s21_calc::check_a(int i, int j) {
  if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
      str[i + 4] == '(') {
    res[j] = 'C';
  } else if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n' &&
             str[i + 4] == '(') {
    res[j] = 'S';
  } else if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n' &&
             str[i + 4] == '(') {
    res[j] = 'T';
  } else
    throw "err: acos or asin or atan";
  i += 3;
  return i;
}

int s21_calc::check_m(int i, int j) {
  if (str[i + 1] == 'o' && str[i + 2] == 'd') {
    res[j] = 'm';
    i += 2;
  } else
    throw "err: mod";
  if (i >= len - 1) {
    throw "err: out of range";
  }
  return i;
}

void s21_calc::validator() {
  int staples = 0;
  int dots = 0;
  int j = 0;
  int len = str.length();
  if (str[0] == '-') {
    res += '0';  // проверяем унарный минус
    j++;
  }
  checker2(str[0]);
  if (len == 0 || len >= 254) {
    throw "so long or short ";
  }
  for (int i = 0; i < (len); ++i) {
    res += str[i];
    if (!isdigit(str[i]) && str[i] != '.' && str[i] != ',') {
      dots = 0;
    }
    switch (str[i]) {
      case '-':
        if (str[i - 1] > 0 && str[i - 1] == '(') {
          res[j] = '0';
          j++;
          res += '-';
        }
        checker(str[i + 1]);  // была проверка на то что if (i >= len - 1 ||
                              // checker(str[i + 1]))
        break;
      case '/':
        if (str[i + 1] == '0' && str[i + 2] != '.') {
          throw "err: cant div on 0 ";
        }
        checkChars(i, len);
        break;
      case '+':
      case '*':
      case '^':
        checkChars(i, len);
        break;
      case '(':
        staples += 1;  // смотрим число скобок
        break;
      case ')':
        staples -= 1;  // следим чтоб все закрывалось
        break;
      case ',':
        res[j] = '.';
        if (str[i - 1] < '0' || str[i - 1] > '9' || str[i + 1] < '0' ||
            str[i + 1] > '9' ||
            dots == 1)  // смотрим чтб перед точкой и после было число
          throw "err: with dots";
        dots = 1;
        break;
      case 'c':
        if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(')
          i += 2;
        else
          throw "err: wrong cos";
        break;
      case 's':
        i = check_s(i, j);
        break;
      case 't':
        if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(') {
          res[j] = 't';
          i += 2;
        } else
          throw "err: wrong tang";
        break;
      case 'a':
        i = check_a(i, j);
        break;
      case 'm':
        i = check_m(i, j);
        break;
      case 'l':
        if (str[i + 1] == 'n') {
          res[j] = 'l';
          i += 1;
        } else if (str[i + 1] == 'o' && str[i + 2] == 'g') {
          res[j] = 'L';
          i += 2;
        } else {
          throw "err: ln log";
        }
      default:
        break;
    }
    j++;
  }
  if (staples != 0) throw "err: check your staples";
  str = res;
}

int s21_calc::add_number(int j) {
  char strNum[50] = {0};
  int i = 0;
  while (isdigit(str[i + j]) || str[i + j] == '.') {
    strNum[i] = str[i + j];
    i++;
  }
  setlocale(LC_NUMERIC, "en_US.utf8");
  this->_stack.pushDouble(atof(strNum));
  return j + i;  // возвращаем то где заканчивается число
}


void s21_calc::Chet() {
  double tmp = 0;
  if (this->symbolic_stack.member != NULL && this->_stack.member != NULL) {
    char timeVal = this->symbolic_stack.get_symbol();
    switch (timeVal) {
      case '+':
        tmp = this->_stack.popDouble() + this->_stack.get_value();
        // тип возвращаем последнее и предпоследнее число
        break;

      case '-':
        tmp = this->_stack.popDouble();
        tmp = this->_stack.get_value() - tmp;
        // тип возвращаем последнее и предпоследнее число
        break;
      case '*':
        tmp = this->_stack.popDouble() * this->_stack.member->value;
        // тип возвращаем последнее и предпоследнее число
        break;
      case '/':
        tmp = this->_stack.popDouble();
        if (tmp == 0) throw "error";
        tmp = this->_stack.member->value / tmp;
        // тип возвращаем последнее и предпоследнее число
        break;
      case '^':
        tmp = this->_stack.popDouble();
        tmp = pow(this->_stack.member->value, tmp);
        // тип возвращаем последнее и предпоследнее число
        break;
      case 'c':
        tmp = cos(this->_stack.member->value);
        break;
      case 's':
        tmp = sin(this->_stack.member->value);
        break;
      case 't':
        tmp = tan(this->_stack.member->value);
        break;
      case 'C':
        tmp = acos(this->_stack.member->value);
        break;
      case 'S':
        tmp = asin(this->_stack.member->value);
        break;
      case 'T':
        tmp = atan(this->_stack.member->value);
        break;
      case 'q':
        tmp = sqrt(this->_stack.member->value);  // число >0
        break;
      case 'm':
        tmp = this->_stack.popDouble();
        tmp = (int(this->_stack.member->value) % int(tmp));
        // тип возвращаем последнее и предпоследнее число
        break;
      case 'l':
        tmp = log(this->_stack.member->value);
        break;
      case 'L':
        tmp = log10(this->_stack.member->value);
        break;
    }
    this->symbolic_stack.popChar();  // удаляю использованный знак
    this->_stack.member->value = tmp;
  }
}


void s21_calc::RetPrior(char symb) {
  static const int dictionarySize =
      sizeof(massDictionary) / sizeof(massDictionary[0]);
  ret = {0, -1};
  for (int j = 0; j < dictionarySize; j++) {
    if (massDictionary[j].symbol == symb) {
      ret = massDictionary[j];
      break;
    }
  }
  //   return ret;
}


int s21_calc::is_digit(int i, float x) {
  if (isdigit(str[i])) {  // вводить x
    i = add_number(i);
  } else if (str[i] == 'x') {
    this->_stack.pushDouble(x);
  }
  return i;
}

double s21_calc::pol_notation(float x) {  // х это переменная для графиков устанавлваем
  for (size_t i = 0; i < str.length(); i++) {
    // печатаем число итерации и сколько там элементов
    i = is_digit(i, x);
    if (i < str.length()) {
      RetPrior(str[i]);

      if (ret.symbol != 0) {
        if (this->ret.symbol == ')') {
          while (this->symbolic_stack.get_symbol() != '(') Chet();
          this->symbolic_stack.popChar();
        } else {
          while (this->symbolic_stack.get_symbol() != '(' &&
                 this->_stack.count >= 2 &&
                 this->symbolic_stack.get_prioritet() >=
                     this->ret.prioritet) {
            Chet();
          }

          this->symbolic_stack.pushChar(ret);
        }
      }
    }
  }
  while (this->symbolic_stack.count > 0) {
    Chet();
  }
  double calc = this->_stack.popDouble();
  return calc;
}
