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
	printf("No  상품명   중량   가격  표준가격  별점\n");
	printf("=======================================\n");     
	for(int i=0 ; i<count ; i++){
		if(s[i] != NULL){
	printf("%2d %10s %5d %5d %5d %5d \n", i+1,  s[i]->name, s[i]->weight, s[i]->price, s[i]->s_price, s[i]->score);          
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
