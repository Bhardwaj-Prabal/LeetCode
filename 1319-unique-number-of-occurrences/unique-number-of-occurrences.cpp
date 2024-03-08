class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int> mp;
       
for (const auto& element : arr) {
    mp[element]++; 
}

unordered_set<int> set;
for(auto it = mp.begin(); it != mp.end(); ++it) {
    set.insert(it->second);
}


      
            
        return mp.size()==set.size();
    }
};