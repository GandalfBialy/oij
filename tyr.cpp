#include "bits/stdc++.h"
using namespace std;

#define double long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> in(n);
    for(auto &ele: in)
        cin >> ele.first >> ele.second;

    double answer = 1e6;
    pair<int, int> indices;
    for(int iteration : {-1, 1}) {
        vector<int> sorted(n);
        iota(sorted.begin(), sorted.end(), 0);
        sort(sorted.begin(), sorted.end(), [&](int i, int j) {
            auto p = [&](int k) {
                return make_pair(in[k].second, in[k].first * iteration);
            };
            return p(i) < p(j);
        });

        for(int i = 1; i < n; ++i) {
          int xi, xj, yi, yj;
            tie(xi, yi) = in[sorted[i]];
            tie(xj, yj) = in[sorted[i - 1]];
            if(yi != yj) {
                if (answer > abs((double)(yi - yj) / (double)(xi - xj))) {
                    answer = abs((double)(yi - yj) / (double)(xi - xj));
                    indices = {sorted[i], sorted[i - 1]};
                }
            }
        }
    }
    int i, j;
    tie(i, j) = indices;
    cout << i + 1 << " " << j + 1 << "\n";
}
