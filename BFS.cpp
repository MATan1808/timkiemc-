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

void BFS (int u,int late) {
	cout<<"dinh bat dau  "<<u<<endl;
	cout<<"dinh ket thuc "<<late<<endl;
	// khoi tao 
	queue<int>q;
	// day vao hang doi 
	q.push(u);
	// danh dau da tham 
	visited[u]=true;
	cout<<"duong di cua BFS :"; 
	while (!q.empty() ) {
		int v=q.front(); // lay dinh cua hang doi 
		q.pop(); // xoa dinh vua lay cua hang doi 
		cout<<v<<" "; // in ra dinh da duoc tham 
		if (v==late) break; // kiem tra neu dinh duyet bang dinh cuoi thi cho dung 
		for (int x: adj[v]) {
			// ktra neu chua duoc tham 
			if (!visited[x]) {
				q.push(x);// day ham chua dc tham vao hang doi 
				visited[x]=true; // va danh dau da tham 
			}
		}
	}  
} 
int main () {
	int batdau, ketthuc;
	cout<<"nhap dinh bat dau ";
	cin>>batdau;
	cout<<"nhap dinh ket thuc ";
	cin>>ketthuc; 
	imp();
	cout<<"dinh bat dau la "<<batdau<<endl;
	cout<<"dinh ket thuc la "<<ketthuc<<endl;
	cout<<"Duong di cua BFS :"<<endl;
	BFS(batdau,ketthuc); // chay tu dinh 1 va ket thuc la 7
}
// danh sach ke cua do thi 
// dinh =10 canh =11
/*
1 2
1 3
1 4
1 10
2 4
3 6
3 7
3 9
6 7
5 8
8 9

ket qua 1 2 3 4 10 6 7
*/

