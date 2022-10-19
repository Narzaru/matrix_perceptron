#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <ostream>

// TODO(bgreydon) implement a rows vector that inherits the Matrix
class Matrix {
 public:
  Matrix(int row, int col);

  double *operator[](int i) const;

  [[nodiscard]] int get_rows() const {
    return row_;
  }
  [[nodiscard]] int get_cols() const {
    return col_;
  }

  void Rand();

 private:
  double *matrix_;
  int row_;
  int col_;
};

Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator+(const Matrix& first, const Matrix& second);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

#endif  //_MATRIX_H_
