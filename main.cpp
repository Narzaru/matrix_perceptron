#include <iostream>

#include "matrix.h"
#include "perceptron.h"

int main() {
  Perceptron perc;
  perc.Configure({8, 2, 3, 1});
  perc.SetActivationFunc([](const Matrix &item) -> Matrix {
    Matrix new_matrix(item.get_rows(), item.get_cols());
    for (int i = 0; i < item.get_rows(); ++i) {
      new_matrix[i][0] = std::max(0.0, item[i][0]);
    }
    return new_matrix;
  });
  perc.PrepareMatrices();

  std::cout << perc.GetConfig() << std::endl;


  *(perc.GetInputLayer())[0][0] = 0.3;
  const Matrix& res = perc.GetOutputLayer();

  std::cout << "Result is " << res;
  return 0;
}
