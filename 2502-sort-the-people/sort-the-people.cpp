class Solution {
public:
    // Sort function should be a static member or a standalone function
    static bool sortbysec(const pair<string, int> &a, const pair<string, int> &b) {
        return (a.second > b.second);
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> res;
        int n = names.size();

        // Create pairs of names and heights
        for (int i = 0; i < n; i++) {
            res.push_back(make_pair(names[i], heights[i]));
        }

        // Sort pairs by the second element (height)
        sort(res.begin(), res.end(), sortbysec);

        vector<string> result;
        // Extract names from sorted pairs
        for (int i = 0; i < n; i++) {
            result.push_back(res[i].first);
        }

        return result;
    }
};
