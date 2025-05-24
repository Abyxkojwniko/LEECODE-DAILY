class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        occ=set()
        left,right,ans=0,0,0
        n=len(s)
        for right in range(0,n):
            ch=s[right]
            while ch in occ:
                occ.remove(s[left])
                left+=1
            occ.add(ch)
            ans=max(ans,right-left+1)
        return ans