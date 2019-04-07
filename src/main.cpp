#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
// #include "print-vector.h"
using namespace std;

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

class FunctionPart {
  public:
    FunctionPart(const char& newOperation, const double& newValue) {
      operation = newOperation;
      value = newValue;
    }
    double Apply(double sourceValue) const {
      if (operation == '-') {
        return sourceValue - value;
      } else if (operation == '+') {
        return sourceValue + value;
      } else if (operation == '*') {
        return sourceValue * value;
      } else {
        return sourceValue / value;
      }
    }
    void Invert() {
      if (operation == '-') {
        operation = '+';
      } else if (operation == '+') {
        operation = '-';
      } else if (operation == '*') {
        operation = '/';
      } else {
        operation = '*';
      }
    }
  private:
    char operation;
    double value;
};

class Function {
  public:
    void AddPart(const char& newOperation, const double newValue) {
      parts.push_back({newOperation, newValue});
    }
    double Apply(double value) const {
      for (auto const& f : parts) {
        value = f.Apply(value);
      }
      return value;
    }
    void Invert() {
      for (auto& f : parts) {
        f.Invert();
      }
      reverse(parts.begin(), parts.end());
    }
  private:
    vector<FunctionPart> parts;
};

// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('*', params.a);
//   function.AddPart('-', image.freshness * params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

int main() {
  // Image image = {10, 2, 6};
  // Params params = {4, 2, 6};
  // cout << ComputeImageWeight(params, image) << endl;
  // cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
