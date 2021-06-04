#ifndef THREADIMAGE_H
#define THREADIMAGE_H

#include <QObject>
#include<QImage>
class ThreadImage : public QObject
{
    Q_OBJECT
public:
    explicit ThreadImage(QObject *parent = nullptr);
public slots:
    void drawImage();


signals:
    void sendimage(QImage);

};

#endif // THREADIMAGE_H
