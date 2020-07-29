// Average-case complexity: T(n)=О(n+k), M(n)=O(n+k), k is the range.

#include <iostream>
#include <vector>

void COUNTING_SORT(std::vector<int> &input, int range) {

  std::vector<int> count(range+1);
  std::vector<int> new_array(input.size());

  for(int i : input) {
    count[i] += 1;
  }

  for(int i=1; i<=range+1; i++) {
    count[i] += count[i-1];
  }

  for(int i : input) {
    new_array[count[i]-1] = i;
    count[i]--;
  }

  for(int i=0; i<input.size(); i++) {
    input[i] = new_array[i];
  }
}


int main() {

  std::vector<int> input = {2, 4, 6, 5, 6, 7, 3, 9, 0, 2, 6, 3, 8, 4, 6, 1, 0, 9};
  COUNTING_SORT(input, 10);

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

