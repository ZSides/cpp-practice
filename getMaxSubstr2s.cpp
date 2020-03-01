#include <iostream>
#include <string>
#include <functional>

using namespace std;

void test(const function<int(string)>& func, const string & str , int expectation_value) {
    int result = func(str);
    cout << (result == expectation_value ? "YES" : "NO") << "! Expected: " << expectation_value << "; Result: " << result << '\n';
}

int getMax(const string & s) {
    int la, lh, t = 0, answer = 0;
    char c, h, a;
    bool flag_h, flag_a;
    flag_a = flag_h = false;
    for (int i = 0, z = s.size(); i < z; ++i) {
        c = s[i];
        if (!flag_a) { // a not init
            flag_a = true;
            a = c;
            la = i;
        } else if ((!flag_h) && (c != a)) { // h not init and we got new symbol
            flag_h = true;
            h = c;
            lh = i;
        } else if ((c != h) && (c != a)) { // new symb
            t = i - min(la, lh) - 1;
            if (la < lh) {
                la = i;
                a = c;
            } else {
                lh = i;
                h = c;
            }
        } else {
            if (c == h) {
                lh = i;
            } else {
                la = i;
            }
        }
        t++;
        answer = max(t, answer);
    }
    return answer;
}

int main() {
    string s;
    test(getMax, "qweabaaabaxabaaaaba", 8);
    test(getMax, "abbaqeqeaaaabbbb", 8);
    test(getMax, "eabbaeeewqababa", 5);
    test(getMax, "eabbaeeeababab", 6);
    test(getMax, "abbaeeewqababa", 5);
    test(getMax, "qweabaaabaewq", 7);
    test(getMax, "eaaabbbbbe", 8);
    test(getMax, "aaabbbbb", 8);
    test(getMax, "   ", 3);
    test(getMax, "aa", 2);
    test(getMax, "qw", 2);
    test(getMax, "a", 1);
    test(getMax, "", 0);
    return 0;
}