//백준 10451번
//순열 사이클 문제
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> number; //순열을 저장할 벡터
int visited[1001];
void dfs(int i);
int count; //사이클의 갯수를 저장할 변수

int main(){
	int tc, size, num;

	cin >> tc; //테스트케이스 입력받음

	for(int i=0; i<tc; i++){
		cin >> size;
		number.resize(size+1); //벡터크기 재조정

		for(int j=1; j<=size; j++){
			cin >> num;
			number[j].push_back(num); //인덱스에 해당하는 번호 저장
		}

		for(int k=1; k<=size; k++){
			if(visited[k] == 0){ //방문하지 않은 경우
				dfs(k); //dfs탐색
			}
		}
		cout << count << endl;
		//여기서부턴 변수 초기화
		count = 0;
		number.clear();
		for(int l=1; l<=size; l++){
			visited[l] = 0;
		}
	}



	return 0;
}

void dfs(int i){
	visited[i] = 1;

	if(visited[number[i][0]] == 0){
		dfs(number[i][0]);
	}
	else{ //이미 방문한 곳이라면 사이클이 형성된것.
		count++;
	}
}
