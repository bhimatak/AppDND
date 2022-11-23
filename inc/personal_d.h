#ifndef PERSONAL_D_H
#define PERSONAL_D_H
#include <common.h>

typedef struct personal_d
{
	int _id;
	long int phone;
	int dndReg; /* flag to indicate if registered for DND services */
	char name[30];
	struct personal_d *next;

}PersonalDB;

PersonalDB *loadPersonaldb();
int tokenizePD(PersonalDB*, char *);
void dispPersonalData(PersonalDB *);


#endif