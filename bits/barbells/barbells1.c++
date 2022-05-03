/*
https://codeforces.com/gym/101291
por simon fallon
https://github.com/simonfallon
*/
#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define el '\n'
#define sz(v) ((int)v.size())
#define d(x) cout<< #x<< " " << x<<el
 
using namespace std;
 
typedef vector<int> vi;
 
int main(){
  int n, m; cin >> n >> m;
  vi b(n), p(m);
  forn(i, n) cin >> b[i];
  forn(i, m) cin >> p[i];
 
  set<int> ans;
  for(int barra: b) ans.insert(barra);
 
  forn(mask, 1<<m){
    vi van;
    forn(bit, m){
      if(mask & 1<<bit){
        van.push_back(p[bit]);
      }
    }
    forn(mask2, 1 << sz(van)){
      int sum1 = 0, sum2 = 0;
      forn(bit, sz(van)){
        if(mask2 & 1<<bit){
          sum1 += van[bit];
        } else{
          sum2 += van[bit];
        }
      }
      if(sum1 == sum2){
        for(int barra: b){ 
          ans.insert(barra + sum1 + sum2);
        }
      }
    }
  }
 
  for(int val: ans) cout << val << el;
}
