#include <iostream>
#include <vector>

template <typename T>
void SHELL_SORT_PHASE(std::vector<T> &input, int gap) {
  for(int i = gap; i < input.size(); i++) {
    T key = input[i];
    int j = i - gap;
    while(j>=0 && input[j]>key) {
      input[j + gap] = input[j];
      j -= gap;
    }
    input[j + gap] = key;
  }
}

template <typename T>
void SHELL_SORT(std::vector<T> &input){
  static const int gaps[] = {1, 4, 10, 23, 57, 132, 301, 701};

  for(int i = sizeof(gaps)/sizeof(gaps[0]) - 1; i >= 0; i--) {
    SHELL_SORT_PHASE(input, gaps[i]);
  }
}

int main() {

  std::vector<int> input = {253, 603, 962, 720, 390, 156, 131, -884, 39, 917, 103, 0, -72, 111};
  SHELL_SORT(input);

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

