#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <QObject>
#include <QtQuick>

class TextProcessor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString text
               READ text
               WRITE setText
               NOTIFY textChanged)

    Q_PROPERTY(QString processedText
               READ processedText
               NOTIFY processedTextChanged)

    Q_PROPERTY(Action action
               READ action
               WRITE setAction
               NOTIFY actionChanged)

    // ToDo: declare text property --
    // ToDo: declare action property --
    // ToDo: declare processedText property --

public:
    enum Action { NoAction, MakeUppercase, MakeLowercase };
    Q_ENUM(Action)
    // ToDo: register Action enumeration --

    explicit TextProcessor(QObject *parent = nullptr);

    QString text() const;
    Action action() const;
    QString processedText() const;

    Q_INVOKABLE QString prepend(const QString &string);
    // ToDo: register prepend method --

signals:
    void textChanged();
    void actionChanged();
    void processedTextChanged();

public slots:
    void setText(const QString &text);
    void setAction(Action action);

private:
    QString _text;
    Action _action;
};

#endif // TEXTPROCESSOR_H
