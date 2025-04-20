#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QDateTime>
#include<string>
using namespace std;
class users
{
public:
	users(QString name, int idcard, string keyword);
	QString getname()const;
	int getidcard()const;
	bool hashcmp(users A, users B);
private:
	QString m_name;
	int m_idcard;
	string m_keyword;
};

#endif