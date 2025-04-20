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
    virtual ~MainWindow(); // �ؼ�����
private slots:
    void on_publishButton_clicked();    // ������Ʒ
    void on_searchButton_clicked();     // ������Ʒ
    void showProductDetails(QListWidgetItem* item); // ��ʾ����
    void updateRecommendations();       // �����Ƽ�

private:
    Ui::MainWindow* ui;
    QList<Product> m_products;          // ��Ʒ�б�
    QList<Product> m_recommendations;   // �Ƽ���Ʒ

    void refreshProductList();          // ˢ����Ʒ�б�
    void setupChatWindow();             // ��ʼ�����촰��
};

#endif // MAINWINDOW_H