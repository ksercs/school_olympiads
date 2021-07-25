#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

long long MAX_X, MAX_Y, st_x, st_y, k = 1;
long long ans=1;

void in()
{
    ifstream cin ("path.in");
    cin >> MAX_X >> MAX_Y;
    cin >> st_x >> st_y;
}

void solution()
{
    if (st_x > 0 && st_x <= MAX_X && st_y > 0 && st_y <= MAX_Y)
    {
        /*while(true)
        {
            if (st_y > MAX_Y)  {ans += (MAX_Y-st_y); break;}
            st_x+=k; ans+=k;
            //cout <<"1: " << ans << "\n";
            if (st_x > MAX_X)  {ans += (MAX_X-st_x); break;}
            st_y-=k; ans+=k;
            k++;
            //cout <<"2: " << ans << "\n";
            if (st_y <= 0)  {ans -= (st_y+1); break;}
            st_x-=k; ans+=k;
            //cout <<"3: " << ans << "\n";
            if (st_x <= 0)  {ans -= (st_x+1); break;}
            st_y+=k; ans+=k;
            k++;
            //cout <<"4: " << ans << "\n\n";
        }*/
        long long kv = min(min(st_x-1, st_y-1), min(MAX_X-st_x, MAX_Y-st_y));
        long long kv_s = kv*2;
        kv_s += 1;
        long long kv_sq = kv_s*kv_s;
        //cout << kv_s << " " << kv_sq << "\n";
        if (kv == MAX_Y-st_y) ans = kv_sq + 3*kv_s + 2;
        if (kv == st_x-1) ans = kv_sq + 2*kv_s + 1;
        if (kv == st_y-1) ans = kv_sq + kv_s;
        if (kv == MAX_X - st_x) ans = kv_sq;
    }
    else ans = 0;
}

void out()
{
     ofstream cout ("path.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
