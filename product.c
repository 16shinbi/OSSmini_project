#include "product.h"

int addProduct(Product *s){     
	printf("상품명은?");     
	scanf(" %[^\n]", s->name); 
 
    	printf("중량은?");     
	scanf(" %d", &s->weight); 
 
    	printf("가격은?");     
	scanf(" %d", &s->price); 
 
    	printf("10g 당 표준가격은?");     
	scanf(" %d", &s->s_price); 
 
    	printf("별점수는? (1-5)");     
	scanf(" %d", &s->score); 
 
    	printf("=>추가됨\n\n");     
	return 1; 
} 
 
int updateProduct(Product *s){     	
	printf("상품명은?");     
	scanf(" %[^\n]", s->name); 
 
    	printf("중량은?"); 
    	scanf(" %d", &s->weight); 
 
   	printf("가격은?");     
	scanf(" %d", &s->price); 
 
    	printf("10g 당 표준가격은?");     
	scanf(" %d", &s->s_price); 
 
    	printf("별점수는? (1-5)");     
	scanf(" %d", &s->score);     
	printf("=>수정됨\n\n");     
	return 1; 
} 
 
void listProduct(Product *s[],int count){     
	printf("=========================================================== =====\n");     
	for(int i=0 ; i<count ; i++){
		if(s[i] != NULL){
	printf("%d %15s %10d %10d %10d %10d \n",i+1,  s[i]->name, s[i]->weight, s[i]->price, s[i]->s_price, s[i]->score);     
	printf("=========================================================== =====\n");     
		}	
	}
	printf("\n"); 

} 
 
int deleteProduct(Product *s){     
	s->weight =-1;     
	s->price =-1;     
	s->s_price =-1;     
	s->score =-1;     
	return 1; 
}

void saveData(Product *s[], int count){
	FILE *fp;
	fp = fopen("Menu.txt", "wt");
	for(int i=0 ; i<count ; i++){
		fprintf(fp, "%s %d %d %d %d",s[i]->name, s[i]->weight, s[i]->price, s[i]->s_price, s[i]->score);
	}
	printf("저장됨\n");
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
		fscanf(fp, "%s %d %d %d %d",s[count]->name, &s[count]->weight, &s[count]->price, &s[count]->s_price, &s[count]->score); 
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("=>로딩성공\n");
	return count;
}
