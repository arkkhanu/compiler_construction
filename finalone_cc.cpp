#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
using namespace std;
//void int main() 'sd'g'

//****************************************************
//       keywords
//****************************************************
bool check_keywords(string word) {
	string keywords[] = { "struct","for","switch","main","do","while","case","if","else","break","void" };
	for (int i = 0; i<11; i++)
	{
		if (word == keywords[i])
		{
			return true;
		}
	}
	return false;
}
//****************************************************
//       DataTypes
//****************************************************
bool datatype_class(string word)
{
	string DT[] = {"int","float","string","char","bool"};
	for(int i=0;i<6;i++)
	{
		if(DT[i] == word)
		{
			return true;
		}
	}
	return false;
}
//****************************************************
//       Operators
//****************************************************
int check_operators(char word)
{
	char operators[] = { '+','-','*','/','%','=','!','&','>','<','|' };
	for (int i = 0; i<11; i++)
	{
		if (word == operators[i])
		{
			return i;
		}
	}
	return -1;
}
//****************************************************
//       Combine Operators
//****************************************************
int check_combine_operators(int side_1,int side_2)
{
	int combine_operators[11][11] = {  {1,0,0,0,0,2,0,0,0,0,0},
									   {0,1,0,0,0,2,0,0,0,0,0},
									   {0,0,3,9,0,2,0,0,0,0,0},
									   {0,0,8,7,0,2,0,0,0,0,0},
									   {0,0,0,0,0,2,0,0,0,0,0},
									   {0,0,0,0,0,4,0,0,0,0,0},
									   {0,0,0,0,0,4,0,0,0,0,0},
									   {0,0,0,0,0,0,0,6,0,0,0},
									   {0,0,0,0,0,4,0,0,0,0,0},
									   {0,0,0,0,0,4,0,0,0,0,0},
									   {0,0,0,0,0,0,0,0,0,0,5} };
	
	return combine_operators[side_1][side_2];
}
//****************************************************
//       Get class of Operators
//****************************************************
string get_class_of_operator(int index)   
{
	string operator_class[] = {"N/A","INC/DEC","ASGN-OP","POINTER","RELAT-OP","OR-OP","AND-OP","Single_cmt","cmt_start","cmt_end"};
	
	return operator_class[index];
}

string get_class_of_single_operator(int index)   
{
	string operator_class[] = {"Add-Sub","Add-Sub","Mul","Div-Mod","Div-Mod","Asgn-Op","Not-Op","Adress-Op","Relat-Op","Relat-Op","invalid"};
	
	return operator_class[index];
}
//****************************************************
//       punctuators
//****************************************************
bool check_punctuators(char word)
{
	char punctuators[] = { '(',')','[',']','{','}',';',':',',' };
	for (int i = 0; i<9; i++)
	{
		if (word == punctuators[i])
		{
			return true;
		}
	}
	return false;
}
//****************************************************
//       identifiers
//****************************************************
int table(char ch, int state)
{
	int trans[3][4] = { { 1, 2, 1, 2 }, 
						{ 1, 1, 1, 2 }, 
						{ 2, 2, 2, 2 } };	
	if (ch == '_')
	{
		return trans[state][0];
	}
	else if (ch >= '0' && ch <= '9')
	{
		return trans[state][1];
	}
	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return trans[state][2];
	}
	else
	{
		return trans[state][3];
	}
}

int check_identifiers(string word)
{
	int current = 0;
		for (int i = 0;i < word.length();i++)
		{
			current = table(word[i], current);
		}
	return current;
}
//****************************************************
//       integer and float constants
//****************************************************
int constant_table(char ch, int state)
{
	int trans[6][4] = { { 1, 2, 3, 5 }, 
						{ 5, 2, 3, 5 }, 
						{ 5, 2, 3, 5 },
						{ 5, 4, 5, 5 },
						{ 5, 4, 5, 5 },
						{ 5, 5, 5, 5 } };	
	if (ch == '+' || ch == '-')
	{
		return trans[state][0];
	}
	else if (ch >= '0' && ch <= '9')
	{
		return trans[state][1];
	}
	else if (ch == '.' )
	{
		return trans[state][2];
	}
	else
	{
		return trans[state][3];
	}
}

