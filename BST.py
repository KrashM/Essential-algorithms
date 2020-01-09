class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

    def insert(self, current, new):
        if current.data < new.data:
            if current.right != None:
                self.insert(current.right, new)
            else:
                current.right = new
        if current.data > new.data:
            if current.left != None:
                self.insert(current.left, new)
            else:
                current.left = new

    def search(self, current, wanted):
        if current.data == wanted:
            print('There it is!')
            return
        if current.data < wanted and current.right != None:
            self.search(current.right, wanted)
        if current.data > wanted and current.left != None:
            self.search(current.left, wanted)
    
    def cout(self, current):
        if current:
            self.cout(current.left)
            print(current.data)
            self.cout(current.right)

input_array = input("Input:\n").split(' ')

root = Node(int(input_array[0]))

for i in range(1, len(input_array)):
    new = Node(int(input_array[i]))
    root.insert(root, new)

root.cout(root)

wanted = int(input('What do you want to search for?\n'))

root.search(root, wanted)