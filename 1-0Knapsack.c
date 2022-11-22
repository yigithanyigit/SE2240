#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

typedef struct pairs_s
{
    int weight;
    int values;
} pairs_t[1], *pairs_ptr;

pairs_ptr pair_init(int size)
{
    pairs_ptr pairs = malloc(sizeof(pairs_t) * size);
    return pairs;
}

void pair_free(pairs_ptr pairs)
{
    free(pairs);
}

int knapSack(int W, pairs_ptr pairs, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (pairs[n - 1].weight > W)
        return knapSack(W, pairs, n - 1);

    else
        return max(pairs[n - 1].values + knapSack(W - pairs[n - 1].weight, pairs, n - 1), knapSack(W, pairs, n - 1));
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    pairs_ptr pairs = pair_init(n);
    for (int i = 0; i < n; i++)
    {
        pairs[i].values = val[i];
        pairs[i].weight = wt[i];
    }

    printf("%d", knapSack(W, pairs, n));

    return 0;
}