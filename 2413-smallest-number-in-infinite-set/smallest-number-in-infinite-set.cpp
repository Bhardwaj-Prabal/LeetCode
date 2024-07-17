class SmallestInfiniteSet {
private:
    vector<int> set;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SmallestInfiniteSet() {
        // Initialize set with 1001 elements, each initialized to its index + 1
        for (int i = 0; i < 1001; ++i) {
            set.push_back(i + 1);
            pq.push(i + 1);
        }
    }

    int popSmallest() {
        int top = pq.top();
        pq.pop();
        set[top - 1] = -1; // Mark the element as removed

        return top;
    }

    void addBack(int num) {
        if (set[num - 1] != -1) {
            return; // Element is already removed
        }
        pq.push(num);
        set[num - 1] = num; // Restore the element in set
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */