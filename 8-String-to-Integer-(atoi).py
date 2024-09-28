class Solution:
    def myAtoi(self, s: str) -> int:
        # Remove leading whitespace
        s = s.lstrip()
        
        # Check if the string is empty after stripping
        if not s:
            return 0
        
        # Initialize variables
        digits = []
        sign = 1
        i = 0
        
        # Check for optional sign
        if s[i] == '+':
            sign = 1
            i += 1
        elif s[i] == '-':
            sign = -1
            i += 1
        
        # Handle invalid cases: if the next character is not a digit
        if i < len(s) and not s[i].isdigit():
            return 0
        
        # Use a for loop to collect digits in a list
        for i in range(i, len(s)):
            if s[i].isdigit():
                digits.append(s[i])  # Collect the digit as a string
            else:
                break  # Stop if a non-digit character is found
        
        # If no digits were collected, return 0
        if not digits:
            return 0
        
        # Convert the list of string digits to an integer
        num = int(''.join(digits))  # Join the list into a string and convert to int
        
        # Apply the sign
        num *= sign
        
        # Handle overflow
        INT_MIN = -2**31
        INT_MAX = 2**31 - 1
        
        if num < INT_MIN:
            return INT_MIN
        if num > INT_MAX:
            return INT_MAX
        
        return num  # Return the final result