#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> JS(vector<int>& deadline, vector<int>& profit){
        vector<vector<int>> jobs;
        int n = deadline.size();
        int count = 0;
        int totalProfit = 0;
        for (int i=0; i < n; i++) jobs.push_back({profit[i],deadline[i]});

        sort(jobs.rbegin(), jobs.rend()); 
        vector<int> slots;
        slots.resize(n);
        for (int i=0; i < n; i++) slots[i] = 0;

        for (int i=0; i < n; i++){
            int currProfit = jobs[i][0];
            int currDeadline = jobs[i][1];
            int start = min(n,currDeadline) - 1;
            for (int j=start; j >= 0; j--){
                if (slots[j] == 0){
                    slots[j]=1;
                    count++;
                    totalProfit+=currProfit;
                    break;
                }
            }
        }
        return {count, totalProfit}; /*imp way v.imp*/
    }
};
int main(){
    vector<int> deadline = {2,1,2,1,3};
    vector<int> profit = {100,19,27,25,15};

    Solution s1;
    vector<int> result = s1.JS(deadline,profit);

    cout << "Jobs Completed: " << result[0] << endl;
    cout << "Max Profit: " << result[1] << endl;
    return 0;
}
/*OUTPUT:
Jobs Completed: 3
Max Profit: 142*/

/*https://www.geeksforgeeks.org/cpp/vector-rbegin-and-rend-function-in-c-stl/*/