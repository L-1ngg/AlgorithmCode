#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int num[4];
char itoc[4] = { 'W','I','N','G' };
bool can[4][4][4], f[200][200][4];
map<char, int>ctoi = { {'W',0},{'I',1},{'N',2},{'G',3} };

bool print(int i) {
    if (i == 4)return 0;
    if (f[0][s.size() - 1][i]) cout << itoc[i];
    return print(i + 1) || f[0][s.size() - 1][i];
}

int main() {
    for (int i = 0;i < 4;++i)cin >> num[i];
    for (int i = 0;i < 4;++i)
        for (int j = 0;j < num[i];++j) {
            cin >> s;
            can[i][ctoi[s[0]]][ctoi[s[1]]] = 1;
        }
    cin >> s;
    for (int i = 0;i < s.size();++i)
        f[i][i][ctoi[s[i]]] = 1;
    for (int len = 2;len <= s.size();++len)
        for (int l = 0, r = len - 1;r < s.size();++l, ++r)
            for (int m = l;m < r;++m)
                for (int i = 0;i < 4;++i)
                    for (int j = 0;j < 4;++j)
                        for (int k = 0;k < 4;++k)
                            f[l][r][i] |= f[l][m][j] && f[m + 1][r][k] && can[i][j][k];
    if (!print(0))cout << "The name is wrong!";
    return 0;
}