//백준 1697번
//숨바꼭질 문제
#include <iostream>
#include <queue>

using namespace std;

long long time[100001]; //위치 별 도달하는 시간 저장
void bfs(int subin, int n);

int main(){
	int subin, n;
	cin >> subin >> n;

	bfs(subin, n);

	cout<< time[n];

	return 0;
}

void bfs(int subin, int n){
	queue<int> que;
	que.push(subin); //수빈 위치 푸시

	while(!que.empty()){
		int next = que.front();
		que.pop();

		if(next == n){ //동생을 찾으면 종료
			return;
		}

		if(next-1 >= 0 && time[next-1] == 0){ //방문가능하며, 최초방문일때
			que.push(next-1);
			time[next-1] = time[next] + 1;
		}
		if(next+1 <= 100000 && time[next+1] == 0){
			que.push(next+1);
			time[next+1] = time[next] + 1;
		}
		if(next*2 <= 100000 && time[next*2] == 0){
			que.push(next*2);
			time[next*2] = time[next] + 1;
		}
	}

}

