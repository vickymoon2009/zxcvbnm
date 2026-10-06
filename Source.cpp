#include <iostream>
using namespace std;


class Date
{
    int day;
    int month;
    int year;

public:

    Date()
    {
        cout << "Construct\n";
        day = month = year = 0;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void Output()
    {
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }

    void Init(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    int operator -(Date& b)
    {
        int d1 = (year * 365) + ((month - 1) * 30) + day;
        int d2 = (b.year * 365) + ((b.month - 1) * 30) + b.day;

        if (d1 > d2)
        {
            return d1 - d2;
        }
        else
        {
            return d2 - d1;
        }
    }
    Date& operator +(int AddDat)
    {
        *this += AddDat;
        return *this;
    }
    bool operator ==(Date& b)
    {
        if (day == b.day && month == b.month && year == b.year)
        {
            return true;
        }

        return false;
    }
    bool operator <(Date& b)
    {
        if (year < b.year)
        {
            return true;
        }

        if (year == b.year && month < b.month)
        {
            return true;
        }

        if (year == b.year && month == b.month && day < b.day)
        {
            return true;
        }

        return false;
    }

    bool operator >(Date& b)
    {
        if (year > b.year)
        {
            return true;
        }

        if (year == b.year && month > b.month)
        {
            return true;
        }

        if (year == b.year && month == b.month && day > b.day)
        {
            return true;
        }

        return false;
    }
    Date& operator +=(int AddDat)
    {
        for (int i = 0; i < AddDat; i++)
        {
            ++(*this);
        }

        return *this;
    }
    Date& operator++()
    {
        day++;

        int daysInMonth[12] =
        {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        if (day > daysInMonth[month - 1])
        {
            day = 1;
            month++;

            if (month > 12)
            {
                month = 1;
                year++;
            }
        }

        return *this;
    }
    Date& operator--()
    {
        day--;

        if (day == 0)
        {
            month--;

            if (month == 0)
            {
                month = 12;
                year--;
            }

            int daysInMonth[12] =
            {
                31, 28, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31
            };

            day = daysInMonth[month - 1];
        }

        return *this;
    }
};


int main()
{
    Date a(15, 9, 2026);
    Date b(14, 8, 2024);


    if (a > b)
    {
        cout << "a>b" << endl;
    }
    else if (a < b)
    {
        cout << "a<b" << endl;
    }
    else if (a == b)
    {
        cout << "a==b" << endl;
    }


    a += 20;
    a.Output();


    ++a;
    a.Output();


    --a;
    a.Output();
}
