/*
    XOR
    https://www.acmicpc.net/problem/14245
*/
#include <bits/stdc++.h>

using namespace std;

template <class T, class V>
class lazy_segment_tree
{
	vector<pair<T, V>> m_tree;
	function<T(const T&, const T&)> m_join;
	function<T(const T&, const V&)> m_apply;
	function<void(V&, const V&)> m_merge;
	V m_identity;
public:
	template <class It>
	lazy_segment_tree(
		It begin,
		It end,
		const T& default_value,
		function<T(const T&, const T&)> join,
		const V& identity,
		function<T(const T&, const V&)> apply,
		function<void(V&, const V&)> merge)
		: m_join(join), m_apply(apply), m_merge(merge), m_identity(identity){
		size_t init_value_count = distance(begin, end);
		size_t node_count = 1;
		while(node_count < init_value_count)node_count <<= 1;

        	m_tree.resize(node_count << 1, {default_value, m_identity});

		for(size_t i = node_count; begin != end; ++i)
			m_tree[i].first = *begin++;
        
		for(size_t i = node_count; i--;)
			m_tree[i].first = m_join(m_tree[i << 1].first, m_tree[i << 1 | 1].first);
			
	}

	size_t leafSize() { return m_tree.size() >> 1; }
	size_t nodeSize() { return m_tree.size(); }
	const T& rawLeafAt(size_t idx) { return m_tree[idx].first; }

	void apply(size_t idx)
	{
		if(idx < leafSize()){
			m_merge(m_tree[idx<<1].second, m_tree[idx].second);
			m_merge(m_tree[idx<<1|1].second, m_tree[idx].second);
		}
		m_tree[idx].first = m_apply(m_tree[idx].first, m_tree[idx].second);
		m_tree[idx].second = m_identity;
	}

	class iterator
	{
		size_t m_idx;
		lazy_segment_tree& m_seg;
	public:
		iterator(size_t idx, lazy_segment_tree& seg): m_idx(idx), m_seg(seg)
		{
			m_seg.apply(m_idx);
		}
		iterator parent() { return iterator(m_idx>>1, m_seg); }
		iterator left() { return iterator(m_idx<<1, m_seg); }
		iterator right() { return iterator(m_idx<<1|1, m_seg); }
		const T& operator*() { return m_seg.rawLeafAt(m_idx); }
		bool isLeaf() { return m_idx >= m_seg.leafSize(); }
		bool isRoot() { return m_idx == 1; }
		bool isValid() { return m_idx >= 1 && m_idx < m_seg.nodeSize(); }
	};

	iterator root() { return iterator(1, *this); }

	void recursive_apply(size_t idx)
	{
		if(idx != 1)
			recursive_apply(idx >> 1);
		apply(idx);
	}

	const T& nodeAt(size_t idx)
	{
		recursive_apply(idx);
		return m_tree[idx].first;
	}
	const T& leafAt(size_t leaf_idx) { return nodeAt(leafSize() + leaf_idx); }

	void update(size_t leaf_idx, const T& new_value)
	{
		size_t idx = leafSize() + leaf_idx;
		recursive_apply(idx);	
		m_tree[idx] = new_value;

		while(idx != 1){
			idx >>= 1;
			m_tree[idx] = m_join(m_tree[idx<<1], m_tree[idx<<1|1]);
		}
	}

	void update(size_t leaf_begin, size_t leaf_end, const V& v)
	{
		size_t begin = leafSize() + leaf_begin;
		size_t end = leafSize() + leaf_end;

		while(begin < end){
			if(begin & 1)m_merge(m_tree[begin++].second, v);
			if(end & 1)m_merge(m_tree[--end].second, v);

			begin >>= 1; end >>= 1;
		}
	}
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	using ll = long long;
	vector<ll> v(N);
	for(auto& c:v)
		cin >> c;

	lazy_segment_tree<ll, ll> seg(
		v.begin(),
		v.end(),
		0,
		[](ll a, ll b) { return a^b; },
		0,
		[](ll a, ll b) { return a^b; },
		[](ll& a, ll b) { a^=b; }
	);

	size_t M;
	cin >> M;
	while(M--){
		size_t c;
		cin >> c;
		if(c == 2){
			size_t x;
			cin >> x;
			cout << seg.leafAt(x) << "\n";
		}else{
			size_t i, j;
			ll k;
			cin >> i >> j >> k;
			seg.update(i, j+1, k);
		}
	}
}