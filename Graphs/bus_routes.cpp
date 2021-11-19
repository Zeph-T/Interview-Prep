class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>gr;
        
        for(int i=0;i<routes.size();i++){ // get all the buses that stop in each bus stops
            for(int route : routes[i]){
                gr[route].push_back(i);
            }
        }
        unordered_set<int>visited_stops,visited_buses;
        queue<int>q;
        q.push(source);
        visited_stops.insert(source);
        int level = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int stop = q.front();
                q.pop();
                if(stop == target)return level;
                
                for(int bus : gr[stop]){ //for each stop, check the buses that stop here,
                    if(visited_buses.find(bus) != visited_buses.end())continue;
                    
                    for(int route : routes[bus]){ // check the routes the buses go to from the station
                        if(visited_stops.find(route) != visited_stops.end())continue;
                        q.push(route);
                        visited_stops.insert(route);
                    }
                    visited_buses.insert(bus);
                }
                
            }
            level++;
        }
        return -1;
    }
};