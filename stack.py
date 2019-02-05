class Stack:
    def __init__(self):
        self.stack=[]
    def add(self,data_value):
        # push value into the stack
        if data_value not in self.stack:
            self.stack.append(data_value)
            return self.stack
        else:
            print("input already exist")
    def peek(self):
        # observe the value in the stack without changing state
        print(self.stack[0])
        return self.stack[0]
    def remove(self):
        # pop the value in the stack
        if len(self.stack) <= 0:
            return ("no element in stack")
        else:
            print(self.stack.pop())
            return self.stack.pop()

My_Stack = Stack()
My_Stack.add(1)
My_Stack.add(2)
My_Stack.add(3)
My_Stack.peek()
My_Stack.remove()



