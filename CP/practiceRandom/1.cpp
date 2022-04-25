#include<bits/stdc++.h>
using namespace std;


    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ansv;
        int ans = a[n-1];
        for(int i = n-1; i>=0; i--){
            cout<<a[i];
            if(a[i]<ans) continue;
            ans = a[i];
            ansv.push_back(ans);
        }
        return ansv;
    }

    

int equilibriumPoint(int a[], int n) {
        int  bb = a[0], ee = a[n-1], b =0, e = n-1;
        while(b+2<e){
            if(bb<ee){
                b++;
                bb+=a[b];
                cout<<bb<<"* ";
            }else{
                e--;
                ee+=a[e];
                cout<<ee<<"- ";
            }
        }// Your code here
        if(bb==ee)
        return b+1;
        else return -1;
    }

int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int arv = 0;
    	int dpt = 0;
    	int st = 0;
    	int ans = 0;
        cout<<n<<endl;
    	while(arv<n ){
            cout<<arv<<" "<<dpt<<" "<<ans<<"\n";
    	    if(arr[arv]<dep[dpt]){
    	        st++;
    	        arv++;
    	    }else{
    	        st--;
    	        dpt++;
    	    }
    	    if(ans<st) ans = st;
    	    
    	}
    	return ans;
    }

int main(){
    int a[5] = {1,2,3,4,6};
    // vector<int> s = leaders(a, 5);
    // for(auto d:s) cout<<d<<" ";
    int arr[3] = {900 ,1100, 1235};
    int dpt[3] = {1000, 1200, 1240};

    cout<<findPlatform(arr, dpt, 3);
}

/**
 * 
 * 3
0900 1100 1235
1000 1200 1240
*/