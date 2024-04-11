#include <iostream>
#include <vector>

// Класс матрицы
class Matrix {
public:

    // Конструктор матрицы
    Matrix(int rows, int cols) : data(rows, std::vector<int>(cols)) {}

    // Ввод матрицы с клавиатуры
    void input() {
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                std::cin >> data[i][j];
            }
        }
    }

    // Вывод матрицы на экран
    void display() {
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Сложение матриц
    Matrix operator+(const Matrix& other) {
        Matrix result(data.size(), data[0].size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Умножение матриц
    Matrix operator*(const Matrix& other) {
        Matrix result(data.size(), other.data[0].size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < other.data[0].size(); j++) {
                int sum = 0;
                for (int k = 0; k < data[0].size(); k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

private:
    std::vector<std::vector<int>> data;
};

int main() {
    // Создание матриц
    Matrix A(2, 2);
    Matrix B(2, 2);
    Matrix C(2, 2);

    // Ввод матриц с клавиатуры
    std::cout << "Enter matrix A:" << std::endl;
    A.input();
    std::cout << "Enter matrix B:" << std::endl;
    B.input();

    // Сложение матриц
    C = A + B;
    std::cout << "Matrix A + B:" << std::endl;
    C.display();

    // Умножение матриц
    C = A * B;
    std::cout << "Matrix A * B:" << std::endl;
    C.display();

    return 0;
}