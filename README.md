

## 1. Goal

For this assignment, you will write a C++ program, in the VM provided for this course, to manage a user’s
personal agenda of appointments. Your program will implement an agenda that stores multiple calendars to
hold the different types of appointments, for example a work calendar and a personal calendar. Each calendar
will contain the dates that represent the appointments and events in the user’s busy life. You will practice
writing correctly designed code with simple classes in C++, as well as working with dynamically allocated
memory.

## 2. Learning Outcomes

With this assignment, you will:

- write correctly designed code with simple C++ classes with composition associations between them
- work with dynamically allocated memory and pointers
- write and package a program following standard C++98 and Unix programming conventions

## 3. Instructions

Your program will implement several new classes representing a user’s agenda, the different calendars con-
tained in the agenda, and the dates contained within each of those calendars.

For example, some users may choose to manage separately the events in their work or school life from those in
their personal life. Therefore, they may have one calendar for work or school events, and a different calendar
for their personal appointments. The combination of the user’s multiple calendars together will make up their
agenda. Your program will initialize the user’s multiple calendars with several dates. It will print out the
content of the individual calendars, as well as the entire agenda with the combined dates of all the calendars.

This program requires the implementation of several new classes. All new classes must follow the implemen-
tation conventions that we saw in the course lectures, including but not restricted to the correct separation of
code into header and source files, the use of include guards, basic error checking, and the documentation of
each class in the class header file. A more comprehensive list of constraints can be found in the Constraints
section below.

```
3.1. Modify theDateclass
You will begin with theDateclass that we worked on during the lectures. You can find this class in the
in-class coding examples posted in cuLearn , in section 1.5, program #2.
Modify theDateclass to add the following data members:
3.1.1. an event name, which is a C++ standard librarystringobject
3.1.2. a start time for the event, which is an integer representing the number of minutes since midnight
3.1.3. the duration of the event, in minutes
3.1.4. a flag to represent whether the event is recurring, stored as a boolean
3.1.5. the number of weeks for which the event recurs
3.1.6. a flag to indicate whether the date information contained in the object is valid, stored as a boolean
```
```
TheDateclass will contain the following additional member functions:
3.1.7. a default constructor that takes 9 parameters, in the following order: the event name, day, month,
year, starting hour, starting minute, duration, recurrence, and number of recurring weeks; the default
constructor will initialize all the data members from these parameters, as follows:
```

```
(a) the name and recurrence data members can be set directly from parameters
(b) the valid flag will be set to the result of the newvalidate()member function, described below;
if the parameters are not valid, then default values must be used
(c) the existingsetDate()function must be called to validate and set the day, month, and year
(d) the given starting hour and starting minute parameters must be validated, and the start time of
the event must be stored as a number of minutes since midnight, using these parameters
(e) the duration must be validated and set from a parameter
(f) if the event is recurring, the number of recurring weeks must be set to the corresponding param-
eter, otherwise it must be initialized to zero
(g) all error checking must be performed
(h) the constructor must specify default values for all parameters; by default, events do not recur,
and the default number of recurring weeks must be 10
3.1.8. a copy constructor, as seen in the coding example in section 1.5, program #
3.1.9. avalidate()member function that takes as parameters the values for the day, month, year, start
hour, start minute, and duration, and returns whether or not these values are valid
3.1.10. abool lessThan(Date* d)function that compares twoDateobjects, and returns true if the date in
thethisobject occurs earlier than the date in thedparameter
3.1.11. getter member functions for the recurrence and valid flags
3.1.12. avoid print()member function that replaces bothprintShort()andprintLong(); this function
prints to the screen all the data members, except the duration; instead, the start time and end time
of the event must both be printed to the screen in the HH:MM format; you can assume that all events
start and end on the same day
3.1.13. any other private helper member functions that are necessary for good design
```
3.2. **Implement theCalendarclass**

```
You will create a newCalendarclass that manages a primitive array of dates and provides the required
member functions to manipulate them.
TheCalendarclass will contain the following data members:
3.2.1. a calendar name, which will be a C++ standard librarystringobject
3.2.2. a collection of the dates in the calendar
(a) this will be a dynamically allocated array ofDateobject pointers
(b) you can refer to the coding example in section 1.6, program #5, for examples of the four different
kinds of arrays
3.2.3. the current number of dates in the array
```
```
TheCalendarclass will contain the following member functions:
3.2.4. a default constructor that takes a calendar name as parameter, and initializes all the data members
(a) when allocating the dynamic array, you will define a preprocessor constant for the maximum
number of dates; this can be set to a reasonable number such as 64;
(b) it is not necessary to initialize each array element to null, since your code should never access
any element beyond the current number of dates
(c) it is bad form to initialize data members in the class definition; you must do this in the body of
the constructor instead
3.2.5. a destructor that deallocates the memory for each date in the calendar, as well as the dates array
itself
3.2.6. a getter function for the calendar name
3.2.7. abool add(Date*)member function that inserts the given date in the array, directly in its correct
place , in ascending (increasing) order by date
(a) you must shift the elements in the array towards the back (the end) of the array to make room
for the new element in its correct place; do not add to the end of the array and sort; do not use
any sorting function or sorting algorithm
```

