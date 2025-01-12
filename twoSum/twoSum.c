#include <unistd.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int i = 0, j = 0;
    int *result = (int *)malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    while (i < numsSize)
    {
        j = i + 1;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return (result);
            }
            j++;
        }
        i++;
    }
    *returnSize = 0;
    free(result);
    return (NULL);
}