int check_constants(string word)
{
	int current = 0;
		for (int i = 0;i < word.length();i++)
		{
			current = constant_table(word[i], current);
		}
	return current;
}
//****************************************************
//       Character Constant
//****************************************************
int trans(int state, char ch)
{
	int table[6][4] = { { 1,5,5,5 },{ 5,4,2,2 },{ 3,5,5,5 },{ 5,5,5,5 },{2,2,3,2},{5,5,5,5} };

	if (ch == '\'')
	{
		return table[state][0];
	}
	else if (ch == '\\')
	{
		return table[state][1];
	}
	else if (ch == 'n' || ch == 't' || ch == 'a' || ch == 'v' || ch == 'b' || ch == 'r' || ch == 'f' || ch == '\\' || ch == '\'' || ch == '\"' )
	{
		return table[state][3];
	}
	else
	{
		return table[state][2];
	}
}

bool check_character_constant(string word)
{
	int curr = 0;
	for (int i = 0; i < word.length(); i++)
	{
		curr = trans(curr, word[i]);
	}

	if (curr == 3)
		return true;
	else
		return false;
}
//****************************************************
//    Ckecking Keywords, Identifiers and Constants
//****************************************************
string check_keyword_id_constant(string word)
{
		if(check_keywords(word))
		{	
			return "keyword"; 
		}
		else if(datatype_class(word)){
			return "DataTypes";
		}
		else if(check_identifiers(word) == 1)
		{
			return "Identifier";
		}
		else if(check_constants(word) == 2)
		{
			return "Integer_Const";
		}
		else if(check_constants(word) == 4)
		{
			return "Float_Const";
		}
		else
		{
			return "L.E";
		}
}
//****************************************************
//     Converting a Single Character to a String
//****************************************************
string toString(char x) 
{  
    string s(1, x); 
    return s;    
} 
//****************************************************
//       main body
//****************************************************
int main() {

	string line = "", word = "";
	int line_num=0;
	bool read = true, no_string = true;
	fstream infile;
	ofstream token;
	token.open("Token.txt" , ios::out);
		cout<<"Enter code : \n";
		getline(cin,line);  //
	
      for (int i = 0; i < line.length(); i++)
	  {
	  
	  ///////////////////////////////////////////////
	  ///////////////////////////////////////////////
	  	
		if(no_string && read && check_punctuators(line[i]))           
		{
			if(word != "")
			{
				token<<"( "<<check_keyword_id_constant(word)<<" , "<< word <<" , "<<line_num<<" )\n";
				word = "";
			}
			token<<"( Punctuator , "<< toString(line[i]) <<" , "<<line_num<<" )\n";
		}
		
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		

		else if(no_string && read && line[i] == '\'')
		{
			if(word != "")
			{
				token<<"( "<<check_keyword_id_constant(word)<<" , "<< word <<" , "<<line_num<<" )\n";
				word = "";
			}
			if(line[i+1] == '\\')
			{
				word = line.substr(i,4);
				if(check_character_constant(word))
				{
					token<<"( Character_cons , "<< word <<" , "<<line_num<<" )\n";
				}
				else
				{
					token<<"( L.E , "<< word <<" , "<<line_num<<" )\n";
				}
				i+=3;
				word="";
			}
			else
			{
				word = line.substr(i,3);
				if(check_character_constant(word))
				{
					token<<"( Character_cons , "<< word <<" , "<<line_num<<" )\n";
				}
				else
				{
					token<<"( L.E , "<< word <<" , "<<line_num<<" )\n";
				}
				i+=2;
				word="";
			}
		}
		
		//////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////
		
		else if(read && line[i] == '\"')
		{
			if(no_string)
			{
				if(word != "")
				{	
					token<<"( "<<check_keyword_id_constant(word)<<" , "<< word <<" , "<<line_num<<" )\n";
					word = "";
					
				}
				no_string = false;
				word+=line[i];
			}
			else
			{
				if(line[i-1] == '\\')
				{
					word+=line[i];
				}
				else
				{
					no_string = true;
					word+=line[i];
					token<<"( String_Const , "<< word <<" , "<<line_num<<" )\n";
					word = "";
				}
			}
		}
		
		/////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////
		
		else if(no_string && check_operators(line[i]) !=-1)           
		{
			if(read && word != "")
			{
				token<<"( "<<check_keyword_id_constant(word)<<" , "<< word <<" , "<<line_num<<" )\n";
				word = "";
			}			
			int second_opr = check_operators(line[i+1]);
			if( second_opr != -1)
			{
				cout<<check_combine_operators(check_operators(line[i]),second_opr);
				string class_part = get_class_of_operator(check_combine_operators(check_operators(line[i]),second_opr));
				if(class_part !="N/A")
				{
					if(read && class_part == "Single_cmt")
					{
						i= line.length()-1;
					}
					else if(read && class_part == "cmt_start")
					{
						read = false;
						word="";
					}
					else if(class_part == "cmt_end")
					{
						read = true;
						word="";
					}
					else
					{
						if(read)
							token<<"( "<<class_part<<" , "<< toString(line[i])<<toString(line[i+1]) <<" , "<<line_num<<" )\n";
					}			
					i++;	
				}
				else
				{
					if(read)
						token<<"( "<<get_class_of_single_operator(check_operators(line[i]))<<" , "<<toString(line[i]) <<" , "<<line_num<<" )\n";
				}
			}
			else
			{
				if(read)
					token<<"( "<<get_class_of_single_operator(check_operators(line[i]))<<" , "<<toString(line[i]) <<" , "<<line_num<<" )\n";
			}
			
		}
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
	else if(no_string && read && line[i] == '.')
		{
			if(word == "")
			{
				if(line[i+1] >='0' && line[i+1] <= '9')
				{
					word += line[i];
				}
				else
				{
					token<<"( Dot , "<< toString(line[i]) <<" , "<<line_num<<" )\n";
					word = "";
				}
			}
			else if(check_constants(word) == 4)
			{	
					token<<"( Float_Const , "<< word <<" , "<<line_num<<" )\n";
					word="";
					i--;		
		    } 
			else 
			{
				if(check_keywords(word) )
				{
					token<<"( "<<datatype_class(word)<<" , "<< word <<" , "<<line_num<<" )\n";
					word = "";
					if(line[i+1] >='0' && line[i+1] <= '9')
					{
						word += line[i];
					}
					else
					{
						token<<"( Dot , "<< toString(line[i]) <<" , "<<line_num<<" )\n";
					}
				}
				else if(check_identifiers(word) == 1)
				{
					token<<"( Identifier , "<< word <<" , "<<line_num<<" )\n";
					word = "";
					if(line[i+1] >='0' && line[i+1] <= '9')
					{
						word += line[i];
					}
					else
					{
						token<<"( dot , "<< toString(line[i]) <<" , "<<line_num<<" )\n";
					}
				}
				else if(check_constants(word) == 2 )
				{
					if(line[i+1] >='0' && line[i+1] <= '9')
					{
						word += line[i];
					}
					else 
					{
						token<<"( Integer_Const , "<< word <<" , "<<line_num<<" )\n";
						word = "";
						token<<"( Dot , "<< toString(line[i]) <<" , "<<line_num<<" )\n";
					}
				}
				else
				{
					token<<"( L.E , "<< word <<" , "<<line_num<<" )\n";
					word = "";
					i--;
				}
				
			}	
		}
		//////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////
		else if( (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\0'))   
		{
			if(no_string && read && word != "")
			{
				token<<"( "<<check_keyword_id_constant(word)<<" , "<< word <<" , "<<line_num<<" )\n";
				word = "";
			}
			else
			{
				if(!no_string)
				{
					token<<"( L.E , "<< word <<" , "<<line_num<<" )\n";
					no_string = true;
					word = "";
				}
			}
		}
		/////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////
		else           
		{
			word += line[i];
		}
		
		////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////
		
	  }

	 cout<<"Done!!!";

    token.close();
    string file_name = "Token.txt";
    system(file_name.c_str());
	return 0;
}
