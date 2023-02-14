// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Gurpinder Singh
//  Student ID    : 140515206
//  Student Email : gsingh944@myseneca.ca
//  Course Section: ZEE
// ===================================================================================


#ifndef ACCOUNT_T_UI
#define ACCOUNT_T_UI
#include "ticket.h"
#include "account.h"
void displayAccountSummaryHeader(void);
void displayAccountDetailHeader(void);
void displayAccountSummaryRecord(struct AccountTicketingData ac, int ii);
void displayAccountDetailRecord(struct AccountTicketingData ac, int ii);
void applicationStartup(struct AccountTicketingData* ac);
int menuLogin(struct AccountTicketingData ac);
void ClientMainMenu(struct AccountTicketingData ac, struct AccountTicketingData* acb);
int findAccountIndexByAcctNum(int acnum, struct AccountTicketingData ac, int max, int TF);
int findticketIndexByAcctNum(int tknum, struct AccountTicketingData ac, int maxi, int TF);
int fromticketnumfindticketindex(int ticketnum, struct AccountTicketingData ac, int maxi);
void CreateNewTicket(struct AccountTicketingData* ac, int currentac);
void ModifyTicket(struct AccountTicketingData* ac, int currentac, struct AccountTicketingData ab);
void listCloseTickets(struct AccountTicketingData ac);
void manageticket(struct AccountTicketingData* ac, struct AccountTicketingData ab);

void menuAgent(struct AccountTicketingData ac, struct AccountTicketingData* acb, struct AccountTicketingData delac, struct AccountTicketingData* deleac);

int loadAccounts(struct Account* ac, int size);
int loadTickets(struct Ticket* TK, int size);
void displayAllAccountSummaryRecords(struct AccountTicketingData ac, int max);

int loadAccounts(struct Account* ac, int size);
int loadTickets(struct Ticket* TK, int size);
//void getdatafromtxt(struct AccountTicketingData* ac);


#endif


