#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    vector<int> a = {1, 3, 5, 4, 2, 5, 7, -1, -2, -3};
    vector<int> b = {2, 4, 5, 6, 1, -1};
    unordered_multiset<int> c = {1, 2, -5, -5, 3, 4, -1, -5};
    int answer = 0;
    for (auto ai = a.begin(), aie = a.end(); ai != aie; ++ai) {
        for (auto bi = b.begin(), bie = b.end(); bi != bie; ++bi) {
            answer += c.count(-*ai - *bi);
        }
    }
    cout << answer << '\n';
    return 0;
}