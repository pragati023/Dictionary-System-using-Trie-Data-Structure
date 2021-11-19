#include<iostream>
#include<string>
#include<string.h>
#include"D:\vs_code\dsa project\Hashmap.cpp"
#include<vector>
using namespace std;
class trienode{
	public:
	char data;
	hashmap<trienode*> child;
	bool terminal;
	char *meaning;
	
	
	trienode(char data)
	{
		this->data=data;
		terminal=false;
		meaning=NULL;
	}
	void setmeaning(string matlab)
	{
		char *str=new char[matlab.length()];
		for(int i=0;i<matlab.length();i++)
		str[i]=matlab[i];
        
        str[matlab.length()]='\0';
		
		this->meaning=str;
	}
	char* getmeaning()
   {
   this->meaning;
   }
	
};
class trie{
	
	trienode *root;
	int number_of_words;
	public:
	trie()
	{
		root=new trienode('\0');
		number_of_words=0;
	}
	void insert(string s,string meaning)
   {
   		trienode*temp=root;
   	for(int i=0;i<s.length();i++)
   	{
   	
   		char ch =  s[i];
            if(temp->child.find(ch)){
                temp = temp->child[ch];
            }
            else{
               trienode* n = new trienode(ch);
                temp->child.insert(ch,n);
                temp = n;
            }
        }
        temp->terminal=true;
        temp->setmeaning(meaning);
	   }
	   
	bool search(string s,string &meaning)
	{
			trienode*temp=root;
   	for(int i=0;i<s.length();i++)
   	{ 
   		char ch =  s[i];
   		
   		
            if(temp->child.find(ch)){
                temp = temp->child[ch];
            }
            else
            return false;
    }
    
        if(temp->terminal==true)
        {meaning=temp->meaning;
        return true;
      }
      
    return false;
	}
	void update(string s,string m)
	{
			trienode*temp=root;
			bool found=true;
   	for(int i=0;i<s.length();i++)
   	{ 
   		char ch =  s[i];
            if(temp->child.find(ch)){
                temp = temp->child[ch];
            }
            else
            { found=false;
            	break;
			}
    }
    
 if(found==true &&temp->terminal==true)
 {
 temp->setmeaning(m);
 }
 else
 {
 	insert(s,m);
 }
 return;
    
	}
   trienode* return_node(char c)
   {

   	trienode*temp=root;
   	if(temp->child.find(c)==true)
   	return temp->child[c];
   	
   	return NULL;
   }
   
   
   void suggestions(trienode* temp,string str,vector<string> &suggestion_list)
     {
     if(temp==NULL)
	{
		return;
	}
	for(char ch='a';ch<='z';ch++)
	{
        if(temp->child.find(ch))
        {
        	if(str.length()==0)
        	{
        		str+=temp->data;
			}
		char c=ch;
        str+=c;
		suggestions(temp->child[c],str,suggestion_list);
        str.erase(str.end()-1);
    }
	}
    if(temp->terminal)
    suggestion_list.push_back(str);
	return;
     	
	 }

	
};
