#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const int Row_num = 80;
const int Col_num = 80;

long sum = INT_MAX;
int matrix[Row_num][Col_num];
int sub_sum_matrix[Row_num][Col_num];

void print_matrix();
bool try_parse_matrix(const char* _Filename);

/// <summary>
/// Slow recursive approach.
/// </summary>
void move(long current_sum, int i, int j) {
    current_sum += matrix[i][j];

    if (current_sum > sum)
        return;

    if (i + 1 < Row_num)
        move(current_sum, i + 1, j);

    if (j + 1 < Col_num)
        move(current_sum, i, j + 1);

    if (i + 1 == Row_num && j + 1 == Col_num && current_sum < sum)
        sum = current_sum;
}

void solve() {
    //move(0, 0, 0);

    sub_sum_matrix[Row_num - 1][Col_num - 1] = matrix[Row_num - 1][Col_num - 1];
    for (int j = Col_num - 2; j >= 0; j--) {
        sub_sum_matrix[Row_num - 1][j] = sub_sum_matrix[Row_num - 1][j + 1] + matrix[Row_num - 1][j];
    }

    for (int i = Row_num - 2; i >= 0; i--) {
        sub_sum_matrix[i][Col_num - 1] = sub_sum_matrix[i + 1][Col_num - 1] + matrix[i][Col_num - 1];
    }

    for (int i = Row_num - 2; i >= 0; i--) {
        for (int j = Col_num - 2; j >= 0; j--) {
            sub_sum_matrix[i][j] = std::min(sub_sum_matrix[i + 1][j], sub_sum_matrix[i][j + 1]) + matrix[i][j];
        }
    }

    std::cout << sub_sum_matrix[0][0] << std::endl;
}

int main() {
    if (try_parse_matrix("problem_81_input.txt")) {
        std::cout << "The minimal path sum from the top left to the bottom right is ";
        solve();
    }
}

bool try_parse_matrix(const char* _Filename) {
    std::string line;
    std::fstream input_file;

    input_file.open(_Filename, std::ios_base::in);
    if (input_file.is_open() == false) {
        std::cout << "Failed to open input file\n";
        return false;
    }

    int i = 0, j = 0;
    while (std::getline(input_file, line)) {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        j = 0;
        std::string token;
        size_t pos = line.find(',');
        while (pos != std::string::npos) {

            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(',');

            matrix[i][j++] = std::stoi(token);
        }
        matrix[i++][j++] = std::stoi(line);
    }

    input_file.close();
    //print_matrix();

    return true;
}

void print_matrix() {
    for (int i = 0; i < Row_num; i++) {
        for (int j = 0; j < Col_num; j++) {
            std::cout << sub_sum_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}