const int N = 1005;
struct BIT2D
{
	int a[N + 1][N + 1];
	void add(int x, int y, int val) {
		x++; y++;
		for (int i = x; i < N; i += (i & -i)) {
			for (int j = y; j < N; j += (j & -j)) {
				a[i][j] += val;
			}
		}
	}
	// tells the sum of numbers from
	// (0,0) to (x,y) whole rectangle
	int sum(int x, int y) {
		x++; y++;
		int ans = 0;
		for (int i = x; i > 0; i -= (i & -i)) {
			for (int j = y; j > 0; j -= (j & -j)) {
				ans += a[i][j];
			}
		}
		return ans;
	}
	int query(int x1, int y1, int x2, int y2) {
		int j4 = sum(x2, y2);
		int j1 = sum(x2, y1 - 1);
		int j2 = sum(x1 - 1, y2);
		int j3 = sum(x1 - 1, y1 - 1);
		// inclusion exclusion
		return j4 - j1 - j2 + j3;
	}
} bit;