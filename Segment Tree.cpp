class segmentTree {
public:
	vector<ll>seg;
// For Minimum ------------------------------------------->
	segmentTree(ll n) {
		seg.resize(4 * n);
	}
	void build(ll idx, ll low, ll high, vector<ll>&cont) {
		if (low == high) {
			seg[idx] = cont[low];
			return;
		}
		ll mid = low + (high - low) / 2;
		build(2 * idx + 1, low, mid, cont);
		build(2 * idx + 2, mid + 1, high, cont);
		seg[idx] = min(seg[2 * idx + 1] , seg[2 * idx + 2]);
	}
	ll query(ll idx, ll low, ll high, ll l, ll r) {
		if (high < l || r < low)return LLONG_MAX;
		if (l <= low && r >= high)return seg[idx];
		ll mid = low + (high - low) / 2;
		ll left = query(2 * idx + 1, low, mid, l, r);
		ll right = query(2 * idx + 2, mid + 1, high, l, r);
		return min(left, right);
	}
	void update(ll idx, ll low, ll high, ll val, ll i) {
		if (low == high) {
			seg[idx] = val;
			return;
		}
		ll mid = low + (high - low) / 2;
		if (i <= mid)update(2 * idx + 1, low, mid, val, i);
		else update(2 * idx + 2, mid + 1, high, val, i);
		seg[idx] = min(seg[2 * idx + 1] , seg[2 * idx + 2]);
	}
};
// --------------------------------------------------------->
// For sum-------------------------------------------------->
class segmentTree {
public:
	vector<ll>seg;
	segmentTree(ll n) {
		seg.resize(4 * n);
	}
	void build(ll idx, ll low, ll high, vector<ll>&cont) {
		if (low == high) {
			seg[idx] = cont[low];
			return;
		}
		ll mid = low + (high - low) / 2;
		build(2 * idx + 1, low, mid, cont);
		build(2 * idx + 2, mid + 1, high, cont);
		seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
	}
	ll query(ll idx, ll low, ll high, ll l, ll r) {
		if (high < l || r < low)return 0;
		if (l <= low && r >= high)return seg[idx];
		ll mid = low + (high - low) / 2;
		ll left = query(2 * idx + 1, low, mid, l, r);
		ll right = query(2 * idx + 2, mid + 1, high, l, r);
		return left + right;
	}
	void update(ll idx, ll low, ll high, ll val, ll i) {
		if (low == high) {
			seg[idx] = val;
			return;
		}
		ll mid = low + (high - low) / 2;
		if (i <= mid)update(2 * idx + 1, low, mid, val, i);
		else update(2 * idx + 2, mid + 1, high, val, i);
		seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
	}
}
// ------------------------------------------------------------>
