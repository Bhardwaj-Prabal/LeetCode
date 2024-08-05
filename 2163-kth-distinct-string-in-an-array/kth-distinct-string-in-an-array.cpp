class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string,vector<int>> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        for(auto &word:mp){
            if(word.second.size()>1) continue;
            else{
                vector<int> temp=word.second;
                pq.push(make_pair(temp[0],word.first));
            }
        }
        int count =1;
        if(pq.size()<k) return "";
        for(int j=1;j<k;j++){
            pq.pop();
            count++;
        }

        return pq.top().second;
    }
};