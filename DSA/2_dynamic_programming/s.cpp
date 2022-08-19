#include "./util/recursion_utilities.cpp"
using namespace std;


double getSqroot(double a,double b, double f2, double precision){
    // w(a,b,f2,precision);
    double mid = ((a+b)/2);
    if((mid+precision)*(mid+precision)>=f2 && (mid-precision)*(mid-precision)<=f2 )return mid;
    else if(mid*mid<f2) return getSqroot((a+b)/2,b,f2,precision);
    else return getSqroot(a, (a+b)/2 ,f2,precision);
}

double getSqurt(double f2, double precision){
    double a = 0;
    while(a*a<f2)a++;
    a--;
    while(abs(a*a-f2)>precision){
        if(a*a<f2){
            a+=(f2-a*a)/(2*a);
            // cout<<(f2-a*a)/(2*a)<<endl;
        }else{
            a-=(a*a-f2)/(2*a);
            // cout<<(a*a-f2)/(2*a)<<endl;
        }
            // cout<<abs(a*a-f2)<<" "<<a*a<<endl;
    }
    return a;
};


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
int y =10;
//position 1,0 left,right
TreeNode* sortedArrayToBSTin(int start, int end, vector<int>& nums,int position) {
        int mid = (end+start+1)/2;
        e(nums[mid],start,end);
        TreeNode* ans  = new TreeNode(nums[mid]);
        if(start==end){
            b('h');
            return ans;
        }else if (start>end) {
            b('r');
            return NULL;
        }
        else{
            ans->left =  sortedArrayToBSTin(start,mid-1,nums,1);
            ans->right =  sortedArrayToBSTin(mid+1,end,nums,0);
            b('h');
            return ans;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTin(0,nums.size()-1,nums,0);
    }

    // return weight and value pair
// max value possible for array from i to n-1 that have maximum weight w
int f(int ind, int w, vector<int>& value, vector<int>& weight){
    e(ind,w);
    int n = weight.size();
    //! if(w<0){b(1);return 0;}
    if(ind>=n){b(2);return 0;}
    else{
        int notTake = f(ind+1,w,value,weight);
        int take = 0;
        //! we cant take this w<0 as base case, instead, we have to take care such a function call is not   made, because, in case of take, we will add value[ind], so either a way we will have to check before adding the value, so, better call after check 
        if(w-weight[ind]>=0)take=f(ind+1,w-weight[ind],value,weight)+value[ind];
        b(3,take,notTake);
        return max(take,notTake);
    }
}

int knapsack(vector<int> weight, vector<int> value, int n, int w) 
{
	// Write your code here
    return f(0,w,value,weight);
}

int main(){
    // double precision = 0.00000001;
    // double f2 = 58758.7643455;
    
    // cout<<sqrt(f2)<<endl;
    
    // cout<<getSqurt(f2,precision)<<endl;

    // cout<<getSqroot((double)0,f2,f2,precision)<<endl;

    // vector<int> a = {1,3};
    // sortedArrayToBST(a);

    vector<int> w={  7 };
    vector<int> v={1  };

    cout<<knapsack(w,v,7,1);
    
}