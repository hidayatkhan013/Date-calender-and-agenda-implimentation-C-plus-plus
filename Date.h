#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
  public:
	Date(string=" ",int=0, int=0, int=2000,int=0,int=0,int=0,bool=false,int=10);
	Date(const Date&);
	~Date();
    void setDate(int,int,int);
	bool lessThan(Date* d);
	bool isValidDate();
	bool isRecurrence();
	void print();



  private:
    int day;
    int month;
    int year;
	bool validate(int,int,int,int,int,int);
	string event_name;
	int event_start_time;
	int start_hour;
	int start_mint;
	int duration_of_event;
	bool is_recurring;
	int no_of_weeks;
	bool is_date_valid;

    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
};

#endif
