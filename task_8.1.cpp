#include <iostream>
#include <exception>
#include <Windows.h>

class StringExeption : public std::exception
{
private:
    std::string error{};

public:
    StringExeption() = default;
    StringExeption(std::string_view setError) : error(setError) {}

    const char* what() const noexcept override
    {
        return error.c_str();
    }
};


int func(std::string& str, int& len)
{
    int lenStr = str.length();

    if (lenStr == len)
    {
        throw StringExeption("bad_lenght");
    }
    else
    {
        return lenStr;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str{};
    int forbiddenLen{}, strLen{};

    try
    {
        std::cout << "Введите запретную длину: ";
        std::cin >> forbiddenLen;

        while (true)
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            strLen = func(str, forbiddenLen);
            std::cout << "Длина слова \"" << str << "\" равна " << strLen << std::endl;
        }
    }
    catch (StringExeption& err)
    {
        if (static_cast<std::string>(err.what()) == "bad_lenght")
        {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
        }
        else
        {
            std::cout << "Text error: " << err.what() << std::endl;
        }
    }
}