```
(b) you must perform all basic error checking; invalid dates cannot be added to the array
(c) this function returns true if no errors occurred, and false otherwise
3.2.8. avoid merge(Calendar* c)member function that takes every date in the given calendarc, creates
a copy of this date, and adds the copy to the current (thethis) calendar; existing functions must be
reused everywhere possible
3.2.9. avoid printDates()member function that prints to the screen the information for each date in the
calendar; using correct design principles, this function must call an existing function on eachDate
object
3.2.10. avoid print()member function that prints to the screen all the calendar information, including
the calendar name and all the information for each date in the calendar
```
3.3. **Implement theAgendaclass**

```
You will implement a newAgendaclass that manages a collection of calendars for the user.
TheAgendaclass will contain the following data members:
3.3.1. an agenda name, stored as astring
3.3.2. a collection of the calendars in the agenda
(a) this will be a statically allocated array ofCalendarobject pointers
(b) you can refer to the coding example in section 1.6, program #5, for examples of the four different
kinds of arrays
3.3.3. the current number of calendars in the array
```
```
TheAgendaclass will contain the following member functions:
3.3.4. a default constructor that takes an agenda name as parameter, and initializes the necessary data
members
3.3.5. a destructor that deallocates the dynamically allocated calendars contained in the calendars array
3.3.6. abool add(Calendar*)function that adds the given calendar to the back (the end) of the calendars
array; this function returns true if the calendar was successfully added, and false otherwise
3.3.7. abool find(string n, Calendar** c)function that searches the calendars array for the calendar
with the name specified in parametern, and returns that calendar pointer using parameterc; you
must use the parameter to return this data; do not use the return value
3.3.8. abool add(Date* d, string n)function that does the following:
(a) find the calendar to which the date will be added; this is theCalendarobject with the given
calendar namen; if the corresponding calendar is not found, the date cannot be added
(b) perform all relevant error checking
(c) add the given datedto the calendar’s dates array
(d) return true if the date was successfully added, and false otherwise
3.3.9. avoid print()function that prints out all the combined dates contained all the calendars, in
ascending order; the function does the following:
(a) create a temporary calendar object
(b) for every calendar in the agenda, merge the content of that calendar into the temporary calendar;
this copies every date and inserts it into the temporary calendar in the correct position
(c) print the agenda name to the screen
(d) print out the dates in the temporary calendar to the screen
Note #1: You must use correct design principles in the implementation of all the above functions. This
means that you must reuse existing functions everywhere possible, and perform all error checking.
Note #2: Do not implement any additional getter or setter functions, as these are not necessary. How-
ever, you may implement additional “helper” member functions (not global functions) as needed.
```
3.4. **Write themain()function**

```
Yourmain()function must test your program thoroughly. To do so, it will initialize an agenda object and
two calendar objects. It will initialize several different dates and add them to the different calendars,
and it will print the calendars and the agenda data to the screen.
```

```
Your program must use a global function to initialize the dates, specifically theinitDates(Agenda&)
function that is provided in thea1-posted.ccfile posted in cuLearn.
```
```
Yourmain()function will do the following:
3.4.1. declare an agenda object with an appropriate name; this object can be statically allocated
3.4.2. dynamically allocate two calendar objects; you will give one of them the name “Work” and the other
“Home”
3.4.3. add both calendars to the agenda
3.4.4. initialize the data by calling theinitDates()function provided, using the agenda that you declared;
this will create multiple dates and add them to the agenda’s “Work” and “Home” calendars
3.4.5. print out each calendar separately; this will show the individual dates in each calendar, in ascending
order
3.4.6. print out the agenda; this will show the dates in both calendars combined, in ascending order
```
```
3.5. Packaging
Every assignment in this course is required to follow the conventional packaging rules for Unix-based
systems:
3.5.1. Your code must be correctly separated into header and source files, as seen in class.
3.5.2. You must provide a Makefile that compiles and links all your code into a working executable.
(a) do not use a generic Makefile; it must be specific to this program
3.5.3. You must provide a README file that contains a preamble (program author, purpose, list of source,
header, data files if applicable), as well as compiling and launching instructions.
3.5.4. Do not submit any additional files, including object files, executables, or supplementary files or
directories (macOS users must remove their additional hidden directories).
```
```
3.6. Test the program
You must provide code that tests your program thoroughly. For this program, the use of the provided
global function will be sufficient. Specifically:
3.6.1. Check that the date information is correct when it is printed at the end of the program.
3.6.2. Make sure that all dynamically allocated memory is explicitly deallocated when it is no longer used.
Usevalgrindto check for memory leaks.
```
## 4. Constraints

Your program must comply with all the rules of correct software engineering that we have learned during the
lectures, including but not restricted to:

```
4.1. The code must be written in C++98. It must compile and execute in the default course VM, without any
libraries or packages or any software that’s not already provided in the VM.
```
```
4.2. Your program must not use any classes, containers, or algorithms from the C++ standard template library
(STL), unless explicitly permitted in the instructions.
4.3. Your program must follow basic OO programming conventions, including the following:
4.3.1. Do not use any global variables or any global functions other than the ones explicitly permitted.
4.3.2. Do not usestructs. You must use classes instead.
4.3.3. Objects must always be passed by reference, never by value.
4.3.4. Existing functions must be reused everywhere possible.
4.3.5. All basic error checking must be performed.
4.3.6. All dynamically allocated memory must be explicitly deallocated.
4.4. All classes must be thoroughly documented in every class definition, as indicated in the course material,
section 1.3
