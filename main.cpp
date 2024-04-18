#include<bits/stdc++.h>
using namespace std;

/*
dict volume: Sum<x=1, n>[(char_candidates_length)^x * (x+2)] bytes
char_candidates_length:
    36: lower cases and numbers
    62: lower&upper cases and numbers
    92: all printable characters (except for " and \ )
*/

const int char_candidates_length=92;
const char char_candidates[100]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()_+{}|:<>?-=[];',./ ";
int string_length, current_length, current_pos;
char string_candidate[20];
FILE* dictfile;

void ostring(){
    for(int i=1;i<=current_length;i++){
        // putchar(string_candidate[i]);
        fputc(string_candidate[i],dictfile);
    }
    // putchar('\n');
    fputc('\n',dictfile);
    return;
}

void generate(){
    if(current_pos>current_length){
        ostring();
        return;
    }
    current_pos++;
    for(int i=0;i<char_candidates_length;i++){
        string_candidate[current_pos-1]=char_candidates[i];
        generate();
    }
    // string_candidate[current_pos-1]=NULL;
    current_pos--;
    return;
}

int main(){
    dictfile=fopen("passdict.dict","w");
    cout<<"Length:";
    cin>>string_length;
    for(current_length=1;current_length<=string_length;current_length++){
        current_pos=1;
        generate();
    }
    return 0;
}
