//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<functional>
//using namespace std;

//#pragma warning(disable:4267)������������


//�ַ�������ѧϰ
//void FunIterator()
//{
	//string str("abcdefg");
	//string::iterator ite;  //char*

	//const char* a = str.c_str();
	//ite = str.begin();     //end() 

	//for (ite; ite != str.end(); ite++)
	//{
	//	*ite = 'a';
	//	//cout << *ite << " ";
	//}

	//str.append(18, 'a');
	//ite = str.begin(); //û�л�ʹ�õ�����ʧЧ���ַ����������µĿռ䣬��ַ�ͷ�
	//ite[3] = 'w';
	
	//for (size_t i = 0; i < str.size(); i++)
	//{
	//	cout << *ite << " ";
	//	ite++;
	//}
	//for (size_t i = 0; i < str.size(); i++)
	//{
	//	cout << ite[i] << " ";
	//}
//}

//void testiterator()
//{
//	string str("abcefghi");
////	string str1("edf");
////	str.append(str1.begin(), str1.end());
//
//
////	str.erase(str.begin() + 2,str.begin()+4);
//
//	string str1("zxcvbn");
//
//	str.insert(str.begin() + 2, str1.begin(), str1.end());
//
//
//	cout << str << endl;
//}

//void fun(char c)
//{
//	cout << c;
//}
//
////����
//void FunForeach()
//{
//	string str("queasdfgjkhgnfl");
//	/*for_each(str.begin(), str.end(), fun);*/
//
//	/*cout << endl;*/
//	sort(str.begin(),str.end());//Ĭ�ϴ�С����
//
//	sort(str.begin(), str.end(), greater<char>());//�Ӵ�С
//	for_each(str.begin(), str.end(), fun);
//}
//
//int main()
//{ 
//	//���
//	//string str2("nihao");
//	//cout << str2 << endl;
//	//cout << str2[2] << endl;
//	//cout << str2.c_str() << endl;
//	//cout << str2.at(2);  //��������ĸ�ʽ��0��ʼ����Ϊ����λ
//	//try
//	//{
//	//	str2.at(8);
//	//}
//	//catch (out_of_range& a)
//	//{
//	//	cout << "Խ����" << endl;
//	//}
//
//	//�޸�
//	//string str3("abcdefg");
//	/*str3[3] = 'q';*/
//	//����
//	//string str4 = "abc";
//	/*const char* p = str4.c_str();*/
//	/*str3.insert(2, str4);*/
//	/*str3.insert(2,p);*/
//	/*str3.insert(2, str4, 1, 2);*/
//	/*str3.insert(2, p, 3);*/
//	/*str3.insert(2, 3, 'i');*/
//	/*str3 += str4;*/
//	/*str3.append(3,'a');*/
//	//��ֵ
//	/*str3.assign(3, 'c');*/
//	//ɾ��
//	/*str3.erase(0, str3.length());*/
//
//	/*cout << str3 << endl;*/
//	//�Ƚ�(ԭ��
//	//abcdef  abc
//	/*cout << (str3 > str4) << endl;*/
//	/*cout << str3.compare(str4) << endl;*/
//	//����
//	/*char str[6] = { 0 };
//	int i=str3.copy(str, 4, 1);*/
//	/*cout << "i=" << i << endl;*/
//	//cout << str3.data() << endl;
//	//cout << str3.empty() << endl;
//	//cout << str3.find('z', 0) << endl;
//	/*if (str3.find('z', 0) == string::npos)
//	{
//		cout << "Wouldn't find!!!" << endl;
//	}*/
//	/*cout << str3.length() << endl;
//	cout << size(str3) << endl;*/
//	//cout << str3.max_size() << endl;
//	//cout << str3 << endl;
//	//string s = "They say he carved it himself...from a BIGGER spoon";
//	//string s2 = "find your soul-mate, Homer.";
//	//s.replace(32, s2.length(), s2);
//	//cout << s << endl;
//	/*str3.resize(10, 'a');
//	cout << str3.data() << endl;*/
//
//	//������
//	//FunIterator();
//	//testiterator();
//
//	FunForeach();
//
//	return 0;
//}
