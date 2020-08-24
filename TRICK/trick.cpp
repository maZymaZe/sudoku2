#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int ans = 0, mp[9][9], it, hh[9][10], ss[9][10], bb[3][3][10], err = 0, v[9][9],
    cc = 0, a[9], b[9], c[4][4], vv[9][9];
struct qs {
    int x, y;
} ls[81];
int cmp(const qs& aa, const qs& bc) {
    return vv[aa.x][aa.y] > vv[bc.x][bc.y];
}
void op() {
    int s = 0;
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            s += v[i][j] * mp[i][j];
        }
    }
    if (s > ans)
        ans = s;
}
void dfs(int w) {
    if (w == cc + 1) {
        err = 0;
        printf("\n");
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                printf("%d ", mp[i][j]);
            }
            printf("\n");
        }
        op();
    } else {
        for (int k = 9; k >= 1; k--) {
            if (hh[ls[w].x][k] == 0)
                if (ss[ls[w].y][k] == 0)
                    if (bb[ls[w].x / 3][ls[w].y / 3][k] == 0) {
                        mp[ls[w].x][ls[w].y] = k;
                        hh[ls[w].x][k]++;
                        ss[ls[w].y][k]++;
                        bb[ls[w].x / 3][ls[w].y / 3][k]++;
                        dfs(w + 1);
                        mp[ls[w].x][ls[w].y] = 0;
                        hh[ls[w].x][k]--;
                        ss[ls[w].y][k]--;
                        bb[ls[w].x / 3][ls[w].y / 3][k]--;
                    }
        }
    }
}
int main() {
    printf("you can input the Sudoku like the following:\n");
    printf(
        "080 600 010\n906 050 402\n004 890 005\n\n013 004 008\n070 906 "
        "030\n400 700 150\n\n200 071 600\n709 060 801\n060 009 040\n");
	printf("and press enter to see the result");

        for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            v[i][j] = 10 - max(abs(i - 4), abs(j - 4));
            scanf("%1d", &it);
            if (it != 0) {
                mp[i][j] = it;
                if (hh[i][it] == 0)
                    hh[i][it] = 1, a[i]++;
                else
                    err = 1;
                if (ss[j][it] == 0)
                    ss[j][it] = 1, b[j]++;
                else
                    err = 1;
                if (bb[i / 3][j / 3][it] == 0)
                    bb[i / 3][j / 3][it] = 1, c[i / 3][j / 3]++;
                else
                    err = 1;
            } else {
                cc++;
                ls[cc].x = i;
                ls[cc].y = j;
            }
        }
    }
    if (err == 1) {
        printf("-1");
    } else {
        err = 1;
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                vv[i][j] = max(c[i / 3][j / 3], max(a[i], b[j]));
            }
        }
        sort(ls + 1, ls + cc + 1, cmp);
        dfs(1);
        if (err == 1)
            printf("-1");
        //	else printf("%d",ans);
    }
	system("pause");
    return 0;
}
