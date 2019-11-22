#include <stdio.h>
#include <stdlib.h>
#define NUM 64
typedef char *MemberName;
typedef struct family *FamilyMember;
typedef struct family {
    MemberName name;
    int sex;
    double birthdayDate;
    int count;
    FamilyMember left;
    FamilyMember right;
} Family;

FamilyMember familyCreate(MemberName,int,double);

int familyGetHeight(FamilyMember);

void printFamily(FamilyMember);

//void familyOrder(FamilyMember, char, int);

void printFamilyMember(FamilyMember);

void AddFamilyMember(FamilyMember);

void modiFamilyMember(FamilyMember);

void delFamilyMember(FamilyMember);

void printMemberDate(FamilyMember);
