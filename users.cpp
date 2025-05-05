#include "users.h"
#include <QDateTime>

users::users(QString name, int id_card, string password):
    user_name(name), user_id_card(id_card), user_password(password){}


QString users::get_name()const
{
    return user_name;
}
int users::get_id_card()const
{
    return user_id_card;
}
bool users::hash_cmp(users A, users B)//没实现
{
    return false;
}
