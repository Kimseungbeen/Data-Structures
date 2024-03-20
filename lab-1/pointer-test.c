#include <stdio.h>

int main()
{
    int i, *p;
    //정수변수 i와 정수에 대한 포인터*p

    i = 10;
    //i = 10으로 저장.

    printf("value of i = %d\n", i);
    //%d는 정수를 나타내므로 i 의 값 10을 나타낸다.
    printf("address of i = %p\n", &i);
    //%p는 포인터를 나타내므로 &i 의 주소를 나타낸다.
    printf("value of p = %p\n", p);
    //p의 값은 없으므로 0을 나타낸다.
    printf("address of p = %p\n", &p);
    //&p 의 주소를 나타낸다.

    p = &i;
    //p에 &i의 주소를 저장한다.
    
    printf("\n\n----- after p = &i ------------\n\n");
    printf("value of p = %p\n", p);
    //p의 값에 &i의 주소를 넣었으므로 위에서 나온 &i 의 주소 0061FF1C가 나온다.
    printf("address of p = %p\n", &p);
    //&p 의 주소는 동일하므로 위와 같다.
    printf("dereferencing *p = %d\n", *p);
    //*p 의 주소가 가르키는 곳은 i값의 주소이므로 i의 주소에 있는 10이 나온다.
    return 0;
}