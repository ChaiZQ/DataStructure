#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc,char**argv){
    string str;
    getline(cin,str);
    int max_='z'-'A';
    vector<int> vote_list;
    vote_list.resize(max_+1);
    char out;
    for(int i=0;i<str.length();++i){
        int curr=str[i]-'a';
		if (curr < 0)continue;
        if(curr>max_)continue;
        if(++vote_list[curr]>=3){
            out=str[i];
            break;
        }
    }
    cout<<out;
    
    return 0;
}