#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[100001]; 
bool visited[100001];
void imp() {
	cout<<"mhap dinh ";
	cin>>n;
	cout<<"nhap canh ";
	cin>>m;

	for (int i=0; i<m; i++) {
		int x,y; cin>>x>>y;
		adj[x].push_back(y); // co huong  x->y 
		adj[y].push_back(x); // vo huong  y->x 
	}
	memset(visited,false,sizeof(visited)); // cho tat ca la false
}
void DFS (int u, int late, bool& check) {

	cout<<u<<" ";
	//danh dau la dinh  u da duoc tham 
	visited[u]=true; // va danh dau duoc tham la true
	if (u==late) {
		check=true; // neu u ma bang dinh cuoi thi cho check bang true
		return; 
	}
	for (int x:adj[u]) {
		// neu cac dinh chua duoc tham 
		if (check) return; // kiem tra co bang true ko ?? neu bang thi return 
		if (!visited[x]) {
			DFS(x,late,check);
		}
	}
}
int main () {
	imp();
	bool check=false; // de check =false de cho DFS chay 
	cout<<"Duong di cua DFS :"<<endl;
	DFS(1,9,check); // chay tu dinh 1 va dinh ket thuc la 9
	if (!check) cout<<"khong tim thay dinh \n";
	return 0; 
}
/* danh sach ke 
dinh = 9, canh = 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
3 8
8 9

ket qua 
*/

