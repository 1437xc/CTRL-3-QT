#ifndef RECOMMEND_H
#define RECOMMEND_H

#include "product.h"
#include <QList>

class Recommend
{
public:
    Recommend();
    QList<Product> generate_recommendations(const QList<Product>& allProducts, const QList<Product>& userHistory);

private:
    // 基于关键词匹配的推荐算法
    QStringList analyzeKeywords(const QList<Product>& history);
};

#endif
