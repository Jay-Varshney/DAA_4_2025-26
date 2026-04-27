class Solution {
  public:
    int find(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        vector<pair<int,int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        
        sort(jobs.rbegin(), jobs.rend());
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        
        vector<int> parent(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++){
            parent[i] = i;
        }
        
        int countJobs = 0, totalProfit = 0;
        
        for(auto &job : jobs){
            int prof = job.first;
            int dead = job.second;
            
            int slot = find(dead, parent);
            
            if(slot > 0){
                countJobs++;
                totalProfit += prof;
                
                parent[slot] = find(slot - 1, parent);
            }
        }
        
        return {countJobs, totalProfit};
    }
};