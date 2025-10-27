#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

    const int DEFAULT_MONTH = 1;
    const int DEFAULT_DAY = 1;
    const int DEFAULT_YEAR = 1900;

    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:

    Date() {
        month = DEFAULT_MONTH;
        day = DEFAULT_DAY;
        year = DEFAULT_YEAR;
    }

    Date(int m, int d, int y) {
        
        month = DEFAULT_MONTH;
        day = DEFAULT_DAY;
        year = DEFAULT_YEAR;
        setDate(m, d, y);
    }

    void setDate(int m, int d, int y) {

      if (m < 1 || m > 12) {
            month = DEFAULT_MONTH;
            day = DEFAULT_DAY;
            year = DEFAULT_YEAR;
            return;
        }

        int maxDay = lastDay(m, y);
        if (d < 1 || d > maxDay) {
            month = DEFAULT_MONTH;
            day = DEFAULT_DAY;
            year = DEFAULT_YEAR;
            return;
        }

        month = m;
        day = d;
        year = y;
    }

    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    bool isLeapYear() const {
        return isLeapYear(year);
    }

    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int lastDay() const {
        return lastDay(month, year);
    }

    int lastDay(int m, int y) const {
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30; 
        } else if (m == 2) {
            return isLeapYear(y) ? 29 : 28; 
        } else {
            return 31; 
        }
    }

    void printFormat1() const {
        cout << month << "/" << day << "/" << year;
    }

    void printFormat2() const {
        string monthNames[] = {"", "January", "February", "March", "April", "May", "June", 
                               "July", "August", "September", "October", "November", "December"};
        cout << monthNames[month] << " " << day << ", " << year;
    }

    void printFormat3() const {
        string monthNames[] = {"", "January", "February", "March", "April", "May", "June", 
                               "July", "August", "September", "October", "November", "December"};
        cout << day << " " << monthNames[month] << " " << year;
    }
};


void runTests();

int main() {
    runTests();
    return 0;
}

void runTests() {
    cout << "======================================================\n";
    cout << "              Date Class Test Program\n";
    cout << "======================================================\n";

    Date d1; 

    cout << "Test default constructor: ";
    d1.printFormat1();
    cout << endl;

    Date d2(2, 28, 2009); 
    cout << "Test constructor with valid date (2/28/2009): ";
    d2.printFormat1();
    cout << endl;

    Date d3(45, 2, 2009); 
    cout << "Test constructor with invalid month (45, 2, 2009): ";
    d3.printFormat1();
    cout << " (Month invalid)" << endl; 

    Date d4(2, 29, 2009); 
    cout << "Test constructor with invalid day (2/29/2009): ";
    d4.printFormat1();
    cout << " (Day invalid)" << endl; 

    Date d5(2, 29, 2008); 
    cout << "Test for leap year with good date (2/29/2008): ";
    d5.printFormat1();
    cout << endl; 

    d1.setDate(13, 10, 2025);
    cout << "Test setDate with bad month (13, 10, 2025): ";
    d1.printFormat1();
    cout << " (Month invalid)" << endl; 

    d1.setDate(9, 31, 2025);
    cout << "Test setDate with bad day (9, 31, 2025): ";
    d1.printFormat1();
    cout << " (Day invalid)" << endl; 

    d1.setDate(12, 25, 2021); 

    cout << "\nTest print functions for date 12/25/2021:\n";
    cout << "Format 1 (M/D/YYYY): "; d1.printFormat1(); cout << endl;
    cout << "Format 2 (Month DD, YYYY): "; d1.printFormat2(); cout << endl;
    cout << "Format 3 (DD Month YYYY): "; d1.printFormat3(); cout << endl;

    cout << "\nTest isLeapYear() function:\n";
    cout << "Is 2008 a leap year? " << (d5.isLeapYear() ? "Yes" : "No") << endl; 
    cout << "Is 2009 a leap year? " << (d2.isLeapYear(2009) ? "Yes" : "No") << endl;

    cout << "\nTest lastDay() function:\n";
    cout << "Last day of current object (Dec 2021): " << d1.lastDay() << endl; 
    cout << "Last day of Feb 2024 (Leap): " << d1.lastDay(2, 2024) << endl; 
    cout << "Last day of Feb 2025 (Non-Leap): " << d1.lastDay(2, 2025) << endl; 

    cout << "\n======================================================\n";
}
