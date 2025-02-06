class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<2*n;i++)
          v.push_back(nums[i%n]);
        for (int i = 0; i <2*n; i++) {
            while (!st.empty() && v[i] > v[st.top()]) {
                ans[st.top()%n] = v[i];
                st.pop();
            }
            st.push(i);
        }       
        return ans;
    }
};