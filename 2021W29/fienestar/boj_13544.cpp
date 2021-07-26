/*
    수열과 쿼리 3
    https://www.acmicpc.net/problem/13544
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
            if(begin & 1) query(begin++);
            if(end & 1) query(--end);
            begin >>= 1; end >>= 1;
        }
    }
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<vector<int>> A(N);
	for(auto& a:A){
		a.resize(1);
		cin >> a[0];
	}

	segment_tree<vector<int>> seg(A.begin(), A.end(), {}, [](auto& a, auto& b){
		vector<int> result(a.size() + b.size());
		merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());

		return result;
	});

	size_t M;
	cin >> M;

	size_t last_ans = 0;
	while(M--){
		size_t a, b, c;
		cin >> a >> b >> c;

		a ^= last_ans;
		b ^= last_ans;
		c ^= last_ans;

		size_t count = 0;
		seg.range_query(a-1, b, [&](size_t idx){
			auto& v = seg.nodeAt(idx);
			count += v.end() - upper_bound(v.begin(), v.end(), c);
		});

		cout << count << "\n";
		last_ans = count;
	}
}