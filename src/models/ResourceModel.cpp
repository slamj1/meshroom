#include "ResourceModel.hpp"
#include <QFileInfo>
#include <QDir>

namespace mockup
{

ResourceModel::ResourceModel(const QUrl& url, QObject* parent)
    : QObject(parent)
{
    setUrl(url);
}

void ResourceModel::setUrl(const QUrl& url)
{
    if(url != _url)
    {
        if(!url.isValid())
            return;
        _url = url;
        QFileInfo fileInfo(url.toLocalFile());
        setName(fileInfo.fileName());
        emit urlChanged();
    }
}

void ResourceModel::setName(const QString& name)
{
    if(name != _name)
    {
        _name = name;
        emit nameChanged();
    }
}

void ResourceModel::setIsPairImageA(const bool b)
{
    if(b != _isPairImageA)
    {
        _isPairImageA = b;
        emit isPairImageAChanged();
    }
}

void ResourceModel::setIsPairImageB(const bool b)
{
    if(b != _isPairImageB)
    {
        _isPairImageB = b;
        emit isPairImageBChanged();
    }
}

// static
bool ResourceModel::isValidUrl(const QUrl& url)
{
    if(!url.isValid())
        return false;
    QFileInfo fileInfo(url.toLocalFile());
    if(fileInfo.isDir())
        return false;
    foreach(QString e, validFileExtensions())
    {
        QString suffix = fileInfo.suffix().toLower();
        if(suffix == e.right(suffix.size()))
            return true;
    }
    return false;
}

} // namespace
