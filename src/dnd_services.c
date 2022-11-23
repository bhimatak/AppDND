#include <dnd_services.h>
#include <common.h>

DNDService *loadDNDServ()
{
	FILE *fp = NULL;
	DNDService *newNode = NULL;
	DNDService *head = NULL;
	DNDService *tmpNode = NULL;
	
	
	int fSize = 0;
	char tmpBuff[MAXBUFF];

	fp = fopen("./data/dnd_db.csv", "r");

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
			newNode = (DNDService *)malloc(sizeof(DNDService));
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
			tokenizeDndDB(newNode, tmpBuff);
		}
	}


	fclose(fp);

	return head;
}


int tokenizeDndDB(DNDService* nn, char *tmpBuff)
{
	char *tokens = NULL;
	int i;
	
	tokens = strtok(tmpBuff, ",");
	nn->_id = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	nn->dndReg = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	nn->dndActive = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	strcpy(nn->dServices,tokens);

	tokens = strtok(NULL, ",");
	i = 0;
	while(tokens!= NULL)
	{
		strcpy(nn->dndSPhones[i], tokens);
		tokens = strtok(NULL, ",");
		i++;
	}

		
	return 0;
}


void dispDNDData(DNDService *head)
{
	while(head != NULL)
	{
		printf("\n\t%d ", head->_id);
		head = head->next;
	}
}