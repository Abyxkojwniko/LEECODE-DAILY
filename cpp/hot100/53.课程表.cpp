class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto point : prerequisites){
            graph[point[1]].emplace_back(point[0]);
        }
        vector<int> colors(numCourses);
        auto dfs = [&](this auto&& dfs, int x) -> bool{
            colors[x] = 1;
            for(auto y : graph[x]){
                if(colors[y] == 1 || colors[y] == 0 && dfs(y)){
                    return true;
                }
            }
            colors[x] = 2;
            return false;
        };
        for(int i = 0; i < numCourses; i++){
            if(colors[i] == 0 && dfs(i)){
                return false;
            }
        }
        return true;
    }
};