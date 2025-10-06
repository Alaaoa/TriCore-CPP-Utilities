#include <iostream>
#include "clsDate.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;

int main() {
    cout << "=============== Testing clsDate ===============" << endl;

    // Constructors
    clsDate d1; // system date
    clsDate d2("15/10/2025");
    clsDate d3(3, 3, 2023);
    clsDate d4(100, 2024); // 100th day of 2024

    cout << "System date (d1): " << d1.DateToString() << endl;
    cout << "From string (d2): " << d2.DateToString() << endl;
    cout << "From day/month/year (d3): " << d3.DateToString() << endl;
    cout << "From day order (d4): " << d4.DateToString() << endl;

    // Properties
    cout << "\nDay: " << d2.Day << ", Month: " << d2.Month << ", Year: " << d2.Year << endl;
    d2.Day = 20;
    d2.Month = 12;
    d2.Year = 2030;
    cout << "Modified d2: " << d2.DateToString() << endl;

    // Validations
    cout << "\nIsValid(d3): " << (d3.IsValid() ? "Yes" : "No") << endl;
    cout << "Leap year check for 2024: " << (clsDate::isLeapYear(2024) ? "Yes" : "No") << endl;

    // Days / Months / Years calculations
    cout << "\nDays in Feb 2024: " << clsDate::NumberOfDaysInAMonth(2, 2024) << endl;
    cout << "Days in year 2023: " << clsDate::NumberOfDaysInAYear(2023) << endl;
    cout << "Hours in year 2023: " << clsDate::NumberOfHoursInAYear(2023) << endl;

    // Day of week
    cout << "\nDay of week for d3: " << d3.DayShortName() << endl;

    // Print Calendar
    cout << "\nCalendar for March 2023:\n";
    d3.PrintMonthCalendar();
    cout << "\nYear calendar for 2023:\n";
    clsDate::PrintYearCalendar(2023);

    // Add / Increase Dates
    cout << "\nBefore AddOneDay: " << d3.DateToString() << endl;
    d3.AddOneDay();
    cout << "After AddOneDay: " << d3.DateToString() << endl;

    clsDate d5("28/02/2024");
    cout << "\nBefore IncreaseDateByOneMonth: " << d5.DateToString() << endl;
    d5.IncreaseDateByOneMonth();
    cout << "After IncreaseDateByOneMonth: " << d5.DateToString() << endl;

    // Difference
    clsDate d6("01/01/2025");
    clsDate d7("10/01/2025");
    cout << "\nDifference in days between " << d6.DateToString()
        << " and " << d7.DateToString() << ": "
        << clsDate::GetDifferenceInDays(d6, d7) << endl;

    // Business days & Vacation
    cout << "\nBusiness days between " << d6.DateToString() << " and " << d7.DateToString()
        << ": " << clsDate::CalculateBusinessDays(d6, d7) << endl;

    clsDate vac = clsDate::CalculateVacationReturnDate(d6, 5);
    cout << "Vacation start " << d6.DateToString() << " + 5 business days return: " << vac.DateToString() << endl;

    // Compare dates
    cout << "\nCompare d6 vs d7: ";
    switch (clsDate::CompareDates(d6, d7)) {
    case clsDate::Before: cout << "Before"; break;
    case clsDate::Equal: cout << "Equal"; break;
    case clsDate::After: cout << "After"; break;
    }
    cout << endl;

    cout << "==================================================" << endl;

    cout << "\n=============== Testing clsString ===============" << endl;

    clsString s1("hello world from clsString class!");

    cout << "Original: " << s1.Value << endl;
    cout << "Length: " << s1.Length() << endl;
    cout << "Words: " << s1.CountWords() << endl;
    cout << "Upper all: " << clsString::UpperAllString(s1.Value) << endl;
    cout << "Lower all: " << clsString::LowerAllString(s1.Value) << endl;

    s1.UpperFirstLetterOfEachWord();
    cout << "Capitalize first letter each word: " << s1.Value << endl;

    s1.InvertAllLettersCase();
    cout << "Invert case: " << s1.Value << endl;

    cout << "Vowel count: " << s1.CountVowels() << endl;
    cout << "Specific letter 'l' count: " << s1.CountSpecificLetter('l') << endl;

    vector<string> parts = s1.Split(" ");
    cout << "Split by spaces: ";
    for (string& p : parts) cout << "[" << p << "] ";
    cout << endl;

    cout << "Joined again: " << clsString::JoinString(parts, "-") << endl;

    s1.RemovePunctuations();
    cout << "After removing punctuations: " << s1.Value << endl;

    cout << "Reverse words: " << clsString::ReverseWordsInString("one two three four") << endl;

    cout << "==================================================" << endl;



       clsUtil::Srand();

        cout << "Random Key: " << clsUtil::GenerateKey() << endl;

        string encrypted = clsUtil::EncryptText("Hello World", 2);
        string decrypted = clsUtil::DecryptText(encrypted, 2);

        cout << "Encrypted: " << encrypted << endl;
        cout << "Decrypted: " << decrypted << endl;

       // clsDate d1(2025, 10, 6), d2(2023, 5, 9);
        clsUtil::Swap(d1, d2);
        cout << "After swapping dates: " << d1.DateToString() << " and " << d2.DateToString() << endl;

        return 0;
    }





