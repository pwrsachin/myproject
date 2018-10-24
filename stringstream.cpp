#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
   if(s[8]=='p'){
     stringstream ss1(s);
       int hh,mm,ss;
       char ch;
       
       ss1>>hh>>ch>>mm>>ch>>ss;
       stringstream str1;
       if(hh!=12){
            hh=12+hh;
           
          
           str1<<setw(2)<<setfill('0')<<hh<<ch<<setw(2)<<setfill('0')<<mm<<ch<<setw(2)<<setfill('0')<<ss;
       }
           else{
               str1<<hh<<":"<<mm<<":"<<ss;
           }
           return str1.str();
       }
      
    else{
         stringstream ss1(s);
       int hh,mm,ss;
       char ch;
       
       ss1>>hh>>ch>>mm>>ch>>ss;
        
      stringstream str1;
       
        
           if(hh==12){
           	
           	hh=0;
           	
           	str1<<setw(2)<<setfill('0')<<hh<<ch<<setw(2)<<setfill('0')<<mm<<ch<<setw(2)<<setfill('0')<<ss;
           	
           	return str1.str();
		   }
        str1<<setw(2)<<setfill('0')<<hh<<ch<<setw(2)<<setfill('0')<<mm<<ch<<setw(2)<<setfill('0')<<ss;
        return str1.str();
    

}
}

int main()
{
	cout<<"enter the time in dd:mm:ssPM or AM \n";

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout<<result<<"\n";

    return 0;
}

