# C++ Primer Plus code sheatsheet

C++ built-in [operators, precedence, and associativity](https://docs.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-170)

Some `iostream` API:

- `cin.get(char *, int)` will never pass throught `<Enter>`.
- `cin.get(char)` can be implicitly converted to `bool`: to `true` if last read was successful (`cin.eof()` and `cin.fail()` are false and no other errors are present), to `false` if not.
- `cin.get(void)` returns an ASCII code for a `char` it have red, but EOF (-1) if if reads `<EOF>` or `<Ctrl+Z><Enter>`. In some OS default `char` type can be `unsigned` and `(ch = cin.get()) != EOF` will always be true. So you need to specify `ch` as `signed char`.
- `cout.put()` puts a charecter in output stream.
- `cout.setf()` sets formating for float-point numbers.
  - `fixed` set fixed precision.
  - `floatfiled` set precision to 6th decimal place.
  - `ios::boolalpha` enables printing bool values as `true` and `flase` instead of `1` and `0`.
- `hex` & `oct` manipulators determine the output format of an integer typed value.

Some pointer notation:

- There is a pointer to an array:

  ```C++
  int my_arr[10];
  int *arr_ptr = my_arr; // pointer to the first array element
  int (*big_ptr)[10] = &my_arr; // pointer to the sizeof(int)*10 memory block
  ```
  
  So pointer ariphmetics will look like this:
  
  ```C++
  arr_ptr + 1; // <=> arr_ptr + sizeof(int)
  big_ptr + 1; // <=> git_ptr + sizeof(int)*10 / DOESN'T WORK
  ```

- `sizeof` behaviour:

  ```C++
  sizeof(my_arr); // == sizeof(int)*10
  sizeof(arr_ptr); // == ptr size (4 to 8 bytes)
  sizeof(big_ptr); // == ptr size (4 to 8 bytes)
  ```

- string literals in loops tend to have the same address every cycle. So modifying the literal ones affects all pending cycles.

Some operator madness:

- Operation "`,`" behaviour:

  ```C++
  /* Allowed */
  int i, j;  // declaration separator
  i = 10, j = 20;  // initializer separator; returns value of the last expression
  ```

  ```C++
  /* Allowed */
  int i = 10, j = 20;  // declaration and initialization separator
  /* Declaration has no return */
  ```

  ```C++
  /* NOT allowed */
  int i = 10, int j = 20;
  ```

  ```C++
  /* Allowed */
  int i, j;  // declaration separator
  i = 10, j = 20 + i;  // initializer separator
  /* Comma is a sequence point, with left to right assosiotion so `i = 10` will be executed fist and then `j = 20 + i`.
  Returns value of the `j = 20 + i` expression */
  ```

  ```C++
  /* Allowed */
  i = 10, 255;  // same as
  (i = 10), 255; // `i` is set to 10 and expression returns 255;
  // But
  i = (10, 255); // `i` is set to 255 and expression returns 255;
  ```

  All "`,`" operations can be chained and will always return the last value.

- Operation "`:`" behaviour:

  ```C++
  double prises[] {1.0, 33.1, 233.4};
  /* Immutable foreach C++ variant */
  for (auto x : prises) {
    std::cout << x;
  }
  /* Mmutable foreach C++ variant */
  for (auto &x : prises) {
    x += 21.777;
    std::cout << x;
  }
  ```

`#define` vs `typedef` in type definition:

  ```C++
  #define char *byte_ptr;

  byte_ptr pa, pb;  // The preprocessor just replaces byte_ptr witch char * before compilation. So `pa` will have type `char *` and `pb` will be `char`.
  ```

  ```C++
  typedef char *byte_ptr;

  byte_ptr pa, pb;  // Typedef crates an alias for a type. So `pa` and `pb` will be `cahr *`.
  ```
