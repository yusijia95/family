//
// Created by edz on 2019/10/16.
//
#include "family.h"
#include <string.h>

#define NUMBER 64
char arr[NUMBER];
double arr3[100][100];

FamilyMember familyCreate(MemberName name, int sex, double birthdayDate) {
    int count = 1;
    FamilyMember rlt = (FamilyMember) malloc(sizeof(Family));
//    rlt->name = name;
    rlt->name = (MemberName) malloc(8 * sizeof(double));
    strcpy(rlt->name, name);
    rlt->sex = sex;
    rlt->birthdayDate = birthdayDate;
    rlt->count = count;
    rlt->right = NULL;
    rlt->left = NULL;
    return rlt;
}

int familyGetHeight(FamilyMember node) {
    int deep = 0;
    if (node != NULL) {
        int leftdeep = familyGetHeight(node->left);
        int rightdeep = familyGetHeight(node->right);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep;
    }
    return deep;
}

void print(FamilyMember node, int num) {
//    int deepNum = 0;
//    int leftdeep, rightdeep;
//        if (familyGetHeight(node->left) < familyGetHeight(node->right)) {
//            if (num > 0 && (node->right != NULL || node->left != NULL)) { num--; }
//        }
//        int leftdeep = print(node->left, no, num);
//        if (leftdeep != 0) { num = leftdeep; }
//        int rightdeep = print(node->right, no, num);
//        if (num > 0 && leftdeep >= rightdeep) {
//            rightdeep = num + 1;
//        deepNum = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep;
//        int num = print(node->left, no, ++num);
//        num = print(node->right, no, ++num);
//        num--;
//        deepNum = num;
//    }
//    if (deepNum == no) {
//        printf("姓名：%s，性别：%d，出生日期：%6.0f，孩子：", node->name, node->sex, node->birthdayDate);
//        if (node->left != NULL) {
//            printf("%s  ", node->left->name);
//            node = node->left;
//            while (node->right != NULL) {
//                printf("%s  ", node->right->name);
//                node = node->right;
//            }
//        }
//        putchar('\n');
    if (node != NULL) {
        if (node->count == num + 1) {
            printf("姓名：%s，性别：%d，出生日期：%6.0f，孩子：", node->name, node->sex, node->birthdayDate);
            if (node->left != NULL) {
                printf("%s  ", node->left->name);
                node = node->left;
                while (node->right != NULL) {
                    printf("%s  ", node->right->name);
                    node = node->right;
                }
            }
            putchar('\n');
        }
        print(node->left, num);
        print(node->right, num);
    }
}

void printFamily(FamilyMember node) {
    int deep = familyGetHeight(node);
    for (int i = 0; i < deep; i++) {
        printf("第%d代：\n", i + 1);
        print(node, i);
    }
}

void familyOrder(FamilyMember node, char arr[], int n) {
    if (node == NULL) {
        return;
    }
    if (strcmp(arr, node->name) == 0) {
        printf("姓名：%s,性别：%d,出生日期：%6.0f\n", node->name, node->sex, node->birthdayDate);
        while (node->left != NULL) {
            printf("%s", node->name);
            node = node->left;
        }
        return;
    }
    familyOrder(node->left, arr, n);
    familyOrder(node->right, arr, n);
    if (node->name == "A") {
        printf("查无此人");
    }
}

void printFamilyMember(FamilyMember node) {
//    char arr[NUMBER];
    printf("请输入姓名：");
    scanf("%s", arr);
    familyOrder(node, arr, NUMBER);
}

void addFamilyOrder(FamilyMember node, char arr[], int n, int num) {
    int sex;
    double date;
    if (node == NULL) {
        return;
    }
    if (strcmp(arr, node->name) == 0) {
        if (node->left == NULL) {
            printf("请输入第1位成员姓名,请输⼊入成员性别,请输⼊入成员出⽣日期\n");
            scanf("%s", arr);
            scanf("%d", &sex);
            scanf("%lf", &date);
            node->left = familyCreate(arr, sex, date);
            node->left->count = node->count + 1;
            node = node->left;
            for (int i = 0; i < num - 1; i++) {
                printf("请输入第%d位成员姓名,请输⼊入成员性别,请输⼊入成员出⽣日期\n", i + 2);
                scanf("%s", arr);
                scanf("%d", &sex);
                scanf("%lf", &date);
                node->right = familyCreate(arr, sex, date);
                node->right->count = node->count;
                node = node->right;
            }
            printf("添加完成\n");
        } else {
            node = node->left;
            while (node->right != NULL) {
                node = node->right;
            }
            for (int i = 0; i < num; i++) {
                printf("请输入第%d位成员姓名,请输⼊入成员性别,请输⼊入成员出⽣日期\n", i + 1);
                scanf("%s", arr);
                scanf("%d", &sex);
                scanf("%lf", &date);
                node->right = familyCreate(arr, sex, date);
                node->right->count = node->count;
                node = node->right;
            }
            printf("添加完成\n");
        }

        return;
    }
    addFamilyOrder(node->left, arr, n, num);
    addFamilyOrder(node->right, arr, n, num);
    if (node->name == "A") {
        printf("添加失败");
    }
}

