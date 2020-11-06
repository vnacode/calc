#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QDebug>
struct listmodelItem
{
    QString data;
    int decoratation;
};


class listmodel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(CalcRoles)
    Q_ENUMS(ColorConsole)
public:

    static listmodel *getInstance()
    {
        static listmodel instance;
        return  &instance;
    }

    enum CalcRoles {
        DataStringRole = Qt::UserRole + 1,
        DecorRole
    };

    enum ColorConsole {
        ConsoleGreen = 0,
        ConsoleBlue=1,
        ConsoleRed=2,
    };

    using QAbstractListModel::QAbstractListModel;

    QHash<int, QByteArray> roleNames() const override {
        QHash<int, QByteArray> roles;
        roles[DataStringRole] = "datavalue";
        roles[DecorRole] = "decoratation";
        return roles;
    }
    int rowCount(const QModelIndex & parent = QModelIndex()) const override {
        if (parent.isValid())
            return 0;
        return m_list.size();
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role) override
    {
        if (!hasIndex(index.row(), index.column(), index.parent()) || !value.isValid())
            return false;
        //  qDebug()<<"adds";

        listmodelItem &item = m_list[index.row()];
        if (role == DataStringRole) item.data = value.toString();
        else if (role == DecorRole) item.decoratation = value.toInt();
        else return false;

        emit dataChanged(index, index, { role } );

        return true ;

    }

    Q_SLOT void addToConsole(const QString &dat,int role)
    {

        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_list.push_back({dat,role});
        endInsertRows();
    }

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override
    {
        if (!hasIndex(index.row(), index.column(), index.parent()))
            return {};

        const listmodelItem &item = m_list.at(index.row());
        if (role == DataStringRole) return item.data;
        if (role == DecorRole) return item.decoratation;
        return {};
    }

private:
    QVector<listmodelItem> m_list ={};

};

#endif // LISTMODEL_H
