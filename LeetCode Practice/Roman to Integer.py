class Solution:
    def romanToInt(self, s: str) -> int:
        # translations of each roman numeral to value
        translations = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        # replacements to make the str easier to convert
        s = s.replace("IV", "IIII").replace("IX", "VIIII") #replaces 4, 9
        s = s.replace("XL", "XXXX").replace("XC", "LXXXX") #replaces 40, 90
        s = s.replace("CD", "CCCC").replace("CM", "DCCCC") #replaces 400, 900

        number = 0

        for char in s:
            number += translations[char]

        return number
