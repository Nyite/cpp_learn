#include <iostream>

void solve() {
    int n = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            n += i;
    }
    std::cout << n << std::endl;
}

int main() {
    std::cout << "The sum of all the multiples of 3 or 5 below 1000 is ";
    solve();
}
