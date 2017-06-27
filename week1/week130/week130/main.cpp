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