#include "family.h"

Family::Family(QObject *parent) : QObject(parent) //,
 //   m_familyId(-1), m_familyName("")
{

}

Family::Family(const int &familyId, const QString &familyName, QObject *parent):
    QObject(parent), m_familyId(familyId), m_familyName(familyName)
{

}

int Family::getFamilyId() const
{
    return m_familyId;
}

QString Family::getFamilyName() const
{
    return m_familyName;
}

void Family::setFamilyId(int familyId)
{
    if (m_familyId == familyId)
        return;

    m_familyId = familyId;
    emit familyIdChanged(m_familyId);
}

void Family::setFamilyName(QString familyName)
{
    if (m_familyName == familyName)
        return;

    m_familyName = familyName;
    emit familyNameChanged(m_familyName);
}
