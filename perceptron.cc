#include "perceptron.h"

void Perceptron::SetActivationFunc(Perceptron::fun_ptr function) {
  func = function;
}

void Perceptron::Configure(const std::vector<int> &layer_config) {
  layer_config_.clear();
  for (auto i : layer_config) {
    layer_config_.push_back(i);
  }
}

void Perceptron::PrepareMatrices() {
  for (auto i : layer_config_) {
    layers_.emplace_back(i, 1);
  }

  // TODO(bgreydon) add configuration bias later
  for (int i = 0; i < layer_config_.size() - 1; ++i) {
    biases_.emplace_back(layer_config_[i + 1], 1);
    for (int j = 0; j < biases_[i].get_rows(); ++j) {
      // bias layer[i]
      // matrix[j][0]
      biases_[i][j][0] = 1.0;
    }
  }

  for (int i = 0; i < layer_config_.size() - 1; ++i) {
    weights_.emplace_back(layer_config_[i + 1], layer_config_[i]);
    weights_[i].Rand();
  }
}
Perceptron::Config Perceptron::GetConfig() {
  return {&weights_, &layers_, &biases_};
}

Matrix* Perceptron::GetInputLayer() { return &layers_[0]; }

const Matrix& Perceptron::GetOutputLayer() {
  Matrix temp(0, 0);
  for (int i = 1; i < layer_config_.size(); ++i) {
    layers_[i] = weights_[i - 1] * layers_[i - 1];
    layers_[i] = layers_[i] + biases_[i - 1];
    layers_[i] = func(layers_[i]);
  }

  return layers_.back();
}
