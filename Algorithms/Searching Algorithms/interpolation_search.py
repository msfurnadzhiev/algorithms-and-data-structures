def interpolation_search(array, left, right, key):

    while left <= right and key >= array[left] and key <= array[right]:

        pivot = left + (right - left) * (key - array[left]) // (array[right] - array[left])

        if array[pivot] == key:
            return pivot
        
        elif array[pivot] < key:
            left = pivot + 1
        
        else:
            right = pivot - 1
    
    return -1


if __name__ == '__main__':

    array = [ 2, 4, 6, 9, 12, 15, 18]
    
    index = interpolation_search(array, 0, len(array) - 1, 15)

    print(index)