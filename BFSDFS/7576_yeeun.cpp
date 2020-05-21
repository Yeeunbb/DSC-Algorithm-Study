//백준 7576번
//토마토 문제
#include <iostream>
#include <queue>

using namespace std;

int day[1000][1000]; //익어가는 날짜 수 저장
int box[1001][1001]; //토마토 박스
int result; //모두 익는데 걸린 날짜 수
int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
queue<pair<int,int>> que;
void bfs(int M, int N);

int main() {
	int M, N, tomatN=0, count=0;
	cin >> M >> N;

	for(int i=0; i<N; i++){ //박스에 토마토 상황을 저장함.
		for(int j=0; j<M; j++){ //1은 익토, 0은 익않토, -1은 없토
			cin >> box[i][j];
			if(box[i][j] == 0 || box[i][j] == 1) tomatN++; //익었든, 안익었든 토마토 총 갯수 카운트
			if(box[i][j]==1) que.push(make_pair(i, j)); //익은 토마토 위치를 미리 큐에 저장
		}
	}

	bfs(M, N); //탐색

	for(int i=0; i<N; i++){ //토마토가 모두 익었는지 확인
		for(int j=0; j<M; j++){
			if(box[i][j] == 1) count++;
		}
	}

	if(count == tomatN){ //모두 익은 경우
		cout << result;
	}
	else{
		cout << "-1";
	}

	return 0;
}

void bfs(int M, int N){

	while(!que.empty()){
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for(int i=0; i<4; i++){
			int next_x = x + dir[i][1];
			int next_y = y + dir[i][0];

			if(next_x >= 0 && next_x < M && next_y >= 0 && next_y < N){ //상자 범위 안일 때
				if(box[next_y][next_x] == 0){ //아직 익지 않은 토마토 일때,
					que.push(make_pair(next_y,next_x)); //큐에 저장
					box[next_y][next_x] = 1; //익었다고 표시
					day[next_y][next_x] = day[y][x] + 1; //다음 토마토가 익은 날짜는, 지금 토마토가 익은 날 + 1
					result = day[next_y][next_x]; //마지막 토마토가 익은 날이 모든 토마토가 익은 최소 날짜
				}
			}
		}
	}
}
