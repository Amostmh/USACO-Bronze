#include <bits/stdc++.h>
using namespace std;
struct cow
{
    char direction;
    int x;
    int y;
    int order;
    int distance_walked = 0;
    bool operator<(cow i)
    {
        if(direction == 'E')
        {
            return y < i.y;
        }
        else
        {
            return x < i.x;
        }
    }
};

int main()
{
    int n; cin >>n;
    vector<cow> east;
    vector<cow> north;
    char a;
    int b,c;
    for(int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        if(a == 'E')
        {
            east.push_back({a,b,c,i});
        }
        else
        {
            north.push_back({a,b,c,i});
        }
    }

    sort(east.begin(),east.end());
    sort(north.begin(),north.end());

    for(int i = 0; i < east.size(); ++i)
    {
        for(int j = 0; j < north.size(); ++j)
        {
            if(east[i].x < north[j].x && east[i].y > north[j].y && !north[j].distance_walked)
            {
                //East stop north
                if(east[i].y - north[j].y > north[j].x - east[i].x)
                {
                    north[j].distance_walked = east[i].y - north[j].y;
                }
                //East stopped by north
                else if(east[i].y - north[j].y < north[j].x - east[i].x)
                {
                    east[i].distance_walked = north[j].x - east[i].x;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < north.size(); ++i)
    {
        east.push_back(north[i]);
    }

    sort(east.begin(),east.end(),[](cow i, cow j){return i.order < j.order;});


    for(vector<cow>::iterator it = east.begin(); it < east.end(); ++it)
    {
        if(it->distance_walked != 0)
        {
            cout << it->distance_walked << '\n';
        }
        else{
            cout << "Infinity" << '\n';
        }
    }

}
