class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map=dict()
        for str in strs:
            temp="".join(sorted(str))
            if temp not in map:
                map[temp]=[]
            map[temp].append(str)
        return list(map.values())