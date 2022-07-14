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
    string first_name;
    string last_name;
    char grade;
    int age;

    cout << "What is you first name? ";
    getline(cin, first_name);
    cout << "What is you last name? ";
    getline(cin, last_name);
    cout << "What letter grade do you deserve? ";
    (cin >> grade).ignore(1000, '\n');
    grade += 1;
    cout << "What is you age? ";
    cin >> age;

    cout << "Name: " << last_name + ", " + first_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age << endl;
}

void task_2()
{
    const int ArSize = 20;
    string name;
    string desert;

    cout << "Enter yout name:\n";
    getline(cin, name);
    cout << "Enter ypu favourite desert:\n";
    getline(cin, desert);
    cout << "I have some delicious " << desert;
    cout << " for you, " << name << endl;
}

void task_3()
{
    const int buf_size = 100;
    const int out_buf_size = 200;

    char name_buf[buf_size] {};
    char last_name_buf[buf_size] {};

    cout << "Enter your name: ";
    cin.getline(name_buf, buf_size);
    cout << "Enter your last name: ";
    cin.getline(last_name_buf, buf_size);

    char *name = new char[strlen(name_buf) + 1];
    strcpy(name, name_buf);
    char *last_name = new char[strlen(last_name_buf) + 1];
    strcpy(last_name, last_name_buf);

    char out_buf[out_buf_size] = "Here's the information in the single string: ";
    strcat(out_buf, name);
    strcat(out_buf, ", ");
    strcat(out_buf, last_name);

    char *out = new char[strlen(out_buf) + 1];
    strcpy(out, out_buf);

    cout << out << endl;

    delete [] name;
    delete [] last_name;
    delete [] out;
}

void task_4()
{
    string name;
    string last_name;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your last name: ";
    getline(cin, last_name);

    string out = "Here's the information in the single string: " +
    name + ", " + last_name;
    cout << out << endl;
}

struct CandyBar {
    string title;
    double weight;
    int calories;
};

void task_5()
{
    CandyBar snack {
        "Mocha Munch",
        2.3,
        350
    };

    cout << "snack.title:\t" << snack.title << endl;
    cout << "snack.weight:\t" << snack.weight << endl;
    cout << "snack.calories:\t" << snack.calories << endl;
}

void task_6()
{
    CandyBar sweets[3] {};
    for (int i = 0; i < 3; i++) {
        sweets[i].title = "title " + to_string(i);
        sweets[i].weight = (i + 1) / 0.75;
        sweets[i].calories = (i + 1) * 10;

        cout << "sweets[" << i << "] title:\t" << sweets[i].title << endl;
        cout << "sweets[" << i << "] weight:\t" << sweets[i].weight << endl;
        cout << "sweets[" << i << "] calories:\t" << sweets[i].calories << endl;
    }
}

struct Pizza {
    string producer;
    float diametr;
    float weight;
};

void task_7()
{
    Pizza pizza {};

    cout << "Enter the producer of the pizza: ";
    getline(cin, pizza.producer);
    cout << "Enter the diametr of the pizza: ";
    cin >> pizza.diametr;
    cout << "Enter the weight of the pizza: ";
    cin >> pizza.weight;

    cout << "Your pizza struct is:\n";
    cout << "pizza.producer:\t\t" << pizza.producer << endl;
    cout << "pizza.diametr:\t\t" << pizza.diametr << endl;
    cout << "pizza.prodweightucer:\t" << pizza.weight << endl;
}

void task_8()
{
    Pizza *pizza = new Pizza {};

    cout << "Enter the diametr of the pizza: ";
    (cin >> pizza->diametr).get();
    cout << "Enter the producer of the pizza: ";
    getline(cin, pizza->producer);
    cout << "Enter the weight of the pizza: ";
    cin >> pizza->weight;

    cout << "Your pizza struct is:\n";
    cout << "pizza.producer:\t\t" << pizza->producer << endl;
    cout << "pizza.diametr:\t\t" << pizza->diametr << endl;
    cout << "pizza.prodweightucer:\t" << pizza->weight << endl;

    delete pizza;
}

void task_9()
{
    CandyBar *sweets = new CandyBar[3] {};
    for (int i = 0; i < 3; i++) {
        sweets[i].title = "title " + to_string(i);
        sweets[i].weight = (i + 1) / 0.75;
        sweets[i].calories = (i + 1) * 10;

        cout << "sweets[" << i << "] title:\t" << sweets[i].title << endl;
        cout << "sweets[" << i << "] weight:\t" << sweets[i].weight << endl;
        cout << "sweets[" << i << "] calories:\t" << sweets[i].calories << endl;
    }

    delete [] sweets;
}

void task_10()
{
    const int arr_size {3};
    array<float, arr_size> results {};

    cout << "Enter " << arr_size << " results of marathon: ";
    cin >> results[0] >> results[1] >> results[2];
    cout << "Your results are: " << results[0] << ", " <<
    results[1] << ", " << results[2] << " | avg = " <<
    (results[0] + results[1] + results[2]) / arr_size << endl;
}
