class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    def insert(self,data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                    # self.left=Node
                else:
                    self.left.insert(self, data)
                    # what does self.left.insert(data)mean
                    #
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(self, data)
    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data)
        if self.right:
            self.right.print_tree()

    def in_order_traversal(self,root):
        # order:left root right
        res = []
        if root:
            res = self.in_order_traversal(root.left)
            res.append(root.data)
            res = res+self.in_order_traversal(root.right)
        return res
    def pre_order_traversal(self, root):
        res = []
        if root:
            res.append(root.data)
            res = res+self.pre_order_traversal(root.left)
            res = res+self.pre_order_traversal(root.right)
        return res
    def post_order_traversal(self, root):
        res=[]
        if root:
            res = self.post_order_traversal(root.left)
            res = res+self.post_order_traversal(root.right)
            res.append(root.data)
        return res
root=Node(27)
root.insert(14)
root.insert(35)
print(root.in_order_traversal(root))
print(root.pre_order_traversal(root))
print(root.post_order_traversal(root))