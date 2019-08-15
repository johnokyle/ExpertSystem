#include "familytablemodel.h"

FamilyTableModel::FamilyTableModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int FamilyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
//qDebug() << m_datasource->familyCount();
    return m_datasource->familyCount();
}

int FamilyTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QVariant FamilyTableModel::data(const QModelIndex &index, int role) const
{
//qDebug() << "got to data";
    if (index.row() < 0 || index.row() >= m_datasource->familyCount())
    {
        return QVariant();
    }

 //   if (role > Qt::UserRole)
   //     return m_datasource->data(index.row(), index.column(), role);

    switch (role) {
        case FamilyIdRole:
            return QString("FamilyId: %1, %2").arg(index.column()).arg(index.row());
        case FamilyNameRole:
            return QString("FamilyName: %1, %2").arg(index.column()).arg(index.row());
    }

    return QVariant();
}

QHash<int, QByteArray> FamilyTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FamilyIdRole] = "familyId";
    roles[FamilyNameRole] = "familyName";
    return roles;
}

QVariant FamilyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
//qDebug() << "got to header";
    if (orientation == Qt::Horizontal /* && role == Qt::DisplayRole */) {
        switch (role)
        {
            case FamilyIdRole:
                return "ID";
          /*  case FamilyNameRole:
                return "Family Name";*/
        default:
            return QVariant();
        }
    }

    return QVariant();
}

FamilyDataSource *FamilyTableModel::datasource() const
{
    return m_datasource;
}

void FamilyTableModel::setDataSource(FamilyDataSource *datasource)
{
    beginResetModel();
    if (m_datasource && signalConnected)
        m_datasource->disconnect(this);

    m_datasource = datasource;

    connect(m_datasource, &FamilyDataSource::preFamilyModelChanged, this, [=](){
        beginResetModel();
    });

    connect(m_datasource, &FamilyDataSource::postFamilyModelChanged, this, [=](){
        endResetModel();
    });

    endResetModel();
}

bool FamilyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "got to setData";
    return true;
}

