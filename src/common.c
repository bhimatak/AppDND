#include <common.h>
#include <personal_d.h>

void welcomeScreen()
{
	printf("\n\t=====================Welcome to DND Implementation=====================\n");
}

int signUpInMenu()
{
	int ch;
	printf("\n\tPress,\n\t1. SignUp\n\t2. SingIn\n\t3. Exit");
	printf("\n\tChoice: ");

	scanf("%d",&ch);
	return ch;
}



void rLeadingWS(char *src, char *desc)
{
	int idx = 0, j, k = 0;
 	
    // Iterate String until last
    // leading space character
    while (src[idx] == ' ' || src[idx] == '\t' || src[idx] == '\n')
    {
        idx++;
    }
 
    // Run a for loop from index until the original
    // srcing ends and copy the content of src to desc
    for (j = idx; src[j] != '\0'; j++)
    {
        desc[k] = src[j];
        k++;
    }
 
    // Insert a string terminating character
    // at the end of new string
    desc[k] = '\0';
}