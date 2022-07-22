//snip:6,50//

#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 300000+1000;
ll fact[MAXN] = {1};

void initFact(int p) {
	for(int i=1; i<MAXN; i++) {
		fact[i] = fact[i-1] * i;
		if (fact[i] >= p) fact[i] %= p;
	}
}

ll powmod(ll a, ll b, ll p) {
	if (a >= p) a %= p;
	if (a == 0) return 0;

	ll res = 1;

	while(b > 0) {
		if (b & 1 ) {
			res *= a;
			if (res >= p) {
				res %= p;
			}
		}
		a *= a;
		if (a >= p) a %= p;
		b >>= 1;
	}

	return res;
}

ll invmod(ll a, ll p) {
	return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p) {
	ll A = fact[n] * invmod(fact[k], p);
	if (A >= p) A %= p;
	ll B = A * invmod(fact[n-k], p);
	if (B >= p) B %= p;
	return B;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	// Test powmod
	int p = 1e9 + 7;

  int n;
  cin >> n;

  initFact(p);

  ll ans = 0;

  ll x;
  for(int i=0; i<n; i++) {
    cin >> x;
    ans += nCk(n-1, n-i-1, p) * x * ((n-i-1 & 1) == 0 ? +1 : -1);
    
    if (ans >= p || ans <= -p) ans %= p;
  }

  cout << (ans%p + p)%p << endl;
}	
