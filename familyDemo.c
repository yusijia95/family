//
// Created by edz on 2019/10/16.
//
#include "family.h"
#include <string.h>
//const char family[]="family1";
int main(void) {
    int no;
    FamilyMember root = familyCreate("A",1,20191016);
//    FILE *fp;
//    fp = fopen("/Users/edz/project/family/.family", "w");
    printf("欢迎来到家谱管理理系统!\n1. 显示家谱图\n2. 根据姓名查询，输出成员信息\n3. 给某个成员添加孩⼦子\n4. 修改某个成员信息\n5. 删除某成员(连同其后代)\n6. 按出⽣生⽇日期增顺显示家族成员\n7. 退出系统\n");
    while ((no = getchar()) != '7'){
        switch (no) {
            case '1':printFamily(root);
                break;
            case '2':printFamilyMember(root);
                break;
            case '3':AddFamilyMember(root);
                break;
            case '4':modiFamilyMember(root);
                break;
            case '5':delFamilyMember(root);
                break;
            case '6':printMemberDate(root);
                break;
//            case '7':;
//                break;
            default:
                break;
        }
    }
    free(root->name);
    free(root);
    return 0;
}