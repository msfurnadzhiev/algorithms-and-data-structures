// Average-case complexity: T(n)=О(nlog(n)), M(n)=1

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void HEAPIFY(std::vector<T> &input, int n, int index) {
  int largest = index;
  int left = 2*index + 1;
  int right = 2*index + 2;

  if(left < n && input[left] > input[largest]) {
    largest = left;
  }

  if(right < n && input[right] > input[largest]) {
    largest = right;
  }

  if(largest != index) {
    std::swap(input[index],input[largest]);
    HEAPIFY(input,n,largest);
  }
}


template <typename T>
void HEAP_SORT(std::vector<T> &input) {

  //build max-heap
  for(int i = input.size()/2 - 1; i >= 0; i--) {
    HEAPIFY(input, input.size(), i);
  }

  //heapsort
  for(int i = input.size() - 1; i >= 0; i--) {
    std::swap(input[0],input[i]);
    HEAPIFY(input,i,0);
  }
}


int main() {

  std::vector<int> input = {253, 603, 962, 720, 390, 156, 131, -884, 39, 917, 103, 0, -72, 111};
  HEAP_SORT(input);

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}

