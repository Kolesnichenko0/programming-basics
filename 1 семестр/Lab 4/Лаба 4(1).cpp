//Двійкове представлення числа
#include <iostream>
using namespace std;

void next(unsigned short int a, int counter)
{
    cout << "Двiйкове представлення числа: ";
    for (int j = counter; j < 16; j++) // цикл буде починатися з counter, щоб не писати 0, кількість яких порахував лічильник
    {
        cout << (a >> 15);
        a <<= 1;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "UKR");
    unsigned short int a;
    while (true)
    {
        int counter = 0;
        cout << "Введiть коротке цiле число без знаку для двiйкового представляення цього числа:" << endl;
        cin >> a;
        for (int i = 0; i < 16; i++)
        {
            int e = (a >> 15); // e - 1 чи 0
            if (e == 0)
            {
                a <<= 1;
                counter += 1; // counter - лічильник, який рахує кількість 0 попереду
            }
            else
            {
                next(a, counter); // функція , яка буде писати двійкове представлення числа без нулів попереду
                break;
            }

        }
        if (a == 0)
        {
            cout << "Двiйкове представлення числа: 0";
            break;
        }
    }



}