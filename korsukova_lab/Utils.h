#pragma once
#include <iostream>
#include <string>

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::wcin >> x).fail()
        || std::wcin.peek() != '\n'
        || x < min || x > max)
    {
        std::wcin.clear();
        std::wcin.ignore(256, '\n');
        std::wcout << L"\nНеверный ввод!" << std::endl;
        std::wcout << L"Введите число от " << min << " до " << max << std::endl;
    }
    //std::cerr << x << std::endl;
    return x;
}

inline std::wstring input_string()
{
    //std::wcin >> std::ws;
    std::wstring str;
    std::getline(std::wcin>> std::ws, str);
    //std::cerr << str << std::endl;
    return str;
}