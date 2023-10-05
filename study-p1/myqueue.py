class MyQueue:
    def __init__(self, size):
        self._ini = 0
        self._fim = 0
        self._size = size
        self._array = [None] * self._size
    def enqueue(self, value):
        if (self._fim == self._size):
            print("queue is full")
            return
        else:
            self._array[self._fim] = value
            self._fim += 1

    def dequeue(self):
        if(self._ini == self._fim):
            print("queue is empty")
            return
        else:
            aux = self._array[self._ini]
            self._array[self._ini] = None
            self._ini += 1
            return aux
    
    def print(self):
        print(f"first -> {self._array} <- last")

q = MyQueue(size=4)

[q.enqueue(i) for i in [1,2,3,4]]
q.print()

print(q.dequeue())
print(q.dequeue())

q.print()
