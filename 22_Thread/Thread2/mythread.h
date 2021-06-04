#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void settoclose(bool value);

public slots:
    void mytimeout();




signals:
    void changesignal();
private:
    bool toclose;


};

#endif // MYTHREAD_H
