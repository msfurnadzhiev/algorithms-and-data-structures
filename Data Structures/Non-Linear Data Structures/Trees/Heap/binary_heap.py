class BinaryHeap:
    def __init__(self, items=[]):
        self.build_max_heap(items)

    def size(self):
        return len(self.items)

    def left(self, i):
        return 2*i + 1
    
    def right(self, i):
        return 2*i + 2
    
    def parent(self, i):
        return (i-1)//2

    def swap(self, i, j):
        self.items[i], self.items[j] = self.items[j], self.items[i]


    def max_heapify(self, i):
        l = self.left(i)
        r = self.right(i)
        largest = i

        if l < self.size() and self.items[l] > self.items[largest]:
            largest = l
        if r < self.size() and self.items[r] > self.items[largest]:
            largest = r
        if largest != i:
            self.swap(largest, i)
            self.max_heapify(largest)


    def build_max_heap(self, items):
        self.items = items
        i = self.parent(self.size())

        while i >= 0:
            self.max_heapify(i)
            i -= 1


    def insert(self, key):
        self.items.append(key)
        index = self.size()-1

        while index != 0:
            p = self.parent(index)
            if self.items[p] < self.items[index]:
                self.swap(p, index)
            index = p


    def remove(self, i):
        element = self.items[i]
        self.items[i] = self.items.pop()
        self.max_heapify(i)
        return element

    def extract_max(self):
        return self.remove(0)


    # It is assumed that 'key' is largest than items[index]
    def increase_key(self, index, key): 
        if key < self.items[index]:
            raise TypeError('Error: value of key must be largest \
                             than value of items[index]')
        
        self.items[index] = key

        while index != 0:
            p = self.parent(index)
            if self.items[p] < self.items[index]:
                self.swap(p, index)
            index = p


if __name__ == '__main__':
    
    items = [7, 10, 3, 5, 6, 2, 8, 9, 4]

    bheap = BinaryHeap(items)
