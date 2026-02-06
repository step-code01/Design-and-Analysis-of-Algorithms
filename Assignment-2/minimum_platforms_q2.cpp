#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int MNPR(int N, vector<int>& AT, vector<int>& DT){
        sort(AT.begin(),AT.end());
        sort(DT.begin(),DT.end()); //v.imp O(2nlogn) = O(nlogn)
        
        int i=0,j=0;
        int total_platforms = 0;
        int curr_platforms = 0; //curr platforms in use
        while (i!=N-1 && j!=N-1){
            if (AT[i] <= DT[j]){
                curr_platforms++;
                i++;
            }
            else{
                curr_platforms--;
                j++;
            }
            total_platforms = max(curr_platforms,total_platforms);
        }
        return total_platforms;
    }
};

int main(){
    vector<int> AT = {900,910,920,1100,1120}; 
    vector<int> DT = {940,1200,950,1130,1140};

    Solution s1;
    cout << "Minimum number of platforms required = " << s1.MNPR(AT.size(),AT,DT) << endl;
    return 0;
}
/*OUTPUT:
Minimum number of platforms required = 3*/


/*leading zeros not allowed in int - not a valid octal number 
0900 yeh allowed nhi hora tha v.imp

https://stackoverflow.com/questions/10020634/is-there-a-work-around-for-invalid-octal-digit-in-an-array*/

/*  vector<string> AT = {"09:00","09:10","09:20","11:00","11:20"};
    vector<string> DT = {"09:40","12:00","09:50","11:30","11:40"};
    want 1 step comparison nahh isliye avoided
*/
/*sort v.imp! dry run ntbk rem! v.imp*/