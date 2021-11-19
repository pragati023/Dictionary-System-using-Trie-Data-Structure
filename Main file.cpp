#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include"D:\vs_code\dsa project\trieclass.cpp"
#include"D:\vs_code\dsa project\formatting file.cpp"
using namespace std;
void print_word_list(vector<string> list,int idx,string compare)
{	int val=0;
	for(int i=0;i<list.size();i++)
  	{ 
	auto found=list[i].find(compare);
  	if(found!=string::npos)
  	{   
  		if(found==0 || list[i]==compare)
  		{    val++;
  		
		  	align_center();
		if(i==idx || list[i]==compare || i==list.size()-1 && val==1)
		{cout<<Change_color_to("GREEN")<<list[i]<<endl;
		idx=i;
	    }
		else 
		cout<<Change_color_to("RED")<<list[i]<<endl;
	}

	}

}
}
int main()
{  
	int c;
	char ch;
	
	vector<string> word_list;
	trie dictionary;
	fontsize(40,40);
	dictionary.insert("apple","A type of fruit");
	dictionary.insert("application","the practical use (of something)");
	dictionary.insert("applaud","to express approval of something");
	dictionary.insert("abhor","hate");
	dictionary.insert("audience","people who are watching someone perform");
	dictionary.insert("baffled","confused");
	dictionary.insert("benevolent","friendly and helpful to others");
	dictionary.insert("candour","the quality of being honest");
	dictionary.insert("candid","saying exactly what you think");
	cout<<Change_color_to("RED");
	print_intial_page();
	align_center();
    print_exit_next("left");
	bool counter_next=0;
	bool counter_update=0;
	bool counter_search=0;
	int idx=0;
	bool escape_pressed=0;
	cout<<endl;

	
   string m;
    while(1)//intial page loop
    {
    	c=getch();
    	if(c==224)
    	{
    		int a;
    		a=getch();
    		if(a==75)
            {
            	counter_next=0;
    			system("CLS");
    			print_left();

			}
			else if(a==77)
			{
				counter_next=1;
    			system("CLS");
    			print_right();
				
			}
		}
		else if(c==13)
		{
		   
		     if(counter_next==1)//user wants to go ahead
			 {
			 	 system("CLS");
    		 add_or_search("add");
    		 
    		 while(1)
    		 {	
			 c=getch();//user chosing add or search
				
				if(c==224)
				{
					int b;
					b=getch();
					if(b==72)//go up
					{
						counter_search=0;
						system("CLS");
						add_or_search("add");
					}
					else if(b==80)//go down
					{
					    counter_search=1;
						system("CLS");
						add_or_search("update");	
					}
					
				}
		        else if(c==13)
		        {
		        	if(counter_search==1)//user wants to search
		        	{
		        		string word;
              	string meaning;
				system("CLS");
				shift_down();
				align_center();
				print_enter_word();
				c=getch();
				ch=char(c);
				word+=ch;
				trienode*temp=dictionary.return_node(ch);
				vector<string> suggestion_list;
				string str;
				dictionary.suggestions(temp,str,suggestion_list);
								
				cout<<Change_color_to("YELLOW")<<" "<<word<<endl;
				cout<<endl;
				int als=suggestion_list.size();	
				print_word_list(suggestion_list,idx,word);
						
			while(1)//searching a word loop begins
				{   
				label:
				escape_pressed=0;
					c=getch();
				    
				    if(c==27)
				    {
    		      system("CLS");
    		      add_or_search("add");
    		      counter_search=0;
    		      break;	
				    }
					else if(c==224)
					{  
						int x;
						x=getch();
						if(x==72)
						{
							if(idx>0)
							idx--;
							else
							idx=als-1;
							
							system("CLS");
							shift_down();
							align_center();
							print_enter_word();
							cout<<Change_color_to("YELLOW")<<" "<<word<<endl;
							cout<<endl;

							print_word_list(suggestion_list,idx,word);
							
						}
						else if(x==80)
						{
							idx=(idx+1)%als;
							system("CLS");
							shift_down();
							align_center();
							print_enter_word();
							cout<<Change_color_to("YELLOW")<<" "<<word<<endl;
							cout<<endl;
							print_word_list(suggestion_list,idx,word);
							
						}
					}
					else if(isalpha(c))//alphabet is pressed
					{
						ch=char(c);
		                 word+=ch;
		                 system("CLS");
							shift_down();
							align_center();
							print_enter_word();
							cout<<Change_color_to("YELLOW")<<" "<<word<<endl;
							cout<<endl;
							print_word_list(suggestion_list,idx,word);

					}
					else if(c==8 && word.length()!=0)//backspace pressed
					{
						word.erase(word.length()-1);
						if(word.length()==0)
						{
								system("CLS");
				shift_down();
				align_center();
				print_enter_word();
				
				c=getch();
				ch=char(c);
				word+=ch;
				trienode*temp=dictionary.return_node(ch);
			suggestion_list.clear();
				str.erase();
				dictionary.suggestions(temp,str,suggestion_list);		
				cout<<Change_color_to("YELLOW")<<" "<<word<<endl;
				cout<<endl;
				als=suggestion_list.size();	
				print_word_list(suggestion_list,idx,word);
				goto label;
							
						}
						else
						{system("CLS");
							shift_down();
							align_center();
							print_enter_word();
							cout<<Change_color_to("YELLOW")<<" "<<word<<endl;
							cout<<endl;
					
					   
							print_word_list(suggestion_list,idx,word);
						}

					}
					else if(c==13)
					{
						cout<<endl;
					    align_center();
                        string pr;
        
					if(dictionary.search(word,meaning))
					{
						cout<<Change_color_to("RED")<<word<<" means "<<Change_color_to("YELLOW")<<meaning<<endl;
						pr=word;
					
					}
					else if(suggestion_list.size()!=0 && dictionary.search(suggestion_list[idx%als],meaning) && suggestion_list[idx%als][0]==word[0])
					{
					cout<<Change_color_to("RED")<<suggestion_list[idx]<<" means "<<Change_color_to("YELLOW")<<meaning<<endl;
					pr=suggestion_list[idx];
					
					}
					else
					{
					   system("CLS");
					   Word_not_found();
					   int g=getch();
					   break;
					   
					}
					
					cout<<endl;
					align_center();
					cout<<Change_color_to("RED")<<"Are you satisfied with the meaning provided"<<"\n";
					align_center();
					cout<<"or do you wish to change it"<<"\n";
					yes_no("no");
        
                  while(1)
                  {
				  c=getch();
                  
                  if(c==224)
                  {
                  	int e;
						e=getch();
						if(e==75)//left arrow pressed
						{  counter_update=1;
						    system("CLS");
						    shift_down();
							align_center();
							print_enter_word();
							cout<<Change_color_to("RED")<<" "<<word<<endl;
							cout<<endl;
					
							print_word_list(suggestion_list,20,word);
							cout<<endl;
							align_center();
					cout<<Change_color_to("RED")<<pr<<" means "<<Change_color_to("YELLOW")<<meaning<<"\n\n";
					align_center();
						cout<<Change_color_to("RED")<<"Are you satisfied with the meaning provided"<<endl;
							align_center();
							cout<<"or do you wish to change it"<<endl;
							yes_no("yes");
						}
						else if(e==77)
						{
							counter_update=0;
						
	                       system("CLS");
	                       shift_down();
							align_center();
							print_enter_word();
							cout<<Change_color_to("RED")<<" "<<word<<endl;
							cout<<endl;
					
							print_word_list(suggestion_list,20,word);
							cout<<endl;
							align_center();
	                       cout<<Change_color_to("RED")<<pr<<" means "<<Change_color_to("YELLOW")<<meaning<<"\n\n";
	                       align_center();
							cout<<Change_color_to("RED")<<"Are you satisfied with the meaning provided"<<endl;
							align_center();
							cout<<"or do you wish to change it"<<endl;
							yes_no("no");
							
						}
						
					}
				  else if(c==13)//enter is pressed
				  {  
				  
				     if(counter_update==1)
				     {
				        string new_mean;
				system("CLS");
				shift_down();
				align_center();
				cout<<Change_color_to("RED")<<"The word you entered was "<<pr<<"\n\n";
				align_center();
					cout<<Change_color_to("RED")<<"Enter the new meaning of the word :";
					cout<<Change_color_to("YELLOW");
						getline(cin,new_mean,'\n');
						cout<<"\n";
					align_center();
					dictionary.update(pr,new_mean);
					cout<<Change_color_to("RED")<<"Meaning updated successfully";
					int t=getch();
				   break;
                    
				}
				else
				{ 
				   if(word.length()!=0)
					word.erase();
					
				system("CLS");
				shift_down();
				align_center();
				print_enter_word();
				c=getch();
				escape_pressed=0;
				if(c==27)
				{
					escape_pressed=1;
				break;
			}
				ch=char(c);
				word+=ch;
				trienode*temp=dictionary.return_node(ch);
				suggestion_list.clear();
				str.erase();
				dictionary.suggestions(temp,str,suggestion_list);
								
				cout<<Change_color_to("RED")<<" "<<word<<endl;
				cout<<endl;
				als=suggestion_list.size();	
				print_word_list(suggestion_list,idx,word);
				break;
			
				}
                  	
				  }
					}
			
		        }
		       // cout<<escape_pressed<<endl;
		        if(escape_pressed==1)
		        {
		        	counter_search=0;
						system("CLS");
						add_or_search("add");
		        
		        break;
		    }
		    }
		}
					else//user wants add a word
					{
				   	while(1)
				   	{
				system("CLS");
				shift_down();
				align_center();
                cout<<Change_color_to("RED")<<"Enter the word you want to add: ";
				string w;
				string m;
				cout<<Change_color_to("YELLOW");
				cin>>w;
				cin.get();
	          //  cout<<"\n";
				align_center();
				cout<<Change_color_to("RED")<<"Enter its meaning: ";
				cout<<Change_color_to("YELLOW");
				cin.get();
				getline(cin,m,'\n');
				dictionary.insert(w,m);
				cout<<"\n";
				align_center();
				cout<<Change_color_to("RED")<<"Word added successfully\n\n";
				align_center();
				cout<<"Press escape to return";
				int d=getch();
				if(d==27)
				{  system("CLS");
				counter_search=0;
    		 add_or_search("add");
					break;
				}
}
						
					}
}
						
				else if(c==27)
				{
					system("CLS");
					counter_next=0;
					cout<<Change_color_to("RED");
	print_intial_page();
	align_center();
    print_exit_next("left");
	break;	
					
				}
			 	
			}
		}
				 else //break the main window loop exit the program;
				 break;	
		}
		
}
system("CLS");
shift_down();
shift_down();
align_center();
	cout<<Change_color_to("PURPLE")<<"Thank you for using our dictionary!\n\n";
  align_center();
	system("pause");
}
