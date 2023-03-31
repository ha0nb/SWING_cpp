//랜덤 함수 사용법 & 배수를 출력하는 조건식 & 반복문,조건문,제어문
#include<iostream> //#include<stdio.h> 
#include <cstdlib> //#include<stdlib.h>
#include <ctime> //#include<time.h>
using namespace std;

int main(void)

{
	int turn, mul;//입력받을 프로그램 실행 횟수는 turn, n의 배수에서 n은 mul이라는 변수 선언

	//srand(10);//srand=Seedrandom 랜덤함수를 나타내기 위한 기준값(,씨앗), 콩심으면 콩만나는것처럼 고정된값(ex.10)을 지정하면 랜덤이안됨
	//cout << rand(); //무작위 수를 표현할수없음. 계속41이나와
	//cout << time(NULL);//1970년 1월 1일 00:00부터 지금까지의 초, 고정된 값일 수가없음
	srand((unsigned int)time(NULL));//씨앗을 time 함수로 설정해서 무작위 수를 표현,타임함수는 음수일수없으므로 정수형을 unsigned으로 바꿈
	int ran = rand() % 101;//(+@);//무작위 수가 출력되긴한다만 그 수가 너무크므로 %연산자를 이용
	cout << "랜덤한 수 : " << ran; //표현하고 싶은 숫자(0~100)를 개수(101개)로 나누고 첫번째 수를 더하면됨.우리는 원하는 첫 숫자가 0이므로 따로 더해줄 필요는 없음.

	cout << endl << "특정 배수 개수 : ";
	cin >> turn;//실행 횟수를 사용자에게 입력받음.

	for (int h = 1; h <= turn; h++) {
		cout << endl << endl << h << "번째 특정 배수 : ";//1번째,2번째...몇번째인지 숫자를 출력하기위해 for 반복문이용, turn값과 같아질때까지 반복
		cin >> mul;//사용자에게 특정 배수를 입력받음.

		cout << endl << "<특정 배수만 출력하는 프로그램>" << endl;

		for (int i = 1; i <= ran; i++)//숫자 1부터 랜덤으로 출력된 0~100사이의 ran숫자까지 반복문이 적용됨
		{
			if (i % mul == 0)//조건 : 어떤 실수를 mul로 나누었을때 나누어떨어지면 = 어떤실수가 mul의 배수라는 뜻 = 나머지가 0
			{
				cout << i << ",";//조건을 만족하면 해당 실수를 출력
			}
		}
		cout << endl << endl << "<특정 배수 제외 출력하는 프로그램>" << endl;
		for (int i = 1; i <= ran; i++)
		{
			if (i % mul == 0)
				continue;//배수는 반복문 처음으로 돌아감 위에서 출력했으므로 따로 출력하지않음
			cout << i << ",";//배수가 아닌수들이 출력됨
		}
	}
}
