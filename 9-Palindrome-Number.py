class Solution:
    def isPalindrome(self, x: int) -> bool:
        # remowing any spaces and all character into lowercase
        x=str(x).replace(\ \,\\).lower()
        # check if x is palindrome or not
        return x==x[::-1]