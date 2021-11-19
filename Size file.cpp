#include <iostream>  
#include <Windows.h>  
using namespace std;  
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
void fontsize(int a, int b)
{  
  PCONSOLE_FONT_INFOEX changefontobj = new CONSOLE_FONT_INFOEX();  
  changefontobj->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, changefontobj);  
  changefontobj->dwFontSize.X = a;  
  changefontobj->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, changefontobj); 
 }  

