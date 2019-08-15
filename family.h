#ifndef FAMILY_H
#define FAMILY_H

#include <QObject>

class Family : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int familyId READ getFamilyId WRITE setFamilyId NOTIFY familyIdChanged)
    Q_PROPERTY(QString familyName READ getFamilyName WRITE setFamilyName NOTIFY familyNameChanged)


public:
    explicit Family(QObject *parent = nullptr);
    Family(const int &familyId, const QString &familyName, QObject *parent = nullptr);

    int getFamilyId() const;
    QString getFamilyName() const;

    void setFamilyId(int familyId);
    void setFamilyName(QString familyName);

signals:
    void familyIdChanged(int familyId);
    void familyNameChanged(QString familyName);

public slots:

private:
    int m_familyId;
    QString m_familyName;
};

#endif // FAMILY_H
