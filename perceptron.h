#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include <vector>

#include "matrix.h"

class Perceptron {
  using fun_ptr = Matrix (*)(const Matrix &);

 public:
  Perceptron() : func(nullptr) {}

  void SetActivationFunc(fun_ptr function);
  void Configure(const std::vector<int> &layer_config);
  void PrepareMatrices();
  Matrix *GetInputLayer();
  const Matrix &GetOutputLayer();

  // TODO(bgreydon) add config builder instead of the ctor
  class Config {
   public:
    Config(std::vector<Matrix> *weights, std::vector<Matrix> *layers,
           std::vector<Matrix> *biases)
        : weights_(weights), layers_(layers), biases_(biases) {}

    friend std::ostream &operator<<(std::ostream &os, const Config &config) {
      os << "Matrix perceptron configuration" << std::endl;
      os << "Perceptron has " << config.layers_->size() << " layers" << std::endl;
      for (const auto &item : *config.weights_) {
        os << item;
        os << std::endl;
      }
      return os;
    }

   private:
    std::vector<Matrix> *weights_;
    std::vector<Matrix> *layers_;
    std::vector<Matrix> *biases_;
  };
  Config GetConfig();

 private:
  std::vector<int> layer_config_;
  // Matrix of weights
  std::vector<Matrix> weights_;
  // Layers with neurons
  std::vector<Matrix> layers_;
  // Matrix of biases
  std::vector<Matrix> biases_;

  Matrix (*func)(const Matrix &);
};


#endif  // PERCEPTRON_H_
