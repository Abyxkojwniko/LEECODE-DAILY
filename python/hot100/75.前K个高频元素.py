class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map = collections.Counter(nums)
        max_freq = len(nums)
        buckets = [[] for  _ in range(max_freq + 1)]
        for num, frep in map.items():
            buckets[frep].append(num)
        result = []
        for i in range(max_freq, 0, -1):
            for num in buckets[i]:
                result.append(num)
                if len(result) == k:
                    return result
        return result