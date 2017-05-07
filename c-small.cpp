#include <iostream>
#include<fstream>
#include<cstdio>

//long long mod = 1000000007L;
//long long twoNmod109[10010];

int mini(int a, int b, int c) {
    if (a < b) {
        if (a < c) return a;
        else return c;
    } else {
        if (b < c) return b;
        else return c;
    }
//    return (a) < (b) ? ((a) < (c) ? (a) : c) : ((b) < (c) ? (b) : (c));
}

int h[110][110];
char grid[110][110];

using namespace std;

int main() {

    // 只是小数据!!! K==1

    ifstream in("/Users/sonion/Downloads/C-small-attempt1.in.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    ofstream out("/Users/sonion/Downloads/C-small-attempt1.out.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());


    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M, K;
        cin >> N >> M >> K;

        // violent clear
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= M + 1; j++) {
                grid[i][j] = '.';
                h[i][j] = 0;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> grid[i][j];
//                h[i][j] = 0; ////// debaka! 2017-05-07 14:48:08
            }
        }
//
//        // 糊墙
//        for (int i = 0; i <= N + 1; i++) {
//            grid[i][0] = '.';
//            grid[i][M + 1] = '.';
//            h[i][0] = 0;
//            h[i][M + 1] = 0;
//        }
//        for (int j = 0; j <= M + 1; j++) {
//            grid[0][j] = '.';
//            grid[N + 1][j] = '.';
//            h[0][j] = 0;
//            h[N + 1][j] = 0;
//        }

//        cout<<"---"<<endl;
//        for (int i = 1; i <= N; i++) {
//            for (int j = 1; j <= M; j++){
//                cout<< grid[i][j];
//            }
//            cout<<endl;
//        }

        for (int j = 1; j <= M; j++) {
            if (grid[N][j] == '#') {
                h[N][j] = 1;
            } else { // == '.'
                h[N][j] = 0;
            }
        }

        int maxh = 0;
//        bool once = true;
        for (int i = N - 1; i >= 1; i--) {
            for (int j = 1; j <= M; j++) {
                if (grid[i][j] == '#') {
                    h[i][j] = 1 + mini(h[i + 1][j - 1], h[i + 1][j], h[i + 1][j + 1]);
                    if (h[i][j] > maxh) {
                        maxh = h[i][j];
                    }
                    /////
//                    if (t == 3 && maxh == 11 && once) {
//                        once = false;
//                        cout << i << ' ' << j << endl;
//                    }
                } else { // debaka forgot else!!!!! 2017-05-07 15:07:35
                    h[i][j] = 0;
                }
            }
        }


        if (t == 64) {
            cout << N << ' ' << M << ' ' << K << endl;
        }

        cout << "Case #" << t << ": " << maxh * maxh << endl;

    }

    return 0;

}