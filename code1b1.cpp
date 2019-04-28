#include<bits/stdtr1c++.h>
using namespace std;
typedef long long int lli;
#define elif else if
#define getchar_unlocked getchar
#define destruct return
#define NULL 0
#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n-1;i>-1;--i)
int zero=0;


inline void scanx(long long int *a){
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

inline void scant(int *a){
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

bool comparison(const pair<int,int> &a,const pair<int,int> &b){
    return a.second>b.second; }

int main()
{
    lli t,n,k,x,y;
    vector<pair<lli,lli> >v;
    pair<lli,lli> answer;
    map<pair<lli,lli>,lli> mapper;
    map<string,int> alpha;
    set<string>d;
    string z;
    cin>>t;
    REP(i,t)
    {
        cin>>n>>k;
        lli arr[k][k];
        for(int j=0;j<k;++j)
        {
            for(int c=j;c<k;++c) mapper[make_pair(c,j)]=0;
        }
        alpha["N"]=0;
        alpha["E"]=0;
        alpha["W"]=0;
        alpha["S"]=0;
        while(n--)
            {
                cin>>x>>y>>z;
                d.insert(z);
                ++alpha[z];
                //arr[x][y]=1;
                if(z=="N")
                {
                  arr[x][y+1]=1;
                  v.push_back(make_pair(x,y+1));

                }
                elif(z=="S")
                    {arr[x][y-1]=1;
                    v.push_back(make_pair(x,y-1)); }
                elif(z=="E")
                {
                    arr[x+1][y]=1;
                    v.push_back(make_pair(x+1,y));
                }
                elif(z=="W")
                {
                    arr[x-1][y]=1;
                    v.push_back(make_pair(x-1,y));
                }

            }

            lli maxi=INT_MIN,res1,res2;

           for(int f=0;f<v.size();++f)
           {
               mapper[make_pair(v[f].first,v[f].second)]+=1;
               if(mapper[make_pair(v[f].first,v[f].second)]>maxi)
               {
                   maxi=mapper[make_pair(v[f].first,v[f].second)];
                   res1=v[f].first;
                   res2=v[f].second;
               }
             //  cout<<mapper[make_pair(v[i].first,v[i].second)];
             //  cout<<endl;
           }



        set<string>::iterator it;
        string pow;
         if(d.size()==1)
           {
               for(it=d.begin();it!=d.end();++it)
                pow=*it;
               if(pow=="N" && alpha[pow]==maxi)
                {
                    if(alpha[pow]==alpha["E"] || alpha[pow]==alpha["W"])
                        {
                            res1=0;
                            res2=0;
                        }
                        else res1=0;
                }
               if(pow=="S" && alpha[pow]==maxi)
                {
                    if(alpha[pow]==alpha["E"] || alpha[pow]==alpha["W"])
                        {
                            res1=0;
                            res2=0;
                        }
                        else res1=0;
                }
               if(pow=="E" && alpha[pow]==maxi)
                {
                    if(alpha[pow]==alpha["N"] || alpha[pow]==alpha["S"])
                        {
                            res1=0;
                            res2=0;
                        }
                        else res2=0;
                }
                if(pow=="W" && alpha[pow]==maxi)
                {
                    if(alpha[pow]==alpha["N"] || alpha[pow]==alpha["S"])
                        {
                            res1=0;
                            res2=0;
                        }
                        else res2=0;
                }

           }
           pow="0";

            cout<<"Case #"<<i+1<<": "<<res1<<" "<<res2<<endl;

           v.clear();
           d.clear();


        //cout<<"Case #"<<i+1<<": "<<rand()%k<<" "<<rand()%k<<endl;

    }

    destruct zero;
}
