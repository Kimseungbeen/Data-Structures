#include <stdio.h>
#include <stdlib.h>
void main()
{
int list[5];
//정수형 배열 list의 크기 5
int *plist[5] = {NULL,};
//포인터 배열 plist의 크기 5 값은 NULL
plist[0] = (int *)malloc(sizeof(int));
//plist 의 첫번쨰에 정수에 대한 포인터를 저장
list[0] = 1;
//list의 첫번째에 1 할당
list[1] = 100;
//list의 두번쨰에 100 할당
*plist[0] = 200;
//plist의 주소에 첫번째에 200 할당
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
printf("list[0] = %d\n", list[0]); // list[0] 은 첫번쨰 값에 1을 할당했으므로 1
printf("&list[0] = %p\n", &list[0]); // list[0]은 list 의 첫번째를 %p는 주소값을 나타낸다.
printf("list = %p\n", list); // list는 첫번째를 나타내므로 %p 포인터 list의 첫번째 주소값을 나타낸다.
printf("&list = %p\n", &list); // list 의 주소값을 나타낸다.
printf("----------------------------------------\n\n");

printf("list[1] = %d\n", list[1]); // list[1] 은 두번째 값에 100을 할당했으므로 100
printf("&list[1] = %p\n", &list[1]); // list[1]은 list 의 두번쨰를 %p는 주소값을 나타낸다.
printf("*(list+1) = %d\n", *(list + 1)); // list는 첫번째를 나타내고 +1 을 했으므로 두번째값 100이 나온다.
printf("list+1 = %p\n", list+1); // list의 두번째의 %p 포인터 이므로 두번쨰 주소를 나타낸다.
printf("----------------------------------------\n\n");

printf("*plist[0] = %d\n", *plist[0]); //plist의 첫번째에 200을 할당했으므로 200
printf("&plist[0] = %p\n", &plist[0]); //plist의 첫번째 주소를 나타낸다.
printf("&plist = %p\n", &plist); // plist의 주소를 나타낸다.
printf("plist = %p\n", plist); // plist의 첫번째 주소를 나타낸다.
printf("plist[0] = %p\n", plist[0]); // plist의 첫번째 주소를 나타낸다.
printf("plist[1] = %p\n", plist[1]); // int *plist[5] = {NULL,}; 이므로 00000000
printf("plist[2] = %p\n", plist[2]); // int *plist[5] = {NULL,}; 이므로 00000000
printf("plist[3] = %p\n", plist[3]); // int *plist[5] = {NULL,}; 이므로 00000000
printf("plist[4] = %p\n", plist[4]); // int *plist[5] = {NULL,}; 이므로 00000000
free(plist[0]);
}
