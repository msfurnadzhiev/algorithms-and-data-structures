def binary_search(array, left, right, key):

    while left <= right:
        middle = left + (right - left) // 2

        if array[middle] == key:
            return middle
        
        elif array[middle] < key:
            left = middle + 1
        
        else:
            right = middle - 1
    
    return -1


if __name__ == '__main__':

    array = [ 2, 3, 7, 13, 42, 133, 453]

    index = binary_search(array, 0, len(array) - 1, 133)
    
    print(index)
