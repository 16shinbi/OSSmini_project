#include "product.h"
#include "manager.h"
#define DEBUG

int selectMenu(){
    int menu;
    printf("1.조회\n");
    printf("2.추가\n");
    printf("3.수정\n");
    printf("4.삭제\n");
    printf("5.저장\n");
    printf("6.저장불러오기\n");
    printf("7.상품명검색\n");
    printf("0.종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){

//    Product *sp[100];
    int menu;
    int count = 0;
    int curcount;
    
    curcount = count;

    while(1){
        menu = selectMenu();
       if(menu==0) break;
#ifdef DEBUG
	    if(menu==1){
            if(count>0) listProduct(sp, curcount);
           else printf("데이터가 없습니다\n\n");
        }

        else if(menu==2){
           sp[curcount] = (Product *)malloc(sizeof(Product));
            count += addProduct(sp[curcount++]);
        }

        else if(menu==3){
            int no = selectDataNo();
	    if(no == 0){
            	printf("취소됨\n\n");
                continue;
            }
            updateProduct(sp[no-1]);
        }

        else if(menu==4){
	  int no = selectDataNo();
	  if(no == 0){
		printf("취소됨\n\n");
		continue;
	  }
          int deleteok;
          printf("정말로 삭제하시겠습니까?(삭제 1)");
          scanf("%d", &deleteok);
          if(deleteok == 1){
          	if(sp[no-1]) free(sp[no-1]);
		sp[no-1] = NULL;
		count --;
	  }
	}
	else if(menu==5){
	  if(count==0) printf("데이터가 없습니다\n");
	  else {
		sp[curcount] = (Product *)malloc(sizeof(Product));
		saveData(sp, curcount);
		}
	}
	else if(menu==6){
	  loadData(sp);
	  free(sp[curcount]);
	}
	else if(menu==7) searchName(sp, count);
}
    printf("=>종료됨\n");
#endif
    return 0;
}

