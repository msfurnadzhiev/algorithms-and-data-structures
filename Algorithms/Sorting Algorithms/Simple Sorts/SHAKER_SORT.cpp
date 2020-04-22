//Average-case complexity: T(n)=О(n²), M(n)=O(1)


template <typename T>
void SHAKER_SORT(Т* arr, int size)
{
    int left = 1;
    int right = size-1;

    while (left <= right) {

        for (int i = right; i >= left; i--) {
            if (arr[i - 1] > arr[i]) {
		swap(arr[i],arr[i-1]);
            }
        }
        left++;

        for (int i = left; i <= right; i++) {
            if (arr[i - 1] > arr[i]) {
		swap(arr[i],arr[i-1]);
            }
        }
        right--;
    }
}
