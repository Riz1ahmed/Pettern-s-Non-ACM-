#include<bits/stdc++.h>
using namespace std;

///Tested inputs:
///E->ABCd|ABC|ABCEF
///E->ABCd|ABCK|ABCEF
///A->def|defgh|dfa
///X->abc|def

int main(){
    int i,j,mn=1e9;
    string String;
    puts("Input a Grammar like E->ABCd|ABC|ABCEF\n");
    cin>>String;
    String+='|';
    char nont=String[0];
    vector<string> States;

    ///Separate the states.
    for (i=3; i<String.size(); i++){
        string sate="";
        while(String[i]!='|')
            sate+=String[i], i++;

        States.push_back(sate);
        mn=min(mn,int(sate.size()));
    }

    ///Find Common string
    int Common,f=0;
    for (Common=0; Common<mn; Common++){
        char c=States[0][Common];
        for (j=0; j<States.size(); j++){
            if (States[j][Common]!=c){
				f=1;
                break;
            }
        }
        if (f) break;
    }
    Common--;
    if (Common==-1) puts("Left factor is impossible for this grammar");
    else{
        printf("%c->",nont);
        for (i=0; i<=Common; i++)
            printf("%c",States[0][i]);
        printf("%c'\n",nont);

        printf("%c'->",nont);
        for (i=0; i<States.size(); i++){
            for (j=Common+1; j<States[i].size(); j++)
                printf("%c",States[i][j]);
            if (States[i].size()!=Common+1)
                printf("|");
        }
        puts("epsilon");
    }
    return 0;
}