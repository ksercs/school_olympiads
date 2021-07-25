#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

const int M_MAX = 1000,
          NM_MAX = 100000;

struct dung{ int a, b, c, d; };
typedef pair<int, pair<int,int> > pp;

dung burn[M_MAX + 1][M_MAX + 1];
set < pp > Vortex;
int times[M_MAX + 1][M_MAX + 1];
pair< int, int > burns[NM_MAX + 1];
int N, M, K,
    answer;

void vector_filling()
{
    for( int c = 1; c <= N; c++ )
    {
        for(int b = 1; b <= M; b++)
        {
            times[c][b] = INT_MAX;
            pp nw;
            nw.first = INT_MAX;
            nw.second.first = c;
            nw.second.second = b;
            Vortex.insert(nw);
        }
    }
}

void V_add(pp V, int nzn)
{
    if(times[V.second.first][V.second.second] > nzn)
    {
        Vortex.erase(V);
        V.first = nzn;
        times[V.second.first][V.second.second] = nzn;
        Vortex.insert(V);
    }
}

void in()
{
    ifstream cin ("fort.in");
    cin >> N >> M >> K;
    for( int c = 1; c <= N; c++ )
    {
        for(int b = 1; b <= M; b++ )
        {
            cin >> burn[c][b].a >> burn[c][b].b >> burn[c][b].c >> burn[c][b].d;
        }
    }
    for( int c = 0; c < K; c++ )
    {
        cin >> burns[c].first >> burns[c].second;
    }
}

void solution()
{
    vector_filling();
    for( int c = 0; c < K; c++ )
    {
        pp nw;
        nw.first = INT_MAX;
        nw.second.first = burns[c].first;
        nw.second.second = burns[c].second;
        times[nw.second.first][nw.second.second] = 0;
        V_add(nw, 0);
    }
    int fire = 0;
    set <pp> :: iterator it;
    while( fire < N * M )
    {
        it = Vortex.begin();
        cout << it->second.first << " " << it->second.second << " " << it->first << "\n";
        fire++;
        if(it->second.first - 1 != 0)V_add( (*it), it->first + burn[it->second.first][it->second.second].a );
        if(it->second.second - 1 != M + 1 )V_add( (*it), it->first + burn[it->second.first][it->second.second].b );
        if(it->second.first + 1 != N + 1)V_add( (*it), it->first + burn[it->second.first][it->second.second].c );
        if(it->second.second - 1 != 0)V_add( (*it), it->first + burn[it->second.first][it->second.second].d );
        Vortex.erase(it);
    }
    answer = it->first;
}

void out()
{
     ofstream cout("fort.out");
     cout << answer << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
