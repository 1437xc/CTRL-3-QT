// File: product.cpp
#include "product.h"
#include <QDateTime>

// ���캯�� - ��ʼ����Ʒ��Ϣ
Product::Product(QString name, double price, QString desc, QString seller)
    : m_name(name),
    m_price(price),
    m_description(desc),
    m_seller(seller),
    m_publishTime(QDateTime::currentDateTime()) // �Զ���¼��ǰʱ��
{
}

// Getter���� - ��ȡ��Ʒ����
QString Product::getName() const {
    return m_name;
}

// Getter���� - ��ȡ��Ʒ�۸�
double Product::getPrice() const {
    return m_price;
}

// Getter���� - ��ȡ��Ʒ����
QString Product::getDescription() const {
    return m_description;
}

// Getter���� - ��ȡ������Ϣ
QString Product::getSeller() const {
    return m_seller;
}

// Getter���� - ��ȡ����ʱ��
QDateTime Product::getPublishTime() const {
    return m_publishTime;
}