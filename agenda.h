#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include "Calendar.h"
using namespace std;
class Agenda
{
	string agenda_name;
	Calendar* calenders;
	int current_no_calenders;

public:
	Agenda(string = "");
	~Agenda();
	bool add(Calendar*);
	bool find(string n, Calendar** c);
	bool add(Date* d, string n);
	void print();
};
#endif