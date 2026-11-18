#include <iostream>
#include <exception>
#include <Windows.h>

class bad_lenght : public std::exception
{
private:
    std::string error{};

public:
    bad_lenght() = default;
    bad_lenght(std::string_view setError) : error(setError) {}

    const char* what() const noexcept override
    {
        return error.c_str();
    }
};


int func(std::string& str, size_t& len)
{
    size_t lenStr = str.length();

    if (lenStr == len)
    {
        throw bad_lenght("Вы ввели слово запретной длины! До свидания");
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
    size_t forbiddenLen{}, strLen{};

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
    catch (bad_lenght& err)
    {
        std::cout << err.what() << std::endl;
    }
}
