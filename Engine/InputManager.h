#pragma once

class InputManager
{
public:
	bool IsKeyDown(int VKCode) { return GetAsyncKeyState(VKCode) & 0x8000; }
};

// 객체 만들기
// 값을 잃어버려도 됨
// 변수 복사 
// 정적 할당

// 포인터 변수
// 오브젝트의 정보 -> 스코프 나왔을 때 정보 사라짐 안돼애애ㅐㅇ
// 값을 잃어버리면 안돼
// 동적할당 -> ㅇㅇ ㅇㅇ ㅇㅇ ㅇㅇ ㅇㅇ ㅇㅇ 내가 해제해줄 때까지 값이 남아있음
// 값이 담겨있는 위치를 가리킴