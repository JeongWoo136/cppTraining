/*
cpp의 입출력 클래스
cpp의 모든 입출력 클래스는 ios_base를 기반클래스로 하게됨
ios_base 클래스는 스트림의 입출력 형식 관련 데이터를 처리함.
실수형 출력시 정밀도, 10진수, 16진수 등

ios클래스는 스트림 버퍼를 초기화
버퍼: 한번에 전송하는 것
현재 입출력 작업의 상태도 처리함
eof함수를 호출하면 파일의 끝에 도달했는지 알 수 있고 good함수를 호출하면 good함수를 호출하면 됨.

istream 클래스
실제로 입력을 수행하는 클래스
opertator>>는 istream에 정의된 연산자.
cin은 istream클래스의 객체이다.

operator >> 는 모든 공백문자를 입력시에 무시한다.
즉 한단어만 입력된다.
ios클래스에서는 스트림의 상태를 관리함
4개의 플래그가 존재
goodbit: 스트림에 입출력 작업이 가능할 때
badbit: 스트림에 복구불가능한 오류 발생시
failbit:스트림에 복구가능한 오류 발생시
eofbit: 입력작업시에 eof도달 시

타입에 맞지않는 값을 넣은경우 failbit가 켜진다.
failbit가 켜지면 입력값을 받지않고 리턴한다.
이 경우 버퍼에 남아있는 "c\n" 에 손대지않기때문에 계속해서 읽어 루프에 빠진다.


*/

// #include <iostream>
// using namespace std;
// int main()
// {
//     int t;
//     while (true)
//     {
//         std::cin.setf(std::ios_base::hex,std::ios_base::basefield); //입력받는 형식을 16진수로 바꿈.
//         //setf 인자를 두개받는 경우 두번째인자(basefield)를 초기화하고 첫번째인자를 적용시키는 것이다.
//         //basefield는 몇진법으로 수를 처리할지 보관한다.
//         //std::endl은 개행문자출력 +flush (버퍼 비우기)
//         std::cin >> t;
//         std::cout << "입력:: "<< t << std::endl;
//         if(std::cin.fail()){
//             std::cout <<"제대로 입력해주세요"<<std::endl;

//             std::cin.clear(); //플래그 초기화
//             std::cin.ignore();
//             //std::cin.ignore(100,'\n'); //최대 100자 개행문자가 나올 때까지 무시

//         }
//         if(t == 1)break;
//     }
// }


/*
스트림 버퍼
streambuf 클래스
입력버퍼 = get area
출력버퍼 = put area
각 버퍼는 스트림의 상태를 나타내는 3개의 포인터를 갖는다 (시작, 다음 읽을 문자(스트림위치지정자), 끝)
get area :: eback(),gptr(),egptr()
put area :: pbase(),pptr(),epptr()
*/
#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    // 위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다 (이 때는 움직이지 않음) //움직이지 않는다는 것의 의미를 모르겠다.
    char peek = std::cin.rdbuf()->snextc(); //cin 은 istream 객체이므로 get area만 갖고있다.
    char peek2 = std::cin.rdbuf()->snextc();
    char peek3 = std::cin.rdbuf()->snextc();
    //snextc()는 스트림위치지정자를 한칸 움직이고 그 위치에 해당하는 문자를 리턴한다.한칸 움직이는데 건드리지 않는다는 의미를 모르겠음.
    if (std::cin.fail())
        std::cout << "Failed";
    std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
    std::cout << "두 번째 단어 맨 앞글자(2) : " << peek2 << std::endl;
    std::cout << "두 번째 단어 맨 앞글자(3) : " << peek3 << std::endl;
    std::cin >> s;
    std::cout << "다시 읽으면 : " << s << std::endl;
}