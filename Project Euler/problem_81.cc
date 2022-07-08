#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define ROW_NUM 80
#define COL_NUM 80

long sum = INT_MAX;
int matrix[ROW_NUM][COL_NUM];
int sub_sum_matrix[ROW_NUM][COL_NUM];

void print_matrix();
bool try_parse_matrix(const char* _Filename);

/// <summary>
/// Slow recursive approach.
/// </summary>
void move(long current_sum, int i, int j) {
    current_sum += matrix[i][j];

    if (current_sum > sum)
        return;

    if (i + 1 < ROW_NUM)
        move(current_sum, i + 1, j);

    if (j + 1 < COL_NUM)
        move(current_sum, i, j + 1);

    if (i + 1 == ROW_NUM && j + 1 == COL_NUM && current_sum < sum)
        sum = current_sum;
}

void solve() {
    //move(0, 0, 0);

    sub_sum_matrix[ROW_NUM - 1][COL_NUM - 1] = matrix[ROW_NUM - 1][COL_NUM - 1];
    for (int j = COL_NUM - 2; j >= 0; j--) {
        sub_sum_matrix[ROW_NUM - 1][j] = sub_sum_matrix[ROW_NUM - 1][j + 1] + matrix[ROW_NUM - 1][j];
    }

    for (int i = ROW_NUM - 2; i >= 0; i--) {
        sub_sum_matrix[i][COL_NUM - 1] = sub_sum_matrix[i + 1][COL_NUM - 1] + matrix[i][COL_NUM - 1];
    }

    for (int i = ROW_NUM - 2; i >= 0; i--) {
        for (int j = COL_NUM - 2; j >= 0; j--) {
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
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM; j++) {
            std::cout << sub_sum_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}