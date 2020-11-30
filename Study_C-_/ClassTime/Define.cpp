#include "Class.h"
#include "Statement.h"

//��������
string InputPassWord()
{
	string PassWord;
	char c;
	while ((c = _getch()) != '\r')
	{
		cout << ' ';
		PassWord += c;
	}
	return PassWord;
}

//�˶���Ϣ
int CheckUserMessage(char* username, string password, char def)
{
	int key = 0;
	if (def == 'T')
	{
		vector<CTeacher> AllTea = ReadTeaFromFile();

		const char* p = password.c_str();
		int i = 0;

		for (AllTea[i]; i < AllTea.size(); i++)
		{
			if ((strcmp(username, AllTea[i].GetName()) == 0) && (strcmp((char*)p, AllTea[i].GetPass()) == 0))
			{
				key = AllTea[i].teakey;
				return key;
			}
		}

	}
	else if (def == 'S')
	{
		vector<CStudent> Allstu = ReadStuFromFile();

		const char* p = password.c_str();
		int i = 0;

		for (Allstu[i]; i < Allstu.size(); i++)
		{
			if ((strcmp(username, Allstu[i].GetName()) == 0) && (strcmp((char*)p, Allstu[i].GetPass()) == 0))
			{
				key = Allstu[i].stukey;
				return key;
			}
		}

	}
	return key;
}

//��ȡ��ʦ��Ϣ
vector<CTeacher> ReadTeaFromFile()
{
	vector<CTeacher> AllTea;
	ifstream infileUse("./teacher.ini", ios::in);
	char tea_Name[20] = { 0 };
	char tea_Pass[20] = { 0 };
	char  tea_key[20] = { 0 };
	char tea_Subj[20] = { 0 };
	char  tea_ClassNum[20] = { 0 };
	char  tea_ClassID[20] = { 0 };

	char Name[11] = { 0 };
	char Pass[11] = { 0 };
	char Subj[11] = { 0 };
	int  key;
	int  ClassNum;
	int  ClassID[10] = { 0 };

	infileUse >> tea_Name >> tea_Pass >> tea_key >> tea_Subj >> tea_ClassNum >> tea_ClassID;
	while (!infileUse.eof())
	{
		CTeacher tea;
		infileUse >> Name;
		tea.SetName(Name);
		infileUse >> Pass;
		tea.SetPass(Pass);
		infileUse >> key;
		tea.teakey = key;
		infileUse >> Subj;
		strcpy_s(tea.teasubj, Subj);
		infileUse >> ClassNum;
		tea.teaclassnum = ClassNum;
		for (int i = 0; i < tea.teaclassnum; i++)
		{
			infileUse >> ClassID[i];
			tea.teaclassid[i] = ClassID[i];
		}
		if (infileUse.fail())
		{
			break;
		}
		AllTea.push_back(tea);
	}
	infileUse.close();
	return AllTea;
}

//��ȡѧ����Ϣ
vector<CStudent> ReadStuFromFile()
{
	vector<CStudent> Allstu;
	ifstream infileUse("./student.ini", ios::in);
	char stu_Name[20] = { 0 };
	char stu_Pass[20] = { 0 };
	char stu_ClassID[20] = { 0 };
	char  stu_key[20] = { 0 };

	char Name[11] = { 0 };
	char Pass[11] = { 0 };
	int  ClassID = 0;
	int  key;

	infileUse >> stu_Name >> stu_Pass >> stu_ClassID >> stu_key;
	while (!infileUse.eof())
	{
		CStudent stu;
		infileUse >> Name;
		stu.SetName(Name);
		infileUse >> Pass;
		stu.SetPass(Pass);
		infileUse >> ClassID;
		stu.stuclassid = ClassID;
		infileUse >> key;
		stu.stukey = key;
		if (infileUse.fail())
		{
			break;
		}
		Allstu.push_back(stu);
	}
	infileUse.close();
	return Allstu;
}

