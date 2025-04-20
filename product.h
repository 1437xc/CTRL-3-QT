// File: product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QDateTime>

// ��Ʒ��
class Product
{
public:
    Product(QString name, double price, QString desc, QString seller);

    QString getName() const;
    double getPrice() const;
    QString getDescription() const;
    QString getSeller() const;
    QDateTime getPublishTime() const;

private:
    QString m_name;        // ��Ʒ����
    double m_price;        // �۸�
    QString m_description; // ����
    QString m_seller;      // ����
    QDateTime m_publishTime;// ����ʱ��
};

#endif // PRODUCT_H