//Перевірка паліндромів
#include <iostream>
#include <cstring>
#include <clocale>
#include <cstdio>



int main()
{
    std::setlocale(LC_ALL, "UKR");
    char str[80], result[80];
    std::printf("Введiть фразу:\n");
    std::cin.getline(str, 80);
    int i, k;
    for (i = 0, k = 0; i <= std::strlen(str); i++)
    {
        if (str[i] > '@' || str[i] <= 'ї')
        {
            result[k] = str[i];
            k++;
        }
    }
    for (i = 0; i < k / 2; i++)
    {
        if (result[i] != result[k - 1 - i])
        {
            std::printf("Не полiндром\n");
            return 0;
        }
    }
    std::printf("Полiндром\n");
    return 0;
}