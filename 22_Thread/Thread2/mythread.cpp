#include "mythread.h"
#include<QDebug>
#include<QThread>
MyThread::MyThread(QObject *parent) : QObject(parent)
{
    toclose=false;

}
void MyThread::mytimeout()
{
    while(1)
    {
        if(toclose)return;

        emit changesignal();

        mySleep(1000);
        qDebug()<<"子线程号："<<QThread::currentThread();
    }
}
void MyThread::settoclose(bool value)
{
    toclose=value;
}
void MyThread::mySleep(int ms)
{
#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}
