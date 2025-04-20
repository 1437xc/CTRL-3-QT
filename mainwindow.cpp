// File: mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDateTime>

// 构造函数 - 初始化界面和信号槽
MainWindow::~MainWindow() {
    delete ui; // 必须存在的释放操作
}

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->productList, &QListWidget::itemClicked,
        this, &MainWindow::showProductDetails);

    setupChatWindow();

    // 初始化测试数据
    m_products.append(Product(QStringLiteral("二手教材"), 25.0, QStringLiteral("《Qt编程入门》九成新"), QStringLiteral("张三")));
    m_products.append(Product(QStringLiteral("自行车"), 180.0, QStringLiteral("凤凰牌山地车，带车锁"), QStringLiteral("李四")));
    refreshProductList();
}

void MainWindow::on_publishButton_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, QStringLiteral("发布商品"),
        QStringLiteral("商品名称："), QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    double price = QInputDialog::getDouble(this, QStringLiteral("价格"), QStringLiteral("请输入价格："),
        0, 0, 10000, 2, &ok);
    if (!ok) return;

    QString desc = QInputDialog::getMultiLineText(this, QStringLiteral("商品描述"),
        QStringLiteral("请详细描述商品情况："));

    Product newProduct(name, price, desc, QStringLiteral("当前用户"));
    m_products.append(newProduct);
    refreshProductList();
    updateRecommendations();
}

void MainWindow::refreshProductList()
{
    ui->productList->clear();
    foreach(const Product & product, m_products) {
        QString itemText = QString(QStringLiteral("%1\n价格：%2 元\n发布时间：%3"))
            .arg(product.getName())
            .arg(product.getPrice())
            .arg(product.getPublishTime().toString(QStringLiteral("yyyy-MM-dd hh:mm")));
        QListWidgetItem* item = new QListWidgetItem(itemText);
        ui->productList->addItem(item);
    }
}

void MainWindow::showProductDetails(QListWidgetItem* item)
{
    int index = ui->productList->row(item);
    if (index < 0 || index >= m_products.size()) return;

    const Product& product = m_products.at(index);

    QString details = QString(QStringLiteral("商品名称：%1\n价格：%2 元\n卖家：%3\n发布时间：%4\n\n商品描述：\n%5"))
        .arg(product.getName())
        .arg(product.getPrice())
        .arg(product.getSeller())
        .arg(product.getPublishTime().toString(QStringLiteral("yyyy-MM-dd hh:mm")))
        .arg(product.getDescription());

    QMessageBox::information(this, QStringLiteral("商品详情"), details);
}

void MainWindow::setupChatWindow()
{
    QWidget* chatWidget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    QTextEdit* chatHistory = new QTextEdit;
    QLineEdit* messageInput = new QLineEdit;
    QPushButton* sendButton = new QPushButton(QStringLiteral("发送"));

    chatHistory->setReadOnly(true);
    messageInput->setPlaceholderText(QStringLiteral("输入消息..."));

    QHBoxLayout* inputLayout = new QHBoxLayout;
    inputLayout->addWidget(messageInput);
    inputLayout->addWidget(sendButton);

    layout->addWidget(chatHistory);
    layout->addLayout(inputLayout);
    chatWidget->setLayout(layout);

    ui->tabWidget->addTab(chatWidget, QStringLiteral("在线聊天"));

    connect(sendButton, &QPushButton::clicked, [=]() {
        if (!messageInput->text().isEmpty()) {
            chatHistory->append(QStringLiteral("我: ") + messageInput->text());
            messageInput->clear();
        }
        });
}

void MainWindow::on_searchButton_clicked()
{
    QString keyword = ui->searchLineEdit->text().trimmed();
    if (keyword.isEmpty()) {
        refreshProductList();
        return;
    }

    QList<Product> results;
    foreach(const Product & product, m_products) {
        if (product.getName().contains(keyword, Qt::CaseInsensitive) ||
            product.getDescription().contains(keyword, Qt::CaseInsensitive))
        {
            results.append(product);
        }
    }

    ui->productList->clear();
    foreach(const Product & product, results) {
        QListWidgetItem* item = new QListWidgetItem(
            QString(QStringLiteral("%1\n价格：%2 元")).arg(product.getName()).arg(product.getPrice()));
        ui->productList->addItem(item);
    }
}

void MainWindow::updateRecommendations()
{
    m_recommendations.clear();
    int count = qMin(3, m_products.size());
    for (int i = m_products.size() - 1; i >= 0 && count > 0; --i, --count) {
        m_recommendations.append(m_products.at(i));
    }

    ui->recommendList->clear();
    foreach(const Product & product, m_recommendations) {
        QListWidgetItem* item = new QListWidgetItem(
            QString(QStringLiteral("推荐：%1\n价格：%2 元")).arg(product.getName()).arg(product.getPrice()));
        ui->recommendList->addItem(item);
    }
}