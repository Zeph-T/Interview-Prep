class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<vector<int>>st;
        vector<int>res(n,0);
        for(string log : logs){
            log+=':';
            stringstream str(log);
            string id,state,time;
            getline(str,id,':');getline(str,state,':');getline(str,time,':');
            if(state == "start")st.push({stoi(id) , stoi(time) , 0}); // if there is a new function, just push P.S 0 indicates the time taken by their child process
            else{
                auto x = st.top();
                st.pop(); // if there is a end state, it means the function which is at the top of the stack
                int interval = stoi(time) - x[1] + 1; // extract the interval by the time it has started and the time it has ended
                res[x[0]] += interval - x[2]; // add this interval and dont forget to subtract the relative count at the time of insertion
                if(!st.empty())st.top()[2] += interval; // ince the removal of the process has taken interval amount of time, we have to add the same amount to the top function which is running.
            };
        }
        return res;
    }
};