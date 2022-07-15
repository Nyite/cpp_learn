#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>

using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
void task_7();
void task_8();
void task_9();
void task_10();

int main ()
{
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    task_8();
    task_9();
    task_10();
    return 0;
}

void task_1()
{
    int max, min {};
    cout << "Enter minimum and maximum: ";
    cin >> min >> max;
    for (int i = min + 1; i <= max; ++i)
        min += i;
    cout << "Your sum is: " << min << endl;
}

void task_2()
{
    const size_t ArSize = 100;
    array<long double, ArSize> fact {1, 1};

    for (size_t i = 2; i < ArSize; ++i) {
        fact[i] = i * fact[i - 1];
    }
    cout << ArSize << "! = " << fact[ArSize - 1] << endl;
}

void task_3()
{
    long double sum {};
    double num;
    cout << "Enter the numbers or stop by entering 0:\n";

    while ((cin >> num) && (num != 0))
        sum += num;

    cout << "Your sum is: " << sum << endl;
}

void task_4()
{
    const double percent_1 = 1.10;
    const double percent_2 = 1.05;
    const double start_money = 100;
    double dafna, kleo {start_money};

    int year_cnt {};
    do {
        dafna += start_money * percent_1; // can be calculated before loop
        kleo *= percent_2;
        ++year_cnt;
        cout << "[Year " << year_cnt << "] Dafna's balance: " << dafna << "\tKleo's balance: " << kleo << endl;
    } while (dafna > kleo);
}

const unsigned char Months = 12;
const string month[Months] {
    "January",
    "Febuary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

void task_5()
{
    int sels[Months];
    int sum {};
    for (unsigned char i = 0; i < Months; ++i) {
        cout << "How many books was sold in " << month[i] << "?\n";
        cin >> sels[i];
        sum += sels[i];
    }
    cout << "You've sold: " << sum << " books in total\n";
}

void task_6()
{
    const unsigned char Years = 3;
    int sels[Years][Months];
    int sum, total {};
    for (unsigned char y = 0; y < Years; ++y) {
        sum = 0;
        for (unsigned char m = 0; m < Months; ++m) {
            cout << "[Year " << y + 2000 << "] How many books was sold in " << month[m] << "?\n";
            cin >> sels[y][m];
            sum += sels[y][m];
        }
        cout << "[Year " << y + 2000 << "] You've sold: " << sum << " books\n";
        total += sum;
    }
    cout << "You've sold: " << total << " books in total\n";
}

void task_7()
{
    struct Car {
        string title;
        int year_of_manifacture;
    };

    int num_cars;
    cout << "How many cars to catalog?\n";
    (cin >> num_cars).get();

    Car *catalog = new Car[num_cars];
    for (int i = 0; i < num_cars; ++i) {
        cout << "Car #"<< i <<":\nInsert the producer: ";
        getline(cin, catalog[i].title);
        cout << "Insert the year of manifacture: ";
        (cin >> catalog[i].year_of_manifacture).get();
    }
    cout << "Your collection:\n";
    for (int i = 0; i < num_cars; ++i) {
        cout << catalog[i].year_of_manifacture << " " << catalog[i].title << endl;
    }

    delete [] catalog;
}

void task_8()
{
    const int Word_len = 100;
    char ch;
    char word[Word_len] {};
    int count {};

    cout << "Enter your words:\n";
    cout.setf(ios::boolalpha);
    while (cin >> word) {
        if (!strcmp(word, "done"))
            break;
        ++count;
    }
    cout << "You have entered " << count << " words\n";
}

void task_9()
{
    string word;
    int count {};

    cout << "Enter your words:\n";
    while (cin >> word) {
        if (word == "done")
            break;
        ++count;
    }
    cout << "You have entered " << count << " words\n";
}

void task_10()
{
    int num {};

    cout << "Enter the amount of rows: ";
    cin >> num;
    for (int i = 1, j = num - 1; i <= num; ++i, --j) {
        for (int k = 0; k < j; ++k) cout << ".";
        for (int k = 0; k < i; ++k) cout << "*";
        cout << endl;
    }
}
