//백준 2644번
//촌수계산 문제
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> family; //관계를 저장하는 벡터
int visited[100]; //dfs방문 여부를 나타내는 배열
int count; //몇 촌인지 세는 count
bool meet; //확인해야하는 사람이 등장하면, dfs종료
int person1, person2; //친척관계를 알아볼 두사람
void dfs(int i);

int main(){
	int n, p1, p2, m, x, y;

	cin >> n; //사람 수
	cin >> p1 >> p2; //촌수를 계산해야 하는 사람 번호
	person1 = p1;
	person2 = p2;
	cin >> m; //부모 자식간의 관계 case 갯수

	family.resize(n+1); //사람수만큼 벡터크기 조정. 인덱스는 0번부터라서 +1

	for(int i=0; i<m; i++){ //부모 자식 관계 입력 받음
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);
	}

	dfs(person1);

	if(meet){ //친척 관계가 있다면
		cout << count;
	}
	else{ //없다면 -1 출력
		cout <<"-1";
	}
	return 0;
}

void dfs(int i){
	visited[i] = 1;

	if(i == person2){ //친척관계가 맞다면
		meet = true;
		return;
	}

	for(int j=0; j<family[i].size(); j++){
		if(visited[family[i][j]] == 0){
			count++;
			dfs(family[i][j]);
			if(meet) return;
			count--; //친척관계가 아니므로 count 감소
		}
	}
}
//count변수를 전역변수가 아닌, 지역변수로 해서
//dfs를 count를 넘겨주는 방식으로 구현해도 된다.
