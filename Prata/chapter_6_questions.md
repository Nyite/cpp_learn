# chapter_6_questions

1. In version 2 the 2nd `if` will only be evaluated if the first `if` is `false`.

    Where in version 1 the 2nd will be allways be evaluated (even if it's already known that `ch == ' '`)

2. `++ch` is `char` and `ch + 1` is int. So they will be displayed differently.

3. Console log will look like this:

    ```C++
    Hi!
    H$i$!$    
    $Send $10 or $20 now!
    S$e$n$d$ $ct1 = 9, ct2 = 9
    ```

    The problem is in `ch = '$'` instead of `ch == '$'`

4. Some combined conditions:

    a) `wieght >= 115 && wieght < 125`

    b) `ch == 'q' || ch == 'Q'`

    c) `x % 2 == 0 && x != 26`

    d) `x % 2 == 0 && !(x % 26 == 0)`

    e) `donation >= 1000 && donation <= 2000 || guest == 1`

    f) `islower(ch) || isupper(ch)`

5. Yes, if `x` is a `bool` variable.

6. `x < 0 ? -x : x`

7. Switch usecase:

    ```C++
    switch (ch) {
        case 'A': a_grade++;
        break;
        case 'B': b_grade++;
        break;
        case 'C': c_grade++;
        break;
        case 'D': d_grade++;
        break;
        default: f_grade++;
    }
    ```

8. `cin >> int` will rise `fallbit` if input won't contain an integer. `cin >> char` will accept any input wich then can be processed accordingly.

9. While loop changes:

    ```C++
    while (cin.get(ch) && ch != 'Q') {
        if (ch == '\n')
            line++;
    }
    ```
