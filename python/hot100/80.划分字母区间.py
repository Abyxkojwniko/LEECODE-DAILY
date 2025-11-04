class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        count = [0] * 26
        result = []
        for i in range(len(s)):
            count[ord(s[i]) - ord('a')] = i
        start, end = 0, 0
        for i in range(len(s)):
            end = max(end, count[ord(s[i]) - ord('a')]);
            if i == end:
                result.append(i - start + 1)
                start = i + 1
        return result