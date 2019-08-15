#ifndef FAMILYDATASOURCE_H
#define FAMILYDATASOURCE_H

#include <QObject>
#include <QtSql>
#include "family.h"

class FamilyDataSource : public QObject
{
    Q_OBJECT
public:
    explicit FamilyDataSource(QSqlDatabase db, QObject *parent = nullptr);

//    void addFamily( Family *family);
    Q_INVOKABLE void addFamily(const QString &familyName);
    Q_INVOKABLE void removeFamily(int id);

    int familyCount();
    void setFilter(const QString &filter);
    QVariant data(const int row, const int column, const int role);

signals:
/*    void preFamilyAdded();
    void postFamilyAdded();
    void preFamilyRemoved(int index);
    void postFamilyRemoved();  */
    void preFamilyModelChanged();
    void postFamilyModelChanged();

public slots:
private:
    QList<Family*> mFamily;

    QSqlDatabase db;
    QSqlQuery *query;
    int rows;

    QString familyQuery;
    QString filt;
};

#endif // FAMILYDATASOURCE_H
