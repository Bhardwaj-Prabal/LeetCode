class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        unordered_map<int,int> mp;

        for(auto &curr : target){
            mp[curr]++;
        }
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()) return false;

            else if(mp[arr[i]]==0) return false;

            mp[arr[i]]--;
        }
        return true;
    }
};