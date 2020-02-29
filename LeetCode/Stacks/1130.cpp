class Solution {
public:
    /*first observation is you can take whatever binar tree and fuse it to
     another binary tree however you want and now you have to find the next           
     (nearest)maximum value for all values in o(n) these kind of problems you         
     have to solve using stacks 
    */
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        stack<int> st;
        st.push(INT_MAX);
        for(int a: arr){
            while(st.top() <= a){
                int x = st.top();
                st.pop();
                ans += x * min(st.top(),a);
            }
            st.push(a);
        }
        while(st.size() > 2){
            int x = st.top();
            st.pop();
            ans += (st.top() * x);
        }
        return ans;
    }
};
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/