/*https://leetcode.com/problems/subsets/*/
#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define el '\n'
#define sz(v) ((int)v.size())
#define d(x) cout<< #x<< " " << x<<el
 
using namespace std;
 
typedef vector<int> vi;
 
int p3[15];
 
inline int get_digit(int mask, int pos){
  return (mask / p3[pos]) % 3;
}
 
int main(){
  int n, m; cin >> n >> m;
  vi b(n), p(m);
  forn(i, n) cin >> b[i];
  forn(i, m) cin >> p[i];
 
  set<int> ans;
  for(int barra: b) ans.insert(barra);
 
  p3[0] = 1;
  for1(i, m) p3[i] = p3[i-1]*3;
 
  forn(mask, p3[m]){
    int sum1 = 0, sum2 = 0;
    forn(bit, m){
      int val = get_digit(mask, bit);
      if(val == 1)
        sum1 += p[bit];
      else if(val == 2)
        sum2 += p[bit];
    }
    if(sum1 == sum2){
      for(int barra: b) 
        ans.insert(barra + sum1 + sum2);
    }
  }
 
  for(int val: ans) cout << val << el;
}