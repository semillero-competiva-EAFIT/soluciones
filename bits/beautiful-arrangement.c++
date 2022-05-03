/*https://leetcode.com/problems/beautiful-arrangement/*/
#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
 
using namespace std;
 
typedef vector<int> vi;
 
int main(){
  int n, m; cin >> n >> m;
  vi b(n), p(m);
  forn(i, n) cin >> b[i];
  forn(i, m) cin >> p[i];
 
  vi sums(1<<m);
  forn(mask, 1<<m){
    int sum = 0;
    forn(bit, m){
      if(mask & 1<<bit){
        sum += p[bit];
      }
    }
    sums[mask] = sum;
  }
 
  set<int> ans;
 
  forn(m1, 1<<m){
    fore(m2, m1, (1<<m)-1){
      if((m1 & m2) || sums[m1] != sums[m2]) continue;
      for(int barra: b){
        ans.insert(barra + sums[m1] + sums[m2]);
      }
    }
  }
  
  for(int val: ans) cout << val << el;
}