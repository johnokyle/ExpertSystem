#include <QQmlContext>
#include <QDebug>
//#include <QMessageBox>
#include "appcontroller.h"

AppController::AppController(QObject *parent) : QObject(parent)
{

}

bool AppController::initialize()
{
    dbase = 1;    // 1 = SQLite
                  // 2 = MySql

//    setWindowIcon(QIcon("DI Icon.jpg"));

    if (dbase == 1)
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(/*QCoreApplication::applicationDirPath() +*/ "DIDB");

        autoincrement = "";
    }
    else if (dbase == 2)
    {
        QFile configFile(QCoreApplication::applicationDirPath() +"/diconfig");
        if (configFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            db = QSqlDatabase::addDatabase(configFile.readLine().replace("\n", ""));
            db.setDatabaseName(configFile.readLine().replace("\n", ""));
            db.setHostName(configFile.readLine().replace("\n", ""));
            db.setUserName(configFile.readLine().replace("\n", ""));
            db.setPassword(configFile.readLine().replace("\n", ""));

            db.setPort(configFile.readLine().replace("\n", "").toInt());

            autoincrement = "AUTO_INCREMENT";
        }


    //    db = QSqlDatabase::addDatabase("QMYSQL");

        /*************** For Michael *********/
 /*       db.setHostName("natterdidb.mysql.database.azure.com");
        db.setUserName("michaelnatter@natterdidb");
        db.setPassword("DynIMT011918"); */

        /*************** For John **************************/
    /*    db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("Glacier38");

        db.setPort(3306); */
    }
    else
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "DIServerDB");
        db.setDatabaseName("Driver={SQL Server};Server=LocalHost;Database=DIServerDB;Trusted_Connection=Yes;");
    }

//    db.setDatabaseName("DIDB");
    if (!db.open()) {
   //     QMessageBox::critical(parent, QObject::tr("Database Error"), db.lastError().text());
    //    close();
    }

    QSqlDatabase::database().commit();

    QSqlQuery query(db);

    if (db.driverName().compare("QSQLITE") == 0)
    {
    if (!query.exec("PRAGMA synchronous=OFF; " ))
      //  QMessageBox::warning(parent, QObject::tr("Pragma Error"),
          qDebug() <<                   query.lastError().text();

    if (!query.exec("PRAGMA main.page_size = 4096; " ))
      //  QMessageBox::warning(parent, QObject::tr("Pragma Error"),
        qDebug() <<                     query.lastError().text();

    if (!query.exec("PRAGMA main.cache_size=10000; "  ))
      //  QMessageBox::warning(parent, QObject::tr("Pragma Error"),
            qDebug() <<                 query.lastError().text();

    if (!query.exec("PRAGMA main.locking_mode=EXCLUSIVE; " ))
      //  QMessageBox::warning(parent, QObject::tr("Pragma Error"),
                 qDebug() <<            query.lastError().text();

    if (!query.exec("PRAGMA main.journal_mode=DELETE; " ))  // WAL
       // QMessageBox::warning(parent, QObject::tr("Pragma Error"),
                 qDebug() <<            query.lastError().text();

    if (!query.exec("PRAGMA main.cache_size=5000;" ))
      //  QMessageBox::warning(parent, QObject::tr("Pragma Error"),
               qDebug() <<              query.lastError().text();

    if (!query.exec("PRAGMA main.auto_vacuum = FULL;" ))
      //  QMessageBox::warning(parent, QObject::tr("Pragma Error"),
                qDebug() <<             query.lastError().text();

    }




    FamilyDataSource *fds = new FamilyDataSource(db, this);
    mFamilyTableModel.setDataSource(fds);
    mEngine.rootContext()->setContextProperty("familyTableModel", &mFamilyTableModel);
    mEngine.rootContext()->setContextProperty("familyDataSource", fds);

    qmlRegisterType<FamilyTableModel>("FamilyTableModel", 1, 0, "FamilyTableModel");

    qmlRegisterType<StrategyTableModel>("StrategyTableModel", 1, 0, "StrategyTableModel");

    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty()){
        return false;
    }
    else {
        return true;
    }
}
