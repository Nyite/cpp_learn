# C++ Primer Plus code sheatsheet

C++ built-in [operators, precedence, and associativity](https://docs.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-170)

Some `iostream` API:

- `cout.put()` puts a charecter in output stream
- `cout.setf()` sets formating for float-point numbers
  - `fixed` set fixed precision
  - `floatfiled` set precision to 6th decimal place
- `hex` & `oct` manipulators determine the output format of an integer typed value

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
  big_ptr + 1; // <=> git_ptr + sizeof(int)*10
  ```

- `sizeof` behaiviour:

  ```C++
  sizeof(my_arr); // == sizeof(int)*10
  sizeof(arr_ptr); // == ptr size (4 to 8 bytes)
  sizeof(big_ptr); // == ptr size (4 to 8 bytes)
  ```

- string literals in loops tend to have the same address every cycle. So modifying the literal ones affects all pending cycles.
