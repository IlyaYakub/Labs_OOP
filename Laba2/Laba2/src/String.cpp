#pragma once

#include "String.h"
#include <iostream>
#include <cstring>
#include <cassert>

// Конструктор по умолчанию
String::String(const char* text) noexcept {
    if (text == nullptr) 
        std::cerr << "ERROR::INPUT. str = nullptr, please enter correct data!\n\n";
    else 
    {
        size_t length = 0;
        while (text[length] != '\0') 
            ++length;

        str = new char[length + 1];

        for (size_t i = 0; i < length; ++i) 
            str[i] = text[i];
        str[length] = '\0';
    }
}


// Конструктор копирования
String::String(const String& Str) noexcept {
    assert(Str.str != nullptr && "Cannot copy from nullptr string.");

    size_t length = 0;
    while (Str.str[length] != '\0') 
        ++length;
    
    str = new char[length + 1];

    for (size_t i = 0; i < length; ++i) 
        str[i] = Str.str[i];
    str[length] = '\0';
}

void String::Input() const
{
    for (int i = 0; i < strlen(str); i++)
        std::cin >> str[i];
}

// Оператор логического НЕ
bool String::operator!() const {
    return str == nullptr || str[0] == '\0';
}

// Оператор подстроки
char* String::operator()(int begin, int end) const {
    assert(begin >= 0 && end < std::strlen(str) && begin <= end && "Invalid substring range.");

    int length = end - begin + 1;
    char* substring = new char[length + 1];

    for (int i = 0; i < length; ++i) 
        substring[i] = str[begin + i];
    substring[length] = '\0';

    return substring;
}

// Оператор индексации
char String::operator[](int index) const {
    assert(index >= 0 && index < std::strlen(str) && "Index out of bounds.");
    return str[index];
}

// Оператор вывода
std::ostream& operator<<(std::ostream& out, const String& Str) {
    out << "Text in String type --> \"" << Str.str << "\"\n\n";
    return out;
}

// Деструктор
String::~String() noexcept {
    delete[] str;
}
