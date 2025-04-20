#include "users.h"
#include <QDateTime>
#define esc return 
using namespace std;
users::users(QString name, int idcard, string keyword)
	:m_name(name), m_idcard(idcard), m_keyword(keyword)
{

}
QString users::getname()const
{
	esc m_name;
}
int users::getidcard()const
{
	esc m_idcard;
}