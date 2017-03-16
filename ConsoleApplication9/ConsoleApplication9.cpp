#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

static int idCount;
int aCountL=0;
int cCountM=0;
int sCountH=0; 
int aCountM= 0;
int cCountL= 0;
int sCountL= 0;
int aCountH= 0;
int cCountH= 0;
int sCountM= 0;

class Ticket
{
	int id;

private:
	int impactedUsers;
	string status;
	string type;
	string priority;
	string name;
	string description;

public:
	Ticket();
	int getID();
	void CloseTicket();
	void ShowTicket();
	void CaptureTicket()
	{
		cout << "What is the name of the caller" << endl;
		cin >> name;
		cout << "Issue Type? S=Server, A=Applicaiton C=Access" << endl;
		cin >> type;
		cout << "What is the description of the issue?" << endl;
		cin >> description;
		cout << "How many user impacted" << endl;
		cin >> impactedUsers;
		
		if (impactedUsers < 10 && type == "s")
		{
			priority = "LOW";
			sCountL++;
		}
		if (impactedUsers < 10 && type == "a")
		{
			priority = "LOW";
			aCountL++;
		}
		if (impactedUsers < 10 && type == "c")
		{
			priority = "LOW";
			cCountL++;
		}
		if (impactedUsers >= 10 && impactedUsers < 50 && type == "s")
		{
			priority = "MED";
			sCountM++;
		}
		if (impactedUsers >= 10 && impactedUsers < 50 && type == "a")
		{
			priority = "MED";
			aCountM++;
		}
		if (impactedUsers >= 10 && impactedUsers < 50 && type == "c")
		{
			priority = "MED";
			cCountM++;
		}
		if (impactedUsers >= 50 && type == "s")
		{
			priority = "HIGH";
			sCountH++;
		}
		if (impactedUsers >= 50 && type == "a")
		{
			priority = "HIGH";
			aCountH++;
		}
		if (impactedUsers >= 50 && type == "c")
		{
			priority = "HIGH";
			cCountH++;
		}
	}
};

Ticket::Ticket()
{
	id = idCount++;
	status = "Open";
}

int Ticket::getID()
{
	return id;
}

void Ticket::CloseTicket()
{
	if (id > 0)
	{
		cout << endl << "Ticket #1 has been closed" << endl;
	}
	
}

void Ticket::ShowTicket()
{
	cout << "_________________________" << endl;
	cout << "Ticket Listing" << endl;
	cout << "_________________________" << endl;
	cout << "Ticket Id: " << id << endl;
	cout << "Status: " << status << endl;
	cout << "Description: " << description << endl;
	cout << "User: " << name << endl;
	cout << "Users Impacted: " << impactedUsers << endl;
	cout << "Priority: " << priority << endl;
}


int main()
{
	Ticket *tickets[100];
	char input;
	int num = 100;

	for (int i = 0; i <= idCount; i++)
	{
		cout << "Open new ticket? Enter Y to continue" << endl;
		cin >> input;
		input = toupper(input);

		if (input == 'Y')
		{
			tickets[i] = new Ticket();
			tickets[i]->CaptureTicket();
		}

		if (input == 'N')
		{
			
			break;
		}

		if (input != ' Y' && input != 'N')
		{
			cout << "Please only enter Y or N" << endl;
		}
	}
	cout << "Issue Summary by type and priority" << endl << endl;
	cout << "    Server App Access" << endl;
	cout << "Low" << "   " << sCountL << "      " << aCountL << "     " << cCountL << "     " << endl;
	cout << "Med" << "   " << sCountM << "      " << aCountM << "     " << cCountM << "     " << endl;
	cout << "High" << "  " << sCountH << "      " << aCountH << "     " << cCountH << "     " << endl;
	for (int i = 0; i < idCount; i++)
	{
		tickets[i]->ShowTicket();
	}

	tickets[0]->CloseTicket();
	system("pause");
	return 0;
}









