#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QFile>
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QDebug>


//变量类型转换
#ifdef UNICODE
#define QStringToTCHAR(x)     (wchar_t*) x.utf16()
#define PQStringToTCHAR(x)    (wchar_t*) x->utf16()
#define TCHARToQString(x)     QString::fromUtf16((x))
#define TCHARToQStringN(x,y)  QString::fromUtf16((x),(y))
#else
#define QStringToTCHAR(x)     x.local8Bit().constData()
#define PQStringToTCHAR(x)    x->local8Bit().constData()
#define TCHARToQString(x)     QString::fromLocal8Bit((x))
#define TCHARToQStringN(x,y)  QString::fromLocal8Bit((x),(y))
#endif


class FileUtils
{
public:
    FileUtils();

    static bool createBatFile(QString batFile, QString exeFilePath, QStringList args);

    static bool toFile(QString filePath, QString content);
    static bool readFile(QString filePath, QString &content);

    //文件工具类
    static bool removeDir(QString dirName);                 //移除目录
    static bool removeFile(QString filename);               //移除文件
    static bool isFileExist(QString filepath);              //判断文件是否存在
    static bool makeDir(QString dirName);                   //新建文件夹
    static bool hideOnWin(QString path);                    //Windows平台下的隐藏文件

    static QList<QString> getAllFiles(QString targetDir, bool suffix = false);   //获取指定目录下包含的所有文件的文件名
    static QList<QString> getAllFilePaths(QString targetDir);   //获取指定目录下包含的所有文件的文件名

    static QString getDirPath(QString filePath);            //获取文件所在的路径
    static QString getFileName(QString filePath);           //从文件路径中摘出文件名
    static bool waitForFile(QString fileName);              //等待文件生成，然后再返回
};

#endif // FILEUTILS_H
