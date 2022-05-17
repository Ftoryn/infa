#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int number) {
    if (number == 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i != 0)
            return false;
    }
    return true;
}

void out(vector<int> v) {
    for (int c : v) {
        cout << c << ' ';
    }
    cout << '\n';
}


int main() {
    // 1
    vector<int> p1;
    for (int i = 1; i < 11; ++i) {
        p1.push_back(i);
    }
    // 2
    for (int i = 0; i < 3; ++i) {
        int t;
        cin >> t;
        p1.push_back(t);
    }
    // 3
    random_shuffle(p1.begin(), p1.end());
    // 4
    for (auto it1 = p1.begin(); it1 != p1.end(); ++it1) {
        for (auto it2 = it1 + 1; it2 != p1.end(); ++it2) {
            if (*it1 == *it2) {
                p1.erase(it2);
            }
        }
    }
    // 5
    int cnt = 0;
    for (int c: p1) {
        cnt += c % 2;
    }
    // cout << cnt << '\n';
    // 6
    int min_ = p1[0], max_ = p1[0];
    for (int c: p1) {
        min_ = min(min_, c);
        max_ = max(max_, c);
    }
    // cout << min_ << ' ' << max_ << '\n';
    // 7
    int prime = -1;
    for (int c : p1) {
        if (is_prime(c)) {
            prime = c;
            break;
        }
    }
    // cout << prime << '\n';
    // 8
    for (int& c : p1) {
        c *= c;
    }
    // 9
    vector<int> p2(p1.size());
    for (int& c : p2) {
        c = rand();
    }
    // 10
    int sum = 0;
    for (int c : p2) {
        sum += c;
    }
    // cout << sum << '\n';
    // 11
    for (auto it =  p2.begin(); it != p2.begin() + 4; ++it) {
        *it = 0;
    }
    // 12
    vector<int> p3(p1.size());
    for (int i = 0; i < p1.size(); ++i) {
        p3[i] = p1[i] - p2[i];
    }
    // 13
    for (auto it = p3.begin(); it != p3.end(); ++it) {
        if (*it == 0) {
            p3.erase(it);
        }
    }
    // 14
    reverse(p3.begin(), p3.end());
    // 15
    vector<int> copy = p3;
    sort(copy.begin(), copy.end(), [](int a, int b) {return b < a;});
    copy.resize(3);
    // 16
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    // 17
    vector<int> merge_(p1.size() + p2.size());
    merge(p1.begin(), p1.end(), p2.begin(), p2.end(), merge_.begin());
    // 18
    // cout << lower_bound(merge_.begin(), merge_.end(), 1) - merge_.begin() << ' ';
    // cout << upper_bound(merge_.begin(), merge_.end(), 1) - merge_.begin() << '\n';
    // 19
    out(p1);
    out(p2);
    out(p3);
    out(merge_);
    return 0;
}