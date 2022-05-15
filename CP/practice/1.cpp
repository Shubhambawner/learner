#include <bits/stdc++.h>
using namespace std;

void Swap(vector<int> arr, int p1, int p2)
{
    int temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

int minSwaps(vector<int> &nums)
{
    // Code here
    vector<int> alt;
    int n = nums.size();
    map<int, int> pos2;
    for (int i = 0; i < n; i++)
    {
        alt.push_back(nums[i]);
        pos2[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == alt[i])
            continue;
        int j = i;
        int k = 0;
        while (nums[i] != alt[i])
        {
            cout << nums[i] << " " << alt[i] << " " << alt[pos2[nums[i]]] << " " << endl;
            
            ans++;
            pos2[alt[i]] = pos2[nums[i]];
            int temp = pos2[nums[i]];
            pos2[nums[i]] = i;

            Swap(alt, i, temp);
            i = pos2[nums[i]];
        }
        i = j;
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 8, 5, 4};
    cout << minSwaps(a);
}
 