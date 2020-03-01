#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    vector<int> a = {1, 3, 5, 4, 2, 5, 7, -1, -2, -3};
    vector<int> b = {2, 4, 5, 6, 1, -1};
    unordered_set<int> c = {1, 2, 3, 4, -1, -5};
    unordered_set<int>::iterator cfind, cend = c.end();
    for (auto ai = a.begin(), aie = a.end(); ai != aie; ++ai) {
        for (auto bi = b.begin(), bie = b.end(); bi != bie; ++bi) {
            cfind = c.find(-*ai - *bi);
            if (cfind != cend) {
                cout << *ai << " + " << *bi << " + " << *cfind << " = 0; ";
            }
        }
    }
    return 0;
}