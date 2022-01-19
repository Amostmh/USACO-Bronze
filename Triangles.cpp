#include <bits/stdc++.h>
using namespace std;

struct somestruct
{
  int diff;
  int y1;
  int y2;
  int x;
  bool operator<(somestruct i){return diff > i.diff;}
};

ofstream fout("triangles.out");
ifstream fin("triangles.in");

int main()
{
  int n; fin >> n;
  vector<pair<int,int>> fences;
  vector<somestruct> foo;
  vector<int> areaList;
  int a, b;
  for(int i = 0; i < n; ++i){fin >> a >> b; fences.push_back({a,b});}

  sort(fences.begin(),fences.end());
  for(int i = 0; i < n-1; ++i)
  {
    int j = i+1;
    while(fences[j].first == fences[i].first)
    {
      foo.push_back({fences[j].second - fences[i].second,fences[j].second,fences[i].second,fences[i].first});
      ++j;
    }
  }
  sort(foo.begin(),foo.end());

  for(int i = 0; i < foo.size(); ++i)
  {
    for(int j = 0; j < fences.size(); ++j)
    {
      if(fences[j].second == foo[i].y1)
      {
        areaList.push_back(foo[i].diff*(max(foo[i].x,fences[j].first) - min(foo[i].x,fences[j].first)));
      }
      else if(fences[j].second == foo[i].y2 && fences[j].first != foo[i].x)
      {
        areaList.push_back(foo[i].diff*(max(foo[i].x,fences[j].first) - min(foo[i].x,fences[j].first)));
      }
    }
  }
  sort(areaList.begin(),areaList.end(), greater<int>());
  fout << areaList[0];
}
