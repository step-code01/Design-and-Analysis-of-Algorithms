#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    void merge(vector<int>& arr, int low, int mid, int high){           
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++){
            L[i] = arr[low + i];
        }
        for (int j = 0; j < n2; j++){
            R[j] = arr[mid + 1 + j];
        }

        int i=0, j=0;
        int k=low;

        while (i<n1 && j<n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& arr, int low, int high){
        if (low >= high)return;

        int mid = low + ((high - low) / 2);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};
int main(){
    vector<int> v1 = {38,27,43,10};
    Solution sol1;
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    sol1.mergeSort(v1,0,v1.size()-1);
    cout <<endl;
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    
    return 0;
}