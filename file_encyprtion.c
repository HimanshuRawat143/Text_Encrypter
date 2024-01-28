#include<stdio.h>
#include<stdlib.h>
void encrypt(FILE* ptr, FILE* ptr1, int key){
    char ch;
    while((ch=fgetc(ptr))!=EOF){
        ch = ch+key;
        fputc(ch,ptr1);
    }
    clearerr(ptr);
    return; 
}
int main(){
    printf("Enter the Input FIle with specified path: ");
    char FILE_NAME1[100];
    gets(FILE_NAME1);
    FILE* ptr = fopen(FILE_NAME1,"w");
    char content[100];
    printf("Enter the content to write: ");
    fgets(content,sizeof(content),stdin);
    fputs(content,ptr);
    fclose(ptr);
    ptr = fopen(FILE_NAME1,"r");
    char FILE_NAME2[100];
    printf("Enter the new Encypted FIle name with specified path: ");
    gets(FILE_NAME2);
    FILE* ptr1 = fopen(FILE_NAME2,"w");
    if(ptr1==NULL){
        perror("Erorr opening output file! ");
        exit(EXIT_FAILURE);
    }
    int key;
    printf("Enter the hash key: ");
    scanf("%d",&key);
    encrypt(ptr,ptr1,key);
    fclose(ptr);
    fclose(ptr1);
    return 0;
}