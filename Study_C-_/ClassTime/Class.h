#pragma once
#include<string>
//�γ���
class CCourse
{
public:
	char subject[10];
	int  coursenum;
	int  coursetime[10];
	char courseteach[10];

};

//�༶��
class CClass:public CCourse
{
private:
	char name[10];
	char pass[10];
public:

	char* GetName() { return name; }
	char* GetPass() { return pass; }
	void  SetName(char* Name) { strcpy_s(name, Name); }
	void  SetPass(char* Pass) { strcpy_s(pass, Pass); }

	virtual int Logini(int) = 0;

    void ViewTimetable(int);
};

//ѧ����
class CStudent:public CClass
{
public:
	int  stukey;
	int  stuclassid;
	
	virtual int Logini(int key);
	void Getmessage(int);
};

//��ʦ��
class CTeacher:public CStudent
{
public:
	int  teakey;
	char teasubj[10];
	int  teaclassid[10];
	int  teaclassnum;

	virtual int Logini(int key);
	void Modifyclass(CTeacher);
};
