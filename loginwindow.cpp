#include "loginwindow.h"
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{
    m_usernameEdit = new QLineEdit(this);
    m_passwordEdit = new QLineEdit(this);
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    m_loginButton = new QPushButton("登录", this);
    m_registerButton = new QPushButton("注册", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("用户名:", this));
    layout->addWidget(m_usernameEdit);
    layout->addWidget(new QLabel("密码:", this));
    layout->addWidget(m_passwordEdit);
    layout->addWidget(m_loginButton);
    layout->addWidget(m_registerButton);

    setLayout(layout);

    connect(m_loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(m_registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterButtonClicked);
}

LoginWindow::~LoginWindow()
{
}

void LoginWindow::onLoginButtonClicked()
{
    QString username = m_usernameEdit->text();
    std::string password = m_passwordEdit->text().toStdString();
    // 这里简单模拟登录，实际应用中需要从数据库或其他存储中验证
    users user(username, 123456, password);
    emit loggedIn(user);
    close();
}

void LoginWindow::onRegisterButtonClicked()
{
    QString username = m_usernameEdit->text();
    std::string password = m_passwordEdit->text().toStdString();
    // 这里简单模拟注册，实际应用中需要将用户信息保存到数据库或其他存储中
    users user(username, 123456, password);
    QMessageBox::information(this, "注册成功", "您已成功注册！");
}
