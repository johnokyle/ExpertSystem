#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QQmlApplicationEngine>
#include <QObject>
//#include <QSqlDatabase>
#include <QtSql>

#include "familydatasource.h"
#include "familytablemodel.h"

#include "strategytablemodel.h"


class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);
    bool initialize();

signals:

public slots:

private:
    QQmlApplicationEngine mEngine;
    FamilyTableModel mFamilyTableModel;

    int dbase;
    QSqlDatabase db;
    QString autoincrement;

};

#endif // APPCONTROLLER_H
