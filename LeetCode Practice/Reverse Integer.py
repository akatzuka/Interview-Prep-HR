class Solution:
    def reverse(self, x: int) -> int:
        neg = 1
        if x < 0:
            neg = -1
            x = -x

        rev = 0
        while x:
            rev = (rev * 10) + x % 10
            x //= 10

        return 0 if rev > pow(2,31) else rev * neg
