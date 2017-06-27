#include<iostream>
#include<ctime>
using namespace std;

int main(){
time_t Time =time(0);
Time +=1;
while(Time>time(0)){
	cout<<"1 ";
	for(int i=0;i<2;i++)
		cout<<"2 ";
}
cout<<"\nreturn\n";
return 0;
}