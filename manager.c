#include "manager.h"
#include "product.h"

int selectDataNo(Product *s[], int count){
	int no;
	printf("번호는?(취소:0)");
	scanf("%d", &no);
	return no;
}
void readProduct(Product s){
	if(s.weight == -1 && s.price == -1 && s.s_price == -1 && s.score == -1) return;

	printf("%10s %5d %5d %5d %5d\n", s.name, s.weight, s.price, s.s_price, s.score);                                                                   
}

void searchName(Product *s[], int count){
	int scount = 0;
	char search[20];

	printf("검색할 상품명?");
	scanf(" %s", search);

	printf("=======================================\n");
	 printf("No  상품명  가격  중량  가격(10g)  별점\n");

	for(int i=0 ; i<count ; i++){
		if(s[i]->weight != -1){
			if(strstr(s[i]->name, search)){
				printf("%2d", i+1);
				readProduct(*s[i]);
				scount++;
			}
		}
	}
	if(scount == 0) printf("=>검색할 데이터 없음\n");
	printf("\n");
}

void searchscore(Product *s[], int count){
	int scount = 0;
	int search;

	printf("검색할 별점?\n");
	scanf(" %d", &search);

	printf("=======================================\n");
	 printf("No  상품명  가격  중량  가격(10g)  별점\n");

	for(int i=0 ; i<count ; i++){
		if(s[i]->weight != -1){
			if(s[i]->score == search){
				printf("%2d", i+1);
				readProduct(*s[i]);
				scount++;
			}
		}
	}
	if(scount == 0) printf("=>검색할 데이터 없음\n");
	printf("\n");
}

void searchPrice(Product *s[], int count){
	int scount = 0;
	int search;

	printf("검색할 가격?\n");
	scanf(" %d", &search);

	printf("=======================================\n");
	 printf("No  상품명  가격  중량  가격(10g)  별점\n");
	 for(int i=0 ; i<count ; i++){
		if(s[i]->weight != -1){
			if(s[i]->price == search){
				printf("%2d", i+1);
				readProduct(*s[i]);
				scount++;
			}
		}
	}
	if(scount == 0) printf("검색할 데이터 없음\n");
	printf("\n");
}

void saveData(Product *s[], int count){
        FILE *fp;
        fp = fopen("Menu.txt", "wt");
        for(int i=0 ; i<count ; i++){
                fprintf(fp, "%s %d %d %d %d\n",s[i]->name, s[i]->weight, s[i]->price, s[i]->s_price, s[i]->score);
        }
        printf("저장됨\n\n");
}

int loadData(Product *s[]){
        int count = 0;
        FILE *fp;
        fp = fopen("Menu.txt", "rt");
        if(fp ==NULL){
                printf("파일없음\n");
                return 0;
        }
        for(;;count++){
                fscanf(fp, "%s %d %d %d %d\n",s[count]->name, &s[count]->weight, &s[count]->price, &s[count]->s_price, &s[count]->score);
                if(feof(fp)) break;
        }
        fclose(fp);
        printf("=>로딩성공\n\n");
        free(p[curcount]);
	return count;
}