void AddFamilyMember(FamilyMember node) {
    int num;
    printf("请输入成员名字：");
    scanf("%s", arr);
    printf("请问添加几个孩子：");
    scanf("%d", &num);
    addFamilyOrder(node, arr, NUMBER, num);
}

void modifamily(FamilyMember node, char arr[], int n) {
    if (node == NULL) {
        return;
    }
    if (strcmp(arr, node->name) == 0) {
        printf("请输入成员姓名：");
        scanf("%s", node->name);
        printf("请输入成员性别：");
        scanf("%d", &(node->sex));
        printf("请输入成员出生日期：");
        scanf("%lf", &(node->birthdayDate));
        printf("修改成功\n");
        return;
    }
    modifamily(node->left, arr, n);
    modifamily(node->right, arr, n);
    if (node->name == "A") {
        printf("查无此人");
    }
}

void modiFamilyMember(FamilyMember node) {
    printf("请输入成员名字：");
    scanf("%s", arr);
    modifamily(node, arr, NUMBER);
}

void delfamilychild(FamilyMember node) {
    if (node == NULL) {
        return;
    }
    delfamilychild(node->left);
    delfamilychild(node->right);
    node->name = NULL;
    node->birthdayDate = '\0';
    node->sex = NULL;
    node->count = NULL;
    node->left = NULL;
    node->right = NULL;
    free(node);
}

void delfamily(FamilyMember node, char arr[], int n) {
    if (node == NULL) {
        return;
    }
    if (strcmp(arr, node->left->name) == 0) {
        delfamilychild(node->left->left);
        node->left = node->left->right;
        free(node->left);
        printf("删除成功\n");
        return;
    }
    if (strcmp(arr, node->right->name) == 0) {
        delfamilychild(node->right->left);
        node->right = node->right->right;
        free(node->right);
        printf("删除成功\n");
        return;
    }
    delfamily(node->left, arr, n);
    delfamily(node->right, arr, n);
    if (node->name == "A") {
        printf("查无此人");
    }
}

void delFamilyMember(FamilyMember node) {
    printf("请输入成员名字：");
    scanf("%s", arr);
    delfamily(node, arr, NUMBER);
}

void swap(int *a, int *b) {
    int temp;
    int *pa = &a;
    int *pb = &b;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void quicksort(int array[], int maxlen, int begin, int end) {
    int i, j;
    if (begin < end) {
        i = begin + 1;
        j = end;
        while (i < j) {
            if (array[i] > array[begin]) {
                swap(&array[i], &array[j]);
                j--;
            } else { i++; }
        }
        if (array[i] >= array[begin]) { i--; }
        swap(&array[begin], &array[i]);
        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}

void sortBirthday(FamilyMember node, int *num, int i) {
    if (node != NULL) {
        if (node->count == i + 1) {
            arr3[*num][100] = node->birthdayDate;
            *num = *num + 1;
        }
        sortBirthday(node->left, &num, i);
        sortBirthday(node->right, &num, i);
    }
}

int printDate(FamilyMember node, int *no) {
    if (node != NULL) {
        if (node->birthdayDate == arr3[*no][100]) {
            printf("姓名：%s，性别：%d，出生日期：%6.0f，孩子：", node->name, node->sex, node->birthdayDate);
            if (node->left != NULL) {
                printf("%s  ", node->left->name);
                node = node->left;
                while (node->right != NULL) {
                    printf("%s  ", node->right->name);
                    node = node->right;
                }
            }
            putchar('\n');
            *no = *no + 1;
        }
        printDate(node->left, &no);
        printDate(node->right, &no);
    }
}

void printMemberDate(FamilyMember node) {
    int deep = familyGetHeight(node);
    int num = 0;
    int no = 0;
    for (int i = 0; i < deep; i++) {
        printf("第%d代：\n", i + 1);
        sortBirthday(node, &num, i);
        for (int i = 0; i < num; i++) {
            printf("%lf\n", arr3[i]);
        }
        quicksort(arr3, 100, 0, num);
        for (int i = 0; i < num; i++) {
            printf("%lf\n", arr3[i]);
        }
        printDate(node, &no);
    }
}
