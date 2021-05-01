class BinomialTree:
    def __init__(self, key):
        self.key = key
        self.children = []
        self.order = 0

    def add(self, item):
        self.children.append(item)
        self.order += 1


class BinomialHeap:
    def __init__(self, items=[]):
        self.trees = []

        if len(items) > 0:
            for item in items:
                self.insert(item)



    def merge(self, other):
        self.trees.extend(other.trees)
        self.trees.sort(key = lambda tree: tree.order) 

        if self.trees == []:
            return

        i = 0
        while i < len(self.trees) - 1:
            alpha = self.trees[i]
            beta = self.trees[i + 1]

            if alpha.order == beta.order:
                if (i + 1 < len(self.trees) - 1 and 
                    self.trees[i+2].order == beta.order):
                    gamma = self.trees[i+2]
                    if beta.key < gamma.key:
                        self.trees[i+1].add(gamma)
                        del self.trees[i+2]
                    else:
                        self.trees[i+2].add(beta)
                        del self.trees[i+1]
                else: 
                    if alpha.key < beta.key:
                        self.trees[i].add(beta)
                        del self.trees[i+1]
                    else:
                        self.trees[i+1].add(alpha)
                        del self.trees[i]
            else:
                i += 1


    def insert(self, key):
        bheap = BinomialHeap()
        bheap.trees.append(BinomialTree(key))
        self.merge(bheap)


    def find_min(self):
        return min([tree.key for tree in self.trees])


    def extract_min(self):
        min = self.trees[0]
        for tree in self.trees:
            if tree.key < min.key:
                min = tree
        self.trees.remove(min)
        temp = BinomialHeap()
        temp.trees = min.children
        self.merge(temp)
        return min.key


if __name__ == '__main__':
    
    items = [7, 10, 3, 5, 6, 2, 8, 9, 4]
                
    bheap = BinomialHeap(items)

