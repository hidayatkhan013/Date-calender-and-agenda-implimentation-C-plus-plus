#ifndef CALENDAR_H
#define CALENDAR_H
#include "Date.h"
using namespace std;


class Calendar
{
public:
	Calendar(string="");
	~Calendar();
	string getCalendar_name();
	bool add(Date*);
	void merge(Calendar* c);
	void printDates();
	void print();

private:
	string  calendar_name;
	Date** array_date;
	int current_no_of_dates;
	


};








#endif
