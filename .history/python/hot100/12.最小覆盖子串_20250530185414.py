class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans_left, ans_right = -1, len(s)
        cnt = defaultdict(int)  #
        for c in t:
            cnt[c] += 1
        less = len(cnt)  

        left = 0
        for right, c in enumerate(s):  
            cnt[c] -= 1  
            if cnt[c] == 0:
                less -= 1
            while less == 0:  
                if right - left < ans_right - ans_left:  
                    ans_left, ans_right = left, right  
                x = s[left]  
                if cnt[x] == 0:
                    less += 1
                cnt[x] += 1  
                left += 1
        return "" if ans_left < 0 else s[ans_left: ans_right + 1]