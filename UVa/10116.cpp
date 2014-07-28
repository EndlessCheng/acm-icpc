#include <stdio.h>
#include <string.h>

int n, m, start, vis[15][15], i, j, judge;
char map[15][15];

void dfs(int x, int y, int step) {
	if (judge)
		return;
	if (map[x][y] == '#') {
		printf("%d step(s) to exit\n", step);
		return;
	}
	if (vis[x][y] != -1) {
		printf("%d step(s) before a loop of %d step(s)\n", vis[x][y], step - vis[x][y]);
		judge = 1;
		return;
	}
	vis[x][y] = step;
	if (map[x][y] == 'W') {
		dfs(x, y - 1, step + 1);
		if (judge)
		return;
	}
	if (map[x][y] == 'S') {
		dfs(x + 1, y, step + 1);
		if (judge)
		return;
	}
	if (map[x][y] == 'E') {
		dfs(x, y + 1, step + 1);
		if (judge)
		return;
	}
	if (map[x][y] == 'N') {
		dfs(x - 1, y, step + 1);
		if (judge)
		return;
	}
}
int main() {
	while (~scanf("%d%d%d", &n, &m, &start) && n && m && start) {
		judge = 0;
		for (i = 0; i <= n + 1; i ++)
			for (j = 0; j <= m + 1; j ++) {
				map[i][j] = '#';
				vis[i][j] = -1;
			}
		getchar();
		for (i = 1; i <= n; i ++) {
			for (j = 1; j <= m; j ++)
				scanf("%c", &map[i][j]);
				getchar();
			}
		dfs(1, start, 0);
	}
	return 0;
}
