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
    vector<int> v1 = {12,11,13,5,6,7};
    Solution sol1;
    cout << "Original Array: "; 
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    sol1.mergeSort(v1,0,v1.size()-1);
    cout <<endl;
    cout << "Sorted Array: ";
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    
    vector<int> v2 = {38, 27, 43, 3, 9, 82, 10};
    Solution sol2;
    cout << "Original Array: "; 
    for (int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    sol2.mergeSort(v2,0,v2.size()-1);
    cout <<endl;
    cout << "Sorted Array: ";
    for (int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    return 0;
}
/*Output:
Original Array: 12 11 13 5 6 7 
Sorted Array: 5 6 7 11 12 13 
Original Array: 38 27 43 3 9 82 10 
Sorted Array: 3 9 10 27 38 43 82*/

//{38,27,43,10} other eg 