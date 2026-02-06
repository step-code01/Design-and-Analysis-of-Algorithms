#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void sortbyDensity(vector<int>& value, vector<int>& weight){
        for (int i=0; i < value.size(); i++){
            for (int j=i+1; j < value.size(); j++){
                if ((double)value[i]/(double)weight[i] <= (double)value[j]/(double)weight[j]){
                    swap(value[i],value[j]);
                    swap(weight[i],weight[j]);
                }
            } //desc order swap
        }
    } //write better algo quick/merge sort based on criteria 
    double FrKnapsack(vector<int>& value, vector<int>& weight, int W){
        sortbyDensity(value,weight); //per weight max contri kiska vo choose
        double maxValue = 0;
        int i=0;
        while (W >=0){
            if (weight[i] > W){ //rem capacity
                maxValue+=(((double)value[i]/(double)weight[i])*W); //if neatly div na ho isliye v.imp
                break;
            } 
            else{
                W-=weight[i];
                maxValue+=value[i];
            }
            i++;
        }
        return maxValue;
    }   
};

int main(){
    vector<int> value = {100,60,120};
    vector<int> weight = {20,10,40};
    int W = 50; //knapsack cap

    Solution s1;
    cout << "Maximum value = " << s1.FrKnapsack(value,weight,W) << endl;
    return 0;
}
/*OUTPUT:
Maximum value = 220*/

/*per weight max value kaun la pa rha hai 
select that (greedy) cuz weight limited hai apne pr*/

/*line 9 float did cuz 120/50 = 2.4 -> 2, 80/30 = 2.67 -> 2 both will become 2, v.imp
we need decimal too
and write double instead of float v.imp better cpp*/  