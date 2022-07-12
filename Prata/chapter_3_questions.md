# chapter_3_questions

1. To give user a choise on how the variable is stored and processed.
2. a) `short var_1 = 80;` b) `unsigned int var_2 = 42110` c) `unsigned long var_3 = 3000000000`.
3. Overflow mechanism regulates integer types overflow. `usigned int` overflow is defined, but `signed int` overflow can result is undefined behaviour.
4. `33L` is `long` and `33` is `int`.
5. As ASCII code for character `A` is 65, yes in systems that use ASCII.
6. `std::cout << char (88) << std::endl;` or `std::cout << (char) 88 << std::endl;` or `std::cout << std::static_cust<char>(88) << std::endl;`
7. `double` has 15 point precision and long is at minimum 32 bits (max_value = 2.7E9). But long can be upto 64 bits (msx_value = 9.2E18) so in that case precision will be lost.
8. 74, 4, 0, 4.5, 3
9. `double var_1 = int(x1) + int(x2);` or `int var_2 = x1 + x2;`
10. `int`, `float`, `char`, `char32_t`, `float`.
