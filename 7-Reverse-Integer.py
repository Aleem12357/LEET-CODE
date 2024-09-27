class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        x *= sign
        list=[]
        x=str(x)
        list=x[::]
        list=list[::-1]
        x=int(list)
        if (x > (2147483647)):
            return 0
        return x*sign