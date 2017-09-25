#include <iostream>
#include <string.h>
using namespace std;
int arr[10];
char result[10][5] = { "ZRO ", "ONE ", "TWO ", "THR ", "FOR ", "FIV ", "SIX ", "SVN ", "EGT ", "NIN " };

int main(){
    int tc;
    cin>>tc;
    for(int k=0;k<tc;k++){
        int n;
        string cur;
        for(int j=0;j<10;j++) arr[j] = 0;
        
        cin>>cur>>n;
        
        for(int u=0;u<n;u++){
            
            char str[3];
            cin>>str;
            
            if(!strcmp(str,"ZRO")){
                arr[0]++;
            }
            else if(!strcmp(str,"ONE")){
                arr[1]++;
            }
            else if(!strcmp(str,"TWO")){
                arr[2]++;
            }
            else if(!strcmp(str,"THR")){
                arr[3]++;
            }
            else if(!strcmp(str,"FOR")){
                arr[4]++;
            }
            else if(!strcmp(str,"FIV")){
                arr[5]++;
            }
            else if(!strcmp(str,"SIX")){
                arr[6]++;
            }
            else if(!strcmp(str,"SVN")){
                arr[7]++;
            }
            else if(!strcmp(str,"EGT")){
                arr[8]++;
            }
            else if(!strcmp(str,"NIN")){
                arr[9]++;
            }
        }
        
        cout<<cur<<'\n';
        for(int i=0;i<10;i++){
            int t = arr[i];
            for(int j=0;j<t;j++){
                cout<<result[i];
            }
        }
        cout<<'\n';
        
    }
}
