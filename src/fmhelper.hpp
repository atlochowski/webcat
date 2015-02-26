#ifndef FMHELPER_HPP
#define FMHELPER_HPP

#include <QtCore/QObject>
#include <QtCore/QFile>
#include <QString>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QMimeType>
#include <QUrl>

class FM : public QObject
{   Q_OBJECT
    public slots:
        void remove(const QString &url)
        {    //qDebug() << "Called the C++ slot and request removal of:" << url;
             QFile(url).remove();
        }
        QString getHome()
        {    //qDebug() << "Called the C++ slot and request removal of:" << url;
             return QDir::homePath();
        }
        QString getRoot()
        {    //qDebug() << "Called the C++ slot and request removal of:" << url;
             return QDir::rootPath();
        }
        bool existsPath(const QString &url)
        {
            return QDir(url).exists();
        }
        bool isFile(const QString &url)
        {
            return QFileInfo(url).isFile();
        }
        QString getMime(const QString &url)
        {
            QMimeDatabase db;
            QUrl path(url);
            QMimeType mime = db.mimeTypeForUrl(path);
            return mime.name();
        }
};


#endif // FMHELPER_HPP
