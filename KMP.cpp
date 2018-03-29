#include<bits/stdc++.h>
using namespace std;


void computeLPSarray(char *pat , int M, int *txt);

void KMPSearch(char *pat,char *txt){

    int res=0;
    int M=strlen(pat);
    int N=strlen(txt);

    int ret[N];
    int lps[M];

    computeLPSarray(pat,M,lps);

    int i=0;
    int j=0;

    while(i<N){

        ret[i]=j;

        if(pat[j] == txt[i]){


            j++;
            i++;
        }

        if(j==M){
            printf("Found Pattern at index %d \n",i-j);

            res++;
            j=lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i]){

            if(j!=0)
                j = lps[j-1];
            else
                i=i+1;
        }
    }


}


void computeLPSarray(char *pat,int M,int *lps){

    int len=0;
    lps[0]=0;
    int i=1;

    while(i<M){

        if(pat[i]==pat[len]){

            len++;
            lps[i]=len;
            i++;
        }
        else{

            if(len!=0){

                len = lps[len-1];
            }

            else{

            lps[i]=0;
            i++;

            }

        }


    }




}


int main()
{
    char txt[10000],pat[10000];
    scanf("%s",txt);//input text
    scanf("%s",pat);//input matching text/pattern
    KMPSearch(pat,txt);//find match
    return 0;
}
