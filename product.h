#ifndef PRODUCT_H
#define PRODUCT_H

#include<Qstring>
#include<QDateTime>
class Product
{
private:
    QString m_name;            //商品名称
    double m_price;            //商品价格
    QString m_description;     //商品描述
    QString m_seller;          //卖家
    QDateTime m_publish_time;  //发布时间
public:
    Product(QString name, double price, QString desc, QString seller);

    QString getName() const;
    double getPrice() const;
    QString getDescription() const;
    QString getSeller() const;
    QDateTime getPublishTime() const;
};

#endif // PRODUCT_H
