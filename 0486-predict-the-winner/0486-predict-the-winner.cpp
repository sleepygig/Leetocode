class Solution {
public:
   int sc(vector<int>&nums,int i,int j,int sum,bool &a){
    {
        if(i==j) return nums[i];
        if(i>j) return 0;
    }
    int l=nums[i]+min(sc(nums,i+2,j,sum,a),sc(nums,i+1,j-1,sum,a));   
    int r=nums[j]+min(sc(nums,i+1,j-1,sum,a),sc(nums,i,j-2,sum,a));
 return max(l,r);
      
    
    return 0;
    }
 bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        bool a=false;
        if(n==1) return true;
       int x= sc(nums,0,n-1,sum,a);
        return x>=sum-x;


    }

};