#include <iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include <vector>

using namespace std;

vector<double> xs(10010);
vector<double> ys(10010);
vector<double> w(10010);

//static bool sort_using(double u, double v)
//{
//    return u < v;
//}
//
//void sss(vector<int>a,int l,int r){
//    for(int i=l+1;i<=r;i++){
//        for(int j=l;j<i;j++){
//            if(a[j]<a[i]){
//                int tmp=a[j];
//                for(int )
//            }
//        }
//    }
//}


int main() {
// small only! w==1
//    ifstream in("/Users/sonion/Downloads/A-large.in.txt");
//    streambuf *cinbuf = cin.rdbuf();
//    cin.rdbuf(in.rdbuf());
//    ofstream out("/Users/sonion/Downloads/A-large.out.txt");
//    streambuf *coutbuf = cout.rdbuf();
//    cout.rdbuf(out.rdbuf());

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> xs[i] >> ys[i] >> w[i];
        }

        sort(xs.begin()+1 , xs.begin() + N+1); // baka!!!!!!!! 1 2017-05-07 16:03:02 well it's not the only problem
        sort(ys.begin()+1 , ys.begin() + N+1);

        double s = 0.;
        for (int i = 1; i <= N / 2; i++) {
            s += (xs[N + 1 - i] - xs[i]);
            s += (ys[N + 1 - i] - ys[i]);
        }

        cout << "Case #" << t << ": " << s << endl;

    }

    return 0;

}