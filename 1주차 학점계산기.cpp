#include <iostream>
using namespace std;

int main() { 
    //이름과 학번을 입력받아서 저장할 변수를 지정
    char name[8]; 
    int innum; 

    //과목별 학점을 입력받아서 저장하는 변수 지정
    float cpro; 
    float comjung; 
    float silmu;
    float gogeup;

    //이름을 공백과 함께 입력받아서 name에 저장
    cout << "이름: ";
    cin.getline(name, 8, '\n');

    //학번을 입력받아서 innum에 저장
    cout << "학번: ";
    cin >> innum;

    //학점 입력 안내문 출력
    cout << "반갑습니다. " << name << "님\n\n";
    cout << "학점 입력을 시작합니다.\n\n";

    cout << "=============== SWING 31 ===============\n";

    //과목별 학점을 입력받음
    cout << "C프로그래밍(3학점) : ";
    cin >> cpro;

    cout << "컴퓨터및정보보호개론(3학점) : ";
    cin >> comjung;

    cout << "소프트웨어개발실무영어Ⅰ(1학점) : ";
    cin >> silmu;

    cout << "대학고급영어(2학점) : ";
    cin >> gogeup;

    //전체 학점을 구하는 변수를 지정하고, 연산식을 세움
    float total = (cpro * 3 + comjung * 3 + silmu + gogeup * 2) / 9;

    //전체 학점을 이름,학번과 함께 출력
    cout << "========================================\n\n";
    cout << name << "(" << innum << ")님의 전체 학점은 " << total << "입니다.";

    return 0;
}
