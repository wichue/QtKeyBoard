#ifndef PINYININPUTMETHOD_H
#define PINYININPUTMETHOD_H

#include <QObject>
#include <QStringList>

class GooglePinyin: public QObject
{
    Q_OBJECT
public:
    GooglePinyin();
    ~GooglePinyin();

signals:
    void pinyinTextChanged(const QString&);

public:
    void SearchCN(const QString &gemfield);
    void BinarySearchEN(const QString &gemfield);
    void Matching(const QString &gemfield, bool isEn = true);
    QStringList HanziModel;

private:
    QStringList lstEN;
};

#endif
