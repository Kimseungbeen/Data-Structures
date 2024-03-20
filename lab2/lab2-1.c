#include <stdio.h>
int main()
{
 char charType;
 int integerType;
 float floatType;
 double doubleType;

//%ld는 10진수 정수로 출력합니다.

 printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
 printf("Size of char: %ld byte\n",sizeof(charType)); // 
 printf("Size of int: %ld bytes\n",sizeof(integerType));
 printf("Size of float: %ld bytes\n",sizeof(floatType));
 printf("Size of double: %ld bytes\n",sizeof(doubleType));
 //각 변수에 대한 크기를 나타내는 구문입니다.
 //char 타입은 1바이트, int 타입은 4바이트, float 타입은 4 바이트, double 타입은 8 타입이므로
 //정상 출력입니다.

 printf("-----------------------------------------\n");
 printf("Size of char: %ld byte\n",sizeof(char));
 printf("Size of int: %ld bytes\n",sizeof(int));
 printf("Size of float: %ld bytes\n",sizeof(float));
 printf("Size of double: %ld bytes\n",sizeof(double));
 //각 타입에 대한 크기를 나타내는 구문입니다.
 //위와 동일하게 char 타입은 1바이트, int 타입은 4바이트, float 타입은 4 바이트, double 타입은 8 타입이므로
 //정상 출력입니다.

 printf("-----------------------------------------\n");
 printf("Size of char*: %ld byte\n",sizeof(char*));
 printf("Size of int*: %ld bytes\n",sizeof(int*));
 printf("Size of float*: %ld bytes\n",sizeof(float*));
 printf("Size of double*: %ld bytes\n",sizeof(double*));
// *는 포인터 변수로 메모리 주소를 나타냅니다..
//각 크기가 4바이트로 나오는 이유는 개발환경이 기본적으로 32비트로 셋팅 되어있습니다.*/

 return 0;
}