#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string,unordered_set<string>>mp;
    for(int i = 0 ; i < n ; i++){
        string topic,language;
        cin >> topic >> language;
        mp[topic].insert(language);
    }

    cin >> n;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        string topic , language;
        cin >> topic >> language;
        if(mp.find(topic) != mp.end()){
            auto lang_set = mp[topic];
            if(lang_set.find(language) == lang_set.end()){
                count++;
                cout << topic << " " << language << endl;
            }
        }
    }
    cout << count;
}