#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void gen(string &input,string &output){
    if(input.length()==0){
        ans.push_back(output);
        return;
    }
    string output1 = output+"_"+input[0];
    string output2 = output+input[0];
    string input1 = input.substr(1,input.length()-1);
    gen(input1,output1);
    gen(input1,output2); 
}
int main(){
    string s = "ABCD";
    string input = "BCD";
    string output = "A";
    gen(input,output);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}