
// Індивідуальне завдання

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
    setlocale(LC_ALL, "UKR");
    const int m = 3;
    const int n = 5;
    int a[3][5]; 
    srand(time(0));
    for (int i = 0; i < m; i++) // генерація випадкових чисел
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (rand() % 40) - 18;
        }
    }
    
    cout << "Початковий масив:" << endl;
    for (int i = 0; i < m; i++) // вивід начального масиву
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << '\t';
            }
            cout << endl;
        }
    bool checking = false;
    for (int i = 0; i < m; i++) // перевірка , чи можливе перетворення
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                checking = true;
           }
        }
    }

    if (checking == false) 
    {
        cerr << "У масивi немає парних чисел, тому перетворення неможливе" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) //перетворення елементів
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                a[i][j] = pow(a[i][j], 2);
            }
        }
    }

    cout << "Масив пiсля перетворення елементiв початкового масиву: " << endl;
    for (int i = 0; i < m; i++) // вивід масиву після першого кроку
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }

    //for (int i = 0; i < n; i++) // перевірка, чи можливе заповнення
   // {
        //for (int j = 0; j < m; j++)
        //{
          //  for (int p = 0; p < m; p++)
        //    {
      //          if (p==j)
        //        {
      //              p++;
    //                
  //              }
 //               if (a[p][i] == a[j][i])
//                {
//                    cerr << "У стовпчику два однакових числа, тому один мiнiмум не знайти" << endl;
//                    return 0;
//                }
//            }
//        }
//
//}

    double b[m][n];         
    for (int i = 0; i < m; i++) // задаємо іншому масиву такі ж значення, що й у a масиві
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    
    }

    double t[n];

    for (int i = 0; i < n; i++) // заповнення елементів 
    {
            int Min = b[0][i];
            for (int j = 1; j < m; j++)
            {
                if (Min > b[j][i])
                {
                    Min = b[j][i];
                    double y = cbrt(b[j][i]);
                    b[j][i] = cbrt(b[j][i]);
                    t[i] = y;
                }

            }
            if (Min == b[0][i])
            {
                double h = cbrt(b[0][i]);
                b[0][i] = cbrt(b[0][i]);
                t[i] = h;
            }
    }
   

    cout << "Масив пiсля заповнення елементiв масиву, який отримали пiсля першого кроку:" << endl;
    for (int i = 0; i < n; i++) // вивід масиву після другого кроку
    {

            cout << t[i] << '\t';


    
    }



    return 0;
}


