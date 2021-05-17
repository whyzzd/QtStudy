#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QMainWindow>
#include<QFileSystemModel>
#include<QLabel>
#include<QCheckBox>
QT_BEGIN_NAMESPACE
namespace Ui { class FileSystem; }
QT_END_NAMESPACE

class FileSystem : public QMainWindow
{
    Q_OBJECT

public:
    FileSystem(QWidget *parent = nullptr);
    ~FileSystem();

    void init();
private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::FileSystem *ui;

    QFileSystemModel *m_Model;
    QLabel *m_FileName;
    QLabel *m_FileType;
    QLabel *m_FileSize;
    QLabel *m_FilePath;

};
#endif // FILESYSTEM_H
