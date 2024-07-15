class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &num:nums){
            mp[num]++;
        }

        priority_queue<std::pair<int,int>> pq;
        for(auto &pairs:mp){
            int frequency=pairs.second;
            int element=pairs.first;
            pq.push(make_pair(frequency,element));
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            int top=pq.top().second;
            pq.pop();
            res.push_back(top);
        }
        return res;
    }
};