//�����༶��
vector<CCourse>  ReadCourseFromFile(int i)
{
	vector<CCourse> Allcour;
	
	if (i == 1)
	{
		ifstream infileUse("./course01.ini", ios::in);

		char cour_Subj[20] = { 0 };
		char cour_Num[20] = { 0 };
		char cour_Time[20] = { 0 };
		char cour_Tea[20] = { 0 };

		char Subj[11] = { 0 };
		int  Num;
		int  Time[10] = { 0 };
		char Tea[20] = { 0 };


		infileUse >> cour_Subj >> cour_Num >> cour_Time >> cour_Tea;
		while (!infileUse.eof())
		{
			int t = 0;
			CCourse course;
			infileUse >> Subj;
			strcpy_s(course.subject, Subj);
			infileUse >> Num;
			course.coursenum = Num;
			for (int i = 0; i < Num; i++)
			{
				infileUse >> Time[i];
				course.coursetime[i] = Time[i];
			}
			infileUse >> Tea;
			strcpy_s(course.courseteach, Tea);
			if (infileUse.fail())
			{
				break;
			}
			Allcour.push_back(course);
		}
		infileUse.close();
		return Allcour;
	}
	else if (i == 2)
	{
		ifstream infileUse("./course02.ini", ios::in);

		char cour_Subj[20] = { 0 };
		char cour_Num[20] = { 0 };
		char cour_Time[20] = { 0 };
		char cour_Tea[20] = { 0 };

		char Subj[11] = { 0 };
		int  Num;
		int  Time[10] = { 0 };
		char Tea[20] = { 0 };


		infileUse >> cour_Subj >> cour_Num >> cour_Time >> cour_Tea;
		while (!infileUse.eof())
		{
			int t = 0;
			CCourse course;
			infileUse >> Subj;
			strcpy_s(course.subject, Subj);
			infileUse >> Num;
			course.coursenum = Num;
			for (int i = 0; i < Num; i++)
			{
				infileUse >> Time[i];
				course.coursetime[i] = Time[i];
			}
			infileUse >> Tea;
			strcpy_s(course.courseteach, Tea);
			if (infileUse.fail())
			{
				break;
			}
			Allcour.push_back(course);
		}
		infileUse.close();
		return Allcour;
	}
	else if (i == 3)
	{
		ifstream infileUse("./course03.ini", ios::in);

		char cour_Subj[20] = { 0 };
		char cour_Num[20] = { 0 };
		char cour_Time[20] = { 0 };
		char cour_Tea[20] = { 0 };

		char Subj[11] = { 0 };
		int  Num;
		int  Time[10] = { 0 };
		char Tea[20] = { 0 };


		infileUse >> cour_Subj >> cour_Num >> cour_Time >> cour_Tea;
		while (!infileUse.eof())
		{
			int t = 0;
			CCourse course;
			infileUse >> Subj;
			strcpy_s(course.subject, Subj);
			infileUse >> Num;
			course.coursenum = Num;
			for (int i = 0; i < Num; i++)
			{
				infileUse >> Time[i];
				course.coursetime[i] = Time[i];
			}
			infileUse >> Tea;
			strcpy_s(course.courseteach, Tea);
			if (infileUse.fail())
			{
				break;
			}
			Allcour.push_back(course);
		}
		infileUse.close();
		return Allcour;
	}
	else if (i == 4)
	{
		ifstream infileUse("./course04.ini", ios::in);

		char cour_Subj[20] = { 0 };
		char cour_Num[20] = { 0 };
		char cour_Time[20] = { 0 };
		char cour_Tea[20] = { 0 };

		char Subj[11] = { 0 };
		int  Num;
		int  Time[10] = { 0 };
		char Tea[20] = { 0 };


		infileUse >> cour_Subj >> cour_Num >> cour_Time >> cour_Tea;
		while (!infileUse.eof())
		{
			int t = 0;
			CCourse course;
			infileUse >> Subj;
			strcpy_s(course.subject, Subj);
			infileUse >> Num;
			course.coursenum = Num;
			for (int i = 0; i < Num; i++)
			{
				infileUse >> Time[i];
				course.coursetime[i] = Time[i];
			}
			infileUse >> Tea;
			strcpy_s(course.courseteach, Tea);
			if (infileUse.fail())
			{
				break;
			}
			Allcour.push_back(course);
		}
		infileUse.close();
		return Allcour;
	}
	else
	{
		;
	}
}

