#ifndef USERS_H
#define USERS_H

#include<QString>
#include<QDateTime>
#include<string>

using namespace std;

class users
{
private:
    QString user_name;      //用户名
    int user_id_card;        //账号
    string user_password;   //密码
public:
    users(QString name, int id_card, string password);
    QString get_name()const;
    int get_id_card()const;
    bool hash_cmp(users A, users B);
};

#endif // USERS_H
