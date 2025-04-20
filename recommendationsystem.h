// File: recommendationsystem.h
#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include "product.h"
#include <QList>

class RecommendationSystem
{
public:
    RecommendationSystem();

    QList<Product> generateRecommendations(const QList<Product>& allProducts,
        const QList<Product>& userHistory);

private:
    // ���ڹؼ���ƥ����Ƽ��㷨
    QStringList analyzeKeywords(const QList<Product>& history);
};

#endif // RECOMMENDATIONSYSTEM_H