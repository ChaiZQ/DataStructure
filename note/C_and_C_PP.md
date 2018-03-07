# C/C++

## i++, ++i

````c++

int main()

{

    int i = 1;

    printf("%d,%d\n", ++i, ++i);    //3,3

    printf("%d,%d\n", ++i, i++);    //5,3

    printf("%d,%d\n", i++, i++);    //6,5

    printf("%d,%d\n", i++, ++i);    //8,9

    system("pause");

    return 0;

}

````

