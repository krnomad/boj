#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 20003
#define MAX_WEIGHT 10002

#define X first
#define Y second

vector<pair<int, int>> adj[MAX_N]; // adj[u] = {w, v}
int d[MAX_N];
const int INF = 0x3f3f3f3f;

int main() {
	// 정점의 개수 V와 간선의 개수 E
	ios::sync_with_stdio(0); cin.tie(0);
	int V, E; cin >> V >> E;
	int start_K; cin >> start_K;

	while( E-- ) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	fill(d, d + MAX_N, INF);
	d[start_K] = 0;

	pq.push({ d[start_K], start_K });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue; // pq에 이후 계산으로 인해 새로운 값이 업데이트 됐을 경우 회피
		for (auto nxt : adj[cur.Y]) {
			int new_weight = d[cur.Y] + nxt.X;
			if (d[nxt.Y] <= new_weight) continue;
			d[nxt.Y] = new_weight;
			pq.push({ new_weight, nxt.Y });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
			continue;
		}
		cout << d[i] << "\n";
	}

	return 0;
}