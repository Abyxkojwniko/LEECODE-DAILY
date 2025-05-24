class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans=[]
        count_p=Counter(p)
        count_s=Counter()
        for right,c in enumerate(s):
            count_s[c]+=1
            left=right-len(p)+1
            if left<0:
                continue
            if count_p==count_s:
                ans.append(left)
            count_s[s[left]]-=1
        return ans