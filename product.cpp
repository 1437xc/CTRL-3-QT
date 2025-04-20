// File: product.cpp
#include "product.h"
#include <QDateTime>

// 构造函数 - 初始化商品信息
Product::Product(QString name, double price, QString desc, QString seller)
    : m_name(name),
    m_price(price),
    m_description(desc),
    m_seller(seller),
    m_publishTime(QDateTime::currentDateTime()) // 自动记录当前时间
{
}

// Getter方法 - 获取商品名称
QString Product::getName() const {
    return m_name;
}

// Getter方法 - 获取商品价格
double Product::getPrice() const {
    return m_price;
}

// Getter方法 - 获取商品描述
QString Product::getDescription() const {
    return m_description;
}

// Getter方法 - 获取卖家信息
QString Product::getSeller() const {
    return m_seller;
}

// Getter方法 - 获取发布时间
QDateTime Product::getPublishTime() const {
    return m_publishTime;
}