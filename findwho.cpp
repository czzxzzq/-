#include<iostream>
#include<vector>
#include<unordered_set>
#include<fstream>
#include<string>
#define pri 99
using namespace std;
unordered_set<string> name;
int main(){
	ifstream file("orginal.txt");
	if(!file.is_open()){
		cout<<"�ļ���ʧ��"<<endl;
	}
	string temp;
	while(!file.eof()){
		file>>temp;
		name.insert(temp);
	}
	file.close();
	
	
	ifstream source("source.txt");
	if(!source.is_open()){
		cout<<"�ļ���ʧ��"<<endl;
	}
	while(!source.eof()){
		source>>temp;
		unordered_set<string>::iterator i=name.find(temp);
		if(i==name.end()){
			cout<<temp<<"���ֲ�����"; 
		} 
		name.erase(i);
	}
	source.close();
	
	
	ofstream destination;
	destination.open("destination.txt",ios::out);
	for(auto i=name.begin();i!=name.end();i++){
		destination<<*i<<endl; 
	}
	destination.close();
	return 0;
} 
