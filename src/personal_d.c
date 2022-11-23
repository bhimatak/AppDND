#include <personal_d.h>
#include <common.h>

PersonalDB *loadPersonaldb()
{
	FILE *fp = NULL;
	PersonalDB *newNode = NULL;
	PersonalDB *head = NULL;
	PersonalDB *tmpNode = NULL;
	
	
	int fSize = 0;
	char tmpBuff[MAXBUFF];

	fp = fopen("data/P_db.csv", "r");

	if(fp == NULL)
	{
		perror("fopen() ");
		return NULL;
	}
	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);

	fSize = ftell(fp);
	if(fSize == 0)
	{
		/* No contents are present in the file */
		return NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff, '\0', MAXBUFF);
		while(fgets(tmpBuff, MAXBUFF, fp))
		{
			newNode = (PersonalDB *)malloc(sizeof(PersonalDB));
			newNode->next = NULL;
			/* Linked List logic is implemented here */
			if(head == NULL)
			{
				head = newNode;
				tmpNode = newNode;

			}
			else
			{
				tmpNode->next = newNode;
				tmpNode = tmpNode->next;
			}
			/* end of LL */
			tokenizePD(newNode, tmpBuff);
		}
	}


	fclose(fp);

	return head;
}


int tokenizePD(PersonalDB* nn, char *tmpBuff)
{
	char *tokens = NULL;
	
	tokens = strtok(tmpBuff, ",");
	nn->_id = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	nn->phone = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	nn->dndReg = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	strcpy(nn->name,tokens);
	rLeadingWS(nn->name, nn->name);
	//welcomeScreen();
	return 0;
}


void dispPersonalData(PersonalDB *head)
{
	while(head != NULL)
	{
		printf("\n\t%d ", head->_id);
		printf("\n\t%d", head->phone);
		printf("\n\t%s ", head->name);
		head = head->next;
	}
}