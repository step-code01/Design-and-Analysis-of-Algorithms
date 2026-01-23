#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if (low<high){
            int q = partition(arr,low,high);
            quickSort(arr,low,q-1);
            quickSort(arr,q+1,high);
        }
    }
    
  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot_elem = arr[high];
        int i = low - 1;
        for (int j=low; j<high; j++){
            if (arr[j] < pivot_elem){
                i = i+1;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp2 = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp2;
        return i+1;
    }
};

int main(){
    Solution sol1;
    vector<int> v1 = {4,1,3,9,7};

    for(int i=0; i<v1.size();i++){
        cout<<v1[i];
    }
    cout << endl;
    sol1.quickSort(v1,0,4);

    for(int i=0; i<v1.size();i++){
        cout<<v1[i];
    }
    return 0;
}
/*Output:
41397
13479*/