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

void addOneSecond() { // A function to add 1 to second and keep the number between 00 and 59.
	ClockTime clockTime; // calling the class 'ClockTime'.
	int s;
	s = clockTime.getSecond(); // pulling the value of second and set it to 's'.
	if ((s >= 0) && (s <= 58)) { // if statement that set the parameters of second.
		s += 1;
	}
	else if (s == 59) { // resets the hour to '0'.
		s = 0;
		addOneMinute(); // calls to add one minute.
	}
	clockTime.setSecond(s); // this is to return the value of 's' for second.
}

void printTime(int h, int m, int s) { // Print statement to display the clock in both 12 and 24 formats.

	
	cout << inCharString(27, '*') << inCharString(3, ' ') << inCharString(27, '*') << endl; // makes the top line.
	cout << "*" << inCharString(6, ' ') << "12-HOUR CLOCK" << inCharString(6, ' ') << "*   *" << inCharString(6, ' ') << "24-HOUR CLOCK" << inCharString(6, ' ') << "*" << endl; // title of 12 and 24 clocks
	cout << endl; // blank space.
	cout << "*" << inCharString(6, ' ') << formatTime12(h, m, s) << inCharString(7, ' ') << "*   *" << inCharString(8, ' ') << formatTime24(h, m, s) << inCharString(9, ' ') << "*" << endl; // displaying the clock formats.
	cout << inCharString(27, '*') << inCharString(3, ' ') << inCharString(27, '*') << endl; // makes bottum line
}

void printMenu() {// Print statement to display the the menu.

	cout << inCharString(23, '*') << endl; // top line.
	cout << "* 1 - Add one hour.   *" << endl; // prints option 1.
	cout << "* 2 - Add one minute  *" << endl; // prints option 2.
	cout << "* 3 - Add one second  *" << endl; // prints option 3.
	cout << "* 4 - Exit Program    *" << endl; // prints option 4. 
	cout << inCharString(23, '*') << endl; // bottum line.
}

void menuAction(int mI) { // this function takes in the input on witch option to preform.

	while ((mI >= 1) && (mI <= 4)) { //A while loop to make sure the input is within the options.
		switch (mI) {
		case 1: // option 1 th add one to hours.
			addOneHour();
			break; // then break back to the loop. 

		case 2:
			addOneMinute(); // option 2 th add one to minutes.
			break; // then break back to the loop.

		case 3:
			addOneSecond(); // option 3 th add one to seconds.
			break; // then break back to the loop.
		case 4: // option 4 to exit the progam.
			cout << "Exiting Clock Progam" << endl; // a "Goodbye" message.
			abort(); // this is what make the program stop.
			//break;
		default: // this is to handle any invalid inputs.
			cout << "Invalid command" << endl; 
		}

		cin >> mI; // a new input for the while loop.
		ClockTime clockTime; // calling the class 'ClockTime'.
		int h{ clockTime.getHour() }; // Supposed to get the hours new value for the printTime function.
		int m{ clockTime.getMinute() }; // Supposed to get the minutes new value for the printTime function.
		int s{ clockTime.getSecond() }; // Supposed to get the seconds new value for the printTime function.
		printTime(h, m, s); // to print the new clock display.
		printMenu(); // to print the menu again after the option was picked.
	}


}

int main() { // this is the main function.
	int menuInput; // a value for input.

	ClockTime clockTime;// calling the class 'ClockTime'. And to set the values for hours, minutes, and seconds.
	int hour;
	int min;
	int sec;

	cout << "Input hour for the clock." << endl;
	cin >> hour; // input for hour.
	cout << "Input minutes for the clock." << endl;
	cin >> min; // input for minute.
	cout << "Input seconds for the clock." << endl;
	cin >> sec; // input for second.

	clockTime.setHour(hour); // Setting hour to the class 'ClockTime'.
	clockTime.setMinute(min);// Setting minute to the class 'ClockTime'.
	clockTime.setSecond(sec);// Setting second to the class 'ClockTime'.
	
	printTime(hour, min, sec); // call to display the clock for the first time.
	printMenu(); // call to display the menu for the first time.

	cin >> menuInput; // the first input for the menu options.
	
	menuAction(menuInput); // call for the action of the menu option loop for the first time.
}
