class LRUCache {
private:
    int capacity;
    list<pair<int,int>> cache_list;
    unordered_map<int,list<pair<int,int>>::iterator> key_to_pair;
public:
    LRUCache(int capacity):capacity(capacity) {
    }
    
    int get(int key) {
        auto map_iter=key_to_pair.find(key);
        if(map_iter==key_to_pair.end()){
            return -1;
        }
        auto list_iter=map_iter->second;
        cache_list.splice(cache_list.begin(),cache_list,list_iter);
        return list_iter->second;
    }
    
    void put(int key, int value) {
        auto map_iter=key_to_pair.find(key);
        if(map_iter!=key_to_pair.end()){
            auto list=map_iter->second;
            cache_list.splice(cache_list.begin(),cache_list,list);
            list->second=value;
            return ;
        }
        cache_list.emplace_front(key,value);
        key_to_pair[key]=cache_list.begin();
        if(key_to_pair.size()>capacity){
            key_to_pair.erase(cache_list.back().first);
            cache_list.pop_back();
        }
    }
};