#include "Class.h"
#include "Statement.h"


int main()
{
	while (1)
	{
		cout << "--------------------Welcome--------------------" << endl;
		int key = User();
		Login(key);
		cout << "\n----------------------Bye----------------------" << endl;
		char S;
		cout << "�Ƿ��˳��ܿα�Y OR N��:";
		cin >> S;
		if (S=='Y') { break; }
	}
	
	return 0;
}


//������룬��Ӧ���
int User()
{
	int key;
	char def;
	char username[10];
	string password;

	while(1)
	{
		cout << "�����������ǽ�ʦ��T������ѧ����S��";
		cin >> def;
		cout << "�û�����";
		cin >> username;
		cout << "����:";
		password = InputPassWord();

		key = CheckUserMessage(username, password, def);

		if (key == 0)
		{
			MessageBox(NULL, TEXT("�û���Ϣ�������������룡����"), TEXT("����"), MB_OK);
			cout << "\n";
		}
		else break;
    }
	return key;
}



//�������
void Login(int key)
{
	if ((key/100) == 1)
	{
		CStudent student;
		student.Logini(key);
	}
	else
	{
		CTeacher teacher;
		teacher.Logini(key);
	}
}

