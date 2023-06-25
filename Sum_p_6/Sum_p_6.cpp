#include <iostream>
#include <vector>
#include <map>
using namespace std;

void calculateGroupSums(const vector<int>& V, map<int, vector<int>>& M) {
    int groupSum = 0;
    int currentDigit = -1;

    for (const auto& num : V) {
        int lastDigit = num % 10;
        if (lastDigit != currentDigit) {
            if (groupSum != 0 && currentDigit != -1) {
                M[currentDigit].push_back(groupSum);
            }
            currentDigit = lastDigit;
            groupSum = 0;
        }
        groupSum += num;
    }

    if (currentDigit != -1) {
        if (M[currentDigit].size() > 1) {
            M[currentDigit].push_back(groupSum);
        }
        else {
            M[currentDigit].push_back(0);
        }
    }
}

int main() {
    vector<int> V;

    int count;
    cout << "Enter the count of elements for V: ";
    cin >> count;

    cout << "Enter elements for V: ";
    for (int i = 0; i < count; ++i) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    map<int, vector<int>> M;

    calculateGroupSums(V, M);

    // Виводимо отримане відображення
    for (const auto& entry : M) {
        cout << entry.first << ": ";
        for (const auto& value : entry.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
