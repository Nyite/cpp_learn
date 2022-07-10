#include <iostream>

void task_1();
void task_2();

void mice();
void run();
void task_3();
void task_4();

double celc2farh(int);
void task_5();

double ly2astra(double lightyears);
void task_6();

void print_time(int hours, int minutes);
void task_7();

int main()
{
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    return 0;
}

void task_1()
{
    using namespace std;
    cout << "My address is \"Moscow, Russia\"\n";
}

void task_2()
{
    using namespace std;
    int farlongs;
    cout << "Enter the distance in farlongs: ";
    cin >> farlongs;
    cout << "That's " << 220 * farlongs << " yards!\n";
}

void task_3()
{
    mice();
    mice();
    run();
    run();
}

void mice()
{
    std::cout << "Three blind mice\n";
}

void run()
{
    std::cout << "See how they run\n";
}

void task_4()
{
    using namespace std;
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age in months is " << 12 * age << endl;
}

void task_5()
{
    using namespace std;
    int celcius;
    cout << "Please enter a Celcius value: ";
    cin >> celcius;
    cout << celcius << " degrees Celcius is " << celc2farh(celcius) << " degrees Fahrenheit\n";
}

double celc2farh(int celcius)
{
    return 1.8 * celcius + 32;
}

void task_6()
{
    using namespace std;
    double lightyears;
    cout << "Enter the nubmer of lightyears: ";
    cin >> lightyears;
    cout << lightyears << " lightyears = " << ly2astra(lightyears) << " astranomical units\n";
}

double ly2astra(double lightyears)
{
    return 63240 * lightyears;
}

void task_7()
{
    using namespace std;
    int hours, minutes;
    cout << "Enter the nubmer os hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    print_time(hours, minutes);
}

void print_time(int hours, int minutes)
{
    using namespace std;
    cout << "Time: " << hours << ":" << minutes << endl;
}
