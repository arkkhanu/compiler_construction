#include <iostream>
#include <string.h>
using namespace std;

void p_String_array(string *array , int n);
char punc[23] = {'+','-','*','/','%','^','(',')','{','}','[',']',',',';',':','>','<','=','&','|'};

int main(){

	string input_s ,arr[100],arr2[100];
	cout<<"Enter String : ";getline(cin,input_s);
	int i=0,j=-1,jj=-1;
	while(i<input_s.length()){
		string temp = "";
		
	
		while(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] !='\n' && isalnum(input_s[i]) || input_s[i] == '.' && i<input_s.length())
		{
			temp+= input_s[i];
			i++;
		}
		
		if(temp != ""){
			
			int inner_temp_1 = 0;
			bool alphafound = false;
			bool foundonce = false;
			
			while(inner_temp_1 < temp.length()){
				
				if(isdigit(temp[inner_temp_1])){
					string string_1 = "";
					
					while(inner_temp_1 < temp.length())	{
						
						if(isdigit(temp[inner_temp_1])){
							string_1 += temp[inner_temp_1];			
						}
						
						if(isalpha(temp[inner_temp_1])){
							alphafound = true;
							string_1 += temp[inner_temp_1];
						}
						
						else if(alphafound == true && temp[inner_temp_1] == '.'){
							break;
							foundonce = true;
						}
						else if(alphafound == false && temp[inner_temp_1] == '.'){
							string_1 += temp[inner_temp_1];
							foundonce = true;
						}
							
					inner_temp_1++;
						if(foundonce == true && temp[inner_temp_1] == '.'){
							break;
						}
					
					}
					
					cout<<"out"<<temp[inner_temp_1];	
					++jj;arr2[jj] = string_1;
				}
				
//				else if(temp[inner_temp_1] == '.' ){
//					
//				}
//				
//				else if(isalpha(temp[inner_temp_1])){
//					
//				}
				
				inner_temp_1++;
			}
			
			//
			++j;//++jj;
			arr[j] = temp;//arr2[jj]=temp;
			//
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
		else if(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] != '\'' && input_s[i] != '\"' && input_s[i] != '\0' && !isalnum(input_s[i]) && input_s[i] != '.')
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
	
	cout<<"\nAfter All \n";
	cout<<jj<<endl;
	p_String_array(arr2,jj);
	
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


//dsfd654.se8.89.int a= 5.5,  9 .a,a .9,'\n' 9a.'e' 5, 9''.a 5; 20 - 11
//int a=5.5,9.a,a.9,9a.5,9.a5; 12 - 6
//int a= 5.5,  9 .a,a .9,'\n' 9a.'e' 5, 9''.a 5; 20 - 11
//dfa'fd'd'f'\nf's''f 6 - 1
// dfa'fd'd'f'\nf'sf  5 - 1
//int a= 5.5,  9 .a,a .9,'\n' 9a.'el'l'; 5, 9''.a 5; 22 - 11
// 'el'l' 1 - -1
//jlds'fdsff'dfd''dfdsf"fdsf  7 - 3
//jlds'fdsff'dfd''dfdsf"fdsf"'sas"c"cdc " dc 'dcdsvd"dvds   13 - 6
//"ds"fs  1 - 0
//''.a 5;  3 - 1
//42rew432.rew
//4w2.a
