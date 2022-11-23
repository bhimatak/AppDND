#ifndef LOGIN_H
#define LOGIN_H

typedef struct  login
{
	int _id;
	int uName[30];
	int uPasswd[30];
	struct login *next;
}LoginDB;

LoginDB *loadLogindb();



#endif