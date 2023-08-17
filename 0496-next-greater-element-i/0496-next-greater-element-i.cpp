class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i=0; i<(int)(nums1.size()); i++) {
            auto itr = m.find(nums1[i]);
            if (itr != m.end()) {
                ans[i] = itr->second;
            }
        }
        return ans;
    }
};