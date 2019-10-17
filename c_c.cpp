#include <iostream>
using namespace std;

void p_String_array(string *array , int n);
char punc[23] = {'+','-','*','/','%','^','(',')','{','}','[',']',',','.',';',':','\'','\"','>','<','=','&','|'};

int main(){

	string input_s ,arr[100];
	cout<<"Enter String : ";getline(cin,input_s);
	int i=0,j=-1;

	while(i<input_s.length()){
		string temp = "";
	
		while(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] !='\n' && isalnum(input_s[i]) && i<input_s.length())
		{
			temp+= input_s[i];
			i++;
		}
		
		if(temp != ""){
			string temp2 = "";
			
			for(int inner_1=0 ; inner_1<temp.length() ; inner_1++)
			{
				if(isdigit(temp[inner_1])){
					temp2 += temp[inner_1];
				}
				if(isalpha(temp[inner_1])){
					break;
				}
				
			}
				if(temp2.length() == temp.length()){
					++j; arr[j] = temp2;	
				}
				else if (temp2 == ""){
					++j; arr[j] = temp;
				}
				else if (temp2 != ""){
					++j; arr[j] = temp2;
					++j; arr[j] = temp.substr(temp2.length(),temp.length());
				}

		}
		
		if(input_s[i] == ' ' || input_s[i] == '\t'){ 
			i++;
		}
		else if(input_s[i] != ' ' && input_s[i] != '\t' && input_s[i] != '\0')
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
