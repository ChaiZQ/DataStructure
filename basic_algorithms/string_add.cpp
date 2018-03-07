#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool char_add(char* a, char* b, bool overflow){
    int num1=*a-'0';
    int num2=*b-'0';
    int res = num1+num2+overflow;
    int over_res=false;
    if(res>=10){
        res%=10;
        over_res=true;
    }
    *a=res+'0';
    return over_res;
}
int main(int argc,char**argv){

    string str1,str2;
    while(cin>>str1>>str2){
        int max_len,min_len;
        if(str1.length()>str2.length()){
            max_len=str1.length();
            min_len=str2.length();
        }
        else{
            max_len=str2.length();
            min_len=str1.length();
        }
        string result;
        result.resize(max_len+1);
        bool over_res=false;
        int i=0;
        for(;i<max_len;++i){
            char a='0',b='0';
            if(str1.length()-1>=i)
				a = str1[str1.length()-1-i];
            if(str2.length()-1>=i)
           		b = str2[str2.length()-1-i];
            if(a<'0'||a>'9'||b<'0'||b>'9')
                {
                cout<<"Error"<<endl;
                break;
            }
            over_res = char_add(&a,&b,over_res);
            result[result.length()-1-i]=a;
        }
        if(i==max_len){
            if(over_res)
                result[0]='1';
            else
                result.erase(result.begin());
            cout<<result<<endl;
        }
        
    }
	system("pause");
    return 0;
}