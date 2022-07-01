#include <bits/stdc++.h>

using namespace std;

//int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};

//int x[4] = {1, 0, -1, 0};
//int y[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long ans = 0;
		string sign = (a[0] > 0 ? "positive" : "negative");
		for (int i = 0; i < n; i++) {
			if (sign == "positive" && a[i] > 0) {
				int id = i;
				int mx = 0;
				while (id < n && a[id] > 0) {
					mx = max(mx, a[id]);
					id++;
				}
				ans += mx;
				sign = "negative";
				i = id - 1;
			} else if (sign == "negative" && a[i] < 0) {
				int id = i;
				int mx = INT_MIN;
				while (id < n && a[id] < 0) {
					mx = max(mx, a[id]);
					id++;
				}
				ans += mx;
				sign = "positive";
				i = id - 1;
			}
		}
		cout << ans << '\n';
	}
}
