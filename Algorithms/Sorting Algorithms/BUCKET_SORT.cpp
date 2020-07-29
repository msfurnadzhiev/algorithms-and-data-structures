// Average-case complexity: T(n)=О(n), M(n)=O(n).

#include <iostream>
#include <algorithm>
#include <vector>

// Sorting algorithm for floating point numbers
void BUCKET_SORT(std::vector<float> &input) {

  int n = input.size();

  std::vector<std::vector<float>> B;
  B.reserve(n);

  // Put array elements in different buckets
  for(int i=0; i<n; i++) {
    B[static_cast<int>(input[i])].push_back(input[i]);
  }

  // Sort individual buckets
  for(int i=0; i<n; i++) {
    std::sort(B[i].begin(),B[i].end());
  }

  int index = 0;
  for(int i=0; i<n; i++) {
    for (float b : B[i]) {
      input[index++] = b;
    }
  }
}


int main() {

  std::vector<float> input = {2.33, 7.123, 0.98, 0.5, 4.87, 3.56, 9.17, 3.14, 2.71, 7.92, 5.5, 0.32, 4.44};
  BUCKET_SORT(input);

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

