
/*. 四则运算测试系统
编写一个计算机教学辅助软件，供小学生进行四则运算练习与测试使用。该软件应能自动出题，自动判分，并给出相应的统计功能。具体要求如下：
（1）设计主界面，为用户提供菜单，可以选择运算类型，题目难度，开始及退出系统等提示。
（2）系统自动产生运算题，其中运算数为1 - 10自然数的加减运算或1－100之间的四则运算。
(3）测试模式及统计功能:在规定的答题时间内完成一定数目的题目，完成所有题目后给出得分。
提示：此题考查函数的设计能力，用多个函数规划程序。可以从使用性角度出发，完善上述功能，并对其作扩展。
*/

#include<iostream>
//#include<cstdlib>
#include<ctime>

using namespace std;
int calculateRandomNumber();
char createRandomOpertor();
double calculate(int x, char op, int y);

int main(){
	cout << "-----------------------------\n";
	cout << "选择项目：\n1.初级练习模式\n2.高级练习模式\n3.测试模式\n4.退出系统\n";
	cout << "-----------------------------\n";
	int key,  i, rightNumber = 0, flag = 0;
	char opchar;
	double a, b,c,d, userAnswer;
	srand(time(NULL));
	while (1){
		cin >> key;
		switch (key)
		{
		case 1:{
				   char cc;
				   cout << "输入运算类型：+，-，*，/: ";
				   cin >> cc;
				   switch (cc)
				   {
				   case '+':{
								a = calculateRandomNumber();
								b = calculateRandomNumber();
								cout << a << "+" << b << " = ";
								cin >> userAnswer;
								if (userAnswer == (a + b)){
									cout << "right\n";
								}
								else{
									cout << "error,try again: ";
									cin >> userAnswer;
									if (userAnswer == (a + b))
										cout << "right\n";
									else{
										cout << "error, exit\n";
										break;
									}
								}
				   }
				   case '-':{
								a = calculateRandomNumber();
								b = calculateRandomNumber();
								cout << a << "-" << b << " = ";
								cin >> userAnswer;
								if (userAnswer == (a - b)){
									cout << "right\n";
								}
								else{
									cout << "error,try again: ";
									cin >> userAnswer;
									if (userAnswer == (a - b))
										cout << "right\n";
									else{
										cout << "error, exit\n";
										break;
									}
								}
				   }
				   case '*':{
								a = calculateRandomNumber();
								b = calculateRandomNumber();
								cout << a << "*" << b << " = ";
								cin >> userAnswer;
								if (userAnswer == (a * b)){
									cout << "right\n";
								}
								else{
									cout << "error,try again: ";
									cin >> userAnswer;
									if (userAnswer == (a * b))
										cout << "right\n";
									else{
										cout << "error, exit\n";
										break;
									}
								}
				   }
				   case '/':{
								a = calculateRandomNumber();
								b = calculateRandomNumber();
								cout << a << "/" << b << " = ";
								cin >> userAnswer;
								if (userAnswer == (a / b)){
									cout << "right\n";
								}
								else{
									cout << "error,try again: ";
									cin >> userAnswer;
									if (userAnswer == (a / b))
										cout << "right\n";
									else{
										cout << "error, exit\n";
										break;
									}
								}
				   }
				   default:
					   break;
				   }
		}
		case 2:{
				   a = calculateRandomNumber() * 10;
				   b = calculateRandomNumber() * 10;
				   c = calculateRandomNumber() * 10;
				   d = calculateRandomNumber() * 10;
				   cout << a << " * " << b << " + " << c << " / " << d << " = ";
				   cin >> userAnswer;
				   if (userAnswer == (a*b+c/d)){
					   cout << "right\n";
				   }
				   else{
					   cout << "error,try again: ";
					   cin >> userAnswer;
					   if (userAnswer == (a*b+c/d))
						   cout << "right\n";
					   else{
						   cout << "error, exit\n";
						   break;
					   }
				   }

		}case 3:{
				   cout << "5秒钟计时\n";
				   time_t start = time(NULL);
				   time_t stop = time(NULL);
				   int second = 5;
				   while ((stop-start)<=second){
					   //cout << "1***** ";
					   for (i = 0; i < 10; i++){
						   a = calculateRandomNumber();
						   b = calculateRandomNumber();
						   opchar = createRandomOpertor();
						   //cout << opchar;
						   //printf("%d %c %d =?\n", a, opchar, b);
						   cout << a << opchar << b << endl;
						   cin >> userAnswer;
						   if (userAnswer == calculate(a, opchar, b)){
							   rightNumber++;
							   cout << "right\n";
						   }
						   else{
							   cout << "wrong\n";
						   }
						   //stop = time(NULL);
					   }
					   stop = time(NULL);
				   }
				   cout << "score: " << rightNumber << "\n";
		}case 4:{
			break;
		}
		}
		if (key == 4){
			break;
		}
		cout << "请再次选择项目\n";
	}
	return 0;
}

int calculateRandomNumber(){
	return rand() % 10 + 1;
}

char createRandomOpertor(){
	int op;
	op = rand() % 4 + 1;
	switch (op)
	{
	case 1:return '+';
	case 2:return '-';
	case 3:return '*';
	case 4:return '/';
	}
}

double calculate(int x, char op, int y){
	switch (op)
	{
	case '+':return x + y;
	case '-':return x - y;
	case '*':return x * y;
	case '/':return x / y;
	}
}

//时间限制ttps://zhidao.baidu.com/question/1733605833367708347.html
//ttp://blog.csdn.net/lin434406218/article/details/52717800