//д��ѧ����Ϣ
void WriteStutoFile(vector<CStudent> Allstu)
{
	std::ofstream SaveStu("./student.ini", ios::out);
	vector<CStudent>::iterator ite;

	int count = 0;  //����

	SaveStu << setiosflags(ios::left) << setw(10) << "����" << setw(10) << "����" << setw(10) << "���ڰ༶" << setw(10) << "Կ��" << endl;

	//����
	for (ite = Allstu.begin(); ite != Allstu.end(); ite++)
	{
		count++;
		if (count == Allstu.size())
			SaveStu << setiosflags(ios::left) << setw(10) << ite->GetName() << setw(10) << ite->GetPass() << setw(10)
			<< ite->stuclassid << setw(10) << ite->stukey;
		else
			SaveStu << setiosflags(ios::left) << setw(10) << ite->GetName() << setw(10) << ite->GetPass() << setw(10)
			<< ite->stuclassid << setw(10) << ite->stukey << endl;
	}
	SaveStu.close();
}

//д��γ���Ϣ
void WriteCourtoFile(vector<CCourse> Allcour, int i)
{
	vector<CCourse>::iterator ite;
	if (i == 1)
	{
		std::ofstream Savecour("./course01.ini", ios::out);

		int count = 0;

		Savecour << setiosflags(ios::left) << setw(10) << "��Ŀ" << setw(10) << "�ڴ�" << setw(10) << "ʱ���" << setw(10) << "��ʦ����" << endl;

		//����
		for (ite = Allcour.begin(); ite != Allcour.end(); ite++)
		{
			count++;
			if (count == Allcour.size())
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach;
			}
			else
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach << endl;
			}
		}
		Savecour.close();
	}
	else if (i == 2)
	{
		std::ofstream Savecour("./course02.ini", ios::out);

		int count = 0;  //����

		Savecour << setiosflags(ios::left) << setw(10) << "��Ŀ" << setw(10) << "�ڴ�" << setw(10) << "ʱ���" << setw(10) << "��ʦ����" << endl;

		//����
		for (ite = Allcour.begin(); ite != Allcour.end(); ite++)
		{
			count++;
			if (count == Allcour.size())
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach;
			}
			else
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach << endl;
			}
		}
		Savecour.close();
	}
	else if (i == 3)
	{
		std::ofstream Savecour("./course03.ini", ios::out);

		int count = 0;  //����

		Savecour << setiosflags(ios::left) << setw(10) << "��Ŀ" << setw(10) << "�ڴ�" << setw(10) << "ʱ���" << setw(10) << "��ʦ����" << endl;

		//����
		for (ite = Allcour.begin(); ite != Allcour.end(); ite++)
		{
			count++;
			if (count == Allcour.size())
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach;
			}
			else
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach << endl;
			}
		}
		Savecour.close();
	}
	else if (i == 4)
	{
		std::ofstream Savecour("./course04.ini", ios::out);

		int count = 0;  //����

		Savecour << setiosflags(ios::left) << setw(10) << "��Ŀ" << setw(10) << "�ڴ�" << setw(10) << "ʱ���" << setw(10) << "��ʦ����" << endl;

		//����
		for (ite = Allcour.begin(); ite != Allcour.end(); ite++)
		{
			count++;
			if (count == Allcour.size())
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach;
			}
			else
			{
				Savecour << setiosflags(ios::left) << setw(10) << ite->subject << setw(10) << ite->coursenum << setw(8);
				for (int i = 0; i < ite->coursenum; i++)
				{
					Savecour << setw(6) << ite->coursetime[i] << setw(6);
				}
				Savecour << setw(10) << ite->courseteach << endl;
			}
		}
		Savecour.close();
	}
	else { return; }
}

////�γ��޸�֪ͨ����ʦ���ܳ�
//void MessageFromWho(int key)
//{
//	int m = key % 100;
//	switch (m)
//	{
//	case 1:
//		MessageBox(NULL, TEXT("��ѧ��ʦ�����˿α�ʱ�䣡����"), TEXT("֪ͨ"), MB_OK);
//		break;
//	case 2:
//		MessageBox(NULL, TEXT("Ӣ����ʦ�����˿α�ʱ�䣡����"), TEXT("֪ͨ"), MB_OK);
//		break;
//	case 3:
//		MessageBox(NULL, TEXT("������ʦ�����˿α�ʱ�䣡����"), TEXT("֪ͨ"), MB_OK);
//		break;
//	case 4:
//		MessageBox(NULL, TEXT("C++��ʦ�����˿α�ʱ�䣡����"), TEXT("֪ͨ"), MB_OK);
//		break;
//	default:
//		break;
//	}
//}

