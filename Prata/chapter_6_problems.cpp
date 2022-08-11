#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <cctype>
#include <fstream>

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
    return 0;
}

void task_1()
{
    char ch;

    cout << "Enter or terminate with \"@\":\n";
    while (cin.get(ch) && ch != '@') {
        if (islower(ch))
            cout << char(toupper(ch));
        else if (isupper(ch))
            cout << char(tolower(ch));
        else
            cout << ch;
    }
}

void task_2()
{
    const int Donations = 10;

    int avg, cnt {};
    double donations[Donations];
    cout << "Enter your donations:\n";

    for (; cin >> donations[cnt] && cnt < Donations; ++cnt) {
        avg += donations[cnt];
    }

    avg /= cnt;
    cout << "Donation avarage is " << avg << endl;
    for (int i = 0; i < cnt; ++i) {
        if (donations[i] > avg)
            cout << "Donation #" << i + 1 << " is above avarage\n";
    }
}

void task_3()
{
    cout << "Please enter one of the following choices:\n";
    cout << "c) carnivore\tp) pianist\nt) tree\t\tg) game\n";

    char ch;
    while (cin >> ch) {
        switch (ch)
        {
        case 'c': cout << "A maple is a carnivore\n";
            break;
        case 'p': cout << "A maple is a pianist\n";
            break;
        case 't': cout << "A maple is a tree\n";
            break;
        case 'g': cout << "A maple is a game\n";
            break;
        default: cout << "Please enter a c, p, t or g: ";
            continue;
        }
        break;
    }
}

void task_4()
{
    const int Strsize = 32;
    const int Participants = 5;
    struct Bop {
        char fullname[Strsize]; // pref = 0
        char title[Strsize];    // pref = 1
        char bopname[Strsize];  // pref = 2

        int preference;
    };

    Bop community_members[Participants] {
        { "Wimp Macho", "Wimp Macho", "Ananas", 0 },
        { "Raki Rhodes", "Junior Programmer", "Bannana", 1 },
        { "Celia Laiter", "MIPS", "Bluberry", 2 },
        { "Hoppy Hipman", "Analyst Trainee", "Wolf", 0 },
        { "Pat Hand", "LOOPY", "Moon", 2 }
    };

    cout << "Benevolent Oreder of Programmers Report\n";
    cout << "a. display by name\tb. display by title\n";
    cout << "c. display by bopname\td. display by preference\n";
    cout << "q. quit\nEnter your choice: ";

    char ch;
    while (cin >> ch) {
        switch (ch)
        {
        case 'a':
            for (int i = 0; i < Participants; ++i) {
                cout << community_members[i].fullname << endl;
            }
            break;
        case 'b':
            for (int i = 0; i < Participants; ++i) {
                cout << community_members[i].title << endl;
            }
            break;
        case 'c':
            for (int i = 0; i < Participants; ++i) {
                cout << community_members[i].bopname << endl;
            }
            break;
        case 'd':
            for (int i = 0; i < Participants; ++i) {
                switch (community_members[i].preference)
                {
                case 0: cout << community_members[i].fullname << endl;
                    break;
                case 1: cout << community_members[i].title << endl;
                    break;
                case 2: cout << community_members[i].bopname << endl;
                    break;
                }
            }
            break;
        case 'q': cout << "Bye!\n";
            return;
        default: cout << "Please enter \'a\', \'b\', \'c\', \'d\' or \'q\': ";
            continue;
        }
        cout << "Next choice: ";
    }
}

void apply_tax(long &tvarps, float &tax, int tax_thr, float tax_pct)
{
    if (tvarps > tax_thr) {
        tax += tax_thr * tax_pct;
        tvarps -= tax_thr;
    } else {
        tax += tvarps * tax_pct;
        tvarps = 0;
    }
}

void task_5()
{
    const int tax_stages = 4;
    int tax_thr[tax_stages] { 5000, 10000, 20000, 35000 };
    float tax_pct[tax_stages] { 0.00f, 0.10f, 0.15f, 0.20f };

    float tax;
    long tvarps;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Enter the number of tvarps: ";
    while (cin >> tvarps && tvarps > 0)
    {
        cout << tvarps << endl;
        tax = 0.00f;
        for (int i = 0; i < tax_stages - 1 && tvarps > 0; ++i)
            apply_tax(tvarps, tax, tax_thr[i], tax_pct[i]);
        tax += tvarps * tax_pct[tax_stages - 1];
        cout << "Your tax is: " << tax << "!\n";
        cout << "Enter a new number of tvarps: ";
    }
    cout << "Bye!\n";
}

struct Member {
    string name;
    double donation;
};

void task_6()
{
    int members_num;
    cout << "Enter the number of members: ";
    (cin >> members_num).get();

    Member *members = new Member[members_num];

    for (int i = 0; i < members_num; ++i) {
        cout << "Please enter name and donation from member #" << i + 1 << endl;
        getline(cin, members[i].name);
        (cin >> members[i].donation).get();
    }

    bool patron_flag = false;
    cout << "Grand Patrons\n";
    for (int i = 0; i < members_num; ++i) {
        if (members[i].donation >= 10000) {
            cout << members[i].name << " donated " << members[i].donation << endl;
            patron_flag = true;
        }
    }
    if (!patron_flag) cout << "none\n";
    else patron_flag = false;

    cout << "Patrons\n";
    for (int i = 0; i < members_num; ++i) {
        if (members[i].donation < 10000) {
            cout << members[i].name << " donated " << members[i].donation << endl;
            patron_flag = true;
        }
    }
    if (!patron_flag) cout << "none\n";

    delete[] members;
}

void task_7()
{
    string word;
    int vowels, consonants, others {};
    while (cin >> word && word != "q")
    {
        if (isalpha(word[0]))
            switch (tolower(word[0])) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u': ++vowels;
                    break;
                
                default: ++consonants;
                    break;
            }
        else
            ++others;
    }
    cout << vowels << " words beginning with vowels\n";
    cout << consonants << " words beginning with consonants\n";
    cout << others << " others\n";
}

void task_8()
{
    ifstream fin;
    fin.open("input.txt", ios::in);

    int cnt {};
    while (fin.get() != EOF) ++cnt;
    fin.close();

    cout << "\"input.txt\" contsins " << cnt << " symbols\n";
}

void task_9()
{
    ifstream fin;
    fin.open("input.txt", ios::in);

    int members_num;
    (fin >> members_num).get();
    Member *members = new Member[members_num];

    for (int i = 0; i < members_num; ++i) {
        getline(fin, members[i].name);
        (fin >> members[i].donation).get();
    }

    bool patron_flag = false;
    cout << "Grand Patrons\n";
    for (int i = 0; i < members_num; ++i) {
        if (members[i].donation >= 10000) {
            cout << members[i].name << " donated " << members[i].donation << endl;
            patron_flag = true;
        }
    }
    if (!patron_flag) cout << "none\n";
    else patron_flag = false;

    cout << "Patrons\n";
    for (int i = 0; i < members_num; ++i) {
        if (members[i].donation < 10000) {
            cout << members[i].name << " donated " << members[i].donation << endl;
            patron_flag = true;
        }
    }
    if (!patron_flag) cout << "none\n";

    delete[] members;
    fin.close();
}
