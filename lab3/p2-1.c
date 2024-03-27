#include <stdio.h>
#define MAX_SIZE 100
float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);
float input[MAX_SIZE], answer;
int i;
void main(void)
{
for(i=0; i < MAX_SIZE; i++) // 반복문을 통해 input0 ~ 99까지 배열에 0~99를 저장한다.
input[i] = i;

/* for checking call by reference */
printf("[----- [ KIM SEUNGBEEN ] [ 2020039107 ] -----]\n");
printf("--------------------------------------\n");
printf(" sum1(input, MAX_SIZE) \n");
printf("--------------------------------------\n");
printf("input \t= %p\n", input); //input의 첫번쨰 주소를 나타낸다.
answer = sum1(input, MAX_SIZE); //input, MAX_SIZE를 대입하고 sum1 함수를 호출한다. 설명은 sum1 함수에 있습니다.
printf("The sum is: %f\n\n", answer);

printf("--------------------------------------\n");
printf(" sum2(input, MAX_SIZE) \n");
printf("--------------------------------------\n");
printf("input \t= %p\n", input); //input의 첫번쨰 주소를 나타낸다.
answer = sum2(input, MAX_SIZE); //input, MAX_SIZE를 대입하고 sum2 함수를 호출한다. 설명은 sum2 함수에 있습니다.
printf("The sum is: %f\n\n", answer);

printf("--------------------------------------\n");
printf(" sum3(MAX_SIZE, input) \n");
printf("--------------------------------------\n");
printf("input \t= %p\n", input); //input의 첫번째 주소를 나타낸다.
answer = sum3(MAX_SIZE, input); //MAX_SIZE, input을 대입하고 sum3 함수를 호출한다. 설명은 sum3 함수에 있습니다.
printf("The sum is: %f\n\n", answer);
}

float sum1(float list[], int n) { //input, MAX_SIZE
printf("list\t= %p\n", list); // input을 대입했고, list의 첫번째 주소는 같다.
printf("&list\t= %p\n\n", &list); // list의 주소를 나타내기 때문에 list의 첫번쨰 주소와 다르게 나타난다.
int i;
float tempsum = 0;
for(i = 0;i < n;i++) // 0 부터 99까지 반복한다.
    tempsum += list[i]; // 0~99 까지의 합은 4950 이다
return tempsum;
}

float sum2(float *list, int n) {//input, MAX_SIZE
printf("list\t= %p\n", list); // input을 대입했고, list의 첫번째 주소는 같다.
printf("&list\t= %p\n\n", &list); // list의 주소를 나타내기 때문에 list의 첫번쨰 주소와 다르게 나타난다.
int i;
float tempsum = 0;
for(i = 0;i < n;i++) // 0 부터 99까지 반복한다.
tempsum += *(list +i); // 0 ~ 99까지 각 배열에 있는 값의 합은 0 ~ 99를 더하므로 4950 이다.
return tempsum;
}

/* stack variable reuse test */
float sum3(int n, float *list) {//위와 다르게 int, float의 순서가 바뀌었지만
// 값을 MAX_SIZE, input 순서로 줬기떄문에 차이점이 없다.
printf("list\t= %p\n", list);// input을 대입했고, list의 첫번째 주소는 같다.
printf("&list\t= %p\n\n", &list);// list의 주소를 나타내기 때문에 list의 첫번쨰 주소와 다르게 나타난다.
int i;
float tempsum = 0;
for(i = 0;i < n;i++)// 0 부터 99까지 반복한다.
tempsum += *(list +i);// 0 ~ 99까지 각 배열에 있는 값의 합은 0 ~ 99를 더하므로 4950 이다.
return tempsum;
}