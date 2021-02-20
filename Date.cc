#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"


Date::Date(const Date& date) {
	event_name = date.event_name;
	day = date.day;
	month = date.month;
	year = date.year;
	start_hour = date.start_hour;
	start_mint = date.start_mint;
	duration_of_event = date.duration_of_event;
	is_recurring = date.is_recurring;
	is_date_valid = date.is_date_valid;
	no_of_weeks = date.no_of_weeks;
	event_start_time = date.event_start_time;
}

Date::~Date()
{
}

Date::Date(string e_name, int d, int m, int y, int s_h, int s_m, int duration, bool recurrence, int no_of_week_Re)
{
	event_name = e_name;
	is_recurring = recurrence;
	if (is_recurring) no_of_weeks = no_of_week_Re; else no_of_weeks = 0;
	is_date_valid = validate(d, m, y, s_h, s_m, duration);
	if (s_h || s_m) event_start_time = (23 - s_h) * 60 + (59 - s_m); else event_start_time = 0;
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12 ) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}


bool Date::lessThan(Date* d)
{
	int total_d = d->year * 365 + d->month * d->lastDayInMonth() + d->day;
	int total_this = this->year * 365 + this->month * this->lastDayInMonth() + this->day;
	if (total_this < total_d) return true;
	return false;
}

bool Date::isValidDate()
{
	return is_date_valid;
}

bool Date::isRecurrence()
{
	return is_recurring;
}

void Date::print()
{
	cout << setfill(' ') <<"=="<< setw(40) << event_name<<":" << setw(15) << getMonthStr() << " " << day << ", " << year<<" @ "<<
		start_hour << ":" << start_mint << " - " << start_hour + (duration_of_event / 60) << ":" << start_mint + (duration_of_event % 60);
	if (isRecurrence() == true) cout << ", recurs for " << no_of_weeks << " weeks";
		cout<<endl;
}

bool Date::validate(int d, int m, int y, int s_h, int s_m, int duration)
{
	if (s_h > 0) start_hour = s_h; else start_hour = 0;
	if (s_m > 0) start_mint = s_m; else start_mint = 0;
	if (duration > 0) duration_of_event = duration; else duration_of_event = 0;
	if (y > 0 && (m > 0 && m <= 12) && (d > 0 && d <= lastDayInMonth())) {
		setDate(d, m, y);
		return true;
	}
	return false;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr()
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

