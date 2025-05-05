#include "recommend.h"
#include <QRegularExpression>

Recommend::Recommend() {}

QStringList Recommend::analyzeKeywords(const QList<Product>& history)
{
    QStringList keywords;
    QRegularExpression wordRegex("\\b\\w+\\b");

    foreach (const Product& product, history) {
        QString text = product.getName() + " " + product.getDescription();
        QRegularExpressionMatchIterator i = wordRegex.globalMatch(text);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            QString word = match.captured(0).toLower();
            if (!keywords.contains(word)) {
                keywords.append(word);
            }
        }
    }

    return keywords;
}

QList<Product> Recommend::generate_recommendations(const QList<Product>& allProducts, const QList<Product>& userHistory)
{
    QStringList keywords = analyzeKeywords(userHistory);
    QList<Product> recommendations;

    foreach (const Product& product, allProducts) {
        QString text = product.getName() + " " + product.getDescription();
        text = text.toLower();
        foreach (const QString& keyword, keywords) {
            if (text.contains(keyword) && !recommendations.contains(product)) {
                recommendations.append(product);
            }
        }
    }

    return recommendations;
}
