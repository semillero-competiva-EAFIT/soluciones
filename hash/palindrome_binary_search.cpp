/*
santiago cano
no hay problema
*/
int calc_hash(string &s){
  int h = 0;
  int x = 29;
  vector<int> pre(s.size());
	vector<int> pot(s.size(), 1);
  for(int i = 0; i < s.size(); ++i){
    char c = s[i];
    h = (c-'a' + 1) + h*x;
    pre[i] = h;
    if(i > 0){
      pot[i] = pot[i - 1]*x;
    }
  }
}

int query(int l, int r, vector<int> &pre){
  if(l==0) return pre[r];
  return pre[r] - (pre[l - 1])*pot[r-l+1];
}

bool f(int l, vector<int> &pre, vector<int> &prer){
  for(int i = 0; i + l - 1 < pre.size(); ++i){
    if(query(i, i+l-1, pre) == query(i, i+l-1, prer)){
      return true;
    }
  }
  return false;
}


int solve(string &s){
  int h = 0, hr = 0;
  int x = 29;
  vector<int> pre(s.size());  
  vector<int> prer(s.size());

	vector<int> pot(s.size(), 1);
  for(int i = 0; i < s.size(); ++i){
    char c = s[i];
    h = (c-'a' + 1) + h*x;
    
    c = s[s.size() - 1 - i];
    hr = (c-'a' + 1) + hr*x;
    
    pre[i] = h;
    pre[s.size() - 1 - i] = hr;
    if(i > 0){
      pot[i] = pot[i - 1]*x;
    }
  }
  
  int l = 0, r = s.size();
  
  while(l + 1 < r){
    int mid = (l + r)/2;
    mid*=2;
    if(f(mid, pre, prer)) l = mid;
    else r = mid;
  }
  return l;
}

