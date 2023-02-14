// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Gurpinder Singh
//  Student ID    : 140515206
//  Student Email : gsingh944@myseneca.ca
//  Course Section: ZEE
// ===================================================================================



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "account.h"
#include "accountTicketingUI.h"

void displayAccountSummaryHeader(void) {
	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
	return;
}

void displayAccountDetailHeader(void) {
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
	return;
}
void displayAccountSummaryRecord(struct AccountTicketingData ac , int ii) {
	
	if (ac.accounts[ii].acttype == 'A') {
		printf("%05d AGENT     %5d", ac.accounts[ii].acnumber,  ac.accounts[ii].dem.birthyear);
	}
	else if (ac.accounts[ii].acttype == 'C') {
		printf("%05d CUSTOMER  %5d", ac.accounts[ii].acnumber,  ac.accounts[ii].dem.birthyear);
	}
	return;
}

void displayAccountDetailRecord(struct AccountTicketingData acb, int ii) {
	//trans(&acb, ii);
	if (acb.accounts[ii].acttype == 'A') {
		printf("%05d AGENT     %5d $%10.2lf %-10s %-15s %-10s %c*%c*%c*%c*", acb.accounts[ii].acnumber, acb.accounts[ii].dem.birthyear, acb.accounts[ii].dem.houseincome, acb.accounts[ii].dem.country, acb.accounts[ii].usl.name, acb.accounts[ii].usl.loginname, acb.accounts[ii].usl.pw[0], acb.accounts[ii].usl.pw[2], acb.accounts[ii].usl.pw[4], acb.accounts[ii].usl.pw[6]);
	}
	else if (acb.accounts[ii].acttype == 'C') {
		printf("%05d CUSTOMER  %5d $%10.2lf %-10s %-15s %-10s %c*%c*%c*%c*", acb.accounts[ii].acnumber, acb.accounts[ii].dem.birthyear, acb.accounts[ii].dem.houseincome, acb.accounts[ii].dem.country, acb.accounts[ii].usl.name, acb.accounts[ii].usl.loginname, acb.accounts[ii].usl.pw[0], acb.accounts[ii].usl.pw[2], acb.accounts[ii].usl.pw[4], acb.accounts[ii].usl.pw[6]);
	}
	return;
}

int loadAccounts(struct Account* ac, int size) {
	int i = 0;
	
	
	FILE* fp = NULL;
	

	fp = fopen("accounts.txt", "r+");
	
	if (fp != NULL) {

		for (i = 0; i < size; i++) {
			fscanf(fp, "%d~%c~%[^~]~%[^~]~%[^~]~%d~%lf~%[^\n]", &ac[i].acnumber, &ac[i].acttype, ac[i].usl.name, ac[i].usl.loginname, ac[i].usl.pw, &ac[i].dem.birthyear, &ac[i].dem.houseincome, ac[i].dem.country);
			
		}

		fclose(fp);

	}

	return i;
	
}

int loadTickets(struct Ticket* TK, int size) {
	int i = 0;
	int j;
	int num = 0;
        
	
	FILE* fj = NULL;

	
	fj = fopen("tickets.txt", "r+");
	if (fj != NULL) {
		
		i = 0;
		while (i < 17) {




			fscanf(fj, "%d|%d|%d|%[^|]|%d|", &TK[i].ticketnumber, &TK[i].relatedaccountnumber, &TK[i].ticketstatuindicator, TK[i].SubjectLine, &TK[i].numberofmessages );
			
			
			
			for (j = 0; j < ((TK[i].numberofmessages)); j++) {
				
				fscanf(fj, "%c|%[^|]|%[^|]|", &TK[i].msg[j].acttype, TK[i].msg[j].name, TK[i].msg[j].messagedetail);
				
			}
			
			i++;


		}
		fclose(fj);

	}
	for (i = 0; i < 17; i++) {
		if (TK[i].ticketnumber != 0) {
			num++;
		}
	}
	return num;
}