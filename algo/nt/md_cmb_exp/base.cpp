//snip:6,50//

#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 1e6;
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
	// Test powmod
	int p = 1e9 + 7;
	
	cout << "Started!\n";

	if (8 == powmod(2, 3, p)) {
		cout << "OK\n";
	} else {
		cout << "Failed!\n";
	}

	if (4 == powmod(p+2, 2, p)) {
		cout << "OK\n";
	} else {
		cout << "Failed!\n";
	}

	// Test invmod
	for(int i=2; i<11; i++) {
		ll inv = invmod(i, p);
		if ((i * inv) % p == 1) {
			cout << "OK\n";
		} else {
			cout << "Failed\n";
		}
	}

}
