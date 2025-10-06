#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsUtil
{
public:
    enum enCharType {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    // Initialize random seed once
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    // Generate random number in a range
    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    // Get a random character of specific type
    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
            CharType = (enCharType)RandomNumber(1, 3);

        switch (CharType)
        {
        case SmallLetter:
            return char(RandomNumber(97, 122));  // a–z
        case CapitalLetter:
            return char(RandomNumber(65, 90));   // A–Z
        case Digit:
            return char(RandomNumber(48, 57));   // 0–9
        case SpecialCharacter:
            return char(RandomNumber(33, 47));   // punctuation
        default:
            return char(RandomNumber(65, 90));   // fallback: A–Z
        }
    }

    // Generate random word of given length
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";
        for (int i = 0; i < Length; i++)
            Word += GetRandomCharacter(CharType);
        return Word;
    }

    // Generate a formatted random key: XXXX-XXXX-XXXX-XXXX
    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";
        for (int i = 0; i < 4; i++)
        {
            Key += GenerateWord(CharType, 4);
            if (i < 3) Key += "-";
        }
        return Key;
    }

    // Generate multiple keys
    static void GenerateKeys(short NumberOfKeys, enCharType CharType = CapitalLetter)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
            cout << "Key [" << i << "]: " << GenerateKey(CharType) << endl;
    }

    // Fill arrays
    static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, short WordLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, WordLength);
    }

    static void FillArrayWithRandomKeys(string arr[], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    // Swap overloads
    static void Swap(int& A, int& B) { int Temp = A; A = B; B = Temp; }
    static void Swap(double& A, double& B) { double Temp = A; A = B; B = Temp; }
    static void Swap(bool& A, bool& B) { bool Temp = A; A = B; B = Temp; }
    static void Swap(char& A, char& B) { char Temp = A; A = B; B = Temp; }
    static void Swap(string& A, string& B) { string Temp = A; A = B; B = Temp; }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    // Shuffle array
    static void ShuffleArray(int arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
    }

    static void ShuffleArray(string arr[], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            Swap(arr[RandomNumber(0, arrLength - 1)], arr[RandomNumber(0, arrLength - 1)]);
    }

    // Tab generator
    static string Tabs(short NumberOfTabs)
    {
        string t = "";
        for (int i = 0; i < NumberOfTabs; i++)
            t += "\t";
        return t;
    }

    // Simple Caesar cipher encryption/decryption
    static string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < (int)Text.length(); i++)
            Text[i] = char((int)Text[i] + EncryptionKey);
        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < (int)Text.length(); i++)
            Text[i] = char((int)Text[i] - EncryptionKey);
        return Text;
    }
};
