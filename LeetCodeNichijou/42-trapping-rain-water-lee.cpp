// https://leetcode.com/problems/trapping-rain-water/#/description
#include<iostream>
#include<vector>

using namespace std;
typedef vector<int> VI;

template<class T>
T min2(T x,T y){
    return x<y?x:y;
}
// status: 示例没过；不想debug了，废弃，用flyinggoblin思路重写。
// 回来用这个思路…… 2017-05-10 14:50:22 AC 
// https://leetcode.com/submissions/detail/102511304/

class Solution {
public:
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
// side effect: will edit height!
    int trap(vector<int>& height) {
        vector<int>& a=height;
        int len=height.size();        
        if(len<=2) return 0;

        int total=0;
        int leftWall;
        int cur,nxt;
        for(cur=0,nxt=1;nxt<len;cur++,nxt++){
            if(a[nxt]<a[cur]){
                leftWall=cur;
                break;
            }
        }
        if(nxt==len) return 0; // end loop by "!nxt<len" rather than "nxt<cur break"

        int forwardSeeker, prev;
        for(forwardSeeker=leftWall+1, prev
        =leftWall;forwardSeeker<len;forwardSeeker++,prev++){
            if(a[forwardSeeker]>a[prev]){
                // kurikaesu
                int rightWall=forwardSeeker;
                // TODO optimize: go back by big step rather than small step
                int complementTarget=min2(a[leftWall],a[rightWall]);
                for(int backwardSeeker=rightWall-1; backwardSeeker>leftWall;backwardSeeker--){
                    int toComplement = complementTarget-a[backwardSeeker];
                    if(toComplement >=0) {
                        total+=toComplement;
                        a[backwardSeeker]=complementTarget;
                    }else{
                        break; // 没到左墙，也该停了。 5 4 1 2 -> 1
                    }
                }
                
                // record new left wall
                if(a[rightWall]>=a[leftWall]){
                    leftWall=rightWall;
                }
            }
        }
        return total;
    }
};

int main(){

    auto s=new Solution();
    // int tca[]={0,1,0,2,1,0,1,3,2,1,2,1}; // 6
    // int tca[]={0,1,0,2,1,0,1,3,2,1,2,2,1}; // return 6. 
    // int tca[]={0,1,0,2,1,1,0,1,3,2,1,2,1}; // return 7. 
    // int tca[]={5,6,7,0,2,1,3,2,4,3,2}; // return 12. 
    // int tca[]={2,3,4,2,3,1,2,0,7,6,5}; // return 12. 
    int tca[]={5,4,1,2}; // return 1 // baka n+1: actual -1
    vector<int> tc(tca,tca+sizeof(tca)/sizeof(int));
    cout<<s->trap(tc)<<endl;

}