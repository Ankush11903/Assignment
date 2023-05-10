#include <bits/stdc++.h>
using namespace std;
#define f(n) for (int i = 0; i < n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define E '\n'
#define pb emplace_back
#define F first
#define S second
#define vi vector<int>
#define SUM(a) accumulate(a.begin(), a.end(), 0)
#define sort(x) sort(x.begin(), x.end())
#define int long long
#define mod 998244353
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<E;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
//======================================******ANKUSH************===========================================

const int MAXN = 100005;

vector<int> adj[MAXN];
vector<pair<int, int>> path;
int low[MAXN], disc[MAXN], parent[MAXN], t;

void dfs(int u) {
    low[u] = disc[u] = ++t;
    for(int v: adj[u]) {
        if(!disc[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) {
                path.emplace_back(u, v);
            }
        } else if(v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    for(auto& a: connections) {
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    for(int i = 0; i < n; i++) {
        if(!disc[i]) {
            dfs(i);
        }
    }
    vector<vector<int>> ans;
    for(auto& a: path) {
        ans.push_back({a.first, a.second});
    }
    return ans;
}

int32_t main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3},{2,3},{4,5},{4,2},{1,9}};
    vector<vector<int>> ans = criticalConnections(n, connections);

    cout<<"Number of critical connections :"<<ans.size()<<endl;
    // We Can Print This Ans In Any Form
    for(auto& a: ans) {
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}
