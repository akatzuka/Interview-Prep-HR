#Two solutions, both work in about the same memory space, but solution 1 is faster

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Solution 1
        count = 0
        for i in reversed(s):
            if i.isspace():
                if count:
                    break
            else:
                count += 1
        return count

        # Solution 2
        #i = 0
        # (going backwards) find first non-space char
        #while len(s) != 0 and s[-(i + 1)] == ' ':
        #    s = s[:-1]
        # keep going until a space or end of string
        #while i != len(s) and s[-(i + 1)] != ' ':
        #    i += 1
        #return i
