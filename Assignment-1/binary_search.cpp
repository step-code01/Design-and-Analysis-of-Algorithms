#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int binary_search(int arr[], int low, int high, int target){
        while (low <= high){
            int mid = low + (high-low)/2;
            if (arr[mid] < target){
                low = mid+1;
            }
            else if (arr[mid] > target){
                high = mid-1;
            }
            else if (arr[mid] == target){
                return mid;
            }
        }
        cout << "Target never found"; //if not present, control here
        return -1;
    }
};
int main(){
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    int target = 23;
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution s1;
    int pos = s1.binary_search(arr,0,size-1,target);
    cout << "Target found at: " << pos << endl;
}
/*Output:
Target found at: 5*/