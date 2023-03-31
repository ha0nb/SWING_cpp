#include<iostream>
using namespace std;

int main() {
	int num, row, column, n_row, n_column;//차례대로 메뉴번호, 열, 번호, 변경열, 변경번호이다.
	const int ROW = 10, COLUMN = 6;//좌석 열과번호를 기호상수로 고정시켰다.
	int seat[ROW][COLUMN] = { 0 }; //좌석의 배열을 0으로 초기화시켰다. 2차원배열로 선언.

	do {//do while을 써서 3번 종료를 누르지않는이상 계속 예약 시스템이 켜지도록 설정했다.
		cout << "\n** 비행기 좌석 예약 시스템 **" << endl << endl;
		cout << "1. 신규 예약\n2. 예약 변경\n3. 프로그램 종료" << endl << endl;
		cout << "번호를 입력하세요 : ";
		cin >> num;

		/*1*/if (num == 1) {
			cout << endl;
			cout << "<잔여 좌석은 0으로 표시됩니다>" << endl << endl;
			cout << "1 2 3\t4 5 6" << endl;
			cout << "-------------" << endl;
			/*좌석표*/for (int i = 0; i < ROW; i++) {//i는 열
				for (int j = 0; j < COLUMN; j++) {//j는 번호
					if (j == 3) {
						cout << "\t"; //4번 좌석 출력전에 통로 출력
					}//if
					if (seat[i][j] == 0 && j == 5) {
						cout << "0\n"; //하나의 열이 끝나면 줄바꿈-빈좌석
					}//if
					if (seat[i][j] != 0 && j == 5) {
						cout << "1\n"; //하나의 열이 끝나면 줄바꿈-예매된 자석
					}//if
					if (seat[i][j] == 0 && j != 5) {
						cout << "0 "; //마지막 번호가 아닌 일반적인 경우 "0 "출력
					}//if
					if (seat[i][j] != 0 && j != 5) {
						cout << "1 "; //마지막 번호 아닌 + 예매좌석인 경우 "1 "출력
					}//if
				}//두번째 for
			}//좌석 모양 출력 끝나는 부분
			cout << endl  << "몇열, 몇번째 좌석을 예약하시겠습니까?";
			cin >> row >> column;
			/*입력받은 열과 번호에 대한 답변*/
			if (row < 1 || row > ROW || column < 1 || column > COLUMN) {
				cout << "잘못된 좌석 번호입니다." << endl;
			}//1
			else if (seat[row - 1][column - 1] != 0) {
				cout << "이미 예약된 좌석입니다." << endl;
			}//2
			else {
				seat[row - 1][column - 1] = 1;
				cout << "좌석 예약이 완료되었습니다." << endl;
			}//3
		}//no.1

		/*2*/if (num == 2) {
			cout << endl;
			cout << "<잔여 좌석은 0으로 표시됩니다>" << endl << endl;
			cout << "1 2 3\t4 5 6" << endl;
			cout << "-------------" << endl;
			/*좌석표*/for (int i = 0; i < ROW; i++) {//i는 열
				for (int j = 0; j < COLUMN; j++) {//j는 번호
					if (j == 3) {
						cout << "\t"; //4번 좌석 출력전에 통로 출력
					}//if
					if (seat[i][j] == 0 && j == 5) {
						cout << "0\n"; //하나의 열이 끝나면 줄바꿈-빈좌석
					}//if
					if (seat[i][j] != 0 && j == 5) {
						cout << "1\n"; //하나의 열이 끝나면 줄바꿈-예매된 자석
					}//if
					if (seat[i][j] == 0 && j != 5) {
						cout << "0 "; //마지막 번호가 아닌 일반적인 경우 "0 "출력
					}//if
					if (seat[i][j] != 0 && j != 5) {
						cout << "1 "; //마지막 번호 아닌 + 예매좌석인 경우 "1 "출력
					}//if
				}//두번째 for
			}//좌석 모양 출력 끝나는 부분
			cout << endl << "현재 좌석과 변경하고자하는 좌석을 입력해주세요" << endl << "( [현재 열,번호] --> [변경할 열,번호] 순서로 작성 )" << endl;
			cin >> row >> column >> n_row >> n_column; //4개의 숫자를 입력받아서 각각의 변수에 넣는다.
			if (1 <= row && row <= ROW && 1 <= n_row && n_row <= ROW && 1 <= column && column <= COLUMN && 1 <= n_column && n_column <= COLUMN){
				//이건 마지막 else를 하고싶어서 선제조건으로 넣었는데 작동이 잘안된다ㅠ
				if (seat[row - 1][column - 1] == 1) {//인데스 번호를 입력받은 값에서 -1하는것을 꼭 기억하자!!
					if (seat[n_row - 1][n_column - 1] == 0) {
						seat[row - 1][column - 1] = 0;
						seat[n_row - 1][n_column - 1] = 1;//예약변경이 완료되었으면 좌석표를 업데이트하는것도 잊지말자!
						cout << "좌석 예약이 완료되었습니다." << endl;
					}//if변경할 좌석이 공석이다 -->예약
					else {
						cout << "이미 예약된 좌석입니다." << endl;
					}//else -->이미 예약된 좌석입니다
				}//if 현재 좌석이 존재한다
				else {
					cout << "현재 좌석이 예약되어있지 않습니다." << endl;
				}// else 현재 좌석이 예약된 좌석이 아니다 -->좌석을 정확히 입력해라
			}//if 번호와 열이 [10][6] 안이다
			else {
				cout << "잘못된 좌석 번호입니다." << endl;
			}//else 좌석을 정확히 입력해라

		}//no.2
		
		/*3*/if (num == 3) {/*break*/
		}//no.3
		
		/*4*/if (num<1 || num >3) {
			cout << endl << "※※올바른 번호를 입력해주세요※※";
		}//no.4

	}//do
	while (num != 3);//프로그램 종료를 입력하지않는이상 계속 돌아가게 

}//메인함수
