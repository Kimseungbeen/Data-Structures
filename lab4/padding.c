#include <stdio.h>
struct student {
char lastName[13]; /* 13 bytes */
int studentId; /* 4 bytes */
short grade; /* 2 bytes */
};
int main()
{
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
struct student pst; // student 에 있는 변수를 선언한다.
printf("size of student = %ld\n", sizeof(struct student)); // student 의 크기 : 24
// 컴파일마다 패딩 처리가 다른데 lastname : 13, studentId 4, grade 2 의 합은 19 지만 8의 배수로 사용된것 같습니다.

printf("size of int = %ld\n", sizeof(int)); // int 의 크기 : 4
printf("size of short = %ld\n", sizeof(short)); // short 의 크기 : 2
return 0;
}