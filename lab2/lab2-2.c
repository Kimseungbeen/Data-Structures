#include <stdio.h>
int main()
{
int i; //정수 i 
int *ptr; //정수형 포인터 ptr
int **dptr; // 이중 포인터 dptr
i = 1234; // i값에 1234 대입

printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
printf("[checking values before ptr = &i] \n");
printf("value of i == %d\n", i); // i의 값은 1234
printf("address of i == %p\n", &i); //%p는 포인터, &은 메모리의 주소를 나타낸다. 
printf("value of ptr == %p\n", ptr); //ptr의 값이 없으므로 00000000
printf("address of ptr == %p\n", &ptr); //ptr의 값이 없어도 메모리 주소는 있다.

ptr = &i; /* ptr is now holding the address of i */
//ptr의 값이 &i의 주소값을 가진다
printf("\n[checking values after ptr = &i] \n");
printf("value of i == %d\n", i); // i의 값은 변한게 없으므로 1234 이다.
printf("address of i == %p\n", &i); // 마찬가지로 주소값도 변한게 없어 위와 동일하다.
printf("value of ptr == %p\n", ptr); //ptr는 &i의 주소값을 가지게 했으므로 &i의 주소와 동일하다.
printf("address of ptr == %p\n", &ptr); //ptr의 값이 &i의 주소를 가지지만, 주소값은 안 변한다.
printf("value of *ptr == %d\n", *ptr); //*은 포인터이고 ptr이 &i의 주소를 가지므로, &i의 주소를 가보면 1234의 값이 있다.

dptr = &ptr; /* dptr is now holding the address of ptr */
//dptr의 값이 &ptr의 주소값을 가진다. &ptr은 &i의 주소를 가르킨다.
printf("\n[checking values after dptr = &ptr] \n");
printf("value of i == %d\n", i); // i 값은 변한게 없으므로 1234 이다.
printf("address of i == %p\n", &i); // 마찬가지로 주소값도 변한게 없어 위와 동일하다. dptr = &ptr;과 연관X
printf("value of ptr == %p\n", ptr); //ptr는 &i의 주소값을 가지게 했으므로 &i의 주소와 동일하다. dptr = &ptr;과 연관X
printf("address of ptr == %p\n", &ptr); //ptr의 값이 &i의 주소를 가지지만, 주소값은 안 변한다. dptr = &ptr;과 연관X
printf("value of *ptr == %d\n", *ptr); //*은 포인터이고 ptr이 &i의 주소를 가지므로, &i의 주소를 가보면 1234의 값이 있다. dptr = &ptr;과 연관X
printf("value of dptr == %p\n", dptr); //dprt는 &ptr의 주소값을 가지게 했으므로 &ptr의 주소와 동일하다.
printf("address of dptr == %p\n", &dptr); //dptr이 &ptr의 주소를 가지지만, 주소값은 안 변한다.
printf("value of *dptr == %p\n", *dptr); // 포인터 dprt은 &ptr이 가르키는 &i의 주소이므로 &i의 주소와 같다.
printf("value of **dptr == %d\n", **dptr); //이중포인터 dptr 이 카르키는 주소에 저장된 값이 므로 &i의 주소에있는 1234이다.

*ptr = 7777; /* changing the value of *ptr */
//포인터 ptr이 가르키는 주소에 저장된값(i) 을 7777으로 바꾼다.
printf("\n[after *ptr = 7777] \n");
printf("value of i == %d\n", i); // ptr이 가르키는 주소에 저장된값(i) 을 7777으로 바꿨으므로 값은 7777이다.
printf("value of *ptr == %d\n", *ptr); //ptr은 &i의 주소를 가지고, &i의 주소에는 7777이 있다.
printf("value of **dptr == %d\n", **dptr); //이중포인터 dptr 이 가르키는 주소에 저장된 값이 므로 &i의 주소에있는 7777이다.

**dptr = 8888; /* changing the value of **dptr */
//이중포인터 dptr이 가르키는 주소에 저장된값 은 &ptr 이 가르키는 &i 이 가르키는 값을 8888으로 변경한다.
printf("\n[after **dptr = 8888] \n");
printf("value of i == %d\n", i); //i값이8888으로 변경되었으니 8888이다.
printf("value of *ptr == %d\n", *ptr); //포인터 ptr이 가르키는 주소의 값이므로 i = 8888
printf("value of **dptr == %d\n", **dptr); //이중포인터 dptr이 가르키는 주소에 저장된 값이므로 &i의 주소에있는 8888이다. 
return 0;
}