class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda p:p[0])
        ans=[]
        for p in intervals:
            if ans and p[0]<=ans[-1][1]:
                ans[-1][1]=max(p[1],ans[-1][1])
            else:
                ans.append(p)
        return ans