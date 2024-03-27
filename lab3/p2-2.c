#include <stdio.h>
void print_one(int *ptr, int rows);
int main()
{
int one[] = {0, 1, 2, 3, 4}; //정수 one 에 순서대로 0~4를 저장
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
printf("one = %p\n", one); //one의 첫번째 주소를 나타낸다.
printf("&one = %p\n", &one); //one의 주소를 나타낸다.
printf("&one[0] = %p\n", &one[0]); //one의 첫번째 주소를 나타낸다.
printf("\n");
printf("------------------------------------\n");
printf(" print_one(&one[0], 5) \n"); 
printf("------------------------------------\n");
print_one(&one[0], 5); //print_one 함수를 호출하고 one의 첫번째 부터 시작을하며 5까지 출력을한다. 
printf("------------------------------------\n");
printf(" print_one(one, 5) \n"); 
printf("------------------------------------\n");
print_one(one, 5); //print_one 함수를 호출하고 one의 첫번쨰 부터 시작을하며 5까지 출력을 한다.
return 0;
}
void print_one(int *ptr, int rows)
{/* print out a one-dimensional array using a pointer */
int i;
printf ("Address \t Contents\n");
for (i = 0; i < rows; i++) // i = 0 은 첫번쨰 주소부터 rows 는 동일하게 5이고, i를 1씩더한다.
printf("%p \t %5d\n", ptr + i, *(ptr + i)); // i=0 일떄를 보면 ptr이 one 일떄는 첫번째이고
//ptr+i 이므로 첫번째+0 = 첫번쨰 주소를 *(ptr + i)는 첫번쨰+0 = *(포인터)첫번쨰 주소에 저장된 값을 불러온다.
printf("\n");
}