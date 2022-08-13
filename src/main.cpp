#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto n = int{};
	cin >> n;

	const auto& inf = numeric_limits<int>::max();
	auto d = vvi(n, vi(n, inf));

	for (auto i = 0; i < n; ++i) {
		auto s = string{};
		cin >> s;

		for (auto j = 0; j < n; ++j) {
			if ('Y' == s[j]) {
				d[i][j] = 1;
			}
		}
	}

	for (auto m = 0; m < n; ++m) {
		for (auto i = 0; i < n; ++i) {
			for (auto j = 0; j < n; ++j) {
				if (inf == d[i][m] || inf == d[m][j]) {
					continue;
				}

				const auto& newDist = d[i][m] + d[m][j];
				if (newDist < d[i][j]) {
					d[i][j] = newDist;
					d[j][i] = newDist;
				}
			}
		}
	}

	auto maxCt = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		auto ct = int{ 0 };
		for (auto j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}

			if (d[i][j] <= 2) {
				++ct;
			}
		}

		if (maxCt < ct) {
			maxCt = ct;
		}
	}

	cout << maxCt;

	return 0;
}