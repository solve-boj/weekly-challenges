/*
    가장 긴 증가하는 부분 수열 5
    https://www.acmicpc.net/problem/14003
*/

#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int A[1000001];
int temp[1000001];
pair<int, int> save[1000001];
stack<int> st;

int bsearch(int end, int target) {
    int l=-1, r=end;
    int mid;
    while(l+1 < r) {
        mid = (l + r) / 2;
        if(temp[mid] == target) {
            return mid;
        }
        if(temp[mid] < target) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    int cnt = 1, idx;
    temp[0] = A[0];
    save[0] = make_pair(0, A[0]);
    for(int i=1;i<N;i++) {
        if(temp[cnt-1] < A[i]) {
            temp[cnt] = A[i];
            ++cnt;

            save[i] = make_pair(cnt-1, A[i]);
        }
        else {
            idx = bsearch(cnt, A[i]);
            temp[idx] = A[i];
            /*      
            for(int j=0;j<cnt;j++) {
                printf("%d ", temp[j]);
            }
            printf("\n");
            */

            save[i] = make_pair(idx, A[i]);
        }
    }
    /*    
    for(int i=0;i<N;i++) {
        printf("%d %d\n", save[i].first, save[i].second);
    }
    */
    

    int t = cnt-1;
    for(int i = N-1;i>=0;i--) {
        if(t == save[i].first) {
            st.push(save[i].second);
            --t;
        }
    }

    printf("%d\n", cnt);
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
}

// keyword: 이분 탐색
// 시간복잡도: O(N log N)
/*
idea: 최대한 앞쪽 원소들을 작게 만들어야 수열을 길게 만들 수 있는 뒤쪽 수의 후보가 늘어남
따라서 새로운 원소를 기존에 만들어둔 수열과 비교
마지막 원소보다 그냥 추가
그렇지 않으면 적절한 위치에 끼워넣음
cnt가 증가할 때마다 그 때의 temp상황을 save에 저장
## stack에 save의 뒤족 원소부터 집어넣으면서 각 idx별로 가장 나중에 대입된 값을 선택
이걸 몰라서 5번이나 틀렸다....
*/