#include <bits/stdc++.h>
using namespace std;
struct event
{
    int time;
    int buckets;
    bool operator<(event i){return time < i.time;}
};
ofstream fout("blist.out");
ifstream fin("blist.in");

int main()
{
    int n; fin >> n;
    int foo, bar, baz;
    vector<event> qweqwe;
    for(int i = 0; i < n; ++i)
    {
        fin >> foo >> bar >> baz;
        qweqwe.push_back({foo,-baz});
        qweqwe.push_back({bar,baz});
    }
    sort(qweqwe.begin(),qweqwe.end());

    int available_buckets = 0;
    int used = 0;
    for(int i = 0; i < qweqwe.size(); ++i)
    {
        if(qweqwe[i].buckets < 0)
        {
            if(available_buckets < (qweqwe[i].buckets*-1))
            {
                used += qweqwe[i].buckets - available_buckets;
                available_buckets = 0;
            }
            else
            {
                available_buckets += qweqwe[i].buckets;
            }
        }
        else if(qweqwe[i].buckets > 0)
        {
            available_buckets += qweqwe[i].buckets;
        }
    }
    fout << available_buckets;
}
