#pragma once

class InputManager
{
public:
	bool IsKeyDown(int VKCode) { return GetAsyncKeyState(VKCode) & 0x8000; }
};

// ��ü �����
// ���� �Ҿ������ ��
// ���� ���� 
// ���� �Ҵ�

// ������ ����
// ������Ʈ�� ���� -> ������ ������ �� ���� ����� �ȵž־֤���
// ���� �Ҿ������ �ȵ�
// �����Ҵ� -> ���� ���� ���� ���� ���� ���� ���� �������� ������ ���� ��������
// ���� ����ִ� ��ġ�� ����Ŵ