class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int, int> map;
        for(auto num : nums){
            ++map[num];
        }
        int maxFreq = nums.size();
        std::vector<std::vector<int>> buckets(maxFreq + 1);
        for(auto const& [num, freq] : map){
            buckets[freq].push_back(num);
        }
        std::vector<int> result;
        for(int i = maxFreq; i >= 0 && result.size() < k; --i){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};