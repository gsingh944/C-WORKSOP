// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Gurpinder Singh
//  Student ID    : 140515206
//  Student Email : gsingh944@myseneca.ca
//  Course Section: ZEE
// ===================================================================================



#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include "ticket.h"

struct AccountTicketingData
{
	struct Account* accounts;   // Array of the accounts
	const int ACCOUNT_MAX_SIZE; // Maximum elements for account array
	struct Ticket* tickets;     // Array of the tickets
	const int TICKET_MAX_SIZE;  // Maximum elements for ticket array
};


struct Demographic {
	int birthyear;
	double houseincome;
	char country[30];

};
struct UserLogin {
	char name[40];
	char loginname[30];
	char pw[30];
	//char pwh[30];

};


struct Account {
	int acnumber;
	char acttype;
	
	struct UserLogin usl;
	struct Demographic dem;
	//char acttype2[10];
	
}; 


void pauseExecution(void);
void getAccount(struct Account* ac);
void getUserLogin(struct Account* us);
void getDemographic(struct Account* de);
void updateAccount(struct AccountTicketingData* ac, int ii, struct AccountTicketingData acb);

//-----
void Viewarchivedaccount(struct AccountTicketingData delac);
void Viewarchivedticket(struct AccountTicketingData delac);

void achcloseac(struct AccountTicketingData* ac, struct AccountTicketingData acb, struct AccountTicketingData delac);
void countSavingSessionModifications(struct AccountTicketingData ac);


#endif// !ACCOUNT_H_

