#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isMatch(char open, char close)
{
	return ((open == '(' && close == ')') || 
			(open == '[' && close == ']') ||
			(open == '{' && close == '}'));
}

bool isValid(char *s) 
{
    int i = 0, top = -1, len = strlen(s);
	char 						  *stack;
	char 				   			 sym;
	bool						   empty;

	stack = (char *)malloc(sizeof(char) * len);
	if (!stack)
		return false;
	while (i < len)
	{
		sym = s[i];
		if (sym == '(' || sym == '[' || sym == '{')
			stack[++top] = sym;
		else
		{
			if (top == -1 || !isMatch(stack[top], sym))
			{
				free(stack);
				return false;
			}
			top--;
		}
		i++;
	}
	empty = (top == -1);
	free(stack);
	return empty;
}

int main() {
    char input1[] = "()[]{}";
    char input2[] = "(]";
    char input3[] = "([)]";
    char input4[] = "{[]}";

    printf("%s -> %s\n", input1, isValid(input1) ? "true" : "false");
    printf("%s -> %s\n", input2, isValid(input2) ? "true" : "false");
    printf("%s -> %s\n", input3, isValid(input3) ? "true" : "false");
    printf("%s -> %s\n", input4, isValid(input4) ? "true" : "false");

    return 0;
}