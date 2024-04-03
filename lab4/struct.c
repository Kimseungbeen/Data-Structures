#include <stdio.h>
struct student1 {
char lastName;
int studentId;
char grade;
};
typedef struct { // 구조 데이터 타입 생성
char lastName;
int studentId;
char grade;
} student2;

int main() {
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
struct student1 st1 = {'A', 100, 'A'}; //student1 을 불러와 st1 의 변수를 만들고 각각 A, 100, A 값을준다.
printf("st1.lastName = %c\n", st1.lastName); // st1.lastName 에는 A 값을 할당했다.
printf("st1.studentId = %d\n", st1.studentId); // st.studentId 에는 100 을 할당했다.
printf("st1.grade = %c\n", st1.grade); // st.grade 에는 A 를 할당했다.

student2 st2 = {'B', 200, 'B'}; // 구조체 변수 st2 를 만들고 각 B, 200, B 값을 준다.
printf("\nst2.lastName = %c\n", st2.lastName); // st2.lastName 는 B
printf("st2.studentId = %d\n", st2.studentId); // st2.studentId 는 200
printf("st2.grade = %c\n", st2.grade); // st2.grade 는 B

student2 st3; // 구조체 변수 st3 를 만든다.
st3 = st2; // st3 에 st2 의 값을 할당한다.
printf("\nst3.lastName = %c\n", st3.lastName); // st3.lastName 는 B
printf("st3.studentId = %d\n", st3.studentId); // st3.studentId 는 200
printf("st3.grade = %c\n", st3.grade); //st3.grade 는 B

/* equality test */
if(st3.lastName == st2.lastName && st3.studentId == st2.studentId && st3.grade == st2.grade) /* not working */ // 구조체의 값이 동일한지 검사를 하고싶지만 구조 치환을 안했으므로 바꿔줍니다.
printf("equal\n"); // st3 = st2 이므로 동일한지 검사를 하면 같다.
else
printf("not equal\n");
return 0;
}