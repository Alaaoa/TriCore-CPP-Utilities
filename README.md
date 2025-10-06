C++ Utilities Library — clsDate, clsString, and clsUtil
🧩 Overview

This project is a modular C++ utilities library built with three main reusable classes:

clsDate – A complete date-handling and calendar utility.

clsString – A flexible string manipulation toolkit.

clsUtil – A collection of general-purpose helper functions for randomization, encryption, array manipulation, and more.

Together, these classes form a solid foundation for C++ learning, projects, and reusable software tools.

📚 Classes and Features
🗓️ 1. clsDate — Date and Calendar Utility

Purpose: Handle all date-related operations in a clean, object-oriented way.

Main Features:

Multiple constructors:

From system date

From string "dd/mm/yyyy"

From day, month, year integers

From day order in year

Validation and leap year detection.

Get day/month/year properties.

Add, subtract, or compare dates.

Calculate:

Days in month/year

Difference between two dates

Business days (excluding weekends)

Generate and print calendars (month or full year).

Compute vacation return dates.

Example:

clsDate d1("15/10/2025");
cout << d1.DateToString(); // "15/10/2025"

clsDate d2(28, 2, 2024);
d2.IncreaseDateByOneMonth();
cout << d2.DateToString(); // "28/03/2024"

✏️ 2. clsString — String Manipulation Utility

Purpose: Simplify and extend string operations that are commonly used in text processing.

Main Features:

Get string length and count words.

Change text case:

Uppercase / lowercase

Capitalize words / invert case

Count:

Specific characters

Capital or small letters

Vowels

Split and join strings by a delimiter.

Trim whitespace (left, right, or both).

Reverse words in a sentence.

Replace words or remove punctuation.

Static methods for direct use without creating objects.

Example:

clsString s("hello world from cpp");

cout << s.CountWords(); // 4
cout << clsString::UpperAllString(s.Value); // "HELLO WORLD FROM CPP"

s.ReverseWordsInString();
cout << s.Value; // "cpp from world hello"

⚙️ 3. clsUtil — General Utilities and Random Generators

Purpose: Provide common helper functions for randomness, swapping, encryption, and array manipulation.

Main Features:

Random number generation.

Random character or word generation (digits, letters, symbols).

Random key generation in the form XXXX-XXXX-XXXX-XXXX.

Fill arrays with random numbers, words, or keys.

Swap overloads (int, double, char, bool, string, clsDate).

Shuffle arrays.

Simple text encryption and decryption (ASCII shift).

Print tabs for formatting.

Integration with clsDate for swapping and randomizing date-related data.

Example:

clsUtil::Srand(); // Seed randomizer

cout << clsUtil::GenerateKey(clsUtil::CapitalLetter);
// Example output: "ABCD-EFGH-IJKL-MNOP"

string encrypted = clsUtil::EncryptText("Hello World", 2);
string decrypted = clsUtil::DecryptText(encrypted, 2);

cout << encrypted << endl; // "Jgnnq\"Yqtnf"
cout << decrypted << endl; // "Hello World"
