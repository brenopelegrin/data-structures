class Stack:
    def __init__(self, size):
        self._stack = [None]*size
        self._eos = size #end of stack
        self._sp = 0 #stack pointer (topo)
        self._bos = 0 #bottom of stack (start)

    def push(self, value):
        if(self._sp >= self._eos):
            print("stack full")
            return
        else:
            self._stack[self._sp] = value
            self._sp += 1
            return
    def pop(self):
        self._sp -= 1
        if(self._sp < 0):
            print("stack empty")
            return
        else:
            aux = self._stack[self._sp]
            self._stack[self._sp] = None
            return aux
            
    def print(self):
        print(self._stack)
