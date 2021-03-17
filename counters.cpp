#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>

int main(int argc, char** argv)
{
    int max = atoi(argv[1]);
    int s = atoi(argv[2]);

    int c = 0;

    int n1 = 1;
    int n2 = 1;
    int sum;

    auto counter = [&] () {return c++;};
    auto prime = [&] () {
        int max_div = floor(sqrt(c)); 
        for (int i = 2; i < 1 + max_div; i++)
        {
            if (c % i == 0)
                return false;
        }
        return true;
    };
    auto fibonacci = [&] () {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        return sum;
    };

    switch (s)
    {
    case 1:
        while (counter() < max)
            printf("%d ", c);
        break;

    case 2:
        while (counter() < max)
            (prime()) ? printf("%d ", c) : 0;
        break;

    case 3:
        printf("%d %d ", n1, n2);
        int temp;
        while ((temp = fibonacci()) < max)
            printf("%d ", temp);
        break;
    
    default:
        printf("Arguments error");
        break;
    }
    
    return 0;
}