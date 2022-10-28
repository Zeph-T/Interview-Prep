#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int &x : arr)cin >> x;
    int x,y;
    cin >> x >> y;

    unordered_map<int,pair<int,int>>mp;
    mp[-1] = {0,0};
    int count = 0;
    for(int i = 0 ; i < n ; i++ ){
        mp[i] = mp[i-1];
        if(arr[i] == 1)mp[i].first++;
        else mp[i].second++;

        



    }




}