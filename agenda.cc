#include "agenda.h"
#define MAX_NO_OF_CAL 64

Agenda::Agenda(string AgendaName)
{
	agenda_name = AgendaName;
	current_no_calenders = 0;
	calenders = new Calendar[MAX_NO_OF_CAL];
}

Agenda::~Agenda()
{
	delete[] calenders;
}

bool Agenda::add(Calendar* c)
{
	if (current_no_calenders >= MAX_NO_OF_CAL)
		return false;
	this->calenders[current_no_calenders] = *c;
	current_no_calenders++;
	return true;
}

bool Agenda::find(string n, Calendar** c)
{
	int size = current_no_calenders;

	for (int i = 0; i < size; i++)
	{
		if (calenders[i].getCalendar_name() == n) {
			*c = &calenders[i];
			return true;
		}

	}
	return false;
}

bool Agenda::add(Date* d, string n)
{


	int size = current_no_calenders;

	for (int i = 0; i < size; i++)
	{
	
		if (this->calenders[i].getCalendar_name() == n) {
			this->calenders[i].add(d);
			return true;
		}

	}

	return false;
}

void Agenda::print()
{
	
	int size = current_no_calenders;
	Calendar temp;
	for (int i = 0; i < size; i++)
	{
		temp.merge(&calenders[i]);
		calenders[i].print();
	}
	cout << "Agenda : " << this->agenda_name << endl;
	temp.printDates();

}
