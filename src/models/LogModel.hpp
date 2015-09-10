#pragma once

#include <QObject>
#include <QString>

namespace mockup
{

class LogModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    LogModel(const QtMsgType& type, const QString& message, QObject* parent);

public slots:
    const int& type() const { return _type; }
    const QString& message() const { return _message; }
    void setType(const int& type);
    void setMessage(const QString& message);

signals:
    void typeChanged();
    void messageChanged();

private:
    int _type;
    QString _message;
};

} // namespace
