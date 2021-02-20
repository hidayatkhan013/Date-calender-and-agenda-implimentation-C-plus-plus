#include <iostream>
#include <string>
#include "Calendar.h"
#define MAX_NO_OF_DATE 64



Calendar::Calendar(string c_name)
{
	calendar_name = c_name;
	current_no_of_dates = 0;
	array_date = new Date*[MAX_NO_OF_DATE];
	
}


Calendar::~Calendar()
{
	delete[] array_date;
}

string Calendar::getCalendar_name()
{
	return calendar_name;
}

bool Calendar::add(Date* date)
{

	if (current_no_of_dates >= MAX_NO_OF_DATE)
		return false;
	if (date->isValidDate()) {
		int i;
		for (i = current_no_of_dates - 1; (i >= 0 && !array_date[i]->lessThan(date)); i--) {
			array_date[i + 1] = array_date[i];
		}


		array_date[i + 1] = date;
		current_no_of_dates++;

		return true;
	}
}

void Calendar::merge(Calendar* c)
{
	
	int size = c->current_no_of_dates+this->current_no_of_dates;
	for (int i = 0; i < c->current_no_of_dates; i++)
	{
		this->add(c->array_date[i]);
	}

}

void Calendar::printDates()
{
	int size = current_no_of_dates;
	for (int i = 0; i < size; i++)
	{
		this->array_date[i]->print();
	}
	cout << endl;
	
}

void Calendar::print()
{
	cout << "Calendar " <<this->getCalendar_name() << endl;
	this->printDates();
}
