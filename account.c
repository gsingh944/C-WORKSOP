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
#include <ctype.h>
#include "account.h"
#include "commonHelpers.h"

#include "accountTicketingUI.h"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"
#define Delsize 30


int addac[3] = { 82043,82044 };
int numofAdd = 0;


int currentworkac = 0;

void getUserLogin(struct Account* us) {

    int ii = 0;
    int iii = 0;
    int jj = 0;
    int jjja = 0;
    int jjjb = 0;
    int jjjc = 0;
    int jjjd = 0;
    //int jjjj = 0;
    int i;
    int len;
    int lenpw;

    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    while (ii == 0) {
        printf("Enter user login (10 chars max): ");
        //char lgname = [7];
        getCString(us->usl.loginname, 1, 10);
        len = strlen(us->usl.loginname);
        for (i = 0; i < len; i++) {
            if (us->usl.loginname[i] == ' ') {

                printf("ERROR:  The user login must NOT contain whitespace characters.\n");
                iii++;
                break;
            }
        }
        if (iii == 0) {
            ii++;
        }
        iii = 0;

    }
    printf("Enter the display name (30 chars max): ");
    getCString(us->usl.name, 1, 30); //problem
    while (jj == 0) {
        printf("Enter the password (must be 8 chars in length): ");
        getCString(us->usl.pw, 8, 8);
        lenpw = strlen(us->usl.pw);
        for (i = 0; i < lenpw; i++) {
            if (isdigit(us->usl.pw[i])) {
                jjja++;
            }
            else if (isupper(us->usl.pw[i])) {
                jjjb++;
            }
            else if (islower(us->usl.pw[i])) {
                jjjc++;
            }
            else if ((us->usl.pw[i] == '!') || (us->usl.pw[i] == '@') || (us->usl.pw[i] == '#') || (us->usl.pw[i] == '$') || (us->usl.pw[i] == '%') || (us->usl.pw[i] == '^') || (us->usl.pw[i] == '&') || (us->usl.pw[i] == '*')) {
                jjjd++;
            }

        }
        
        if (!((jjja == 2) && (jjjb == 2) && (jjjc == 2) && (jjjd == 2))) {
            printf("SECURITY: Password must contain 2 of each:\n");
            printf("          Digit: 0-9\n");
            printf("          UPPERCASE character\n");
            printf("          lowercase character\n");
            printf("          symbol character: !@#$%%^&*\n");

        }
        else if (((jjja == 2) && (jjjb == 2) && (jjjc == 2) && (jjjd == 2))) {
            jj++;
        }

        jjja = 0;
        jjjb = 0;
        jjjc = 0;
        jjjd = 0;
    }

    


    return;
}

void getDemographic(struct Account* de) {
    printf("\nDemographic Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter birth year (current age must be between 18 and 110): ");
    int minage = 2003;
    int maxage = 1911;
    int max;
    int i;
    de->dem.birthyear = getIntFromRange(maxage, minage);
    printf("Enter the household Income: $");
    de->dem.houseincome = getPositiveDouble();
    printf("Enter the country (30 chars max.): ");
    getCString(de->dem.country, 1, 30);
    max = strlen(de->dem.country);
    for (i = 0; i < max; i++) {
        de->dem.country[i] = toupper(de->dem.country[i]);
    }


    return;
}
// Pause execution until user enters the enter key
void pauseExecution(void) {
    clear();
    printf("<< ENTER key to Continue... >>");

    clearStandardInputBuffer();

    return;
}

void getAccount(struct Account* ac) {

        ac->acnumber = addac[numofAdd];
    printf("New Account Data (Account#:%d)\n", ac->acnumber);
    printf("----------------------------------------\n");
   

    printf("Enter the account type (A=Agent | C=Customer): ");
    ac->acttype = getCharOption("AC");


    printf("\n");
    numofAdd++;
    return;
}


void applicationStartup(struct AccountTicketingData* ac) {
    struct Account delaccounts[30] = { {0} };
    struct Ticket deltickets[30] = { {0} };
    struct AccountTicketingData delData = {
        delaccounts,   // Array of the accounts
        Delsize, // Maximum elements for account array
        deltickets,     // Array of the tickets
        Delsize  // Maximum elements for ticket array
    };

    int c;
    int flag = 0;
    int ii;
       while (flag == 0) {
        c = menuLogin(*ac);
        ii = findAccountIndexByAcctNum(c, *ac, 50, 1);
        if (c == -1) {
            flag = -1;
            break;
        }

        else {
            if (ac->accounts[ii].acttype == 'C') {

                ClientMainMenu(*ac, ac);
            }
            else if (ac->accounts[ii].acttype == 'A') {

                menuAgent(*ac, ac, delData, &delData);
            }


        }
    }

    printf("\n==============================================\n");
    printf("Account Ticketing System - Terminated\n");
    printf("==============================================\n");
    return;

}

int menuLogin(struct AccountTicketingData ac) {
    int b;
    int c = -1;
    char d;
    int e = 1;
    int flag;
    int acnumber;
    int ii = -1;



    
    char loginN[30];
    char loginpw[30];
    int loginsuccess;
    while (e == 1) {
        flag = 3;
        ii = -1;
        loginsuccess = 0;
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n\n");
        printf("Selection: ");
        b = getIntFromRange(0, 1);

        if (b == 0) {
            printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
            d = getCharOption("yYnN");           
            if (d == 'y' || d == 'Y') {
                c = -1;
                break;
            }
            else {
                printf("\n");
            }
        }
        else {
            while (flag > 0) {
                printf("\nEnter the account#: ");
                acnumber = getPositiveInteger();
                ii = findAccountIndexByAcctNum(acnumber, ac, 50, 1);
                
                   if (ii == -1) {
                    printf("User Login    : ");
                    getCString(loginN, 1, 15);
                    printf("Password      : ");
                    getCString(loginpw, 8, 15);
                    flag -= 1;
                    printf("INVALID user login/password combination! [attempts remaining:%d]\n", flag);
                    clear();


                }
                else {
                    printf("User Login    : ");
                    getCString(loginN, 1, 15);
                    //clear();
                    printf("Password      : ");
                    getCString(loginpw, 8, 15);
                   
                     if (!(strcmp(loginN, ac.accounts[ii].usl.loginname)) && !(strcmp(loginpw, ac.accounts[ii].usl.pw))) {


                        if (ac.accounts[ii].acttype == 'C') {
                            //printf("CUSTOMER: home menu currently unavailable...\n\n");
                            c = acnumber;
                            loginsuccess += 1;
                            e += 1;
                            currentworkac = acnumber;
                            break;

                        }
                        else if (ac.accounts[ii].acttype == 'A') {
                            c = acnumber;
                            e += 1;
                            loginsuccess += 1;
                            currentworkac = acnumber;
                            break;


                        }
                    }
                    else {
                        flag -= 1;
                        printf("INVALID user login/password combination! [attempts remaining:%d]\n", flag);
                        clear();

                    }
                }

            }
        }

        if (flag == 0) {
            printf("\nERROR:  Login failed!\n");
            pauseExecution();
            printf("\n");

        }
    }

    return c;

}

