// Average-case complexity: T(n)=О(nlog(n)), M(n)=1

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
int PARTITION_HOARE(std::vector<T> &input,int left,int right) {
  T pivot = input[left];
  int i = left - 1, j = right + 1;

  while(true) {
    do {
      i++;
    } while(input[i] < pivot);

    do {
      j--;
    } while(input[j] > pivot);

    if(i<j) {
      std::swap(input[i], input[j]);
    }
    else {
      return j;
    }
  }
}

template <typename T>
void QUICK_SORT(std::vector<T> &input, int left, int right) {
  if(left < right) {
    int partition_index = PARTITION_HOARE(input,left,right);

    QUICK_SORT(input,left,partition_index);
    QUICK_SORT(input,partition_index+1,right);

  }
}

int main() {

  std::vector<int> input = {253, 603, 962, 720, 390, 156, 131, -884, 39, 917, 103, 0, -72, 111};
  QUICK_SORT(input, 0, input.size());

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

