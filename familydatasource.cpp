#include "familydatasource.h"

FamilyDataSource::FamilyDataSource(QSqlDatabase db1, QObject *parent) : QObject(parent)
{
    db = db1;
    familyQuery = "SELECT groupid, groupname "
        "FROM fundgroup "
        "ORDER BY namesort ASC " ;
    query = new QSqlQuery(db);
    rows = 0;
    filt = "";
    setFilter("");
}

void FamilyDataSource::addFamily(const QString &familyName)
{
    QSqlQuery q2(db);

//   emit preFamilyModelChanged();

    if (!q2.exec("INSERT INTO fundgroup (groupname) VALUES (" + familyName + ")"))
        qDebug() << "error = " +  q2.lastError().text();
    setFilter("");

//   emit postFamilyModelChanged();
}

void FamilyDataSource::removeFamily(int id)
{
    QSqlQuery q2(db);

//    emit preFamilyModelChanged();

    if (!q2.exec("DELETE FROM fundgroup "
                "WHERE groupid < " + QString::number(id)))
        qDebug() << "error = " +  q2.lastError().text();

    setFilter("");
//    emit postFamilyModelChanged();
}

int FamilyDataSource::familyCount()
{
    return rows;
}

void FamilyDataSource::setFilter(const QString &filter)
{
//    beginResetModel();
    emit preFamilyModelChanged();
//qDebug() << "Got to filter";

    filt = filter;
    if (!query->exec(familyQuery))
     //   QMessageBox::critical(0, QObject::tr("Group Database Error"),
                 qDebug() <<             query->lastError().text();

    rows = 0;
    while (query->next())
        rows++;

//    endResetModel();
    emit preFamilyModelChanged();

}

QVariant FamilyDataSource::data(const int row, const int column, const int role)
{
    query->seek(row);
    switch (column) {
    case 0: // family id;
        return query->value(0).toInt();
        break;
    case 1: // family name
        return query->value(1).toString();
        break;
    }
    return QVariant();
}