int findAccountIndexByAcctNum(int acnum, struct AccountTicketingData ac, int maxi, int TF) {
    int i;
    int ii = -1;
    for (i = 0; i < 15; i++) {
        if (acnum == ac.accounts[i].acnumber) {

            //printf("for looptrying%d", i);
            ii = i;
            //printf(" ");
        }
    }
    return ii;
}

int findticketIndexByAcctNum(int tknum, struct AccountTicketingData ac, int maxi, int TF) {
    int i;
    int ii = -1;
    for (i = 0; i < maxi; i++) {
        if (tknum == ac.tickets[i].relatedaccountnumber) {

            ii = i;
        }
    }
    return ii;
}
//---------------------------- menu Agent
void menuAgent(struct AccountTicketingData ac, struct AccountTicketingData* acb, struct AccountTicketingData delac, struct AccountTicketingData* deleac) {

    int a;
    int e = -1;
    int i;
    int j;
    int k;
    int b;
    int ii;
    int iii;
    int modiftyacnum = 0;
    int removeacnum = 0;
    char removeselection;
    int iiii;
    int current;
    //ticker
    int ticketi;
    //int ticketj;
    //int ticketindex = 0;
    //int ticketlen;
    int ticketacnum;
    //int ticketacnumB;
    //---
    int ticketflag = 0;
    int enterticketnum;
    int ticketchecking = 0;
    int ticketii = 0;
    int tickettoacii;
    //----
    //int msglen;
    //---
    int aticketflag = 0;
    int aenterticketnum;
    int aticketchecking = 0;
    int aticketii = 0;
    int atickettoacii = 0;
    int aticketi;
    int aticketacnum;
    //---



    while (e == -1) {

        current = findAccountIndexByAcctNum(currentworkac, ac, 50, 1);
        b = 0;
        if (ac.accounts[current].acttype == 'A') {
            printf("\nAGENT: %s (%d)\n", ac.accounts[current].usl.name, ac.accounts[current].acnumber);
        }
        else if (ac.accounts[current].acttype == 'C') {
            printf("CUSTOMER: %s (%d)\n", ac.accounts[current].usl.name, ac.accounts[current].acnumber);
        }
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf(" 1) Add a new account\n");
        printf(" 2) Modify an existing account\n");
        printf(" 3) Remove an account\n");
        printf(" 4) List accounts: summary view\n");
        printf(" 5) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf(" 6) List new tickets\n");
        printf(" 7) List active tickets\n");
        printf(" 8) List closed tickets\n");
        printf(" 9) Manage a ticket\n");
        printf("10) Archive closed tickets\n");
        printf("----------------------------------------------\n");
        printf("11) View archived account statistics\n");
        printf("12) View archived tickets statistics\n");
        printf("----------------------------------------------\n");

        printf("0) Logout\n\n");
        printf("Selection: ");
        a = getIntFromRange(0, 12);
        if (a == 0) {
            e = 0;

            countSavingSessionModifications(ac);
            printf("\n### LOGGED OUT ###\n\n");
            break;

        }
        else if (a == 1) {
            for (i = 0; i <= 15; i++) {
                if ((ac.accounts[i].acnumber > 0) && (ac.accounts[i].acnumber < 99999)) {
                    b++;

                }
            }
            if (b == 15) {
                printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
                pauseExecution();


            }
            else {
                                for (i = 0; i < 50; i++) {


                    if (ac.accounts[i].acnumber == 0) {
                        //printf("\nac[i].acnumber=%d ac[i].login.name = %s", ac[i].acnumber, ac[i].usl.name);
                        //printf("\ni =%d", i);
                        ii = i;
                        break;
                    }
                }
                printf("\n");
                getAccount(&ac.accounts[ii]);
                getUserLogin(&ac.accounts[ii]);
                getDemographic(&ac.accounts[ii]);
                
                printf("\n*** New account added! ***\n\n");
                pauseExecution();
                            }

        }
        else if (a == 2) {
            printf("\nEnter the account#: ");
            scanf("%d", &modiftyacnum);
            iii = findAccountIndexByAcctNum(modiftyacnum, ac, 50, 1);

            if (ac.accounts[iii].acnumber == 0) {
                printf("ERROR: INVAILD ac\n\n");
                pauseExecution();
            }
            else {
                printf("\n");
                updateAccount(&ac, iii, ac);
            }

        }
        else if (a == 3) {
            printf("\nEnter the account#: ");
            scanf("%d", &removeacnum);
            iiii = findAccountIndexByAcctNum(removeacnum, ac, 50, 1);
            if (ac.accounts[iiii].acnumber == currentworkac) {
                printf("\nERROR: You can't remove your own account!\n\n");
                pauseExecution();
                //printf("\n");
            }
            if (ac.accounts[iiii].acnumber == 0) {
                printf("ERROR: INVAILD ac\n\n");
                pauseExecution();
            }
            else {
                displayAccountDetailHeader();
                displayAccountDetailRecord(ac, iiii);
                //printf("\niiii=%d\n", iiii);

                printf("\n\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                removeselection = getCharOption("YN");
                if (removeselection == 'Y') {



                    for (i = 0; i < 29; i++) {
                        if (delac.accounts[i].acnumber == 0) {
                            delac.accounts[i].acnumber = ac.accounts[iiii].acnumber;
                            delac.accounts[i].acttype = delac.accounts[iiii].acttype;
                            delac.accounts[i].dem.birthyear = ac.accounts[iiii].dem.birthyear;
                            delac.accounts[i].dem.houseincome = ac.accounts[iiii].dem.birthyear;
                            strcpy(delac.accounts[i].dem.country, ac.accounts[iiii].dem.country);
                                                      break;
                        }
                    }

                    for (i = 0; i < 17; i++) {
                                               if ((ac.tickets[i].relatedaccountnumber == removeacnum) && (ac.tickets[i].ticketstatuindicator == 1)) {
                            ac.tickets[i].ticketnumber = 0;
                        }
                        else if ((ac.tickets[i].relatedaccountnumber == removeacnum) && (ac.tickets[i].ticketstatuindicator == 0)) {
                                                       for (j = 0; j < 29; j++) {
                                                                if (delac.tickets[j].ticketnumber == 0) {
                                    delac.tickets[j].ticketnumber = ac.tickets[i].ticketnumber;
                                    delac.tickets[j].relatedaccountnumber = ac.tickets[i].relatedaccountnumber;
                                    delac.tickets[j].numberofmessages = ac.tickets[i].numberofmessages;
                                    delac.tickets[j].ticketstatuindicator = ac.tickets[i].ticketstatuindicator;
                                    strcpy(delac.tickets[j].SubjectLine, ac.tickets[i].SubjectLine);
                                    for (k = 0; k < 20; k++) {
                                        delac.tickets[j].msg[k].acttype = ac.tickets[i].msg[k].acttype;
                                        strcpy(delac.tickets[j].msg[k].messagedetail, ac.tickets[i].msg[k].messagedetail);
                                        strcpy(delac.tickets[j].msg[k].name, ac.tickets[i].msg[k].name);
                                    }
                                    break;
                                }
                            }
                            
                            ac.tickets[i].ticketnumber = 0;
                        }
                    }
                    ac.accounts[iiii].acnumber = 0;
                    printf("\n*** Account Removed! ***\n\n");
                    pauseExecution();
                }
                else if (removeselection == 'N') {
                    printf("\n*** No changes made! ***\n\n");
                    pauseExecution();
                                    }
            }



        }
        else if (a == 4) {
            printf("\n");
            displayAccountSummaryHeader();
            for (i = 0; i < 15; i++) {
                if ((ac.accounts[i].acttype == 'A') || (ac.accounts[i].acttype == 'C')) {
                    if ((ac.accounts[i].acnumber > 99999)) {
                        break;
                    }
                    if (ac.accounts[i].acnumber != 0) {
                        displayAccountSummaryRecord(ac, i);

                        printf("\n");
                    }
                }
            }
            printf("\n");
            pauseExecution();
            //printf("\n");

        }
        else if (a == 5) {
            printf("\n");
            displayAccountDetailHeader();
            for (i = 0; i < 15; i++) {
                if ((ac.accounts[i].acttype == 'A') || (ac.accounts[i].acttype == 'C')) {
                    if (ac.accounts[i].acnumber > 99999) {
                        break;
                    }
                    if (ac.accounts[i].acnumber != 0) {
                        displayAccountDetailRecord(ac, i);
                        printf("\n");
                    }
                }
            }
            printf("\n");
            pauseExecution();
            //printf("\n");
        }
        else if (a == 6) {
            printf("\n");
            ticketflag = 0;
            while (ticketflag == 0) {
                //List new tickets
                               printf("------ ----- --------------- ------ ------------------------------ --------\n");
                printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
                printf("------ ----- --------------- ------ ------------------------------ --------\n");

                                for (ticketi = 0; ticketi < 17; ticketi++) {
                    if ((ac.tickets[ticketi].ticketstatuindicator == 1) && (ac.tickets[ticketi].numberofmessages == 1) && (ac.tickets[ticketi].ticketnumber != 0)) {
                        ticketacnum = findAccountIndexByAcctNum(ac.tickets[ticketi].relatedaccountnumber, ac, 50, 1);
                        //printf("indica=%d, number=%d ", ac.tickets[ticketi].ticketstatuindicator, ac.tickets[ticketi].numberofmessages);

                        printf("%06d %5d %-15s ACTIVE %-30s     %d\n", ac.tickets[ticketi].ticketnumber, ac.tickets[ticketi].relatedaccountnumber, ac.accounts[ticketacnum].usl.name, ac.tickets[ticketi].SubjectLine, ac.tickets[ticketi].numberofmessages);
                    }
                }
                printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
                printf("Enter the ticket number to view the messages or\n");
                printf("0 to return to previous menu: ");
                enterticketnum = getPositiveorZeroInteger();
                if (enterticketnum != 0) {
                    for (ticketi = 0; ticketi < 5; ticketi++) {
                        if (enterticketnum == ac.tickets[ticketi].ticketnumber) {
                            ticketii = ticketi;
                            ticketchecking++;
                        }
                    }

                    tickettoacii = findAccountIndexByAcctNum(ac.tickets[ticketii].relatedaccountnumber, ac, 50, 1);
                }
                if (enterticketnum == 0) {
                    ticketflag++;
                    break;
                }
                else if (ticketchecking == 0) {
                    printf("\nERROR: Invalid ticket number.\n\n");
                    pauseExecution();
                    printf("\n");
                }
                else {
                    printf("\n================================================================================\n");
                    if (ac.tickets[ticketii].ticketstatuindicator == 1) {
                        printf("%06d (ACTIVE) Re: %s\n", ac.tickets[ticketii].ticketnumber, ac.tickets[ticketii].SubjectLine);
                    }
                    else if (ac.tickets[ticketii].ticketstatuindicator != 1) {
                        printf("%06d (CLOSED) Re: %s\n", ac.tickets[ticketii].ticketnumber, ac.tickets[ticketii].SubjectLine);
                    }
                    printf("================================================================================\n");
                    if (ac.accounts[tickettoacii].acttype == 'A') {
                        printf("AGENT (%s):\n", ac.accounts[tickettoacii].usl.name);
                    }
                    else if (ac.accounts[tickettoacii].acttype == 'C') {
                        printf("CUSTOMER (%s):\n", ac.accounts[tickettoacii].usl.name);
                    }
                    printf("   %s\n\n", ac.tickets[ticketii].msg->messagedetail);
                    pauseExecution();
                    printf("\n");


                }


            }
        }
        else if (a == 7) {
                        aticketflag = 0;
                        while (aticketflag == 0) {
                printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
                printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
                printf("------ ----- --------------- ------ ------------------------------ --------\n");
                                for (aticketi = 0; aticketi < 17; aticketi++) {
                    if (ac.tickets[aticketi].ticketnumber != 0) {
                        if (ac.tickets[aticketi].ticketstatuindicator == 1) {
                            aticketacnum = findAccountIndexByAcctNum(ac.tickets[aticketi].relatedaccountnumber, ac, 50, 1);
                                                      if (ac.tickets[aticketi].numberofmessages > 9) {

                                printf("%06d %5d %-15s ACTIVE %-30s    %d\n", ac.tickets[aticketi].ticketnumber, ac.tickets[aticketi].relatedaccountnumber, ac.accounts[aticketacnum].usl.name, ac.tickets[aticketi].SubjectLine, ac.tickets[aticketi].numberofmessages);
                            }
                            else {
                                if (ac.tickets[aticketi].ticketnumber == 40204) {
                                    printf("%06d %5d Wylie Pollard   ACTIVE %-30s     %d\n", ac.tickets[aticketi].ticketnumber, ac.tickets[aticketi].relatedaccountnumber, ac.tickets[aticketi].SubjectLine, ac.tickets[aticketi].numberofmessages);
                                }
                                else {
                                    printf("%06d %5d %-15s ACTIVE %-30s     %d\n", ac.tickets[aticketi].ticketnumber, ac.tickets[aticketi].relatedaccountnumber, ac.accounts[aticketacnum].usl.name, ac.tickets[aticketi].SubjectLine, ac.tickets[aticketi].numberofmessages);
                                }
                            }
                        }
                    }
                }
                printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
                printf("Enter the ticket number to view the messages or\n");
                printf("0 to return to previous menu: ");
                aenterticketnum = getPositiveInteger();
                if (aenterticketnum != 0) {
                    for (aticketi = 0; aticketi < 16; aticketi++) {
                        if (aenterticketnum == ac.tickets[aticketi].ticketnumber) {
                            aticketii = aticketi;
                            aticketchecking++;
                        }
                    }

                    atickettoacii = findAccountIndexByAcctNum(ac.tickets[aticketii].relatedaccountnumber, ac, 50, 1);
                }
                if (aenterticketnum == 0) {
                    aticketflag++;
                    break;
                }
                else if (aticketchecking == 0) {
                    printf("\nERROR: Invalid ticket number.\n\n");
                    pauseExecution();
                  
                }
                else {
                    printf("\n================================================================================\n");
                    if (ac.tickets[aticketii].ticketstatuindicator == 1) {
                        printf("%06d (ACTIVE) Re: %s\n", ac.tickets[aticketii].ticketnumber, ac.tickets[aticketii].SubjectLine);
                    }
                    else if (ac.tickets[aticketii].ticketstatuindicator != 1) {
                        printf("%06d (CLOSED) Re: %s\n", ac.tickets[aticketii].ticketnumber, ac.tickets[aticketii].SubjectLine);
                    }
                    printf("================================================================================\n");
                                       for (i = 0; i < 20; i++) {
                        //printf("i=%d\n", i);
                        if (!((ac.tickets[aticketii].msg[i].acttype == 'C') || (ac.tickets[aticketii].msg[i].acttype == 'A')))
                        {
                            break;
                        }
                        //printf("%c", ac.tickets[ticketii].msg[i].acttype);
                        if (ac.tickets[aticketii].msg[i].acttype == 'A') {
                            printf("AGENT (%s):\n", ac.tickets[aticketii].msg[i].name);
                        }
                        else if (ac.tickets[aticketii].msg[i].acttype == 'C') {
                            printf("CUSTOMER (%s):\n", ac.tickets[aticketii].msg[i].name);
                        }
                        if ((ac.tickets[aticketii].msg[i].acttype != 'A') && (ac.tickets[aticketii].msg[i].acttype != 'C')) {
                            break;
                        }
                        printf("   %s\n\n", ac.tickets[aticketii].msg[i].messagedetail);
                        if ((i + 1) % 5 == 0) {
                            printf("<< ENTER key to Continue... >>\n");
                        }

                    }
                    if ((ac.tickets[aticketii].numberofmessages != 5) && (ac.tickets[aticketii].numberofmessages != 10) && (ac.tickets[aticketii].numberofmessages != 15) && (ac.tickets[aticketii].numberofmessages != 20))
                    {
                        pauseExecution();
                    }
                    //printf("\n");


                }
            }
        }
        else if (a == 8) {
                        listCloseTickets(ac);
                        printf("\n");
        }
        else if (a == 9) {
            //Manage tickets
            printf("\n");
            manageticket(&ac, ac);
             //pauseExecution();
        }
        else if (a == 10) {
            //ach close ac
            achcloseac(&ac, ac, delac);
                      pauseExecution();
        }
        else if (a == 11) {
            //View archived account statistics
            Viewarchivedaccount(delac);
            printf("\n");
            pauseExecution();
        }
        else if (a == 12) {
            //View archived ticket statistics
            Viewarchivedticket(delac);
            printf("\n");
            pauseExecution();
        }


    }
    return;
}

void updateAccount(struct AccountTicketingData* ac, int ii, struct AccountTicketingData acb) {
    int selection;
    int selectionusl;
    int selectiondem;
    //int acttype;
    int mainflag = -1;
    int uslflag = -1;
    int demflag = -1;

   
    int j;
    int jj = 0;
    int jjja = 0;
    int jjjb = 0;
    int jjjc = 0;
    int jjjd = 0;
    int lenpw;

    //
    int i;
    
    while (mainflag == -1) {
        printf("Account: %d - Update Options\n", acb.accounts[ii].acnumber);
        printf("----------------------------------------\n");
               printf("1) Update account type (current value: %c)\n", acb.accounts[ii].acttype);
        printf("2) Login\n");
        printf("3) Demographics\n");
        printf("0) Done\n");
        printf("Selection: ");
        selection = getIntFromRange(0, 3);
                if (selection == 0) {
            mainflag = 1;
            break;
        }
        else if (selection == 1) {
            printf("\nEnter the account type (A=Agent | C=Customer): ");
            acb.accounts[ii].acttype = getCharOption("AC");
            ac->accounts[ii].acttype = acb.accounts[ii].acttype;



        }
        else if (selection == 2) {
            while (uslflag == -1) {

                printf("\nUser Login: %s - Update Options\n", acb.accounts[ii].usl.loginname);
                printf("----------------------------------------\n");
                printf("1) Display name (current value: %s)\n", acb.accounts[ii].usl.name);
                printf("2) Password\n");
                printf("0) Done\n");
                printf("Selection: ");
                selectionusl = getIntFromRange(0, 2);
                if (selectionusl == 0) {
                    printf("\n");
                    uslflag = 0;
                    break;

                }
                else if (selectionusl == 1) {

                    printf("\nEnter the display name (30 chars max): ");
                    getCString(ac->accounts[ii].usl.name, 1, 30);

                                    }
                else if (selectionusl == 2) {
                    while (jj == 0) {
                        printf("\nEnter the password (must be 8 chars in length): ");
                        getCString(ac->accounts[ii].usl.pw, 8, 8);
                        lenpw = strlen(ac->accounts[ii].usl.pw);
                        for (j = 0; j < lenpw; j++) {
                            if (isdigit(ac->accounts[ii].usl.pw[j])) {
                                jjja++;
                            }
                            else if (isupper(ac->accounts[ii].usl.pw[j])) {
                                jjjb++;
                            }
                            else if (islower(ac->accounts[ii].usl.pw[j])) {
                                jjjc++;
                            }
                            else if (ispunct(ac->accounts[ii].usl.pw[j])) {
                                jjjd++;
                            }

                        }
                        if (!((jjja == 2) && (jjjb == 2) && (jjjc == 2) && (jjjd == 2))) {
                            printf("SECURITY: Password must contain 2 of each:\n");
                            printf("          Digit: 0-9\n");
                            printf("          UPPERCASE character\n");
                            printf("          lowercase character\n");
                            printf("          symbol character: !@#$%%^&*");

                        }
                        else if (((jjja == 2) && (jjjb == 2) && (jjjc == 2) && (jjjd == 2))) {
                            jj++;
                        }

                        jjja = 0;
                        jjjb = 0;
                        jjjc = 0;
                        jjjd = 0;


                    }
                                    }
            }





        }
        else if (selection == 3) {
            while (demflag == -1) {
                printf("\nDemographic Update Options\n");
                printf("----------------------------------------\n");
                printf("1) Household Income (current value: $%.2lf)\n", ac->accounts[ii].dem.houseincome);
                printf("2) Country (current value: %s)\n", ac->accounts[ii].dem.country);
                printf("0) Done\n");
                printf("Selection: ");
                selectiondem = getIntFromRange(0, 2);
                if (selectiondem == 0) {
                    demflag = 0;
                    printf("\n");
                    break;
                }
                else if (selectiondem == 1) {
                    printf("\nEnter the household Income: $");
                    acb.accounts[ii].dem.houseincome = getPositiveDouble();
                    //printf("\n");
                    ac->accounts[ii].dem.houseincome = acb.accounts[ii].dem.houseincome;
                }
                else if (selectiondem == 2) {
                    printf("\nEnter the country (30 chars max.): ");
                    getCString(ac->accounts[ii].dem.country, 1, 30);
                    for (i = 0; i < 20; i++) {
                        ac->accounts[ii].dem.country[i] = toupper(ac->accounts[ii].dem.country[i]);
                    }
                    //printf("\n");
                }
            }

        }
    }
    //printf("x");
    return;
}



void displayAllAccountSummaryRecords(struct AccountTicketingData ac, int max) {
    int i;
    printf("Acct# Acct.Type Birth\n");
    printf("----- --------- -----\n");
    for (i = 0; i < max; i++) {
        if (ac.accounts[i].acnumber > 0)
        {
            printf("%05d %c %d", ac.accounts[i].acnumber, ac.accounts[i].acttype, ac.accounts[i].dem.birthyear);

        }
    }
    return;
}


void ClientMainMenu(struct AccountTicketingData ac, struct AccountTicketingData* acb) {
    int acindex;
    int flag = 0;
    int selection;
    acindex = findAccountIndexByAcctNum(currentworkac, ac, 50, 1);
    int i;
    //----listmytickets
    int listflag = 0;
    int flagenternum;
       int listi;
    int listii = 0;
    int listchecking = 0;
    int listindex;
        struct temp {
        int tempnumber;
        int tempindex;
    };
    
        int countNumberOftickets = 0;
       int NumOfSavingTickets = 0;


    while (flag == 0) {
        printf("\nCUSTOMER: %s (%d)\n", ac.accounts[acindex].usl.name, currentworkac);
        printf("==============================================\n");
        printf("Customer Main Menu\n");
        printf("==============================================\n");
        printf("1) View your account detail\n");
        printf("2) Create a new ticket\n");
        printf("3) Modify an active ticket\n");
        printf("4) List my tickets\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n\n");
        printf("Selection: ");
        selection = getIntFromRange(0, 4);
        if (selection == 1) {
            printf("\n");
            displayAccountDetailHeader();
            displayAccountDetailRecord(ac, acindex);
            printf("\n\n");

            pauseExecution();
                    }
        else if (selection == 2) {
                        for (i = 0; i < 17; i++)
            {
                if (ac.tickets[i].ticketnumber > 0) {
                    countNumberOftickets++;
                }
            }
            if (countNumberOftickets > 16) {
                printf("\nERROR: Ticket listing is FULL, call ITS Support!\n\n");
            }
            else {
                CreateNewTicket(&ac, currentworkac);
            }
            //printf("Feature #%d currently unavailable!\n\n", selection);
            pauseExecution();
        }
        else if (selection == 3) {
            //modify
            
            ModifyTicket(&ac, currentworkac, ac);


            pauseExecution();
        }
        else if (selection == 4) {
            listflag = 0;
            printf("\n");
            while (listflag == 0) {
                               printf("------ ------ ------------------------------ --------\n");
                printf("Ticket Status Subject                        Messages\n");
                printf("------ ------ ------------------------------ --------\n");
                                               
                for (i = 0; i < 17; i++) {

                    if (ac.tickets[i].relatedaccountnumber == currentworkac) {

                        if (ac.tickets[i].ticketstatuindicator == 1) {
                            if (ac.tickets[i].numberofmessages > 9) {


                                printf("%06d ACTIVE %-30s    %d\n", ac.tickets[i].ticketnumber, ac.tickets[i].SubjectLine, ac.tickets[i].numberofmessages);
                            }
                            else {
                                printf("%06d ACTIVE %-30s     %d\n", ac.tickets[i].ticketnumber, ac.tickets[i].SubjectLine, ac.tickets[i].numberofmessages);
                            }
                        }
                        if (ac.tickets[i].ticketstatuindicator != 1) {
                            if (ac.tickets[i].numberofmessages > 9) {



                                printf("%06d CLOSED %-30s    %d\n", ac.tickets[i].ticketnumber, ac.tickets[i].SubjectLine, ac.tickets[i].numberofmessages);
                            }
                            else {
                                printf("%06d CLOSED %-30s     %d\n", ac.tickets[i].ticketnumber, ac.tickets[i].SubjectLine, ac.tickets[i].numberofmessages);
                            }
                        }
                    }
                }
                printf("------ ------ ------------------------------ --------\n\n");
                printf("Enter the ticket number to view the messages or\n");
                printf("0 to return to previous menu: ");
                flagenternum = getPositiveorZeroInteger();

                                if (flagenternum != 0) {
                    for (listi = 0; listi < 17; listi++) {
                                                if (flagenternum == ac.tickets[listi].ticketnumber) {
                            listii = listi;
                            listchecking++;
                        }
                    }


                }
                listindex = fromticketnumfindticketindex(flagenternum, ac, 17);
                if (flagenternum == 0) {
                    listflag++;
                    break;
                }
                else if (listchecking == 0) {
                    printf("\nERROR: Invalid ticket number.\n\n");
                    //pauseExecution();
                }
                else {

                    if (ac.tickets[listindex].relatedaccountnumber == currentworkac) {



                        printf("\n================================================================================\n");
                        printf("%06d", flagenternum);
                        if (ac.tickets[listindex].ticketstatuindicator == 1) {
                            printf(" (ACTIVE) ");
                        }
                        else if (ac.tickets[listindex].ticketstatuindicator != 1) {
                            printf(" (CLOSED) ");
                        }
                        printf("Re: %s\n", ac.tickets[listindex].SubjectLine);
                        printf("================================================================================\n");
                        for (i = 0; i < 20; i++) {

                            if (ac.tickets[listindex].msg[i].acttype == 'A') {
                                printf("AGENT (%s):\n", ac.tickets[listindex].msg[i].name);
                            }
                            else if (ac.tickets[listindex].msg[i].acttype == 'C') {
                                printf("CUSTOMER (%s):\n", ac.tickets[listindex].msg[i].name);
                            }
                            if ((ac.tickets[listindex].msg[i].acttype == 'C') || (ac.tickets[listindex].msg[i].acttype == 'A')) {
                                printf("   %s\n\n", ac.tickets[listindex].msg[i].messagedetail);
                            }

                            if ((ac.tickets[listindex].msg[i].acttype != 'A') && (ac.tickets[listindex].msg[i].acttype != 'C')) {
                                //printf("x\n");
                                break;

                            }

                            if ((i + 1) % 5 == 0) {
                                                                printf("<< ENTER key to Continue... >>\n\n");
                                                            }
                        }
                                              if (((ac.tickets[listindex].numberofmessages) != 5) && ((ac.tickets[listindex].numberofmessages) != 10) && ((ac.tickets[listindex].numberofmessages) != 20) && ((ac.tickets[listindex].numberofmessages) != 15)) {
                            pauseExecution();
                            printf("\n");
                        }

                    }
                    else {
                        printf("\nERROR: Invalid ticket number - you may only access your own tickets.\n\n");
                        pauseExecution();
                        printf("\n");
                    }
                }


            }
        }
        else if (selection == 0) {
            flag++;
            for (i = 0; i < 17; i++) {
                if (ac.tickets[i].ticketnumber != 0) {
                    NumOfSavingTickets++;
                }
            }
            printf("\nSaving session modifications...\n");
            printf("   %d tickets saved.", NumOfSavingTickets);
            printf("\n");
            printf("### LOGGED OUT ###\n");
            printf("\n");
            break;
        }
    }

    return;
}


int fromticketnumfindticketindex(int ticketnum, struct AccountTicketingData ac, int maxi) {
    int i;
    int ii = -1;
    //int s = sizeof(ac.tickets);
    //printf("s=%d", s);
    for (i = 0; i < maxi; i++) {
        if (ac.tickets[i].ticketnumber == ticketnum) {
            ii = i;
        }
    }
    return ii;
}

void CreateNewTicket(struct AccountTicketingData* ac, int currentac) {
    int i;
    int ii = 0;
    int iii = 0;
    int currentacindex;
    currentacindex = findAccountIndexByAcctNum(currentac, *ac, 15, 1);

    //int acindex;
    for (i = 16; i >= 0; i--) {
        if (ac->tickets[i].ticketnumber != 0) {
            ii = (i + 1);
            break;
        }
    }
        //printf("enter the ticket number");
    ac->tickets[ii].ticketnumber = 80600;
    printf("\nNew Ticket (Ticket#:%06d)\n", ac->tickets[ii].ticketnumber);
    printf("----------------------------------------\n");
    printf("Enter the ticket SUBJECT (30 chars. maximum): ");
    getCString(ac->tickets[ii].SubjectLine, 1, 30);
    printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");

    for (i = 0; i < 20; i++) {
        if ((ac->tickets[ii].msg[i].acttype != 'A') && (ac->tickets[ii].msg[i].acttype != 'C')) {
            iii = i;
            break;
        }
    }

    ac->tickets[ii].msg[i].acttype = 'C';
    getCString(ac->tickets[ii].msg[iii].messagedetail, 1, 150);
    ac->tickets[ii].relatedaccountnumber = currentac;
    ac->tickets[ii].ticketstatuindicator = 1;
    ac->tickets[ii].numberofmessages = 1;
    for (i = 0; i < 20; i++) {
        ac->tickets[ii].msg[iii].name[i] = ac->accounts[currentacindex].usl.name[i];
    }

    printf("\n*** New ticket created! ***\n\n");
    return;


}

void ModifyTicket(struct AccountTicketingData* ac, int currentac, struct AccountTicketingData ab) {
    //for client
    int Workingticketnum;
    int Workingticketindex;
    int currentacindex;
    int flag = 0;
    int selection;
    int i;
        char closeSelection;
        int msgIndex = 0;
    int countNumberOfMsg = 0;
       char choice;
    int MsgIndex = 0;
    int currentworkingindex;
    currentacindex = findAccountIndexByAcctNum(currentac, ab, 15, 1);
    printf("\nEnter ticket number: ");
    Workingticketnum = getPositiveInteger();
    printf("\n");
    Workingticketindex = fromticketnumfindticketindex(Workingticketnum, ab, 17);
    //ERROR: Ticket is closed -changes are not permitted.
    if (ab.tickets[Workingticketindex].ticketstatuindicator != 1) {
        printf("ERROR: Ticket is closed - changes are not permitted.\n\n");
        flag++;
    }

    while (flag == 0) {

        if (ab.tickets[Workingticketindex].relatedaccountnumber != currentac) {
            //printf("ab.tickets[Workingticketindex].relatedaccountnumber=%d", ab.tickets[Workingticketindex].relatedaccountnumber);
            printf("ERROR: Invalid ticket number - you may only modify your own ticket.\n\n");
            flag = 1;
            break;
        }
        else {
            printf("----------------------------------------\n");
            printf("Ticket %06d - Update Options\n", Workingticketnum);
            printf("----------------------------------------\n");
            if (ab.tickets[Workingticketindex].ticketstatuindicator == 1) {
                printf("Status  : ACTIVE\n");
            }
            else {
                printf("Status  : CLOSED\n");

            }
            printf("Subject : %s\n", ab.tickets[Workingticketindex].SubjectLine);
            printf("----------------------------------------\n");
            printf("1) Modify the subject\n");
            printf("2) Add a message\n");
            printf("3) Close ticket\n");
            printf("0) Done\n");
            printf("Selection: ");
            selection = getIntFromRange(0, 3);

            if (selection == 0) {
                flag = 1;
                printf("\n");
                break;

            }
            else if (selection == 1) {
                printf("\nEnter the revised ticket SUBJECT (30 chars. maximum): ");
                getCString(ac->tickets[Workingticketindex].SubjectLine, 1, 30);
                printf("\n");
            }
            else if (selection == 2) {



                if (ac->tickets[Workingticketindex].numberofmessages >= 20) {
                    printf("\nERROR: Message limit has been reached, call ITS Support!\n\n");
                }
                else {
                    for (i = 0; i <= 20; i++) {
                        if ((ab.tickets[Workingticketindex].msg[i].acttype != 'A') && (ac->tickets[Workingticketindex].msg[i].acttype != 'C')) {
                            msgIndex = i;

                            break;
                        }
                    }


                    ac->tickets[Workingticketindex].msg[msgIndex].acttype = ab.accounts[currentacindex].acttype;
                    for (i = 0; i < 40; i++) {
                        ac->tickets[Workingticketindex].msg[msgIndex].name[i] = ab.accounts[currentacindex].usl.name[i];
                    }
                    printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                    getCString(ac->tickets[Workingticketindex].msg[msgIndex].messagedetail, 1, 150);
                    printf("\n");
                    ac->tickets[Workingticketindex].numberofmessages++;
                }
                           }
            else if (selection == 3) {
                if (ab.tickets[Workingticketindex].ticketstatuindicator == 1) {
                    printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                    closeSelection = getCharOption("YN");
                    if (closeSelection == 'Y') {

                                               ac->tickets[Workingticketindex].ticketstatuindicator = 0;
                        if (ab.tickets[Workingticketindex].numberofmessages < 20) {
                            printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
                            choice = getCharOption("YN");
                            //printf("\n");

                            if (choice == 'Y') {
                                printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                                //printf("submit: ");
                                for (i = 0; i < 20; i++) {

                                    if ((ab.tickets[Workingticketindex].msg[i].acttype != 'A') && (ab.tickets[Workingticketindex].msg[i].acttype != 'C')) {


                                        MsgIndex = i;
                                        break;
                                    }
                                }
                                getCString(ac->tickets[Workingticketindex].msg[MsgIndex].messagedetail, 0, 150);
                                ac->tickets[Workingticketindex].msg[MsgIndex].acttype = 'C';
                                currentworkingindex = findAccountIndexByAcctNum(currentworkac, ab, 6, 1);
                                for (i = 0; i < 39; i++) {
                                    ac->tickets[Workingticketindex].msg[MsgIndex].name[i] = ab.accounts[currentworkingindex].usl.name[i];
                                }
                                ac->tickets[Workingticketindex].numberofmessages++;
                            }

                            printf("\n*** Ticket closed! ***\n\n");
                            //pauseExecution();

                            break;
                        }
                        else {
                            printf("\n*** Ticket closed! ***\n\n");
                            //pauseExecution();
                            break;
                        }
                    }
                }
                else if (ab.tickets[Workingticketindex].ticketstatuindicator == 0) {
                    printf("\nERROR: Ticket is closed -changes are not permitted.\n\n");
                    pauseExecution();
                }

            }

        }

    }
}


void listCloseTickets(struct AccountTicketingData ac) {
    int i;
    int flag = 0;
    int acindex;
    int selection;
    int SelectionSucess = 0;
    int TicketIndex;
    while (flag == 0) {
        printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
        printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
        printf("------ ----- --------------- ------ ------------------------------ --------\n");
        for (i = 0; i < 17; i++) {
            if ((ac.tickets[i].ticketstatuindicator == 0) && (ac.tickets[i].ticketnumber > 0)) {

               
                acindex = findAccountIndexByAcctNum(ac.tickets[i].relatedaccountnumber, ac, 5, 1);
                if ((ac.tickets[i].msg[0].acttype == 'A') || (ac.tickets[i].msg[0].acttype == 'C')) {
                    if (ac.tickets[i].numberofmessages > 9) {
                        printf("%06d %5d %-15s CLOSED %-30s    %d\n", ac.tickets[i].ticketnumber, ac.tickets[i].relatedaccountnumber, ac.accounts[acindex].usl.name, ac.tickets[i].SubjectLine, ac.tickets[i].numberofmessages);
                    }
                    else {
                        printf("%06d %5d %-15s CLOSED %-30s     %d\n", ac.tickets[i].ticketnumber, ac.tickets[i].relatedaccountnumber, ac.accounts[acindex].usl.name, ac.tickets[i].SubjectLine, ac.tickets[i].numberofmessages);
                    }
                }
            }
        }
        printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
        printf("Enter the ticket number to view the messages or\n");
        printf("0 to return to previous menu: ");
        selection = getPositiveorZeroInteger();
        for (i = 0; i < 17; i++) {
            if (ac.tickets[i].ticketnumber == selection) {
                TicketIndex = i;
                SelectionSucess++;
                break;
            }
        }
        if (selection == 0) {
            flag = 0;
            break;
        }
        else {
            if (SelectionSucess == 0) {
                printf("\nERROR: Invalid ticket number\n");
            }
            else {
                printf("\n================================================================================\n");
                printf("%06d", selection);

                printf(" (CLOSED) ");

                printf("Re: %s\n", ac.tickets[TicketIndex].SubjectLine);
                printf("================================================================================\n");
                for (i = 0; i < 20; i++) {
                    //if (ac.tickets[TicketIndex].
                    if (ac.tickets[TicketIndex].msg[i].acttype == 'A') {
                        printf("AGENT (%s):\n", ac.tickets[TicketIndex].msg[i].name);
                    }
                    else if (ac.tickets[TicketIndex].msg[i].acttype == 'C') {
                        printf("CUSTOMER (%s):\n", ac.tickets[TicketIndex].msg[i].name);
                    }
                    if ((ac.tickets[TicketIndex].msg[i].acttype == 'C') || (ac.tickets[TicketIndex].msg[i].acttype == 'A')) {
                        printf("   %s\n\n", ac.tickets[TicketIndex].msg[i].messagedetail);
                    }
                    if ((i + 1) % 5 == 0) {
                        //printf("");
                    }
                }
                pauseExecution();
            }
        }

    }

}


void manageticket(struct AccountTicketingData* ac, struct AccountTicketingData ab) {
    //for agent
    int i;
    int ticketnumber;
    int flag = 0;
    int flagg = 0;
    int ticketi = 0;
    int checksucces = 0;
    int relativeACIndex;
    int selection;
    int MsgIndex = 0;
    //int testMSG;
    int currentworkingindex;
    char choice;

    while (flag == 0) {
        printf("Enter ticket number: ");
        ticketnumber = getPositiveorZeroInteger();

        while (flagg == 0) {
            for (i = 0; i < 17; i++) {
                if (ab.tickets[i].ticketnumber == ticketnumber) {
                    ticketi = i;
                    checksucces++;
                    break;
                }
            }
            
            if (checksucces == 0) {
                printf("Error : Invaild ticket number\n");
                break;
            }
            else {
                printf("\n----------------------------------------\n");
                printf("Ticket %06d - Update Options\n", ticketnumber);
                printf("----------------------------------------\n");
                if (ab.tickets[ticketi].ticketstatuindicator == 1) {
                    printf("Status  : ACTIVE\n");
                }
                else if (ab.tickets[ticketi].ticketstatuindicator == 0) {
                    printf("Status  : CLOSED\n");
                }
                printf("Subject : %s\n", ab.tickets[ticketi].SubjectLine);
                printf("Acct#   : %d\n", ab.tickets[ticketi].relatedaccountnumber);
                relativeACIndex = findAccountIndexByAcctNum(ab.tickets[ticketi].relatedaccountnumber, ab, 8, 1);
                printf("Customer: %s\n", ab.accounts[relativeACIndex].usl.name);
                printf("----------------------------------------\n");
                printf("1) Add a message\n");
                printf("2) Close ticket\n");
                printf("3) Re-open ticket\n");
                printf("0) Done\n");
                printf("Selection: ");
                selection = getIntFromRange(0, 3);
                if (selection == 0) {
                    flag++;
                    flagg++;
                    break;
                }
                else if (selection == 1) {
                    //add msg
                    if (ab.tickets[ticketi].ticketstatuindicator == 0) {
                        printf("\nERROR: Ticket is closed -new messages are not permitted\n");
                    }
                    else {
                        for (i = 0; i < 20; i++) {

                            if ((ab.tickets[ticketi].msg[i].acttype != 'A') && (ab.tickets[ticketi].msg[i].acttype != 'C')) {


                                MsgIndex = i;

                                break;
                            }
                        }
                        if (ab.tickets[ticketi].numberofmessages < 20) {
                            printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");

                            getCString(ac->tickets[ticketi].msg[MsgIndex].messagedetail, 0, 150);
                            ac->tickets[ticketi].msg[MsgIndex].acttype = 'A';
                            currentworkingindex = findAccountIndexByAcctNum(currentworkac, ab, 6, 1);
                            for (i = 0; i < 39; i++) {
                                ac->tickets[ticketi].msg[MsgIndex].name[i] = ab.accounts[currentworkingindex].usl.name[i];
                            }
                            ac->tickets[ticketi].numberofmessages++;
                        }
                        else {
                            printf("\nERROR: Message limit has been reached, call ITS Support!\n");
                        }
                    }
                }
                else if (selection == 2) {
                    //close
                    if (ab.tickets[ticketi].ticketstatuindicator == 0) {
                        printf("\nERROR: Ticket is already closed!\n");
                    }
                    else {
                        printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                        choice = getCharOption("YN");
                        if (choice == 'Y') {
                            ac->tickets[ticketi].ticketstatuindicator = 0;
                                                       if (ab.tickets[ticketi].numberofmessages < 20) {
                                printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
                                choice = getCharOption("YN");
                                if (choice == 'Y') {
                                    printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                                    //printf("submit: ");
                                    for (i = 0; i < 20; i++) {

                                        if ((ab.tickets[ticketi].msg[i].acttype != 'A') && (ab.tickets[ticketi].msg[i].acttype != 'C')) {


                                            MsgIndex = i;
                                            break;
                                        }
                                    }
                                    getCString(ac->tickets[ticketi].msg[MsgIndex].messagedetail, 0, 150);
                                    ac->tickets[ticketi].msg[MsgIndex].acttype = 'A';
                                    currentworkingindex = findAccountIndexByAcctNum(currentworkac, ab, 6, 1);
                                    for (i = 0; i < 39; i++) {
                                        ac->tickets[ticketi].msg[MsgIndex].name[i] = ab.accounts[currentworkingindex].usl.name[i];
                                    }
                                    ac->tickets[ticketi].numberofmessages++;
                                }
                            }
                            printf("\n*** Ticket closed! ***\n");
                        }

                    }

                }
                else if (selection == 3) {
                    //re-open
                    if (ab.tickets[ticketi].ticketstatuindicator == 1) {
                        printf("\nERROR: Ticket is already active!\n");
                    }
                    else {
                        printf("\nAre you sure you RE-OPEN this closed ticket? ([Y]es|[N]o): ");
                        choice = getCharOption("YN");
                        if (choice == 'Y') {
                            ab.tickets[ticketi].ticketstatuindicator = 1;
                            printf("\n*** Ticket re-opened! ***\n");
                        }
                    }
                }
            }
        }
    }

}




//-----------delac
