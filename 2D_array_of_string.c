    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<limits.h>
    #include<stdbool.h>
    void Name_calculate(char ***name,int nrow,int ncolumn){
    int first_letter_vowel=0;
    int longest_name_length=INT_MIN;
    char *ans=" ";
    printf("2D array of names is:\n");
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            if(name[row][column][0]=='a' ||name[row][column][0]=='e'||name[row][column][0]=='i'||name[row][column][0]=='o'||name[row][column][0]=='u'||name[row][column][0]=='A'||name[row][column][0]=='E'||name[row][column][0]=='I'||name[row][column][0]=='O'||name[row][column][0]=='U'){
            first_letter_vowel++;
        }
        int length=strlen(name[row][column]);
        if(longest_name_length<length){
            longest_name_length=length;
            ans=name[row][column];
        }
            printf("%s ",name[row][column]);
        }
        printf("\n");
    }
    printf("Number of names starting with a vowel:%d\n",first_letter_vowel);
    printf("Longest name : %s",ans);
    }
    bool solve_string(char ***name,int nrow,int ncolumn){
         bool isValidString=true;
    for(int row=0;row<nrow;row++){
        for(int column=0;column<ncolumn;column++){
            printf("Name at (%d,%d):",row,column);
            scanf("%s",name[row][column]);
            int length=strlen(name[row][column]);
            if(length>50){
            isValidString=false;
                break;
            }
        }
        printf("\n");
    }
    if(!isValidString){
        printf("string with a maximum length of 50 characters is allowed only");
        return false;
    }
    else{
        Name_calculate(name,nrow,ncolumn);
    }
    return isValidString;
    }
    void solve(){
        int nrow,ncolumn;
    
        printf("Enter number of rows:");
        scanf("%d",&nrow);
        printf("Enter number of columns:");
        scanf("%d",&ncolumn);
        if(nrow>=1 && nrow<=10 && ncolumn>=1 && ncolumn<=101){
    // char *name[nrow][ncolumn];
    char ***name=(char***)malloc(nrow*sizeof(char**));
    for(int row=0;row<nrow;row++){
        name[row]=(char**)malloc(ncolumn*sizeof(char*));
        for(int column=0;column<ncolumn;column++){
            name[row][column]=(char*)malloc(51*sizeof(char));
        }
    }
       bool isvalid=solve_string(name,nrow,ncolumn);
        }
        else{
            printf("Rule:\n");
            printf("1.Number of row should be >=1 && <=10\n");
            printf("2.Number of column should be >=1 && <=10\n");
        }
    }
    int main(){
        solve();
        return 0;
    }