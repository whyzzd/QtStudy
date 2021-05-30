#ifndef ONEFORM_H
#define ONEFORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class OneForm; }
QT_END_NAMESPACE

class OneForm : public QWidget
{
    Q_OBJECT

public:
    OneForm(QWidget *parent = nullptr);
    ~OneForm();

private slots:
    void on_goTwoButton_clicked();

    void on_goThreeButton_clicked();

private:
    Ui::OneForm *ui;
};
#endif // ONEFORM_H
