class Queue:
# the queue data structure follows rule called FIFO(First in First out).
    def __init__(self):
        self.queue = list()
        self.front=0
        self.rear=0
        self.maxSize=10
    def size(self):
        if self.front <= self.rear:
            return (self.rear-self.front)
        else:
            return(self.maxSize-(self.front-self.rear))


    def enqueue(self,data):
        if self.size()==(self.maxSize-1):
            return("full queue")
        else:
            self.queue.append(data)
            self.rear=(self.rear+1)%(self.maxSize)#append the element and increase the rear pointer


            return True
    def dequeue(self):
        if self.size()==0:
            return("empty queue")
        else:
            data_dequeue=self.queue[self.front]
            self.front=(self.front+1)%self.maxSize
            return data_dequeue
My_queue=Queue() #initial the object
My_queue.enqueue(2)
My_queue.enqueue(3)
My_queue.enqueue(4)
print("the size of queue is",My_queue.size())
print("the rear of queue is",My_queue.queue[(My_queue.rear)-1])
print(My_queue.queue)
print(My_queue.dequeue())

