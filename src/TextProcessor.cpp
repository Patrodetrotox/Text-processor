#include "TextProcessor.h"

TextProcessor::TextProcessor(QObject *parent) : QObject(parent),
    _action(NoAction)
{
    QObject::connect(this, &TextProcessor::textChanged,
                     this, &TextProcessor::processedTextChanged);

    QObject::connect(this, &TextProcessor::actionChanged,
                     this, &TextProcessor::processedTextChanged);
    // ToDo: notify about processedTextChanged property change when text property changed--
    // ToDo: notify about processedTextChanged property change when action property changed--
}

QString TextProcessor::text() const
{
    return this->_text;
}

TextProcessor::Action TextProcessor::action() const
{
    return this->_action;
}

QString TextProcessor::processedText() const
{
    switch (this->_action) {
    case TextProcessor::MakeUppercase:
        return this->_text.toUpper();
    case TextProcessor::MakeLowercase:
        return this->_text.toLower();
    default:
        return this->_text;
    }
}

QString TextProcessor::prepend(const QString &string) {
    this->_text = string + this->_text;
    emit textChanged();
    // ToDo: notify about text property change --
    return this->_text;
}

void TextProcessor::setText(const QString &text)
{
    this->_text = text;
    emit textChanged();
    // ToDo: notify about text property change --
}

void TextProcessor::setAction(Action action)
{
    this->_action = action;
    emit actionChanged();
    // ToDo: notify about action property change --
}
