/*
    수열과 쿼리 1
    https://www.acmicpc.net/problem/13537
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
    vector<T> m_tree;
    function<T(const T&,const T&)> m_join;

public:
    template <class It>
    segment_tree(It begin, It end, const T& default_value, function<T(const T&,const T&)> join)
        :m_join(join)
    {
        size_t node_count = 1;
        size_t init_value_count = distance(begin, end);
        while(node_count < init_value_count)node_count <<= 1;
        m_tree.resize(node_count << 1, default_value);

        for(size_t i = node_count; begin != end; ++i)
            m_tree[i] = *begin++;
        
        for(size_t i = node_count; i--;)
            m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
    }

    size_t leafSize() { return m_tree.size() >> 1; }
    size_t nodeSize() { return m_tree.size(); }
    const T& leafAt(size_t idx) { return m_tree[(m_tree.size() >> 1) + idx]; }
    const T& nodeAt(size_t idx) { return m_tree[idx]; }
    size_t leaf2node(size_t i) { return i + (m_tree >> 1); }

    void update(size_t i, const T& new_value)
    {
        m_tree[i] = new_value;

        while(i >>= 1)
            m_tree[i] = m_join(m_tree[i << 1], m_tree[i << 1 | 1]);
    }

    template <class Function>
    void range_query(size_t begin, size_t end, Function query)
    {
        begin += leafSize();
        end += leafSize();

        while(begin < end){
            if(begin & 1) query(nodeAt(begin++));
            if(end & 1) query(nodeAt(--end));
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
	using vll = vector<ll>;
	vector<vll> v(N);
	for(auto& c:v){
		c.resize(1);
		cin >> c[0];
	}

	segment_tree<vll> seg(v.begin(), v.end(), vll{}, [](const vll& a, const vll& b){
		vll result(a.size() + b.size());
		size_t i=0;
		size_t j=0;
		for(auto& c:result)
			if(i != a.size() && (j == b.size() || a[i] < b[j]))
				c = a[i++];
			else
				c = b[j++];

		return result;
	});

	size_t M;
	cin >> M;
	while(M--){
		size_t i, j; ll k;
		cin >> i >> j >> k;

		size_t bigger_count = 0;
		seg.range_query(i-1, j, [&](const vll& v){
			bigger_count += v.end() - upper_bound(v.begin(), v.end(), k);
		});

		cout << bigger_count << "\n";
	}
}