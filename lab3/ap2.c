#include <stdio.h>
#include <stdlib.h>
void main()
{
int list[5]; //정수형 배열 list의 크기 5
int *plist[5]; //포인터 배열 plist의 크기 
list[0] = 10; //list의 첫번쨰값은 10
list[1] = 11; //list의 두번째값은 11
plist[0] = (int*)malloc(sizeof(int)); //plist 의 첫번쨰에 정수에 대한 포인터를 저장
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
printf("list[0] \t= %d\n", list[0]); //list의 첫번째 값은 10
printf("list \t\t= %p\n", list); //list의 첫번째 %p 포인터 주소를 나타낸다
printf("&list[0] \t= %p\n", &list[0]);//list의 첫번째 주소를 나타낸다
printf("list + 0 \t= %p\n", list+0);//list의 첫번째 순서에 0 을 더했으로 첫번째 주소를 나타낸다
printf("list + 1 \t= %p\n", list+1);//list의 첫번째 순서에 1 을 더했으므로 두번째 주소를 나타낸다
printf("list + 2 \t= %p\n", list+2);//list의 첫번째 순서에 2 을 더했으므로 세번째 주소를 나타낸다
printf("list + 3 \t= %p\n", list+3);//list의 첫번째 순서에 3 을 더했으므로 네번째 주소를 나타낸다
printf("list + 4 \t= %p\n", list+4);//list의 첫번째 순서에 4 을 더했으므로 다섯번째 주소를 나타낸다
//여기서 주소값이 4씩 차이나는 이유는 정수형 int 의 크기는 4비트이기 때문이다.
printf("&list[4] \t= %p\n", &list[4]); //list 의 크기는 5 이고 배열은 0부터 시작하므로 5번째 주소를 나타낸다
free(plist[0]);
}