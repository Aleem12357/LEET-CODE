class CustomStack:
    def __init__(self, maxSize: int):
        self.maxSize = maxSize
        self.stack = []
        self.increments = [0] * maxSize  # To track increments for each position

    def push(self, x: int) -> None:
        if len(self.stack) < self.maxSize:
            self.stack.append(x)

    def pop(self) -> int:
        if not self.stack:
            return -1
        idx = len(self.stack) - 1
        # Pop the top element and add the increment at that index
        value = self.stack.pop() + self.increments[idx]
        # If there are elements left in the stack, propagate the increment
        if idx > 0:
            self.increments[idx - 1] += self.increments[idx]
        # Clear the increment for the popped element
        self.increments[idx] = 0  # Optional, but helps with clarity
        return value

    def increment(self, k: int, val: int) -> None:
        # Increment the bottom k elements
        if k > len(self.stack):
            k = len(self.stack)
        if k > 0:
            self.increments[k - 1] += val  # Increment the (k-1)th index

