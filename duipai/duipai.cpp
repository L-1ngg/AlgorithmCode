#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    while (true) {
        cout << "test: " << ++t << endl;
        system("gen > data.in");  // 数据生成器将生成数据写入输入文件
        system("solve.exe < data.in > solve.out");  // 获取正解输出
        system("std.exe < data.in > std.out");  // 获取暴力代码输出
        if (system("fc solve.out std.out > diff.log")) {
            std::cout << "WA\n";
            break;
            // 该输入数据已经存放在test.in文件中，可以直接利用进行调试
        }
        std::cout << "AC\n";
    }
}