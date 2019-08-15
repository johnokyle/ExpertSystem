#ifndef STRATEGYTABLEMODEL_H
#define STRATEGYTABLEMODEL_H

#include <QAbstractTableModel>

class StrategyTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum StrategyRoles {
        StrategyIdRole = Qt::UserRole + 1,
        StrategyNameRole
    };

public:
    explicit StrategyTableModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
};

#endif // STRATEGYTABLEMODEL_H
