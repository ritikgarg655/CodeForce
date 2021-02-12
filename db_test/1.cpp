#include <bits/stdc++.h>
using namespace std;
string solution(string &forth){
    int height=0,width=0;
    string ans="";
    int minwidth=0,maxwidth=0;
    for(int i=0;i<forth.length();i++)
    {
        if(forth[i]=='N'){
            height++;
        }
        else if(forth[i]=='E'){
            width++;
        }
        else{
            width--;
        }
        if(width>maxwidth){
            maxwidth=width;
        }
        if(width<minwidth){
            minwidth=width;
        }
    }
    int sidemove;
    if(abs(minwidth)>maxwidth){
        sidemove=maxwidth;
    }
    else{
        sidemove=minwidth;
    }
    // width = -width;
    minwidth--;
    maxwidth++;
    // if left is less
    // cout<<maxwidth<<" "<<minwidth<<" "<<width;
    // cout<<((width>0)?:abs(width)) + ((width>0)?(2*maxwidth-width):(2*maxwidth));
    if(((width>0)?width:0) + ((width>0)?(2*abs(minwidth)):(2*abs(minwidth)-abs(width))) > (width>0?0:abs(width)) + ((width>0)?(2*maxwidth-width):(2*maxwidth)))
    {
        if(width>0){
            for(int i=0;i<(maxwidth-width);i++){
                ans+='E';
            }
        }
        else{
            for(int i = 0;i<abs(width);i++){
                ans+='E';
            }
            for(int i=0;i<maxwidth;i++){
                ans+='E';
            }
        }
        for(int i=0;i<height;i++){
            ans+='S';
        }
        for(int i=0;i<maxwidth;i++){
            ans+='W';
        }
    }
    else
    {
        // cout<<2;
        if(width>0){
            for(int i = 0;i<abs(width);i++){
                ans+='W';
            }
            for(int i=0;i<abs(minwidth);i++){
                ans+='W';
            }
        }
        else{
            for(int i=0;i<abs(minwidth)-abs(width);i++){
                ans+='W';
            }
        }
        for(int i=0;i<height;i++){
            ans+='S';
        }
        for(int i=0;i<abs(minwidth);i++){
            ans+='E';
        }
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string q;cin>>q;
    cout<<solution(q);
}