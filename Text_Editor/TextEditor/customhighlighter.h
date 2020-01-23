#ifndef CUSTOMHIGHLIGHTER_H
#define CUSTOMHIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QObject>
#include <QTextCharFormat>
#include <QStringList>
#include <QtXml/QDomDocument>
#include <QtDebug>
#include <QFile>

class CustomHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
private:
    QString language;
public:
    explicit CustomHighlighter(const QString &language,QObject *parent = 0);
private:
    QStringList keywords;


    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QTextCharFormat tagsFormat;

    QVector<HighlightingRule> startTagRules;


private:

    void highlightBlock(const QString &text) override;
    bool isSyntax(const QString &text);
    void readXml();
    void ListElements(const QDomNode &node);
};

#endif // CUSTOMHIGHLIGHTER_H
