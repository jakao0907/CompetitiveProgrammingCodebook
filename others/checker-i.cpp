#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

#define AC 42
#define WA 43
#define MXN 200005
#define ll long long
#define lowbit(x) (x&-x)

using namespace std;

char reportfile[50];
ll n,k;
ll bit[MXN],arr[MXN];

void update(int x,ll v){
    while(x<=n){
        bit[x]+=v;
        x+=lowbit(x);
    }
}

ll query(int x){
    ll ret = 0;
    while(x){
        ret += bit[x];
        x-=lowbit(x);
    }
    return ret;
}

int main(int argc, char* argv[]) {
    /*
    * argv[1]: 输入
    * argv[2]: 标准输出
    * argv[3]: 评测信息输出的文件夹
    * stdin: 选手输出
    */
    FILE* fin = fopen(argv[1], "r");
    // FILE* fstd = fopen(argv[2], "r");
    sprintf(reportfile, "judgemessage.txt");
    FILE* freport = fopen(reportfile, "w");

    // double pans, jans;
    // scanf("%lf", &pans);
    // fscanf(fstd, "%lf", &jans);
    fscanf(fin, "%lld%lld",&n,&k);

    ll x,m=1;
    while(scanf("%lld",&x)!=EOF){
        arr[m++] = x;
    }
    if(m-1!=n){
        fprintf(freport, "too many value\n");
        // quitf(_wa, "too many value");
        return WA;
    }
    ll tot = 0;
    for(int i=m-1;i>0;i--){
        if(arr[i]>n || arr[i]<1){
            // for(int j=1;j<=m;j++)   fprintf(freport,"%lld ", arr[j]);
            // fprintf(freport, "\n");
            // fprintf(freport, "value %lld out of bound\n",arr[i]);
            // quitf(_wa, "value out of bound");
            return WA;
        }    
        tot += query(arr[i]);
        update(arr[i],1);
    }
    if(tot != k){
        fprintf(freport, "value of k not equal to answer");
        // quitf(_wa, "value of k not equal to answer");
        return WA;
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        if(arr[i] != i){
            fprintf(freport, "not permutation\n");
            // quitf(_wa, "not permutation");
            return WA;
            // return WA;
        }
    }
    fprintf(freport, "accepted\n");
    // return AC;
    // quitf(_ok, "accepted");

    // if (abs(pans - jans) < 1e-3) {
    // fprintf(freport, "Good job\n");
    // return AC;
    // } else {
    // fprintf(freport, "Too big or too small, expected %f, found %f\n", jans,
    //         pans);
    // return WA;
    // }
}