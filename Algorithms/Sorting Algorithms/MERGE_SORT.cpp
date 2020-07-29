// Average-case complexity: T(n)=О(n.log(n)), M(n)=O(n)

#include <iostream>
#include <vector>

template <typename T>
void MERGE(std::vector<T> &input, int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;

  T* L = new T[n1];
  T* R = new T[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = input[left + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = input[middle + 1 + j];
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      input[k++] = L[i++];
    } else {
      input[k++] = R[j++];
    }
  }

  while (i < n1) {  input[k++] = L[i++];  }
  while (j < n2) {  input[k++] = R[j++];  }
}

template <typename T>
void MERGE_SORT(std::vector<T> &input, int left, int right) {
  if(left < right) {
    int middle = (left+right)/2;
    MERGE_SORT(input, left, middle);
    MERGE_SORT(input,middle+1, right);
    MERGE(input, left,middle, right);
  }
}



int main() {

  std::vector<int> input = {253, 603, 962, 720, 390, 156, 131, -884, 39, 917, 103, 0, -72, 111};
  MERGE_SORT(input, 0, input.size());

  for(const auto &elem : input) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}



