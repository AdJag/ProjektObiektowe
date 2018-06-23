#ifndef MATCH_H
#define MATCH_H
#include <QString>


class match
{
public:
    match();
    match(QString name1, QString name2, QString result1, QString result2, QString time, QString quart);

    QString name1;
    QString name2;
    QString result1;
    QString result2;
    QString time;
    QString quart;

    QString build();
};

#endif // MATCH_H
