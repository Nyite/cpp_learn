#include <iostream>

void task_1();
float calcIBM(int, int, int);
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
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

    int height;
    cout << "Enter your height is inches: ___\b\b\b";
    cin >> height;
    cout << "Your height is " << height / 12 << "ft " << height % 12 << "in\n";
}

void task_2()
{
    using namespace std;

    int feet, inches, pounds;
    cout << "Enter your height is feet and inches: ___\b\b\b";
    cin >> feet;
    cin >> inches;
    cout << "Enter your weight is pounds: ___\b\b\b";
    cin >> pounds;

    cout << "Your IBM is " << calcIBM(feet, inches, pounds) << endl;
}

float calcIBM(int feet, int inches, int pounds)
{
    int total_inches = feet * 12 + inches;
    float metric_height = total_inches * 0.0254f;
    float kilograms = pounds / 2.2f;

    return kilograms / (metric_height * metric_height);
}

void task_3()
{
    using namespace std;

    int deg, min, sec;
    cout << "Enter a latitude in degrees, minutes, and seconds: __ __ __\b\b\b\b\b\b\b\b\b";
    cin >> deg >> min >> sec;

    float out_deg = deg + min / 60.0f + sec / 3600.0f;
    cout << deg << " degrees, " << min << " minutes, " << sec << " seconds = " << out_deg << endl;
}

void task_4()
{
    using namespace std;

    unsigned long long sec;
    cout << "Enter the number of seconds: ";
    cin >> sec;
    auto input_sec = sec;
    int days, hours, minutes;
    days = sec / (24 * 60 * 60);
    sec %= 24 * 60 * 60;
    hours = sec / (60 * 60);
    sec %= 60 * 60;
    minutes = sec / 60;
    sec %= 60;
    cout << input_sec <<" seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << sec << " seconds\n";
}

void task_5()
{
    using namespace std;
    unsigned long long pop;
    unsigned long long country;

    cout << "Enter the world's population: ";
    cin >> pop;
    cout << "Enter th Russia population: ";
    cin >> country;
    cout << "The population of Russia is " << (long double) country / pop * 100 << "% of the world's population\n";
}

void task_6()
{
    using namespace std;
    double kilometers, liters;
    cout << "Enter the number of kilometers: ___\b\b\b";
    cin >> kilometers;
        cout << "Enter the number of liters: ___\b\b\b";
    cin >> liters;
    cout << "Your fuel consumption [l/100km]: " << (liters / kilometers) * 100 << endl;
}

void task_7()
{
    using namespace std;
    double consumption;
    cout << "Enter the fuel consumption [l/100km]: ___\b\b\b";
    cin >> consumption;
    consumption /= 100; // [l/km]
    cout << "Your fuel consumption [gal/mil]: " << ( 3.8875 * 0.6214 ) / consumption << endl;
}