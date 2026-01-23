#include <iostream>
#include <climits>
using namespace std;
/*max sum either:
1. completely in L
2. completely in R
3. crossing subarray

hence find max(crossing sum, Lsum, Rsum)*/
class Solution{
    public:
    int findMaxSubarray(int arr[], int low, int high){
        if (low == high) return arr[low];
        else{
            int mid = (low+high)/2;
            int L = findMaxSubarray(arr,low,mid); 
            int R = findMaxSubarray(arr,mid+1,high);
            int C = FMCS(arr,low,mid,high);
            
            if(L >= R && L >= C) return L;
            else if(R >= L && R >= C) return R;
            else return C;
        }
    }
    int FMCS(int arr[],int low, int mid, int high){
        int Lsum = INT_MIN;
        int sum = 0;
        for (int i = mid; i>=low; i--){
            sum = sum + arr[i];
            if (sum > Lsum){
                Lsum = sum;
            }
        }
        int Rsum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= high; i++){
            sum = sum + arr[i];
            if (sum > Rsum){
                Rsum = sum;
            }
        }
        return Lsum + Rsum;
    }
};
int main(){
    Solution s;
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = s.findMaxSubarray(arr, 0, n-1);
    cout << max_sum;
    return 0;
}
/*Output: 7*/