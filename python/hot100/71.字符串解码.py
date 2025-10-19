class Solution:
    def decodeString(self, s: str) -> str:
        if not s:
            return s
        if s[0].isalpha():
            return s[0] + self.decodeString(s[1:])

        i = s.find('[')
        balance = 1
        for j in count(i + 1):
            if s[j] == "[":
                balance += 1
            elif s[j] == "]":
                balance -= 1
                if balance == 0:
                    return self.decodeString(s[i+1 : j]) * int(s[:i]) + self.decodeString(s[j + 1:])