#include<stdio.h>
#include<stdlib.h>
void main()
{
int **x; // 정수 x의 이중 역참조 연산자이다.
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
printf("sizeof(x) = %lu\n", sizeof(x)); //%lu 는 부호없는 10진정수 출력이다. x의 사이즈는 4 이므로 4이다.
printf("sizeof(*x) = %lu\n", sizeof(*x)); // *x는 x가 가르키는 값의 크기이므로 4 이다.
printf("sizeof(**x) = %lu\n", sizeof(**x)); // **x는 *x가 가르키는 값의 크기이고 *x는 x가 가르키는 값이므로 4 이다.
}