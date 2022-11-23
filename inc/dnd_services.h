#ifndef DND_SERV_H
#define DND_SERV_H

typedef struct dnd_services
{
	int _id;
	int dndReg; /* flag to indicate if registered for DND services */
	int dndActive; /* flag to indicate if DND is active/not active */
	char dServices[256]; /* this buff will store which service user has perfered */
	char dndSPhones[10][10]; /*selective serv phone numbers if active will have numbers
								else buff will be null */
	struct dnd_services *next;
}DNDService;


DNDService *loadDNDServ();


#endif