#ifndef MAINWINDO_H
#define MAINWINDO_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
  class MainWindo;
}

class MainWindo : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindo(QWidget *parent = nullptr);
  ~MainWindo();

private slots:
  void on_percent_clicked();

  void on_clear_clicked();

  void on_one_clicked();

  void on_two_clicked();

  void on_three_clicked();

  void on_four_clicked();

  void on_five_clicked();

  void on_six_clicked();

  void on_seven_clicked();

  void on_eight_clicked();

  void on_nine_clicked();

  void on_zero_clicked();

  void on_dot_clicked();

  void on_negative_clicked();

  void on_plus_clicked();

  void on_minus_clicked();

  void on_multiply_clicked();

  void on_division_clicked();

  void on_equals_clicked();

private:
  void calculate();
  void set_operation(char op);
  void clear_background();
  void set_text(QString txt);

  Ui::MainWindo *ui;
  QLabel *label;
  char operation = ' ';
  QString prevValue = "";
  char isNewValue = 1;
};

#endif // MAINWINDO_H
