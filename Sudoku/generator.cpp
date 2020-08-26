#include "Sudoku/generator.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <experimental/random>
using std::max;
using std::sort;
using std::experimental::randint;
using namespace Sudoku;
int val[10][10], mp[10][10];
int ans = 0, hh[10][10], ss[10][10], bb[3][3][10], err = 0, cc = 0;
int a[10], b[10], c[4][4], ret[10][10];

struct qs {
    int x, y;
};
qs ls[81];
int cmp(const qs& a, const qs& b) {
    return val[a.x][a.y] > val[b.x][b.y];
}
int abs(int x) {
    return x < 0 ? -x : x;
}

bool Sudoku::check(int now_map[10][10]) {
    int helper[10] = {0};
    for (int i = 1; i <= 9; i++) {
        memset(helper, 0, sizeof(helper));
        for (int j = 1; j <= 9; j++) {
            if (!now_map[i][j])
                return false;
            if (helper[now_map[i][j]])
                return false;
            helper[now_map[i][j]]++;
        }
    }
    for (int i = 1; i <= 9; i++) {
        memset(helper, 0, sizeof(helper));
        for (int j = 1; j <= 9; j++) {
            if (!now_map[j][i])
                return false;
            if (helper[now_map[j][i]])
                return false;
            helper[now_map[j][i]]++;
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            memset(helper, 0, sizeof(helper));
            for (int p = 3 * i - 2; p <= 3 * i; p++) {
                for (int q = 3 * j - 2; q <= 3 * j; q++) {
                    if (!now_map[p][q])
                        return false;
                    if (helper[now_map[p][q]])
                        return false;
                    helper[now_map[p][q]]++;
                }
            }
        }
    }
    return true;
}

void dfs(int w) {
    if (ans == 2)
        return;
    if (w == cc + 1) {
        err = 0;
        ans++;
        if (ans == 1) {
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    ret[i][j] = mp[i][j];
                }
            }
        }
        if (ans == 2)
            return;
    } else {
        for (int k = 9; k >= 1; k--) {
            if (hh[ls[w].x][k] == 0)
                if (ss[ls[w].y][k] == 0)
                    if (bb[(ls[w].x - 1) / 3][(ls[w].y - 1) / 3][k] == 0) {
                        mp[ls[w].x][ls[w].y] = k;
                        hh[ls[w].x][k]++;
                        ss[ls[w].y][k]++;
                        bb[(ls[w].x - 1) / 3][(ls[w].y - 1) / 3][k]++;
                        dfs(w + 1);
                        if (ans == 2)
                            return;
                        mp[ls[w].x][ls[w].y] = 0;
                        hh[ls[w].x][k]--;
                        ss[ls[w].y][k]--;
                        bb[(ls[w].x - 1) / 3][(ls[w].y - 1) / 3][k]--;
                    }
        }
    }
}
int solve(int qmap[10][10]) {
    cc = 0;
    err = 0;
    ans = 0;
    memset(hh, 0, sizeof(hh));
    memset(ss, 0, sizeof(ss));
    memset(bb, 0, sizeof(bb));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (qmap[i][j] != 0) {
                mp[i][j] = qmap[i][j];
                if (hh[i][qmap[i][j]] == 0)
                    hh[i][qmap[i][j]] = 1, a[i]++;
                else
                    err = 1;
                if (ss[j][qmap[i][j]] == 0)
                    ss[j][qmap[i][j]] = 1, b[j]++;
                else
                    err = 1;
                if (bb[(i - 1) / 3][(j - 1) / 3][qmap[i][j]] == 0)
                    bb[(i - 1) / 3][(j - 1) / 3][qmap[i][j]] = 1,
                    c[(i - 1) / 3][(j - 1) / 3]++;
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
        return 0;
    } else {
        err = 1;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                val[i][j] = max(c[(i-1) / 3][(j-1) / 3], max(a[i], b[j]));
            }
        }
        sort(ls + 1, ls + cc + 1, cmp);
        dfs(1);
        if (err == 1)
            return 0;
    }
    if (ans) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                qmap[i][j] = ret[i][j];
            }
        }
    }
    return ans;
}
void fill(int filled_map[10][10]) {
    std::experimental::reseed(time(NULL));
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (randint(1, 81) < 16) {
                filled_map[i][j] = randint(1, 9);
            } else
                filled_map[i][j] = 0;
        }
    }
    while (!solve(filled_map)) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (randint(1, 81) < 30) {
                    filled_map[i][j] = randint(1, 9);
                } else
                    filled_map[i][j] = 0;
            }
        }
    }
}
void fill_mut(int difficulty,
              bool mut_map[10][10],
              int now_map[10][10],
              int filled_map[10][10]) {
    std::experimental::reseed(time(NULL));
    do {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (randint(1, 81) <= difficulty) {
                    mut_map[i][j] = false;
                    now_map[i][j] = filled_map[i][j];
                } else {
                    mut_map[i][j] = true;
                    now_map[i][j] = 0;
                }
            }
        }
    } while (solve(now_map) != 1);
}

void Sudoku::generate(int difficulty,
                      bool mut_map[10][10],
                      int now_map[10][10]) {
    int filled_map[10][10];
    fill(filled_map);
    fill_mut(difficulty, mut_map, now_map, filled_map);
}