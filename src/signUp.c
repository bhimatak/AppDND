#include <signUp.h>

PersonalDB* signUp(PersonalDB* head,PersonalDB* NN)
{
    PersonalDB *tmpNode = NULL;
    PersonalDB *newNode = NULL;
    
    tmpNode = head;

    newNode = NN;//(PersonalDB *)malloc(sizeof(PersonalDB));
    newNode->next = NULL;
    
    if(head == NULL)
    {
        /* no records present */
        printf("\nin if part");
        
        head = newNode;
        tmpNode = newNode;    

    }
    else
    {
        printf("\nin else part");
        while(tmpNode->next != NULL){
            printf("\n\t%d", tmpNode->_id);
            tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;
        tmpNode = tmpNode->next;
    }

    /* ask personal details in nn and assign it */

    printf("\n\tEnter,");
    printf("\n\tID: ");
    scanf("%d",&newNode->_id);
    getchar();
    printf("\n\tName: ");
    scanf("%[^\n]s",newNode->name);
    printf("\n\tPhone Number: ");
    scanf("%ld", &newNode->phone);
    printf("\n\tdndReg");
    scanf("%d",&newNode->dndReg);// = 0;
    printf("\n!Done");
    return head;
}