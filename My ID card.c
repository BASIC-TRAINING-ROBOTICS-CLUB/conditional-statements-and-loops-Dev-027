#include<stdio.h>
#include<string.h>
struct id{
    int enroll;
    char name[20];
    char dob[20];
    char add[50];
    int sem;
    char branch[20];
    char clg[15];
};

int main(){
    printf("Student ID card\n\n");
    struct id Dev;
    Dev.enroll=95;
    strcpy(Dev.name,"Dev Pandya");
    strcpy(Dev.dob, "27/09/2007");
    strcpy(Dev.add,"Indrabaug society,usmanpura,Ahmedabad-380013");
    Dev.sem=3;
    strcpy(Dev.branch,"IT");
    strcpy(Dev.clg,"R.C. Technical Institute");
    printf("Enrollment Number : %d\n",Dev.enroll);
    printf("Name : %s\n",Dev.name);
    printf("DOB : %s\n",Dev.dob);
    printf("Address : %s\n",Dev.add);
    printf("Semester : %d\n", Dev.sem);
    printf("Branch : %s\n",Dev.branch);
    printf("College : %s\n",Dev.clg);
}