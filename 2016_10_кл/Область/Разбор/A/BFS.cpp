#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_COUNT = 1e5+15;

int a, b, cnt, fl;

vector <vector <int> > gr;
vector <int> q;

int d[MAX_COUNT], pred[MAX_COUNT];
bool used[MAX_COUNT];

void BFS()
{
    while (d[b] == 0)
    {
        int v = q[cnt];
        for (int i=0; i<gr[v].size(); ++i)
        {
            int to = gr[v][i];
            if (to == b) {q.push_back(to); d[to] = d[v]+1; fl=1; pred[to]=v; break;}
            if (!used[to] && to < b)
            {
                used[to]= true;
                q.push_back(to);
                d[to]= d[v]+ 1;
                pred[to] = v;
            }
        }
        cnt++;
        if (fl != 0) {break;}
    }

}

void make_graph_R(int s, int f)
{
  for (int i = s; i < f; i++)
  {
   if (i+1 <= f) gr[i].push_back(i+1);
   if (i*2 <= f) gr[i].push_back(i*2);
   if (i*3 <= f) gr[i].push_back(i*3);
  }
}

void in()
{
    ifstream cin ("A.in");
    cin >> a >> b;
}

void solution()
{
    gr.resize(b);
    make_graph_R(a, b);
    q.push_back(a);
    BFS();
}

void out()
{
    ofstream cout ("A.out");
    // גûגמה דנאפא
   /* for (int i = a; i < b; i++)
    {
        cout << i << ": ";
        for (int g = 0; g < gr[i].size(); g++)
        {
            cout << gr[i][g] << " ";
        }
        cout << "\n";
    }*/
    //cout << d[b] << "\n";
    /*for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] <<" ";
    }
    cout <<"\n";
    for (int i = 0; i < q.size(); i++)
    {
        cout << d[q[i]] <<" ";
    }
    cout <<"\n";
    for (int i = 0; i < q.size(); i++)
    {
        cout << pred[q[i]] <<" ";
    }
    cout <<"\n";*/
    cout <<b  <<" = ";
    int indx = b;
    vector <int> path;
    path.push_back(b);
    while (pred[indx] != 2)
    {
        indx = pred[indx];
        path.push_back(indx);
    }
    /*for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << "\n";
    }*/
    for (int i = 0; i < d[b]; i++)
    {
        cout <<"(";
    }
    cout << a;
    int ch = a;
    for (int i = path.size()-1; i>=0; i--)
    {
        if (ch == path[i]-1) {cout << "+1)"; ch++;}
        else
        {
            if (ch == path[i]/2) {cout << "*2)"; ch*=2;}
            else  {cout << "*3)"; ch*=3;}
        }
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
