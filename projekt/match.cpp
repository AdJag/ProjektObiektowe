#include "match.h"

match::match()
{
}

match::match(QString name1, QString name2, QString result1, QString result2, QString time, QString quart)
{
    this->name1 = name1;
    this->name2 = name2;
    this->quart = quart;
    this->result1 = result1;
    this->result2 = result2;
    this->time = time;
}

QString match::build()
{
    return (name1+" "+result1+" : "+ name2 + " " +result2 + " " + quart + " " + time);
}
