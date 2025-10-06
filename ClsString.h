#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class clsString
{
private:
    std::string _Value;

public:
    // Constructors
    clsString() : _Value("") {}
    clsString(const std::string& value) : _Value(value) {}

    // Getter/Setter
    void SetValue(const std::string& value) { _Value = value; }
    std::string GetValue() const { return _Value; }

    __declspec(property(get = GetValue, put = SetValue)) std::string Value;

    // ---- Length ----
    static short Length(const std::string& s) { return static_cast<short>(s.length()); }
    short Length() const { return static_cast<short>(_Value.length()); }

    // ---- Count Words ----
    static short CountWords(std::string s) {
        short counter = 0;
        std::string delim = " ";
        size_t pos;

        while ((pos = s.find(delim)) != std::string::npos) {
            std::string word = s.substr(0, pos);
            if (!word.empty()) counter++;
            s.erase(0, pos + delim.length());
        }
        if (!s.empty()) counter++;
        return counter;
    }
    short CountWords() const { return CountWords(_Value); }

    // ---- Upper / Lower First Letters ----
    static std::string UpperFirstLetterOfEachWord(std::string s) {
        bool isFirst = true;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && isFirst) s[i] = std::toupper(s[i]);
            isFirst = (s[i] == ' ');
        }
        return s;
    }
    void UpperFirstLetterOfEachWord() { _Value = UpperFirstLetterOfEachWord(_Value); }

    static std::string LowerFirstLetterOfEachWord(std::string s) {
        bool isFirst = true;
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && isFirst) s[i] = std::tolower(s[i]);
            isFirst = (s[i] == ' ');
        }
        return s;
    }
    void LowerFirstLetterOfEachWord() { _Value = LowerFirstLetterOfEachWord(_Value); }

    // ---- Upper/Lower whole string ----
    static std::string UpperAllString(std::string s) {
        for (char& c : s) c = std::toupper(c);
        return s;
    }
    void UpperAllString() { _Value = UpperAllString(_Value); }

    static std::string LowerAllString(std::string s) {
        for (char& c : s) c = std::tolower(c);
        return s;
    }
    void LowerAllString() { _Value = LowerAllString(_Value); }

    // ---- Case Inversion ----
    static char InvertLetterCase(char c) { return std::isupper(c) ? std::tolower(c) : std::toupper(c); }
    static std::string InvertAllLettersCase(std::string s) {
        for (char& c : s) c = InvertLetterCase(c);
        return s;
    }
    void InvertAllLettersCase() { _Value = InvertAllLettersCase(_Value); }

    // ---- Letter Counting ----
    enum enWhatToCount { SmallLetters, CapitalLetters, All };

    static short CountLetters(const std::string& s, enWhatToCount what = All) {
        if (what == All) return static_cast<short>(s.length());
        short counter = 0;
        for (char c : s) {
            if (what == CapitalLetters && std::isupper(c)) counter++;
            if (what == SmallLetters && std::islower(c)) counter++;
        }
        return counter;
    }

    static short CountCapitalLetters(const std::string& s) {
        short counter = 0;
        for (char c : s) if (std::isupper(c)) counter++;
        return counter;
    }
    short CountCapitalLetters() const { return CountCapitalLetters(_Value); }

    static short CountSmallLetters(const std::string& s) {
        short counter = 0;
        for (char c : s) if (std::islower(c)) counter++;
        return counter;
    }
    short CountSmallLetters() const { return CountSmallLetters(_Value); }

    static short CountSpecificLetter(const std::string& s, char letter, bool matchCase = true) {
        short counter = 0;
        for (char c : s) {
            if (matchCase ? (c == letter) : (std::tolower(c) == std::tolower(letter)))
                counter++;
        }
        return counter;
    }
    short CountSpecificLetter(char letter, bool matchCase = true) const {
        return CountSpecificLetter(_Value, letter, matchCase);
    }

    // ---- Vowels ----
    static bool IsVowel(char c) {
        c = std::tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    static short CountVowels(const std::string& s) {
        short counter = 0;
        for (char c : s) if (IsVowel(c)) counter++;
        return counter;
    }
    short CountVowels() const { return CountVowels(_Value); }

    // ---- Split ----
    static std::vector<std::string> Split(std::string s, const std::string& delim) {
        std::vector<std::string> result;
        size_t pos;
        while ((pos = s.find(delim)) != std::string::npos) {
            std::string word = s.substr(0, pos);
            if (!word.empty()) result.push_back(word);
            s.erase(0, pos + delim.length());
        }
        if (!s.empty()) result.push_back(s);
        return result;
    }
    std::vector<std::string> Split(const std::string& delim) const { return Split(_Value, delim); }

    // ---- Trimming ----
    static std::string TrimLeft(const std::string& s) {
        size_t i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        return s.substr(i);
    }
    void TrimLeft() { _Value = TrimLeft(_Value); }

    static std::string TrimRight(const std::string& s) {
        if (s.empty()) return "";
        size_t i = s.length() - 1;
        while (i != std::string::npos && s[i] == ' ') {
            if (i == 0) return "";
            i--;
        }
        return s.substr(0, i + 1);
    }
    void TrimRight() { _Value = TrimRight(_Value); }

    static std::string Trim(const std::string& s) { return TrimLeft(TrimRight(s)); }
    void Trim() { _Value = Trim(_Value); }

    // ---- Join ----
    static std::string JoinString(const std::vector<std::string>& arr, const std::string& delim) {
        if (arr.empty()) return "";
        std::string result;
        for (const auto& s : arr) result += s + delim;
        return result.substr(0, result.length() - delim.length());
    }

    static std::string JoinString(std::string arr[], short length, const std::string& delim) {
        if (length == 0) return "";
        std::string result;
        for (short i = 0; i < length; i++) result += arr[i] + delim;
        return result.substr(0, result.length() - delim.length());
    }

    // ---- Reverse Words ----
    static std::string ReverseWordsInString(const std::string& s) {
        auto words = Split(s, " ");
        std::string result;
        for (auto it = words.rbegin(); it != words.rend(); ++it) result += *it + " ";
        if (!result.empty()) result.pop_back(); // remove last space
        return result;
    }
    void ReverseWordsInString() { _Value = ReverseWordsInString(_Value); }

    // ---- Replace ----
    static std::string ReplaceWord(const std::string& s, const std::string& toReplace,
        const std::string& replaceWith, bool matchCase = true) {
        auto words = Split(s, " ");
        for (auto& word : words) {
            if (matchCase) {
                if (word == toReplace) word = replaceWith;
            }
            else {
                if (LowerAllString(word) == LowerAllString(toReplace)) word = replaceWith;
            }
        }
        return JoinString(words, " ");
    }
    std::string ReplaceWord(const std::string& toReplace, const std::string& replaceWith) {
        return ReplaceWord(_Value, toReplace, replaceWith);
    }

    // ---- Remove Punctuations ----
    static std::string RemovePunctuations(const std::string& s) {
        std::string result;
        for (char c : s) if (!std::ispunct(c)) result += c;
        return result;
    }
    void RemovePunctuations() { _Value = RemovePunctuations(_Value); }
};
