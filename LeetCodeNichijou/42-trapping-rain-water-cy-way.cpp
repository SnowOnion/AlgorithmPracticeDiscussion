#include<iostream>
#include<vector>

using namespace std;
typedef vector<int> VI;

template<class T>
T min2(T x,T y){
    return x<y?x:y;
}

// flyinggoblin思路 2017-05-10 711kara午饭时
// 啊啊啊 墙的判定还要更复杂 烦 2017-05-10 14:32:08

class Solution {
public:
    /** 
    Given 
    [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
    [0,1,0,2,1,0,1,3,2,1,2,2,1], return 6. 
    [0,1,0,2,1,1,0,1,3,2,1,2,1], return 7. 
    // 阴险哄人示例用例生成法：让常见错法能碰对。TODO
    */
    int trap(vector<int>& height) {
        VI& a=height;
        int len=height.size();        
        if(len<=2) return 0;
    
        VI wallIndices;
        // int pre,cur,nxt;
        int cur;        
        for(cur=1;cur+1<len;cur++){
            if(a[cur-1]<=a[cur] && a[cur+1]<a[cur]){ // 平台儿 以（最）右者为墙
                wallIndices.push_back(cur);
            }
        } // now cur == len-1
        if(a[cur]>=a[cur-1]) wallIndices.push_back(cur);
        if(wallIndices.size()<2) return 0;

        // exp: 1 3 7 10
        //exp 1 3 8 11 | actual: 1 3 5 8 11

        int totalWater=0;
        for(int lw=0,rw=1;rw<wallIndices.size();lw++,rw++){
            int complementTarget=min2(a[wallIndices[lw]],a[wallIndices[rw]]);
            for(int i=wallIndices[lw]+1; i<wallIndices[rw]; i++){
                totalWater+=(complementTarget-a[i]);
            }
        }
        return totalWater;
    }
};

int main(){

    auto s=new Solution();
    int tca[]={0,1,0,2,1,1,0,1,3,2,1,2,1};
    vector<int> tc(tca,tca+sizeof(tca)/sizeof(int));
    cout<<s->trap(tc)<<endl;

}