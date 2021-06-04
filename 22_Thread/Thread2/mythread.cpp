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
        _sleep(1000);
        qDebug()<<"子线程号："<<QThread::currentThread();
    }
}
void MyThread::settoclose(bool value)
{
    toclose=value;
}
