class Solution:
    def myPow(self, x: float, n: int) -> float:
        exp = abs(n)
        answer = 1.0

        while(exp):
            if(exp & 1):
                answer *= x
            x *= x
            exp >>= 1
        return answer if n >= 0 else 1 / answer
