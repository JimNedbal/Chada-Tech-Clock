// Name:		 Jim Nedbal
// Program Name: Chada Tech Clock Project1
// Class:        CS-210-R4734
// Description:  12 and 24 clock in c++

#include <iostream>
#include <string>

using namespace std;

class ClockTime { // This class is to get the values for hours, minutes, and seconds.
private: // this sets the classes initial values to private.
	int hour;
	int min;
	int sec;

public:
	// Set values for hour, minute, second.
	void setHour(int h) {
		hour = h;
	}
	void setMinute(int m) {
		min = m;
	}
	void setSecond(int s) {
		sec = s;
	}
public:
	// Get values for hour, minute, second.
	int getHour() {
		return hour;
	}
	int getMinute() {
		return min;
	}
	int getSecond() {
		return sec;
	}

};

string inCharString(int n, char c) { // This function is used to make lines out of char's. 
	string lineChar; // A string value to have something to return.

	for (int i = n; i > 0; --i) { // A for loop set to 'n' long.
		lineChar.push_back(c); // this adds the 'c' until the loop ends.
	}
	return lineChar; // this is the returning string value of the line of chars.
}

string twoDigitString(int n) { // This function takes in int's and converts them into two number strings.
	string nn; // A string value to have something to return. 

	if (n < 10) {
		nn = to_string(n); // Converts a one digit number into a string.
		nn.insert(0, "0"); // adds a 0 to the front on the string.
	}
	else {
		nn = to_string(n); // Converts a two digit number into a string.
	}
	return nn; // returning a tow number string. 
}

string formatTime24(int h, int m, int s) { // Sets up athe format of a 24 hour clock as a string.
	string time24; // A string value to have something to return.
	// this is to build the clocks format.
	time24.append(twoDigitString(h));
	time24.push_back(':');
	time24.append(twoDigitString(m));
	time24.push_back(':');
	time24.append(twoDigitString(s));

	return time24; // this is the returning string value of the 24 hour clock format.
}

string formatTime12(int h, int m, int s) {
	string time12; // A string value to have something to return.
	string amPm; // A string value for if the time is AM or PM to return.
	// this is to determine if the time is AM or PM. 
	amPm = " A ";
	while (h >= 12) {
		h -= 12;
		amPm = " P ";
	}
	if (h == 0) {
		h = 12;
	}

	time12 = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s) + amPm + "M"; // this is to build the clocks format.

	return time12;// this is the returning string value of the 12 hour clock format.
}

void addOneHour() { // A function to add 1 to hour and keep the number between 1 and 23.
	ClockTime clockTime; // calling the class 'ClockTime'.
	int h;
	h = clockTime.getHour(); // pulling the value of hour and set it to 'h'.
	if ((h >= 0) && (h <= 22)) { // if statement that set the parameters of hours.
		h += 1;
	}
	else if (h == 23) { // resets the hour to '0' 
		h = 0;
	}
	clockTime.setHour(h); // this is to return the value of 'h' for hour.
}

void addOneMinute() { // A function to add 1 to minute and keep the number between 00 and 59.
	ClockTime clockTime; // calling the class 'ClockTime'.
	int m;
	m = clockTime.getMinute(); // pulling the value of minute and set it to 'm'.
	if ((m >= 0) && (m <= 58)) { // if statement that set the parameters of minute.
		m += 1;
	}
	else if (m == 59) { // resets the hour to '0'.
		m = 0;
		addOneHour(); // calls to add one hour.
	}
	clockTime.setMinute(m); // this is to return the value of 'm' for minute.
}
