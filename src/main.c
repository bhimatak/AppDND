#include <common.h>
#include <personal_d.h>
#include <login.h>
#include <dnd_services.h>

void *CreateNN(){
	return(malloc(sizeof(PersonalDB)));
}

int main()
{
	int ch = 0;

	DNDService *headDND = NULL;
	LoginDB *headLogin = NULL;
	PersonalDB* headPersonal = NULL;

	PersonalDB* NN = NULL;

	/* load the db if present into the respective DS */

	headPersonal = loadPersonaldb();
	headLogin = loadLogindb();
	headDND = loadDNDServ();

	dispPersonalData(headPersonal);
	
	while(1){
		welcomeScreen();
		ch = signUpInMenu();
		switch(ch)
		{
			case 1:
				NN = (PersonalDB*)CreateNN();
				headPersonal = signUp(headPersonal, NN);
				//dispPersonalData(headPersonal);
				break;
			case 2:
				//singIn(headLogin);
				break;
			case 3:
				printf("\n\tThank you for using DND Implementation Application\n\n\n");
				exit(EXIT_SUCCESS);
			default:
				printf("\n\tWrong Choice Entered\n");
		}
	}
	printf("\n\n");

	return 0;
}