class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push elements from nums1 and nums2 into the priority queue
        for (const auto &num : nums1) {
            pq.push(num);
        }
        for (const auto &num : nums2) {
            pq.push(num);
        }

        // Pop elements from the priority queue to form the merged sorted array
        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            res.push_back(top);
        }
        
        int size = res.size();
        
        if (size == 0) {
            return 0.0;
        }
        
        if (size % 2 == 0) {
            return (res[size / 2 - 1] + res[size / 2]) / 2.0;
        } else {
            return res[size / 2];
        }
    }
};
