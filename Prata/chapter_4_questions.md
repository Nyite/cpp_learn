# chapter_4_questions

1. Static C array initialization:

    a) `char actor[30];`

    b) `short betsie[100];`

    c) `float chuck[13];`

    d) `long double depsea[64];`

2. Static `std::array` initialization:

    a) `std::array<char, 30> actor;`

    b) `std::array<short, 100> betsie;`

    c) `std::array<float, 13> chuck;`

    d) `std::array<long double, 64> depsea;`

3. `int arr[5] {1, 3, 5, 7, 9};`
4. `int even = arr[0] + arr[4];`
5. `float ideas[10] {}; std::cout << ideas[1] << std::endl;`
6. `char str[] = "cheeseburger";`
7. `std::string str = "Waldorf Salad";`
8. Struct declaration:

    ```C++
    struct Fish {
        std::string kind;
        int weight;
        float length;
    };
    ```

9. `Fish fish {"Tuna", 3, 2.4};`
10. Enum declaration:

    ```C++
    enum Response {
        Yes = 1,
        No = 0,
        Maybae = 2
    }
    ```

11. Pointer dereference:

    ```C++
    double ted {};
    double *p_ted = &ted;
    std::cout << *p_ted << std::endl;
    ```

12. Array dereference:

    ```C++
    float tracle[10] {};
    float *tracle_p = tracle;
    std::cout << "The first element of tracle is: " << tracle_p[0] << std::endl;
    std::cout << "Last element of tracle is: " << *(tracle_p + 9) << std::endl;
    ```

13. Dynamic array and `std::vector` allocation:

    ```C++
    using namespace std;

    int arr_size {};
    cout << "Please, enter the size of wanted array: ";
    cin >> arr_size;

    int *c_arr = new int[arr_size] {};
    /* ... */
    delete [] c_arr;

    std::vector<int>(arr_size) {};
    ```

14. The listed code is correct and it will print the memmory address of used const string literal.

15. Dynamic struct allocation:

    ```C++
    Fish *fish = new Fish;
    std::cout << "Enter the fish kind: ";
    std::cin >> fish->kind;
    delete fish;
    ```

16. `std::cin` reads input stream until it finds `\n` symbol and leaves the that symbol in input stream. So the next time `std::cin` or `getline()` are called they immediatly get an input.

    `std::cin` insted of `getline()` tries to read input stream untill it gets a value. So this interchage will fix the problem.

17. `std::array` vs `std::vector` initialization:

    ```C++
    #include <string>
    #include <vector>
    #include <array>

    const int str_num = 10;

    std::array<std::string, str_num> arr;
    std::vector<std::string>(str_num) vec;
    ```
