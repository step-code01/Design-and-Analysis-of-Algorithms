#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int MAS(int N, vector<int>& s, vector<int>& f){
        int count = 1;
        int i=1; int j=0;
        cout << "(" << s[i-1] << "," << f[j] << ")"; //first selected activity
        while (i!=N && j!=N){ //v.imp OR (||) nhi! v.v.imp
            if (f[j] <= s[i]){
                count++;
                j++;
                i++;
                cout << "(" << s[i-1] << "," << f[j] << ")";
            }
            else{
                i++;
                N--;
                s.erase(s.begin() + i - 1);
                f.erase(f.begin() + j + 1);
                i--;
            }
        }
        cout << endl;
        return count;
    }
};
int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> finish = {2,4,6,7,9,9};

    /*assuming it is sorted*/
    Solution s1;
    cout << "maximum number of non-overlapping activities that can be performed by the person is: ";
    cout << s1.MAS(start.size(),start,finish) <<endl;
    return 0;
}
/*OUTPUT:
maximum number of non-overlapping activities that can be performed by the person is: (1,2)(3,4)(5,7)(8,9)
4*/