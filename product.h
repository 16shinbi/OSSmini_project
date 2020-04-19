#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[20];      //제품명
    int weight;     //중량
    int price;      //가격
    int s_price;        //표준가격
    int score;      //별점수
}Product;

Product *sp[100];
int curcount;
int count;
int menu;
int addProduct(Product *s);     //제품을 추가하는 함수
int updateProduct(Product *s);      //수정하는 함수
void readPorudct(Product s);
void listProduct(Product *s[], int count);      //읽어온 데이터를 리스트로 출력하는 함수 
int deleteProduct(Product *s);      //삭제하는 함수
void saveData(Product *s[], int count);     //file저장하는 함수
int loadData(Product *s[]);     //file불러오는 함수
void searchName(Product *s[], int count);       //이름검색기능함수
void searchscore(Product *s[], int count);      //별점수검색기능함수
//void searchPrice(Product *s[], int count);      //가격검색기능함수
