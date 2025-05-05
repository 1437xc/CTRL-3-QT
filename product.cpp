#include "product.h"

Product::Product(QString name, double price, QString desc, QString seller)
    : m_name(name),
    m_price(price),
    m_description(desc),
    m_seller(seller),
    m_publish_time(QDateTime::currentDateTime()) // 自动记录当前时间
{}

QString Product::getName() const {
    return m_name;
}

double Product::getPrice() const {
    return m_price;
}

QString Product::getDescription() const {
    return m_description;
}

QString Product::getSeller() const {
    return m_seller;
}

QDateTime Product::getPublishTime() const {
    return m_publish_time;
}
