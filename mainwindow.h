// File: mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QList>
#include "product.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow(); // 关键声明
private slots:
    void on_publishButton_clicked();    // 发布商品
    void on_searchButton_clicked();     // 搜索商品
    void showProductDetails(QListWidgetItem* item); // 显示详情
    void updateRecommendations();       // 更新推荐

private:
    Ui::MainWindow* ui;
    QList<Product> m_products;          // 商品列表
    QList<Product> m_recommendations;   // 推荐商品

    void refreshProductList();          // 刷新商品列表
    void setupChatWindow();             // 初始化聊天窗口
};

#endif // MAINWINDOW_H