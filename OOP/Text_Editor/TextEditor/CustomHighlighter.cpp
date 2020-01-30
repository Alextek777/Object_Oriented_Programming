#include "customhighlighter.h"
#include <QFont>


CustomHighlighter::CustomHighlighter(const QString &language,QObject *parent):QSyntaxHighlighter(parent)
{
    this->language = language;
    readXml();
    qDebug() << "xml file successfully loaded!";

}




void CustomHighlighter::readXml()
{
    QDomDocument document;
    QFile *file;
    if(language == "C++")file = new QFile(":/keywordFiles/xml_words.xml");

    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "couldn`t open file!";
        return;
    }
    else
    {
        if(!document.setContent(file))
        {
            qDebug() << "couldn`t load document!";
            return;
        }
        file->close();
    }
    QDomElement root = document.firstChildElement();

    ListElements(root);
    HighlightingRule rule;
    tagsFormat.setForeground(Qt::blue);
    tagsFormat.setFontWeight(QFont::Bold);

    for (const QString &pattern : keywords)
    {
        rule.pattern = QRegExp(pattern);
        rule.format = tagsFormat;
        startTagRules.append(rule);
    }

}



void CustomHighlighter::ListElements(const QDomNode &node)
{
    QDomNode dom_node = node.firstChild();

    while(!dom_node.isNull())
    {
        if(dom_node.isElement())
        {
            QDomElement dom_element = dom_node.toElement();
            if(!dom_element.isNull())
            {
                if(dom_element.tagName() == "word")
                    keywords << dom_element.text();
            }
        }
        ListElements(dom_node);
        dom_node = dom_node.nextSibling();
    }
}


bool CustomHighlighter::isSyntax(const QString &text)
{
    for(int i=0;i<keywords.length();i++)
    {
        if(text == keywords[i]) return true;
    }
    return false;
}

void CustomHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat format;

    for (const HighlightingRule &rule : startTagRules)
        {
            QRegExp expression(rule.pattern);
            int index = expression.indexIn(text);
            while (index >= 0)
            {
                int length = expression.matchedLength();
                setFormat(index, length, rule.format);
                index = expression.indexIn(text, index + length);
            }
        }
}


