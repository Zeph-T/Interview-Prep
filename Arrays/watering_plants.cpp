class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int current = capacity;
        int n = plants.size();
        for(int index = 0 ; index < n ; index++){
            if(current >= plants[index]){
                current -= plants[index];
                steps++;
            }else{
                steps += 2 * index +1;
                current = capacity - plants[index];
            }
        }
        return steps;
    }
};