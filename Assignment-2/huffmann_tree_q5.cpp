#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printCodes(int node, string code,vector<char>& ch,vector<int>& left,vector<int>& right) {
        if (left[node] == -1 && right[node] == -1) {
            cout << ch[node] << " " << code << endl;
            return;
        }

        printCodes(left[node], code + "0", ch, left, right);
        printCodes(right[node], code + "1", ch, left, right);
    }
    void HEC(vector<char>& chars, vector<int>& freq) {
        int n = chars.size();

        vector<int> f = freq;
        vector<int> left(2 * n, -1);
        vector<int> right(2 * n, -1);
        vector<char> ch(2 * n, '#');
        vector<bool> used(2 * n, false);

        for (int i = 0; i < n; i++) ch[i] = chars[i];
        int size = n;

        while (true) {
            int x = -1, y = -1;
            //1st min
            for (int i = 0; i < size; i++) {
                if (!used[i] && (x == -1 || f[i] < f[x])) {
                    x = i;
                }
            }
            //2nd min 
            for (int i = 0; i < size; i++) {
                if (!used[i] && i != x && (y == -1 || f[i] < f[y])) {
                    y = i;
                }
            }
            if (y == -1) break;
            
            //merge back
            f.push_back(f[x] + f[y]);
            left[size] = x;
            right[size] = y;
            used[x] = used[y] = true;
            used.push_back(false);
            ch.push_back('#');

            size++;
        }

        int root = size - 1;
        printCodes(root, "", ch, left, right);
    }
};

int main() {
    vector<char> chars = {'a','b','c','d','e','f'};
    vector<int> freq  = {5,9,12,13,16,45};

    Solution s1;
    s1.HEC(chars, freq);

    return 0;
}
/*OUTPUT:
f 0
c 100
d 101
a 1100
b 1101
e 111*/
