/*
    모독
    https://www.acmicpc.net/problem/16221
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class segment_tree
{
    vector<T> m_data;
    function<T(const T&, const T&)> m_join;
public:
    segment_tree(size_t n, T default_value, function<T(const T&, const T&)> join)
        :m_join(join)
    {
        size_t i = 1;
        while (i < n) i <<= 1;

        m_data.resize(i << 1, default_value);
    }

    void update(size_t node_i, T value)
    {
        m_data[node_i] = value;
        while (node_i >>= 1)
            m_data[node_i] = m_join(m_data[node_i << 1], m_data[node_i << 1 | 1]);
    }

    size_t leafSize()
    {
        return m_data.size() >> 1;
    }

    size_t nodeSize()
    {
        return m_data.size();
    }

    T getLeaf(size_t leaf_i)
    {
        return getNode(leafSize() + leaf_i);
    }

    T getNode(size_t node_i)
    {
        return m_data[node_i];
    }
};

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t Q;
	cin >> Q;

	segment_tree<size_t> seg(1'000'000, 0, [](size_t a, size_t b)->size_t{
		if(a && b)
			return a + b;
		else
			return 0;
	});

	while(Q--){
		size_t T, K;
		cin >> T >> K;
		--K;

		seg.update(seg.leafSize() + K, seg.getLeaf(K) + 3 - 2 * T);

		size_t i = 1;
		size_t sum = 0;
		while(i < seg.leafSize()){
			i <<= 1;
			if(seg.getNode(i)){
				sum += seg.getNode(i);
				i |= 1;
			}
		}

		cout << sum+seg.getNode(i) << "\n";
	}
}