//һ���༶
void ChangeMessage(int n)
{
	vector<CStudent> Allstu = ReadStuFromFile();
	for (int i = 0; i < Allstu.size(); i++)
	{
		int j = Allstu[i].stuclassid / 10;
		if (j == n)
		{
			Allstu[i].stuclassid += 1;
			
			break;
		}
	}
	WriteStutoFile(Allstu);
}



void Addition(CTeacher teacher)
{
	int m, n, l;
	cout << "����Ҫ�����ĸ���Ŀγ�(ֻ���ĸ���),";
	cout << "�ĸ�ʱ��εĿΣ�������һ��һ��11���ܶ��ڶ���22��" << endl;
	cin >> n >> l;
	vector<CCourse>  Allcour = ReadCourseFromFile(n);
	for (int i = 0; i < Allcour.size(); i++)
	{

		if (strcmp(teacher.teasubj, Allcour[i].subject) == 0)
		{
			//���γ�ʱ���Ƿ��ͻ
			for (int j = 0; j < Allcour[i].coursenum; j++)
			{
				if (Allcour[i].coursetime[j] == l)
				{
					MessageBox(NULL, TEXT("�γ��ظ�������"), TEXT("����"), MB_OK);
					goto end1;
				}

			}
			Allcour[i].coursenum += 1;
			Allcour[i].coursetime[Allcour[i].coursenum - 1] = l;
			WriteCourtoFile(Allcour, n);
			break;
		}
	}
	cout << "���ӳɹ�������" << endl;
	ChangeMessage(n);
end1:
	;
}

void Deletion(CTeacher teacher)
{
	int m, n, l;

	cout << "����Ҫɾ���ĸ���Ŀγ�(ֻ���ĸ���),";
	cout << "�ĸ�ʱ��εĿΣ�������һ��һ��11���ܶ��ڶ���22��" << endl;
	cin >> n >> l;
	vector<CCourse>  Allcour = ReadCourseFromFile(n);
	for (int i = 0; i < Allcour.size(); i++)
	{
		if (strcmp(teacher.teasubj, Allcour[i].subject) == 0)
		{
			//���γ�ʱ���Ƿ񲻴���
			for (int j = 0; j < Allcour[i].coursenum; j++)
			{
				if (Allcour[i].coursetime[j] == l)
				{
					Allcour[i].coursenum = Allcour[i].coursenum - 1;
					if (Allcour[i].coursenum == 0)
					{
						MessageBox(NULL, TEXT("�γ���Ŀ����Ϊ0������"), TEXT("����"), MB_OK);
						goto end3;
					}
					Allcour[i].coursetime[j] = Allcour[i].coursetime[Allcour[i].coursenum];
					WriteCourtoFile(Allcour, n);
					goto end2;
				}


			}

		}
	}
	MessageBox(NULL, TEXT("ֻ��ɾ�����γ̣�����"), TEXT("����"), MB_OK);
	return ;
end2:
	cout << "ɾ���ɹ�������" << endl;
	ChangeMessage(n);
	return ;
end3:
	return ;
}

void Replace(CTeacher teacher)
{
	int m, n, l, k;

	cout << "����Ҫ�滻�ĸ���Ŀγ�ʱ��(ֻ���ĸ���),";
	cout << "���ĸ�ʱ��ε��ĸ�ʱ��Σ�������һ��һ��11���ܶ��ڶ���22��" << endl;
	cin >> n >> l >> k;
	vector<CCourse>  Allcour = ReadCourseFromFile(n);
	for (int i = 0; i < Allcour.size(); i++)
	{
		if (strcmp(teacher.teasubj, Allcour[i].subject) == 0)
		{
			for (int j = 0; j < Allcour[i].coursenum; j++)
			{
				if (Allcour[i].coursetime[j] == l)
				{
					Allcour[i].coursetime[j] = k;
					WriteCourtoFile(Allcour, n);
					goto end5;
				}
			}
		}
	}
	MessageBox(NULL, TEXT("������������Ŀ�滻������"), TEXT("����"), MB_OK);
	return ;
end5:
	cout << "�滻�ɹ�������" << endl;
	ChangeMessage(n);

}