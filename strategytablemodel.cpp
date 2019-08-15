#include "strategytablemodel.h"
#include <QDebug>

StrategyTableModel::StrategyTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant StrategyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
qDebug() << "got to HeaderData";
    // FIXME: Implement me!
    if (orientation == Qt::Horizontal /* && role == Qt::DisplayRole */) {
        switch (role)
        {
            case StrategyIdRole:
                return "ID";
            case StrategyNameRole:
                return "Strategy Name";
        default:
            return QVariant();
        }
    }

    return QVariant();
}

int StrategyTableModel::rowCount(const QModelIndex &parent) const
{
//qDebug() << "got to rowCount";
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 10;
}

int StrategyTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 1;
}

QVariant StrategyTableModel::data(const QModelIndex &index, int role) const
{
//qDebug() << "got to data " + QString::number(role);
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    switch (role) {
        case StrategyIdRole:
            return QString("StrategyId: %1, %2").arg(index.column()).arg(index.row());
        case StrategyNameRole:
            return QString("StrategyName: %1, %2").arg(index.column()).arg(index.row());
    }

    return QVariant();
}

QHash<int, QByteArray> StrategyTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[StrategyIdRole] = "strategyId";
    roles[StrategyNameRole] = "strategyName";
    return roles;
}
