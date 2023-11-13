//JAI SHREE RAM
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fi(n) for(ll i=0; i<n; i++)
#define pb push_back
#define fin(i,a,n) for(ll i=a; i<n; i++)
#define fcontn vector<ll> cont(n); for(ll i = 0;i<n;i++){cin >> cont[i];}
#define nn ll n; cin >> n;
#define nk ll n,k; cin >> n>>k ;
#define nkx ll n,k,x;cin>>n>>k>>x;
#define prs setprecision(1e7)<<
#define lowb(cont,key) lower_bound(cont.begin(),cont.end(),key)-cont.begin()//INCLUDED
#define upb(cont,key) upper_bound(cont.begin(),cont.end(),key)-cont.begin()//NOT INCLUDED
// GIVES NUMBER OF SET BITS IN X
#define countset(x) __builtin_popcountl(x)
// trailing zeros count
#define trzeros(x) __builtin_ctzl(x)
// leading zeros count64bit()
#define lezeros64(x) __builtin_clzll(x)
// leading zeros count32bit()
#define lezeros32(x) __builtin_clz(x)
using namespace std;
const ll mod =1e9+7;
const ll len=1000000;
//This is the length of boolean check array for primes
bool arr[len];
inline void debugMode() {

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
// Factorial with given modulo
vector<ll>factorials(ll modulo,ll range){
	vector<ll>answer(range);
	answer[0]=1;
	for(ll i=1;i<range;i++){
		answer[i]=((answer[i-1]%modulo)*i%modulo)%modulo;
	}
	return answer;
}
// To get this filled with primes run sieve function 
vector<ll>primes;
void sieve(){
	memset(arr, true, sizeof arr);
	arr[2] = true;
	for (ll i = 2; i < sqrt(len); i++) {
		for (ll j = i * i; j < len; j += i) {
			arr[j] = false;
		}
	}
	for (ll i = 2; i < len; i++) {
		if (arr[i]) {
			primes.pb(i);
		}
	}
}
// This Function returns all the primefac of a number without including 1 
vector<ll>primefac(ll x,vector<ll>&primes){
	vector<ll>answer;
	for(ll i=0;i<primes.size();i++){
		if(primes[i]>x)break;
		while(x%primes[i]==0){
			answer.pb(primes[i]);
			x/=primes[i];
		}
	}
	return answer;

}
// This class is able to create an object which can store three values 
class triplet{
public:
	ll x,y,gcd;
};
// extended GCD gives the solution(x,y) of equation ax+by=gcd(a,b) 
triplet extended(ll a,ll b){
	if(b==0){
		triplet temp;
		temp.x=1;
		temp.y=0;
		temp.gcd=a;
		return temp;
	}
	triplet temp=extended(b,a%b);
	triplet answer;
	answer.x=temp.y;
	answer.y=temp.x-((a/b)*temp.y);;
	answer.gcd=temp.gcd;
	return answer;
}
// This Function is binaryexponentiation with modulo 
ll modDivide(ll a,ll b,ll modulo){
	a=a%modulo;
	if(__gcd(b,modulo)!=1){
		cout<<"---MODULO IS NOT PRIME---";
		return -1;
	}
	triplet temp=extended(b,modulo);
	return (a*temp.x+modulo)%modulo;
}
// This Function is binaryexponentiation with modulo 
ll binaryexponentiation(ll x, ll b, ll modulo) {
	ll answer=1;
	while(b){
		if(b&1){
			answer=(answer*(x))%modulo;
		}
		x=(x*x)%modulo;
		b=(b>>1);
	}
	return answer;
}
// This Function prints the binary representation of any number
void bitrepresentation(ll n){
	if(n==0){
		cout<<0;
		return;
	}
	stack<int>s;
	while(n){
		s.push(n&1);
		n=(n>>1);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	debugMode();
	int testcases; cin >> testcases;
	while (testcases--) {
		
	}
}
