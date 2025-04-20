// File: product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QDateTime>

// 商品类
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
    QString m_name;        // 商品名称
    double m_price;        // 价格
    QString m_description; // 描述
    QString m_seller;      // 卖家
    QDateTime m_publishTime;// 发布时间
};

#endif // PRODUCT_H