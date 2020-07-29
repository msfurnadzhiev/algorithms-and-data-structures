//Average-case complexity: T(n)=О(n²), M(n)=O(1)

#include <iostream>
#include <vector>

template <typename T>
void INSERTION_SORT(std::vector<T> &input) {
  int key = 0, j = 0;
  for (int i = 1; i < input.size(); i++) {
    key = input[i];
    j = i - 1;
    while (j >= 0 && input[j]>key) {
      input[j + 1] = input[j];
      j--;
    }
    input[j + 1] = key;
  }
}

int main() {

  std::vector<int> input = {253, 603, 962, 720, 390, 156, 131, -884, 39, 917, 103, 0, -72, 111};
  INSERTION_SORT(input);

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

