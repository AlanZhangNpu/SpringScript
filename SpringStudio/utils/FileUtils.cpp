#include "FileUtils.h"
#include<iostream>
#include<fstream>

#include <QTime>
#include <QCoreApplication>

using namespace std;

FileUtils::FileUtils()
{
}

/**
 * @brief 创建bat文件
 * @param batFile
 * @param exeFilePath
 * @param args
 * @return
 */
bool FileUtils::createBatFile(QString batFile,
        QString exeFilePath,
        QStringList args)
{
    if(!FileUtils::removeFile(batFile))
        return false;

    QFile file(batFile);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate))
    {
        return false;
    }
    QTextStream out(&file);
    out<<"@echo off" <<endl;
    for(int i=0; i<args.size(); i++){
        out<<exeFilePath <<" "<<args[i] <<endl;
    }
    file.close();
    FileUtils::hideOnWin(batFile);//隐藏文件
    return true;
}


bool FileUtils::toFile(QString filePath, QString content)
{
    ofstream outFile;
    outFile.open(filePath.toStdString(), ios::out);
    if(outFile){
        outFile << content.toStdString();
        outFile.close();
        return true;
    }else
        return false;
}

bool FileUtils::readFile(QString filePath, QString &content)
{
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;

    content.clear();

    while(!file.atEnd()){
        content = QString(file.readAll());
        QByteArray bytes = content.toUtf8();  //获取字节
        content = QString(bytes);
    }
    return true;
}

bool FileUtils::removeDir(QString dirName)
{
    QDir dir(dirName);

    QString tmpdir = "";
    if(!dir.exists()){
        return false;
    }

    QFileInfoList fileInfoList = dir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){
            tmpdir = dirName + ("/") + fileInfo.fileName();
            removeDir(tmpdir);    //递归删除
            dir.rmdir(fileInfo.fileName()); //移除子目录
        }
        else if(fileInfo.isFile()){
            QFile tmpFile(fileInfo.fileName());
            tmpFile.setPermissions(QFile::WriteOwner);
            dir.remove(tmpFile.fileName()); //删除文件
        }
    }

    dir.cdUp(); //返回上级目录，因为只有返回上级目录，才可以删除这个目录
    if(dir.exists(dirName)){
        if(!dir.rmdir(dirName))
            return false;
    }
    return true;

}

bool FileUtils::removeFile(QString filename)
{
    if(!isFileExist(filename))
        return true;

    QFile file(filename);
    file.setPermissions(QFile::WriteOwner);
    file.close();
    return file.remove();
}

bool FileUtils::isFileExist(QString filepath)
{
    QFileInfo fi(filepath);
    return fi.isFile();
}

QList<QString> FileUtils::getAllFilePaths(QString targetDir)
{
    if(!targetDir.endsWith("\\") || !targetDir.endsWith("/"))
        targetDir += "\\";

    QDir * dir = new QDir(targetDir);
    QStringList filter;
    filter=dir->entryList(QDir::Files);
    for(int i=0;i<filter.size();i++)
    {
       filter[i] = targetDir + filter[i];
    }
    return filter;
}

/**
 * @brief 由文件名获取其所在的目录的路径
 * @param filePath
 * @return
 */
QString FileUtils::getDirPath(QString filePath)
{
    QFileInfo fi(filePath);
    QString dir = fi.absoluteDir().path();
    if(!dir.endsWith("\\") || !dir.endsWith("/"))
        dir = dir + "/";
    return dir;
}

QString FileUtils::getFileName(QString filePath)
{
    QFileInfo fi(filePath);
    return fi.baseName();
}

bool FileUtils::waitForFile(QString fileName)
{
    while(!FileUtils::isFileExist(fileName)){
        //等待一段时间
        QTime t;
        t.start();
        while(t.elapsed()<1000){
            QCoreApplication::processEvents();
        }
    }
    return true;
}

//bool FileUtils::toOneFile(QString filePath, QStringList files)
//{
//    QFile targetFile(filePath);
//    if(!targetFile.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate))
//        return false;

//    QTextStream out(&targetFile);
//    foreach(QString file, files){
//        QFile sourceFile(file);
//        if(!sourceFile.open(QIODevice::ReadOnly|QIODevice::Text))
//            return false;

//        QFileInfo fi(file);
//        QString fileName = fi.fileName();
//        QString last = fi.lastModified().toString("yyyy年MM月dd日");

//        QString head = "/***************************************************************\n** \n** "
//                + "\n** 文件：" + fileName
//                + "\n** 最后修改时间：" + last
//                + "\n** \n***************************************************************/";
//        out << head << endl;
//        while(!sourceFile.atEnd()){
//            QString line = QString(sourceFile.readLine());
//            if(line.trimmed().isEmpty() || line.trimmed().startsWith("//"))
//                continue;

//            out << line;
//        }
//    }
//    targetFile.close();
//    return true;
//}

bool FileUtils::makeDir(QString dirName)
{
    QDir dir(dirName);
    if(!dir.exists()){
        return dir.mkdir(dirName);
    }
    return true;
}

bool FileUtils::hideOnWin(QString path)
{
//    TCHAR * lpName = QStringToTCHAR(path);
//    DWORD dwResult = ::GetFileAttributes( lpName );
//    if( INVALID_FILE_ATTRIBUTES == dwResult )
//    {
//        return false;
//    }

//    if( !(FILE_ATTRIBUTE_HIDDEN & dwResult) ) // 如果它不是隐藏的
//    {
//        if( INVALID_FILE_ATTRIBUTES == ::SetFileAttributes( lpName, dwResult | FILE_ATTRIBUTE_HIDDEN ) )
//        {
//            return false;
//        }
//        return true;
//    }
//    else// 如果它已经是隐藏的，就当设置成功了
//    {
//        return true;
//    }
    return false;
}

QList<QString> FileUtils::getAllFiles(QString targetDir, bool suffix)
{
    QDir dir(targetDir);
    QStringList filter = dir.entryList(QDir::Files);
    if(!suffix)
        for(int i=0;i<filter.size();i++)
        {
           int set;
           set=filter[i].indexOf(".");
           filter[i]=filter[i].left(set);
        }
    return filter;
}



