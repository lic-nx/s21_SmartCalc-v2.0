#include <gtest/gtest.h>

#include "calc/s21_controller.h"
#include "calc/s21_model.h"
using namespace s21;

TEST(testController, summ) {
  std::string expression = "122,1+877,9";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  ASSERT_NEAR(check, 1000.0, 1e-7);
}
TEST(testController, send_text) {
  std::string expression = "hello world";
  s21::Controller control;
  ASSERT_ANY_THROW(control.Calculate(expression, 0.0));
}
TEST(testController, minus) {
  std::string expression = "122,1-877,9";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  ASSERT_NEAR(check, -755.8, 1e-7);
}

TEST(testController, div) {
  std::string expression = "10/2";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  ASSERT_NEAR(check, 5.0, 1e-7);
}

TEST(testController, errors) {
  std::string expression = "--3";
  s21::Controller control;
  ASSERT_ANY_THROW(control.Calculate(expression, 0.0));
}

TEST(testController, value_test) {
  std::string expression = "4 + 9 + 7 + 9";
  s21::Controller control;
  ASSERT_NEAR(control.Calculate(expression, 0.0), 29.0, 1e-7);
}

TEST(testController, test_div_sum) {
  s21::Controller control;
  std::string expression = "4 + 9 / 2 * 67787";
  double check;
  check = control.Calculate(expression, 0.0);
  ASSERT_NEAR(check, 305045.5, 1e-7);
}

TEST(SmartCalculator, TestTan) {
  std::string expression = "(4^(acos(2/4)))";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 4.2704707206911694, 1e-7);
}

TEST(SmartCalculator, TestFunc1) {
  std::string expression = "tan(2*2)";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 1.1578213, 1e-7);
}

TEST(SmartCalculator, testAcos) {
  std::string expression = "(4^acos(2/4)/tan(2*2))";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 3.6883678, 1e-7);
}

TEST(SmartCalculator, testLongAcos) {
  std::string expression = "(4^acos(2/4)/tan(2*2)/5^acos(2/4))";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 0.68371409, 1e-7);
}

TEST(SmartCalculator, test_acos_tang) {
  std::string expression =
      "(4^acos(2/4)/tan(2*2)/5^acos(2/4)/tan(tan(tan(2*2))))";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, -0.58934796, 1e-7);
}

TEST(SmartCalculator, TestFunc5) {
  std::string expression = "3^cos(0.5)/5";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 0.52449733, 1e-7);
}

TEST(SmartCalculator, TestFunc6) {
  std::string expression = "3^cos(0.5)/sqrt(25)";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 0.52449733, 1e-7);
}

TEST(SmartCalculator, TestFunc7) {
  std::string expression = "log(10)";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 1, 1e-7);
}

TEST(SmartCalculator, TestFunc8) {
  std::string expression = "1+2*(3^sin(0.4))^3*2+1";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 16.436413, 1e-7);
}

TEST(SmartCalculator, TestFunc9) {
  std::string expression = "ln(10)";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 2.3025851, 1e-7);
}

TEST(SmartCalculator, TestFunc10) {
  std::string expression = "acos(-0.5)+asin(-0.5)+atan(0.1)*sin(20)*tan(45)";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 2.6387416522522384, 1e-7);
}

TEST(SmartCalculator, TestFunc11) {
  std::string expression = "1+2*3^(sin(0.4)^(3)) *2 + 1";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 6.2681129394303134, 1e-7);
}

TEST(SmartCalculator, TestFunc12) {
  std::string expression = "(-5)^(-4)";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 0.0016, 1e-7);
}
TEST(SmartCalculator, TestFunc13) {
  std::string expression = "-4+5";
  double check;
  s21::Controller control;
  check = control.Calculate(expression, 0.0);
  // std::cout << (check) << '\n';
  ASSERT_NEAR(check, 1, 1e-7);
}

TEST(testModel, checker) {
  char x = '-';
  s21::s21_calc calc;
  ASSERT_ANY_THROW(calc.checker(x));
}

TEST(testModel, checker1) {
  char x = '2';
  s21::s21_calc calc;
  ASSERT_NO_THROW(calc.checker(x));
}

TEST(testModel, checker1_error) {
  char x = '+';
  s21::s21_calc calc;
  ASSERT_ANY_THROW(calc.checker(x));
}

TEST(testModel, insert_str) {
  std::string str = "test string";
  s21::s21_calc calc;
  calc.insert_str(str);
  ASSERT_EQ(calc.ret_res(), "test string");
}

TEST(testModel, insert_str_empty) {
  std::string str = "";
  s21::s21_calc calc;

  ASSERT_ANY_THROW(calc.insert_str(str));
}

TEST(testModel, check_checker2) {
  char symbol = '*';
  s21::s21_calc calc;
  ASSERT_ANY_THROW(calc.checker2(symbol));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}