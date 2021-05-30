#ifndef TWOFORM_H
#define TWOFORM_H

#include <QWidget>

namespace Ui {
class TwoForm;
}

class TwoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TwoForm(QWidget *parent = nullptr);
    ~TwoForm();

private slots:
    void on_goOneButton_clicked();

    void on_goThreeButton_clicked();

private:
    Ui::TwoForm *ui;
};

#endif // TWOFORM_H
