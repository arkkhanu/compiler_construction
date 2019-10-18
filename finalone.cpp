#include <iostream>
#include <string.h>
using namespace std;

void p_String_array(string *array , int n);
char punc[23] = {'+','-','*','/','%','^','(',')','{','}','[',']',',',';',':','>','<','=','&','|'};

int main(){

	string input_s ,arr[100];
	cout<<"Enter String : ";getline(cin,input_s);
	int i=0,j=-1;

	while(i<input_s.length()){
		string temp = "";
	
		while(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] !='\n' && isalnum(input_s[i]) || input_s[i] == '.' && i<input_s.length())
		{
			temp+= input_s[i];
			i++;
		}
		
		if(temp != ""){
			++j;
			arr[j] = temp;
		}
		if(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] != '\0' && input_s[i] == '\'')
		{
			string slash_chk = "";
			if(input_s[i+1] == '\\')
			{
				for(int i_slash=0 ; i_slash<4 ; i_slash++)
				{
					slash_chk+=input_s[i];
					i++;
				}
				cout<<"output :"<<slash_chk<<endl;
			}
			else{
				for(int i_slash=0 ; i_slash<3 ; i_slash++)
				{
					slash_chk+=input_s[i];
					i++;
				}
				cout<<"output :"<<slash_chk<<endl;
			}
			if(slash_chk != "") {
				++j;arr[j] = slash_chk;
			}
		}
	/*	if(input_s[i] == '\'')
		{
			string slash_ch = "";
			
			if(input_s[i+1] == '\\')
			{	
				for(int i_slash = 0 ; i_slash < 2 ; i++){
					slash_ch += input_s[i+1];
					i++;
				}
				if(slash_ch != "")
				{
					++j;arr[j] = slash_ch;
				}
			}else
			{
				for(int i_slash = 0 ; i_slash < 1 ; i++){
					slash_ch += input_s[i+1];
					i++;
				}
				if(slash_ch != "")
				{
					++j;arr[j] = slash_ch;
				}
			}
		}
		*/
		if(input_s[i] == ' ' || input_s[i] == '\t'){ 
			i++;
		}
		else if(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] != '\'' && input_s[i] != '\0')
		{
			++j;
			arr[j] = input_s[i];
			i++;
		}
		
		
		
	
	
	}
	
	cout<<"\nString \n";
	cout<<j<<endl;
	p_String_array(arr,j);
	
	cout<<"\n\nPunctuators\n";
	
}
	
	void p_String_array(string *array , int n){
		if(n>=0){
		for(int k=0 ; k<=n ; k++){
			cout<<array[k]<<",";
		}
		
		}else{
			cout<<"\nEmpty\n";
		}
}


//int a=5.5,9.a,a.9,9a.5,9.a5;
//int a= 5.5,  9 .a,a .9,'\n' 9a.'e' 5, 9''.a 5;
// dfa'fd'd'f'\nf'sf
