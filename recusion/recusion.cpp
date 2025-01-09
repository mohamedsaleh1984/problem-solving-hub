#include "../common.h"

class PrintTable
{
public:
    void printTable(int n)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("%d * %d = %d\n", n, i, (n * i));
        }
    }
    
    void printTableRec(int n, int i)
    {
        if (i > 10)
            return;
    
        printf("%d * %d = %d\n", n, i, (n * i));
        printTableRec(n, i+1);
    }
};

int main(int argc, char **argv)
{


    return 0;
}