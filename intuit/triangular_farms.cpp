// #include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;


// 1 2 3 4 5 6 7 8 9 10
bool valid(int a,int b,int c){
    if(a + b <= c or a + c <= b or b + c <= a)return false;
    return true;
}

int main() {
	int n ,k;
    cin >> n;
    vector<int>arr(n);
    for(int &x : arr)cin >> x;
    cin >> k;
    sort(arr.begin(),arr.end());

    int i = 0 , j = n - 1;

    int count = 0;
    for(int start = 0 ; start < n ; start++){
        int i = start + 1;
        int j = n - 1;
        int max_limit = k - arr[start] - 1; 
        while(i < j){
            int sum = arr[j] + arr[i];
            if(sum > max_limit)j--;
            else{
                cout << arr[start] << " " << arr[i] << " " << arr[j] << endl;
                if(valid(arr[i],arr[j],arr[start])){
                    count++;  
                }
                i++;
            }
        }
    }

    cout << count;

}