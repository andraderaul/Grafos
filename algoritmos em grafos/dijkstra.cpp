#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
#define INF 1000000000

int main(){
	
	int V,E, s,u,v,w;
	vector <vii> AdjList;
	
	freopen("dijkstra.txt","r",stdin);
	
	scanf("%d %d %d", &V,&E,&s);
	
	AdjList.assign(V,vii()); // preenche com vetores em branco
	for(int i = 0; i < E; i++){
		scanf("%d %d %d",&u,&v,&w);
		AdjList[u].push_back(ii(v,w)); //grafo direcionadoss
	}
	
	//Dijkstra
	vi dist(V,INF); //INF = 1B para evitar overflow
	dist[s] = 0;
	priority_queue < ii, vector<ii>, greater <ii> > pq;
	pq.push(ii(0,s));           // ^ para ordenar os pair incrementando s de distancia
	
	while(!pq.empty()){
		ii front = pq.top();
		int d = front.first, u = front.second;
		pq.pop(); //greedy: escolhe o vertice mais curto nao visitado
		if(d > dist[u]) continue; //essa checagem é importante
		for(int j = 0; j < (int)AdjList[u].size(); j++){
			ii v = AdjList[u][j]; //todas arestas saindo de u
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	} // obs: essa variante pode causar itens duplicados na priority queue

	for(int i = 0; i < V; i++){ // indice + 1 para resposta final
		printf("SSSP(%d,%d) = %d\n",s,i,dist[i]);	
	}

return 0;
}
