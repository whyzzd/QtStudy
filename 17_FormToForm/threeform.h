#ifndef THREEFORM_H
#define THREEFORM_H

#include <QWidget>

namespace Ui {
class ThreeForm;
}

class ThreeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ThreeForm(QWidget *parent = nullptr);
    ~ThreeForm();

private slots:
    void on_goOneButton_clicked();

    void on_goTwoButton_clicked();

private:
    Ui::ThreeForm *ui;
};

#endif // THREEFORM_H
