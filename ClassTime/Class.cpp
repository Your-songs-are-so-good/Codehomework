#include "Class.h"
#include "Statement.h"

//���Էְ༶�鿴
void CClass::ViewTimetable(int key)
{
	vector<CCourse> Allcour;

	if ((key / 100) == 1)
	{
		int m;
		vector<CStudent> Allstu = ReadStuFromFile();
		for (int i = 0; i < Allstu.size(); i++)
		{
			if (key == Allstu[i].stukey)
			{
				m = Allstu[i].stuclassid / 10;
				break;
			}
		}
		 Allcour = ReadCourseFromFile(m);
		 MakeTimeTable(Allcour, m);
	}
	else 
	{
		int m,n;
		vector<CTeacher> AllTea = ReadTeaFromFile();
		for (int i = 0; i < AllTea.size(); i++)
		{
			if (key == AllTea[i].teakey)
			{
				m = i;
				break;
			}
		}
		for (int i = 0; i < AllTea[m].teaclassnum; i++)
		{
			n = AllTea[m].teaclassid[i] / 10;
			Allcour = ReadCourseFromFile(n);
			MakeTimeTable(Allcour, n);
		}
		
	}
	
	
}

//�����ܿα�
void MakeTimeTable(vector<CCourse> Allcour,int key)
{
	string ClassSchedule[4][5];

	for (int i = 0; i < Allcour.size(); i++)
	{
		for (int j = 0; j < Allcour[i].coursenum; j++)
		{

			int a = ((Allcour[i].coursetime[j]) % 10 - 1);
			int b = ((Allcour[i].coursetime[j]) / 10 - 1);
			ClassSchedule[a][b] = Allcour[i].subject;
		}
	}
	cout << setw(25) << key << "��" << endl;
	cout << "      "<< "Mo" <<"    |    "<< "Tu" << "    |    "<< "We" <<"    |    "<< "Th" <<"    |    "<< "Fr" << endl;
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 5; n++)
		{
			int i = 10 - ClassSchedule[m][n].size();
			for (int j = 0; j < i; j++)
			{
				ClassSchedule[m][n] += " ";
			}
		}
		cout << (m + 1) << "|" << ClassSchedule[m][0] << "|" << ClassSchedule[m][1] << "|" << ClassSchedule[m][2] << "|" << ClassSchedule[m][3] << "|" << ClassSchedule[m][4] << endl;
	}
}


int CStudent::Logini(int key)
{
	int i;
	cout << "\n-----------------Welcome to the student interface-----------------" << endl;
	Getmessage(key);
	while (1)
	{
		cout << "���ܣ���1���鿴�ܿα� ��2���˳�" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			ViewTimetable(key);
			break;
		case 2:
			return 0;
		}
	}
	

}


void CStudent::Getmessage(int key)
{
	int m;
	vector<CTeacher> AllTea = ReadTeaFromFile();
	vector<CStudent> Allstu = ReadStuFromFile();

	for (int i = 0; i < Allstu.size(); i++)
	{
		if (key == Allstu[i].stukey)
		{
			m = i;
			break;
		}
	}

	int a = Allstu[m].stuclassid / 10;

	for (int i = 0; i < AllTea.size(); i++)
	{
		for (int j = 0; j < AllTea[i].teaclassnum; j++)
		{
			int b = AllTea[i].teaclassid[j] / 10;
			if ( a == b )
			{
				if (AllTea[i].teaclassid[j] != Allstu[m].stuclassid)//������
				{
					MessageBox(NULL, TEXT("��ʦ�����˿α�ʱ�䣡����"), TEXT("֪ͨ"), MB_OK);
					/*MessageFromWho(AllTea[i].teakey);*/
					//�޸�ʹ��Ϣ������һ��
					Allstu[m].stuclassid = AllTea[i].teaclassid[j];
					WriteStutoFile(Allstu);
				}
			}
		}
	}
}

int CTeacher::Logini(int key)
{
	int i;
	cout << "\n-----------------Welcome to the teacher interface-----------------" << endl;
	while (1)
	{
		int m;
		vector<CTeacher> AllTea = ReadTeaFromFile();
		for (int i = 0; i < AllTea.size(); i++)
		{
			if (key == AllTea[i].teakey)
			{
				m = i;
				break;
			}
		}
		cout << "ѧ��:" << AllTea[m].teasubj << "  " << AllTea[m].GetName() << endl;
		cout << "���ܣ���1���鿴�ܿα� ��2���޸��ܿα� ��3���˳�" << endl;
		cin >> i;
		switch (i)
		{
		case 1:
			ViewTimetable(key);
			break;
		case 2:
			Modifyclass(AllTea[m]);
			break;
		case 3:
			return 0;
		}
	}

}
void CTeacher::Modifyclass(CTeacher teacher)
{
	int i;
	cout << "�γ��޸ģ���1������ ��2��ɾ�� ��3���滻" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		Addition(teacher);
		break;
	case 2:
		Deletion(teacher);
		break;
	case 3:
		Replace(teacher);
		break;
	}
}

