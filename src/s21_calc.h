#ifndef S21_CALC_H_
#define S21_CALC_H_

#include <iostream>
#include <string>

namespace s21{

class stack {
    double value;
    stack* next;
    stack(){
        next = nullptr;
    }
    stack(double value){
        this->value = value;
    }
    stack(double value, stack* other){
        this->value = value;
        this->next = other;
    }
};

class symbolicStack {
  char symbol;
  int prioritet;
  symbolicStack* next;

};


class calc{
    void checker2(char x) {
      if (strchr("*/^m", x)) throw "error: first char dont be *,/,^ or m";  // если есть знак то возвращаем да
    };

    void char_dash(){
        if (str[i - 1] > 0 && str[i - 1] == '(') {
            ret[j] = '0';
            j++;
            ret[j] = '-';
        }
        if (i >= len - 1 || checker(str[i + 1])) {
            err = 1;
        }
    }

    int validator(){ // поставляли сюда строку которую чистим и почищенну засовыем в ret
        int staples = 0;
        int dots = 0;  //
        j = 0;
        int len = str.length();
        if (str[0] == '-' && err == 0) {
            ret[j] = '0';  // проверяем унарный минус
            j++;
        }
        checker2(str[0]);

        if (len == 0 || len >= 254) {
            throw "error: size of equation dont be more then 254 and less then 1 ";
        }
        for (i = 0; i < (len) && err == 0; ++i) {
            ret[j] = str[i];
            if (!isdigit(str[i]) && str[i] != '.' && str[i] != ',') {
            dots = 0;
            }
            switch (str[i]) {
            case '-':
                char_dash(i,j);
                break;
            case '/':
                if (str[i + 1] == '0' && str[i + 2] != '.') {
                err = 4;
                }
                err = checkChars(i, str, len);
                break;
            case '+':
            case '*':
            case '^':
                err = checkChars(i, str, len);
                break;

            case '(':
                staples += 1;  // смотрим число скобок
                break;
            case ')':
                staples -= 1;  // следим чтоб все закрывалось
                break;
            case ',':
                ret[j] = '.';
                if (str[i - 1] < '0' || str[i - 1] > '9' || str[i + 1] < '0' ||
                    str[i + 1] > '9' ||
                    dots == 1)  // смотрим чтб перед точкой и после было число
                err = 17;
                dots = 1;
                break;
            case 'c':
                if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(')
                i += 2;
                else
                err = 5;
                break;

            case 's':
                if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
                i += 2;
                } else if (str[i + 1] == 'q' && str[i + 2] == 'r' &&
                        str[i + 3] == 't' && str[i + 4] == '(') {
                ret[j] = 'q';
                i += 3;
                } else {
                err = 6;
                }
                break;

            case 't':
                if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(')
                i += 2;
                else
                err = 11;
                break;

            case 'a':
                if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
                    str[i + 4] == '(') {
                ret[j] = 'C';
                } else if (str[i + 1] == 's' && str[i + 2] == 'i' &&
                        str[i + 3] == 'n' && str[i + 4] == '(') {
                ret[j] = 'S';
                } else if (str[i + 1] == 't' && str[i + 2] == 'a' &&
                        str[i + 3] == 'n' && str[i + 4] == '(') {
                ret[j] = 'T';
                } else
                err = 8;
                i += 3;
                break;
            case 'm':
                if (str[i + 1] == 'o' && str[i + 2] == 'd') {
                ret[j] = 'm';
                i += 2;
                } else
                err = 10;
                if (i >= len - 1) {
                err = 12;
                }
                break;
            case 'l':
                if (str[i + 1] == 'n') {
                ret[j] = 'l';
                i += 1;
                } else if (str[i + 1] == 'o' && str[i + 2] == 'g') {
                ret[j] = 'L';
                i += 2;
                } else {
                err = 15;
                }
            default:
                break;
            }
            j++;
        }
        if (staples != 0) err = 16;
        return err;
    }

    void set_string(std::string other_str){
        this->str = other_str;

    }
    private:
        std::string str; 
        std::string ret;
        int i;
        int j;

};

}


#endif  // S21_CALC_H_
