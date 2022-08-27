char *ft_memncpy(const char *src, char* dest, unsigned char size)
{
    int i;

    i = 0;
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

int ft_count_lines(char *str)
{
    char **lines;
    int lines_count;
    int i;

    lines_count = 1;
    while(str[i])
    {
        if (str[i] == '\n')
            lines_count++;
    }
    return (lines_count);
}

void ft_initialize_lines_to_null(char **lines, int lines_count)
{
    int i;

    i = 0;
    while (i < lines_count)
    {
        lines[i] = 0;
        i++;
    }    
}

void ft_free_all_lines(char **lines)
{
    int i;

    i = 0;
    while (lines[i])
    {
        free(lines[i]);
        lines[i] = 0;
        i++;
    }
    free(lines);
}

char** ft_save_line(char **lines, int line, char *p, char *prev_p)
{
    unsigned int line_size;

    line_size = p - prev_p;
    lines[line] = (char *)malloc(line_size);
    if (lines[line])
    {
        ft_memncpy(prev_p,lines[line],line_size);
    }
    else
    {
        ft_free_all_lines(lines);
        lines = 0;
    }
    return (lines);
}

char **ft_split_str_in_lines(char *str)
{
    char **lines;
    int lines_count;
    int line;
    char *p;
    char *prev_p;

    prev_p = str;
    line = 0;
    lines_count = ft_count_lines(str);
    lines = (char **)malloc((sizeof(char*)*lines_count));
    ft_initialize_lines_to_null(lines, lines_count);
    p = str;
    while (*p && lines)
    {
        if (*p == '\n' && lines)
        {
            lines = ft_save_line(lines, line, p, prev_p);
            prev_p = p;
            line++;
        }
        p++;
    }
    return (lines);
}