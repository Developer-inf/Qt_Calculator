#include "mainwindo.h"
#include "ui_mainwindo.h"

MainWindo::MainWindo(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindo)
{
  ui->setupUi(this);
  this->label = ui->label;
}

MainWindo::~MainWindo()
{
  delete ui;
}

void MainWindo::on_percent_clicked()
{
    double num = label->text().toDouble();
    set_text(std::to_string(num / 100).c_str());
}

void MainWindo::on_clear_clicked()
{
    set_text("");
    isNewValue = 1;
    prevValue = "";
}

void MainWindo::on_one_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "1");
}

void MainWindo::on_two_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "2");
}

void MainWindo::on_three_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "3");
}

void MainWindo::on_four_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "4");
}

void MainWindo::on_five_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "5");
}

void MainWindo::on_six_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "6");
}

void MainWindo::on_seven_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "7");
}

void MainWindo::on_eight_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "8");
}

void MainWindo::on_nine_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    set_text(label->text() + "9");
}

void MainWindo::on_zero_clicked()
{
    if (!isNewValue)
    {
        clear_background();
        set_text("");
        isNewValue = 1;
    }
    if (label->text().length() > 0 && !label->text().startsWith("0"))
    {
        set_text(label->text() + "0");
    }
}

void MainWindo::calculate()
{
    if (operation != ' ')
    {
        double value = atof(prevValue.toStdString().c_str());
        switch (operation)
        {
          case ('+'):
              value += label->text().toDouble();
              break;
          case ('-'):
              value -= label->text().toDouble();
              break;
          case ('*'):
              value *= label->text().toDouble();
              break;
          case ('/'):
              value /= label->text().toDouble();
              break;
        }
        set_text(std::to_string(value).c_str());
    }
}

void MainWindo::on_dot_clicked()
{
    QString text = label->text();
    if (text.length() == 0)
    {
        label->setText("0.");
    }
    else if (!text.contains('.'))
    {
        label->setText(label->text() + ".");
    }
}

void MainWindo::on_negative_clicked()
{
    double num = label->text().toDouble();
    set_text(std::to_string(-num).c_str());
}

void MainWindo::set_operation(char op)
{
    if (operation != ' ' && isNewValue == 0)
    {
        clear_background();
    }
    else
    {
        calculate();
    }
    prevValue = label->text();
    isNewValue = 0;
    operation = op;

    QPushButton *widget = nullptr;
    switch (op)
    {
      case '+':
        widget = ui->plus;
        break;
      case '-':
        widget = ui->minus;
        break;
      case '*':
        widget = ui->multiply;
        break;
      case '/':
        widget = ui->division;
        break;
    }

    QString style = widget->styleSheet();
    widget->setStyleSheet(style + "background-color: #aaa;");
}

void MainWindo::clear_background()
{
    ui->plus->setStyleSheet(ui->plus->styleSheet().replace("background-color: #aaa;", ""));
    ui->minus->setStyleSheet(ui->minus->styleSheet().replace("background-color: #aaa;", ""));
    ui->multiply->setStyleSheet(ui->multiply->styleSheet().replace("background-color: #aaa;", ""));
    ui->division->setStyleSheet(ui->division->styleSheet().replace("background-color: #aaa;", ""));
}

void MainWindo::on_plus_clicked()
{
    set_operation('+');
}

void MainWindo::on_minus_clicked()
{
    set_operation('-');
}

void MainWindo::on_multiply_clicked()
{
    set_operation('*');
}

void MainWindo::on_division_clicked()
{
    set_operation('/');
}

void MainWindo::on_equals_clicked()
{
    calculate();
    prevValue = label->text();
    operation = ' ';
    isNewValue = 0;
}

void MainWindo::set_text(QString txt)
{
    int idx = -1;
    const char *chars = txt.toStdString().c_str();

    int endIdx = txt.indexOf('.') == -1 ? txt.length() : txt.indexOf('.');
    for (int i = txt.length() - 1; i >= endIdx; i--)
    {
        if (chars[i] != '0')
        {
            idx = chars[i] == '.' ? i : i + 1;
            break;
        }
    }
    label->setText(txt.mid(0, idx));
}
