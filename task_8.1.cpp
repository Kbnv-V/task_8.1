#include <iostream>
#include <Windows.h>

void func(std::string& str, int& len)
{
    int lenStr = str.length();

    if (lenStr == len)
    {
        throw static_cast<std::string>("bad_lenght");
    }
    else
    {
        std::cout << "Длина слова \"" << str << "\" равна " << lenStr << std::endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;
    int len;

    try
    {
        std::cout << "Введите запретную длину: ";
        std::cin >> len;

        while (true)
        {
            std::cout << "Введите слово: ";
            std::cin >> str;

            func(str, len);
        }
    }
    catch (std::string err)
    {
        if (err == "bad_lenght")
        {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
        }
        else
        {
            std::cout << "Text error: " << err << std::endl;
        }
    }
}
