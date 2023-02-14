// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Gurpinder Singh
//  Student ID    : 140515206
//  Student Email : gsingh944@myseneca.ca
//  Course Section: ZEE
// ===================================================================================



#ifndef TICKET
#define TICKET

struct Message {
	char acttype;
	char name[40];
	char messagedetail[151];
};

struct Ticket {
	int ticketnumber;
	int relatedaccountnumber;
	int ticketstatuindicator;
	char SubjectLine[31];
	int numberofmessages;
	struct Message msg[20];
};
#endif
