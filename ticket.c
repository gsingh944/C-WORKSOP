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
#include <string.h>
#include <stdlib.h>
#include "account.h"
#include "commonHelpers.h"

void Viewarchivedaccount(struct AccountTicketingData delac) {
    int i;
    int num = 0;
    for (i = 0; i < 15; i++) {
        if (delac.accounts[i].acnumber != 0)
        {
            num++;

        }
    }
    printf("\nThere are %d account(s) currently archived.\n", num);


}

void Viewarchivedticket(struct AccountTicketingData delac) {
    int i;
    //int j;
    int numberticket = 0;
    int numbermessage = 0;
    for (i = 0; i < 17; i++) {
        if (delac.tickets[i].ticketnumber != 0)
        {

            numbermessage += delac.tickets[i].numberofmessages;
            

            numberticket++;

        }
    }
    printf("\nThere are %d ticket(s) and a total of %d message(s) archived.\n", numberticket, numbermessage);


}



void achcloseac(struct AccountTicketingData* ac, struct AccountTicketingData acb, struct AccountTicketingData delac) {
    char option;
    int i;
    int j;
    int k;
    int count = 0;

     printf("\nAre you sure? This action cannot be reversed. ([Y]es|[N]o): ");
    option = getCharOption("YN");
    if (option == 'Y') {
        for (i = 0; i < 17; i++) {
            if ((acb.tickets[i].ticketstatuindicator == 0) && (acb.tickets[i].ticketnumber != 0)) {
                for (j = 0; j < 20; j++) {
                    if (delac.tickets[j].ticketnumber == 0) {
                        delac.tickets[j].ticketnumber = acb.tickets[i].ticketnumber;
                        delac.tickets[j].relatedaccountnumber = acb.tickets[i].relatedaccountnumber;
                        delac.tickets[j].ticketstatuindicator = acb.tickets[i].ticketstatuindicator;
                        strcpy(delac.tickets[j].SubjectLine, acb.tickets[i].SubjectLine);
                        delac.tickets[j].numberofmessages = acb.tickets[i].numberofmessages;
                        for (k = 0; k < acb.tickets[i].numberofmessages; k++) {
                            if ((acb.tickets[i].msg[k].acttype == 'A') || (acb.tickets[i].msg[k].acttype == 'C')) {
                                strcpy(delac.tickets[j].msg[k].name, acb.tickets[i].msg[k].name);
                                strcpy(delac.tickets[j].msg[k].messagedetail, acb.tickets[i].msg[k].messagedetail);
                                delac.tickets[j].msg[k].acttype = acb.tickets[i].msg[k].acttype;
                            }

                        }

                        count++;

                        break;

                    }
                }
                acb.tickets[i].ticketnumber = 0;

            }
        }
        printf("\n*** %d tickets archived ***\n\n", count);
    }



}


void countSavingSessionModifications(struct AccountTicketingData ac) {
    int CountAC = 0;
    int CountTK = 0;
    int i;
    for (i = 0; i < 15; i++) {
        if (ac.accounts[i].acnumber != 0) {
            CountAC++;
        }
    }
    for (i = 0; i < 17; i++) {
        if (ac.tickets[i].ticketnumber != 0) {
            CountTK++;
        }
    }
    printf("\nSaving session modifications...\n");
    printf("   %d account saved.\n", CountAC);
    printf("   %d tickets saved.", CountTK);

}