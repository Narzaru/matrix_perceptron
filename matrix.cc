#include "matrix.h"

#include <cstdlib>
#include <chrono>

Matrix::Matrix(int row, int col) : row_(0), col_(0), matrix_(nullptr) {
  if (row <= 0 || col <= 0) {
    return;
  }

  row_ = row;
  col_ = col;
  matrix_ = new double[row * col]();
}

double* Matrix::operator[](int i) const { return &(matrix_[i * col_]); }

void Matrix::Rand() {
  std::srand(std::time(nullptr));

  for (int i = 0; i < row_; ++i) {
    for (int j = 0; j < col_; ++j) {
      (*this)[i][j] = 0.01 * static_cast<double>((random() % 101));
    }
  }
}

Matrix operator*(const Matrix& left, const Matrix& right) {
  // !TODO(bgreydon) if necessary add a dim comparison
  Matrix new_matrix(left.get_rows(), right.get_cols());

  for (int i = 0; i < new_matrix.get_cols(); ++i) {
    for (int j = 0; j < new_matrix.get_rows(); ++j) {
      for (int k = 0; k < new_matrix.get_cols(); ++k) {
        new_matrix[i][j] += left[i][k] * right[k][j];
      }
    }
  }

  return new_matrix;
}

Matrix operator+(const Matrix& first, const Matrix& second) {
  // !TODO(bgreydon) if necessary add a dim comparison
  Matrix new_matrix(first.get_rows(), first.get_cols());

  for (int i = 0; i < first.get_rows(); ++i) {
    for (int j = 0; j < second.get_cols(); ++j) {
      new_matrix[i][j] = first[i][j] + second[i][j];
    }
  }

  return new_matrix;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
  for (int i = 0; i < matrix.get_rows(); ++i) {
    for (int j = 0; j < matrix.get_cols(); ++j) {
      os << matrix[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}