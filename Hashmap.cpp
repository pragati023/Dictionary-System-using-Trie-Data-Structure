#include<iostream>
#include<ctype.h>
using namespace std;
template<typename T> 
class hashnode{
	public:
	char key;
	T value;
	
 void setnull()
 {
 	this->value=NULL;
 }
	
};
template<typename T>
class hashmap{
  hashnode<T> *map;
  int curr_size;
  
  public:
  hashmap()
  {
       map=new hashnode<T>[52];
       curr_size=0;
       for(char i='a';i<='z';i++)
       map[hashof(i)].setnull();
       for(char i='A';i<='Z';i++)
       map[hashof(i)].setnull();
  }
   int hashof(char key)
   {
   	if(islower(key))
   	{
   		return key-'a'+26;
   		
	   }
	   else{
	   	return key-'A';
	   	
	   }
   }
   void insert(char key,T value)
   {
   	  map[hashof(key)].value=value;
   	  curr_size++;
   }
   void deletevalue(const char key)
   {
   	map[hashof(key)]->value=NULL;
   	map[hashof(key)]->data='\0';
   	curr_size--;
   }
   bool find(const char key)
   {
   	 if(map[hashof(key)].value!=NULL)
   	 return true;
   	 return false;
   }
  int size()
  {
  	return curr_size;
  }
  T operator[](const char key)
  {
  	return map[hashof(key)].value;
  }

};

