#include <stdio.h>
#include <math.h>

typedef struct
{
    int length;
    float list[2];
} rootList;

rootList rootCalculator(float a, float b, float c);

int main()
{
    printf("Input coefficients \"a, b, c\" of form ax^2 + bx + c = 0 : ");
    float a, b, c;
    scanf("%f, %f, %f", &a, &b, &c);
    rootList r = rootCalculator(a, b, c);
    if(r.length == 0)
    {
        printf("This binomial has no roots\n");
    }
    if(r.length == 1)
    {
        printf("This binomial has root x=%1.2f\n", r.list[0]);
    }
    if(r.length == 2)
    {
        printf("This binomial has roots x=%1.2f, x=%1.2f\n", r.list[0], r.list[1]);
    }

    return 0;
}

rootList rootCalculator(float a, float b, float c)
{
    rootList r;
    float discriminant = b*b - 4*a*c;
    if(discriminant < 0)
    {
        r.length = 0;
    }
    if(discriminant == 0)
    {
        r.length = 1;
        float root = (-b) / (2*a);
        r.list[0] = root;
    }
    if(discriminant > 0)
    {
        r.length = 2;
        float roota = ((-b) + sqrt(discriminant)) / (2*a);
        float rootb = ((-b) - sqrt(discriminant)) / (2*a);
        r.list[0] = roota;
        r.list[1] = rootb;
    }
    return r;
}
