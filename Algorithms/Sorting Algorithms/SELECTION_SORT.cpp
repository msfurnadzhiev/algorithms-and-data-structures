//Average-case complexity: T(n)=О(n²), M(n)=O(1)

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void SELECTION_SORT(std::vector<T> &input) {
  for(int i = 0; i < input.size() - 1; i++) {
    T min = i;
    for (int j = i + 1; j < input.size(); j++) {
      if (input[j] < input[min]) {
        min = j;
      }
    }
    std::swap(input[min], input[i]);
  }
}


int main() {

  std::vector<int> input = {253, 603, 962, 720, 390, 156, 131, -884, 39, 917, 103, 0, -72, 111};
  SELECTION_SORT(input);

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

