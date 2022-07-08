#include <iostream>

void solve() {
    int n = 0, f_1 = 1, f_2 = 2;

    while (true) {
        if (!(f_2 & 0x1))
            n += f_2;

        f_2 += f_1;
        f_1 = f_2 - f_1;

        if (f_2 > 4000000)
            break;
    }

    std::cout << n << std::endl;
}

int main() {
    std::cout << "The sum of the even-valued terms of Fibonacci sequence whose values do not exceed four million is ";
    solve();
}