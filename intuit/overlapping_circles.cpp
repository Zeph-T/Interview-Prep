#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool overlapping(int x1, int x2, int y1, int y2, int r1, int r2)
{
    ll sumOfRadius = r1 + r2;
    ll rightSide = sumOfRadius * sumOfRadius;

    ll diffOFX = x1 - x2;

    ll diffOFY = y1 - y2;

    ll leftSide = (diffOFX * diffOFX) + (diffOFY * diffOFY);

    if (leftSide <= rightSide)
        return true;

    return false;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[i][0] = a, v[i][1] = b, v[i][2] = c;
    }

    vector<int> ad[n];
    for (int i = 0; i < n; i++)
    {
        long long x1 = v[i][0], y1 = v[i][1], r1 = v[i][2];
        for (int j = i + 1; j < n; j++)
        {
            long long x2 = v[j][0], y2 = v[j][1], r2 = v[j][2];
            if (overlapping(x1, y1, x2, y2, r1, r2))
            {
                ad[i].push_back(j);
                ad[j].push_back(i);
            }
        }
    }


    int ans = 0;

    priority_queue<pair<int, int>> pq;
    vector<bool> available(n, true);

    vector<int> degree(n, 0);

    for (int i = 0; i < n; i++)
    {
        degree[i] = ad[i].size();
        pq.push(make_pair(degree[i], i));
    }

    while (!pq.empty())
    {

        pair<int, int> tp = pq.top();
        pq.pop();

        if (tp.first == 0)
            break;

        int node = tp.second;


        if (available[node] == false || (degree[node] != tp.first))
        {
            continue;
        }

        ans++;

        available[node] = false;

        for (int i = 0; i < ad[node].size(); i++)
        {
            int child = ad[node][i];
            if (available[child] == true)
            {
                degree[child]--;
                pq.push(make_pair(degree[i], i));
            }
        }
    }

    cout << ans << endl;
    return 0;
}