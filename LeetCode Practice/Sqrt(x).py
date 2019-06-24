class Solution:
    def mySqrt(self, x: int) -> int:
        #return x ** 0.5

        #binary search version
        left, right = 0, x
        while left < right:
            middle = left + (right - left + 1) // 2
            if middle*middle <= x:
                left = middle
            else:
                right = middle - 1
        return left
