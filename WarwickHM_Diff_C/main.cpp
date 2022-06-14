#include <iostream>
#include <vector>
#include <chrono>
#include <random>

int32_t getRandomNum(const int32_t min, const int32_t max) {
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

class Matrix33 {
    const int row = 3;
    const int col = 3;
    std::vector<std::vector<int>> matrix;
public:
    Matrix33() {
        std::cout << "Creating new matrix 3x3:" << std::endl;
        matrix.resize(row);
        for(int i=0; i<row; i++) {
            matrix[i].resize(col);
            for(int j=0; j<col; j++) {
                matrix[i][j] = getRandomNum(1,9);
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    void determ() {
        int result =
             (matrix[0][0]*matrix[1][1]*matrix[2][2])
            -(matrix[0][0]*matrix[1][2]*matrix[2][1])
            -(matrix[0][1]*matrix[1][0]*matrix[2][2])
            +(matrix[0][1]*matrix[1][2]*matrix[2][0])
            +(matrix[0][2]*matrix[1][0]*matrix[2][1])
            -(matrix[0][2]*matrix[1][1]*matrix[2][0]);
        std::cout << "Determinant: " << result << std::endl;
    }
};

int main() {
    Matrix33 d1;
    d1.determ();
    return 0;
}
