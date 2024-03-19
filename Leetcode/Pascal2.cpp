#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }

    void printLastRow(int rowIndex) {
        vector<int> lastRow = getRow(rowIndex);

        for (int num : lastRow) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution solution;
    int numRows = 5;
    solution.printLastRow(numRows);

    return 0;
}
