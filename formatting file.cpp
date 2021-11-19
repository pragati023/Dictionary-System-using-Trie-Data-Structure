#include<iostream>
#include<string>
#include "C:\Users\Abhi\Desktop\2nd year college\data structures\data structure project\Color file.cpp"
#include"C:\Users\Abhi\Desktop\2nd year college\data structures\data structure project\Size file.cpp"
using namespace std;
void shift_down()
{cout<<"\n\n\n";
}

void align_center()
{
		cout<<"\t";
}
void print_intial_page()
{ 
	shift_down();
	align_center();
	cout<<Change_color_to("RED")<<"\t\tDICTIONARY";
	cout<<"\n\n";
	align_center();
	cout<<Change_color_to("RED");
	cout<<"Hi I am bob I will help you in learning new words\n";
	align_center();
	cout<<"Are you ready"<<endl;
}
void print_enter_word()
{           //align_center();
            cout<<Change_color_to("RED")<<"PRESS ESCAPE TO RETURN\n";
			align_center();
			cout<<endl;
		    align_center();
		    cout<<Change_color_to("RED")<<"Enter the word";
}
void print_exit_next(string s)
{
   // align_center();
	if(s=="left")
	cout<<Change_color_to("GREEN")<<"<-Exit\t\t\t\t"<<Change_color_to("RED")<<"Next->";
	else
	cout<<Change_color_to("RED")<<"<-Exit\t\t\t\t"<<Change_color_to("GREEN")<<"Next->";
	
}
void print_back_done(string s)
{
	 //align_center();
	if(s=="left")
	cout<<Change_color_to("GREEN")<<"<-Back\t\t\t\t"<<Change_color_to("RED")<<"Done->";
	else
	cout<<Change_color_to("RED")<<"<-Back\t\t\t\t"<<Change_color_to("GREEN")<<"Done->";
}
void print_left()
{
	print_intial_page();
  align_center();
  print_exit_next("left");
  
}
void print_right()
{
	print_intial_page();
  align_center();
  print_exit_next("right");
	
}
void add_or_search(string s)
{ 
  if(s=="add")
  {	shift_down();
    	 align_center();
    	 cout<<Change_color_to("RED")<<"Choose the function you wish to perform\n\n";
    	 align_center();
    		 cout<<Change_color_to("GREEN")<<"1. Add a new word"<<endl;
    		 align_center();
    		 cout<<Change_color_to("RED")<<"2. Search a word"<<endl;
    	}
    	else
    	{
    		shift_down();
    	 align_center();
    	 cout<<Change_color_to("RED")<<"Choose the function you wish to perform\n\n";
    	 align_center();
    		 cout<<Change_color_to("RED")<<"1. Add a new word"<<endl;
    		 align_center();
    		 cout<<Change_color_to("GREEN")<<"2. Search a word"<<endl;
		}
}
void yes_no(string s)
{  if(s=="yes")
   {	
	align_center();
	cout<<Change_color_to("GREEN")<<"YES"<<"\t\t"<<Change_color_to("RED")<<"NO";
}
else
{
	
	align_center();
	cout<<Change_color_to("RED")<<"YES"<<"\t\t"<<Change_color_to("GREEN")<<"NO";
	
}
}

void Word_not_found()
{
	shift_down();
	cout<<"    ";
	
	cout<<Change_color_to("RED")<<"The word you entered does not exist make sure to check the\n";
	align_center();
	cout<<"\t   spelling or use the add word feature\n";
}
