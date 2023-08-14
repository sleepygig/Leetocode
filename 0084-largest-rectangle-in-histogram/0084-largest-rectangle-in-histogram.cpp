class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsl(n,0);
        vector<int>nsr(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.size() and heights[st.top()]>=heights[i]) st.pop();
            if(st.size()==0) nsl[i]=-1;
            else if(heights[st.top()]<heights[i]) nsl[i]=st.top();
            st.push(i);
        }
       while (!st.empty()) st.pop();
          for(int i=n-1;i!=-1;i--)
        {
            while(st.size() and heights[st.top()]>=heights[i]) st.pop();
            if(st.size()==0) nsr[i]=n;
            else if(heights[st.top()]<heights[i]) nsr[i]=st.top();
            st.push(i);
        }
        int a=-3;
        for(int i=0;i<n;i++)
        {
            a=max(a,heights[i]*(nsr[i]-nsl[i]-1));
        }

        // deb(a);
        return a;
    }
};