#include<sstream>
#include<iostream>
using namespace std;


//int main()
//{
//	int a = 12345678;
//	string sa;
//
//	// 将一个整形变量转化为字符串，存储到string类对象中
//	stringstream s;
//	s << a;
//	s >> sa;
//	
//	cout << "sa = " << sa << endl;
//	cout << s.str() << endl; // str()方法：返回stringsteam中管理的string类型
//
//	 /*
//	 注意多次转换时，必须使用clear将上次转换状态清空掉，
//	 stringstreams在转换结尾时(即最后一个转换后),会将其内部状态设置为badbit，
//	 因此下一次转换是必须调用clear()将状态重置为goodbit才可以转换。但是clear()不会将stringstreams底层字符串清空掉，
//	 因此使用s.str("")，将stringstream底层管理string对象设置成""，否则多次转换时，会将结果全部累积在底层string对象中。
//     */
//
//	s.str(""); // 将stringstream底层管理string对象设置成""
//	s.clear(); // 清空s, 不清空会转化失败
//
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	cout << "sa = " << sa << endl;
//
//	string sValue;
//	sValue = s.str(); // str()方法：返回stringsteam中管理的string类型
//	cout << sValue << endl;
//	return 0;
//}

//
//int main()
//{
//	stringstream sstream;
//
//	// 将多个字符串放入 sstream 中
//	sstream << "first" << " " << "string,";
//	sstream << " second string";
//
//	cout << "strResult is: " << sstream.str() << endl;
//
//	// 清空 sstream
//	sstream.str("");
//	sstream.clear();
//	sstream << "third string";
//	cout << "After clear, strResult is: " << sstream.str() << endl;
//	return 0;
//}
