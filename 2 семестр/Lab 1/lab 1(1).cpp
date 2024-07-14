//An enumeration for presenting the months of the year
#include <iostream>

enum class MonthOfYear {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

// Overloading the prefix ++ operator
MonthOfYear operator++(MonthOfYear& month) {
    if (month == MonthOfYear::December) {
        month = MonthOfYear::January;
    }
    else {
        month = (MonthOfYear) (static_cast<int>(month) + 1);
    }
    return month;
}

//Overloading the postfix ++ operator
MonthOfYear operator++(MonthOfYear& month, int) {
    MonthOfYear oldMonth = month;
    operator++(month);
    return oldMonth;
}

// Overloading the prefix -- operator
MonthOfYear operator--(MonthOfYear& month) {
    if (month == MonthOfYear::January) {
        month = MonthOfYear::December;
    }
    else {
        month = (MonthOfYear)(static_cast<int>(month) - 1);
    }
    return month;
}

//Overloading the postfix -- operator
MonthOfYear operator--(MonthOfYear& month, int) {
    MonthOfYear oldMonth = month;
    operator--(month);
    return oldMonth;
}

void printMonth(MonthOfYear month) {
    switch (month) {
    case MonthOfYear::January:
        std::cout << "January";
        break;
    case MonthOfYear::February:
        std::cout << "February";
        break;
    case MonthOfYear::March:
        std::cout << "March";
        break;
    case MonthOfYear::April:
        std::cout << "April";
        break;
    case MonthOfYear::May:
        std::cout << "May";
        break;
    case MonthOfYear::June:
        std::cout << "June";
        break;
    case MonthOfYear::July:
        std::cout << "July";
        break;
    case MonthOfYear::August:
        std::cout << "August";
        break;
    case MonthOfYear::September:
        std::cout << "September";
        break;
    case MonthOfYear::October:
        std::cout << "October";
        break;
    case MonthOfYear::November:
        std::cout << "November";
        break;
    case MonthOfYear::December:
        std::cout << "December";
        break;
    default:
        std::cout << "Invalid month";
    }
    std::cout << '\n';
}

int main()
{
    MonthOfYear month;
    //Testing operator ++
    std::cout << "Enter month number(from 1 to 12) to test operator ++:" << std::endl;
    int month_number;
    std::cin >> month_number;

    //Checking the validity of the month number
    if (month_number < 1 || month_number > 12) {
        std::cout << "Error: Invalid month number value";
        return 0;
    }

    //++month
    month = static_cast<MonthOfYear>(month_number);
    std::cout << "Print ++month:" << std::endl;
    for (int i = 0; i < 6; i++) {
        printMonth(++month);
    }
    std::cout << '\n';

    //month++
    month = static_cast<MonthOfYear>(month_number);
    std::cout << "Print month++:" << std::endl;
    for (int i = 0; i < 6; i++) {
        printMonth(month++);
    }
    std::cout << '\n';

    //Testing operator --
    std::cout << "Enter month number(from 1 to 12) to test operator --:" << std::endl;
    std::cin >> month_number;

    //Checking the validity of the month number
    if (month_number < 1 || month_number > 12) {
        std::cout << "Error: Invalid month number value";
        return 0;
    }

    //--month
    month = static_cast<MonthOfYear>(month_number);
    std::cout << "Print --month:" << std::endl;
    for (int i = 0; i < 6; i++) {
        printMonth(--month);
    }
    std::cout << '\n';

    //month--
    month = static_cast<MonthOfYear>(month_number);
    std::cout << "Print month--:" << std::endl;
    for (int i = 0; i < 6; i++) {
        printMonth(month--);
    }
    std::cout << '\n';

    return 0;
}