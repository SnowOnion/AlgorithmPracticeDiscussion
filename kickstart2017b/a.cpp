#include <iostream>
#include<fstream>
#include<cstdio>

long long mod = 1000000007L;
long long twoNmod109[10010];

using namespace std;

int main() {

    ifstream in("/Users/sonion/Downloads/A-large.in.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(in.rdbuf());
    ofstream out("/Users/sonion/Downloads/A-large.out.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());


    twoNmod109[0] = 1;
    for (int j = 1; j < 10001; ++j) {
        twoNmod109[j] = (twoNmod109[j - 1] * 2) % mod;
    }

//    for (int j = 9900; j < 10001; ++j) {
//        cout<<twoNmod109[j]*twoNmod109[j]<<endl;
//    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N, K[10010];
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> K[i];
        }

        long long s = 0;
        for (int i = 1; i <= N; ++i) {
            s = (s + ((twoNmod109[i - 1] * (K[i] - K[N + 1 - i])) % mod)) % mod;
        }


        cout << "Case #" << t << ": " << s << endl;

    }

    return 0;

}