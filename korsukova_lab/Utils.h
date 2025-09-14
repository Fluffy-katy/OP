#pragma once
#include <iostream>
#include <string>

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail()
        || std::cin.peek() != '\n'
        || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\nНеверный ввод!" << std::endl;
        std::cout << "Введите число от " << min << " до " << max << std::endl;
    }
    //std::cerr << x << std::endl;
    return x;
}

inline std::string input_string()
{
    std::cin >> std::ws;
    std::string str;
    std::getline(std::cin, str);
    //std::cerr << str << std::endl;
    return str;
}