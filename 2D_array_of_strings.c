#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
void solve(){
    int nrow,ncolumn;
    printf("Enter number of rows:");
    scanf("%d",&nrow);
    printf("Enter number of columns:");
    scanf("%d",&ncolumn);
   char *name[nrow][ncolumn];
   for(int row=0;row<nrow;row++){
    for(int column=0;column<ncolumn;column++){
        name[row][column]=(char*)malloc(51*sizeof(char));
    }
   }
   for(int row=0;row<nrow;row++){
    for(int column=0;column<ncolumn;column++){
        printf("Name at (%d,%d):",row,column);
        scanf("%s",name[row][column]);
    }
    printf("\n");
   }
   int first_letter_vowel=0;
   int longest_name_length=INT_MIN;
   char *ans=" ";
   printf("2D array of names is:\n");
   for(int row=0;row<nrow;row++){
    for(int column=0;column<ncolumn;column++){
         if(name[row][column][0]=='a' ||name[row][column][0]=='e'||name[row][column][0]=='i'||name[row][column][0]=='o'||name[row][column][0]=='u'||name[row][column][0]=='A'||name[row][column][0]=='E'||name[row][column][0]=='I'||name[row][column][0]=='O'||name[row][column][0]=='U'){
         first_letter_vowel++;
       }
       int n=strlen(name[row][column]);
       if(longest_name_length<n){
        longest_name_length=n;
        ans=name[row][column];
       }
        printf("%s ",name[row][column]);
    }
    printf("\n");
   }
   printf("Number of names starting with a vowel:%d\n",first_letter_vowel);
   printf("Longest name : %s",ans);
   
 

}
int main(){
    solve();
    return 0;
}