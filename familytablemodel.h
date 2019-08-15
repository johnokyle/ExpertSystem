#ifndef FAMILYTABLEMODEL_H
#define FAMILYTABLEMODEL_H

#include <QAbstractTableModel>
//#include <QObject>
#include "family.h"
#include "familydatasource.h"

class FamilyTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum FamilyRoles {
        FamilyIdRole = Qt::UserRole + 1,
        FamilyNameRole
    };

public:
    explicit FamilyTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                    int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
//    Qt::ItemFlags flags(const QModelIndex& index) const;
    FamilyDataSource *datasource() const;
    void setDataSource(FamilyDataSource * datasource);

signals:

public slots:

private:
    FamilyDataSource * m_datasource;
    bool signalConnected {false};
};

#endif // FAMILYTABLEMODEL_H
