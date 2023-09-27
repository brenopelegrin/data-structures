class Queue:
    def __init__(self, size):
        self._size = size
        self._queue = [None]*self._size
        self._start = -1
        self._end = 0
    def enqueue(self, value):
        print(self._end % self._size)
        if(self._end % self._size == self._start):
            print("Queue is full!")
        else:
            self._end = (self._end) % self._size
            self._queue[self._end] = value
        return
    def dequeue(self):
        if (self._end == 0):
            print("Queue is empty!")
        else:
            self._queue[self._start] = None
            self._start += 1
        return
    def print(self):
        print(self._queue)

q = Queue(5)
q.print()

for i in range(1, 6):
    q.enqueue(i)

q.print()
q.enqueue(6)
q.print()
q.dequeue()
q.enqueue(6)
q.print()


