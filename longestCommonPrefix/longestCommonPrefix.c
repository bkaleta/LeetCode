char *longestCommonPrefix(char **strs, int strsSize) 
{
    char *prefix = strs[0];
    
    if (strsSize == 0)
        return "";
    
    int i = 1;
    while (i < strsSize) 
    {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (strlen(prefix) == 0) {
            return "";
        }
        i++;
    }
    
    return prefix;
}