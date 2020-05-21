//2688번
//줄어들지 않아
#include <iostream>

using namespace std;

long long dp[65][10]; //dp[10의n승][0~9] 이 자릿수가 갖는 줄어들지 않는 수. int 로 했다가 계속 틀렷음
int tc[1000]; //test case 입력받는 배열
long long result[1000]; //n의 자릿수가 갖는 줄어들지 않는 수의 갯수

int main(){
	int n;
	cin >> n;

	for(int i=0; i<10; i++){ //초기값 설정
		dp[0][i] = 1;
	}
	result[1] = 10; //한자리수로 만들 수 있는 줄어들지 않는 수는 0~9이므로 10개

	for(int i=1; i<=64; i++){ //자릿수를 나타냄
		for(int j=9; j>=0; j--){ //해당 자리의 숫자를 나타냄
			if(j != 9){ //줄어들지 않는 수는 나보다 큰 숫자가 가지는 수를 누적으로 가짐.
				dp[i][j] = dp[i][j+1] + dp[i-1][j];
			}
			else{ //그 자릿수가 9인 경우 줄어들지 않는 수는 1개밖에 없다.
				dp[i][j] = 1;
			}
			result[i+1] += dp[i][j];
		}
	}

	for(int i=0; i<n; i++){ //test case 입력 받음.
		cin >> tc[i];
	}
	for(int i=0; i<n; i++){ //결과 출력
		cout << result[tc[i]] << endl;
	}

	return 0;
}

