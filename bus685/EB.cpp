#include <bits/stdc++.h>
using namespace std;
int t,n;

vector<int> vec[10000];

void jug(int x){
    if(x>=0 && x<100)cout<<"aa.";
    if(x>=100 && x<200)cout<<"aa.bb.";
    if(x>=300 && x<400)cout<<"aa.bb.cc.";
    if(x>=400 && x<500)cout<<"dd.";
    if(x>=500 && x<600)cout<<"dd.ee.";
    if(x>=600 && x<700)cout<<"dd.ee.ff.";
    if(x>=700 && x<800)cout<<"dd.ee.ff.gg.";
    if(x>=800 && x<900)cout<<"dd.ee.ff.gg.hh.";
    if(x>=900 && x<1000)cout<<"ii.";
    if(x>=1000 && x<1500)cout<<"ii.jj.";
    if(x>=1500 && x<2000)cout<<"ii.jj.kk.";
    if(x>=2000 && x<2500)cout<<"ii.jj.kk.ll.";
    if(x>=2500 && x<3000)cout<<"ii.jj.kk.ll.mm.";
    if(x>=3000 && x<4000)cout<<"ii.jj.kk.ll.mm.nn.";
    if(x>=4000 && x<5000)cout<<"oo.";


}

int main()
{
    ios::sync_with_stdio(false);
    freopen("bus685.txt","r",stdin);
    freopen("flare.json","w",stdout);
    int x,y;
    int maxn = 0;
    while(cin>>x>>y){
        vec[x].push_back(y);
        vec[y].push_back(x);
        maxn = max(maxn,max(x,y));
    }
    cout<<"["<<endl;
    int sz;
    bool first = 1;
    for(int i=0;i<=maxn;i++){
        sz = vec[i].size();
        //if(sz>0){
            if(!first){
                cout<<","<<endl;
            }
            first = 0;
            cout<<"{\"name\":\"flare.";jug(i);
            cout<<i<<"\",\"size\":5,\"imports\":[\"flare.";jug(vec[i][0]);
            cout<<vec[i][0]<<"\"";
            for(int j=1;j<sz;j++){
                cout<<",\"flare.";jug(vec[i][j]);
                cout<<vec[i][j]<<"\"";
            }
            cout<<"]}";
        //}
    }
    cout<<endl<<"]"<<endl;


    return 0;
}
