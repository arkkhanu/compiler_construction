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
					if(input_s[i] == '\'' && i_slash != 0){
						slash_chk+=input_s[i];
						i++;
						break;
					}
					slash_chk+=input_s[i];
					i++;
					
				}
			}
			else{
				for(int i_slash=0 ; i_slash<3 ; i_slash++)
				{	
					if(input_s[i] == '\'' && i_slash != 0){
						slash_chk+=input_s[i];
						i++;
						break;
					}
					
					slash_chk+=input_s[i];
					i++;
				}
			}
			if(slash_chk != "") {
				++j;arr[j] = slash_chk;
			}
		}
		
		if(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] != '\0' && input_s[i] == '\"')
		{
			string sting_ch = "";
			do{
				sting_ch+= input_s[i];
				i++;
				if(input_s[i] == '\"' )
				{
					sting_ch+=input_s[i];	
				}
			}while(input_s[i] != '\"' && i < input_s.length());
			++j;arr[j] = sting_ch;
			i++;
		}
		
		if(input_s[i] == ' ' || input_s[i] == '\t'){ 
			i++;
		}
		else if(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] != '\'' && input_s[i] != '\"' && input_s[i] != '\0' && !isalnum(input_s[i]))
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


//dsfd654.se8.89.int a= 5.5,  9 .a,a .9,'\n' 9a.'e' 5, 9''.a 5;
//int a=5.5,9.a,a.9,9a.5,9.a5;
//int a= 5.5,  9 .a,a .9,'\n' 9a.'e' 5, 9''.a 5;
//dfa'fd'd'f'\nf's''f
// dfa'fd'd'f'\nf'sf
//int a= 5.5,  9 .a,a .9,'\n' 9a.'el'l'; 5, 9''.a 5;
// 'el'l'
//jlds'fdsff'dfd''dfdsf"fdsf
//jlds'fdsff'dfd''dfdsf"fdsf"'sas"c"cdc " dc 'dcdsvd"dvds
//"ds"fs
