#include "mainwindow.h"

#include <iostream>
#include <string>

#include "ui_mainwindow.h"

using namespace s21;

// Controller control();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  Setup();
  creditcalc = new creditCAlc();
  connect(creditcalc, &creditCAlc::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ButtonPressedAndPrinted(bool checked) {
  auto but = static_cast<QAbstractButton *>(
      sender());  // lissing what button was colled
  if (!but & checked) return;
  if (but->text() == "del") {
    QString str = ui->lineEdit->text();
    str.chop(
        1);  // Removes n characters from the end of the string. If 1 is greater
             // than or equal to size(), the result is an empty string
    ui->lineEdit->setText(str);
  } else if (but->text() == "clean") {
    ui->lineEdit->setText("");
  } else if (but->text() == "=") {
    // convert to char array
    QString str1 = ui->lineEdit->text();
    QByteArray ba = str1.toLocal8Bit();
    char *text = ba.data();
    try {
      double result = control.Calculate(text, ui->xValue->value());
      ui->lineEdit->setText("");
      ui->lineEdit->setText(QString::number(result, 'f', 7));
    } catch (const char *error_message) {
      ui->lineEdit->setText(error_message);
    }
  } else {
    ui->lineEdit->setText(ui->lineEdit->text() + but->text());
  }
}

void MainWindow::Setup() {
  for (auto &but : ui->all_btns->buttons())
    connect(but, &QAbstractButton::clicked, this,
            &MainWindow::ButtonPressedAndPrinted);
}

void MainWindow::on_pushButton_13_clicked() {
  QString str1 = ui->lineEdit->text();
  QByteArray ba = str1.toLocal8Bit();
  char *text = ba.data();
  xBegin = ui->start->value();
  xEnd = ui->end->value();
  // очищаем график
  ui->widget->clearGraphs();

  // обнуляем координаты
  float yMin = 0.0, yMax = 0.0, tmp;
  h = 0.1;
  ui->widget->xAxis->setRange(xBegin, xEnd);

  X = xBegin;
  N = (xEnd - xBegin) / h + 2;
  try {
    yMin = control.Calculate(text, xBegin);
    yMax = control.Calculate(text, xBegin);
    for (X = xBegin + h; X < xEnd; X += h) {
      x.push_back(X);
      tmp = control.Calculate(text, X);  // поиск по польской нотации;
      y.push_back(tmp);
      if (tmp < yMin) {
        yMin = tmp;
      } else if (tmp > yMax) {
        yMax = tmp;
      }
    }
  } catch (const char *error_message) {
    ui->lineEdit->setText(error_message);
  }
  ui->widget->yAxis->setRange(yMin - 1, yMax + 1);
  ui->widget->addGraph();  // создаем новый график
  ui->widget->graph(0)->addData(x,
                                y);  // устанавливаем значения для отрисовки
  ui->widget->replot();  // рисуем
  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_14_clicked() {
  this->hide();
  creditcalc->show();
}
