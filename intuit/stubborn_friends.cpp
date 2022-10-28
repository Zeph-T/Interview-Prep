#include<bits/stdc++.h>

using namespace std;



class UF{ // C++20
public:
    vector<int> rank, parent;
    int N;
    UF (int n) : N{n}, rank(n), parent(n){
        iota(begin(parent), end(parent), 0);
    }

    int leader(int x){
        return parent[x] == x? x : (parent[x]=leader(parent[x]));
    }

    void unite(int x, int y){
        x = leader(x);
        y = leader(y);
        if (x == y){
            return;
        }
        if (rank[y] > rank[x]){
            swap(x, y);
        }
        if (rank[y] == rank[x]){
            ++rank[x];
        }
        parent[y] = x;
    }

    vector<vector<int>> getGroups(){
        unordered_map<int,int> mp;
        for (int i = 0; i < N; ++i){
            int sz = size(mp);
            mp.try_emplace(leader(i), sz);
        }
        vector<vector<int>> ans(size(mp));
        for (int i = 0; i < N; ++i){
            ans[mp[leader(i)]].push_back(i);
        }
        return ans;
    }
};

int solve(int N, int C, vector<int> money, vector<int> candy, vector<pair<int,int>> friends){
    UF uf(N);
    for (auto& [a, b] : friends){
        --a; --b;
        uf.unite(a, b);
    }
    vector<vector<int>> groups = uf.getGroups();
    vector<int> dp(C+1);
    for (auto& g : groups){
        vector<int> ndp {dp}; // don't pick any from this group
        for (int person : g){
            for (int j = candy[person]; j <= C; ++j){
                ndp[j] = max(ndp[j], dp[j-candy[person]]+money[person]); // pick from this group
            }
        }
        swap(ndp, dp);
    }
    return dp[C];
}