# chapter_5_questions

1. `for` and `while` loops will evaluate and check the continue expression before entering the loop body. `do while` loop enters the loop body and checks the continue expression after body operator is called.

2. Code output:

    ```txt
    01234
    ```

3. Code output:

    ```txt
    0369
    12
    ```

4. Code output:

    ```txt
    6
    8
    ```

5. Code output:

    ```txt
    k = 8
    ```

6. Multiplication `for` loop:

    ```C++
    for (int i = 1; i <= 64; i *= 2)
        std::cout << i << " ";
    std::cout << std::endl;
    ```

7. Use code block limmited with `{ }`.

8. `int x = (1,024);` is correct. It declares an `int` variable with name `x` and initializes it to `024` (octal number).

    `int y; y = 1,024;` is correct. It separately declares an `int` variable with name `y` and initializes it to `1`.

9. `cin >> ch` will skip spaces, `\t\n\r`. `cin.get(ch)` returns `cin` and `ch=cin.get()` returns an `int` (ASCII or Unicode code of char red). So `cin.get()` requires extra steps in order not to assign `EOF`(-1) to an `unsigned char`. On the other hand, `cin.get(ch)` returns the input stream wich can be casted to bool. The obtianed bool value will be `true` if no errors happened during the last input or no `<EOF>` was red, and `false` otherwise.
