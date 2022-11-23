#include <login.h>
#include <common.h>

LoginDB *loadLogindb()
{
	FILE *fp = NULL;
	LoginDB *newNode = NULL;
	LoginDB *head = NULL;
	LoginDB *tmpNode = NULL;
	
	
	int fSize = 0;
	char tmpBuff[MAXBUFF];

	fp = fopen("./data/L_db.csv", "r");

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
			newNode = (LoginDB *)malloc(sizeof(LoginDB));
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
			tokenizeLD(newNode, tmpBuff);
		}
	}


	fclose(fp);

	return head;
}


int tokenizeLD(LoginDB* nn, char *tmpBuff)
{
	char *tokens = NULL;
	
	tokens = strtok(tmpBuff, ",");
	nn->_id = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	strcpy(nn->uName,tokens);
	
	tokens = strtok(NULL, ",");
	strcpy(nn->uPasswd,tokens);
	
	return 0;
}

void dispLoginData(LoginDB *head)
{
	while(head != NULL)
	{
		printf("\n\t%d ", head->_id);
		head = head->next;
	}
}