typedef struct s_dict_item
{   
    char *key;
    char *num_name;
} t_dict_item;

t_dict_item *ft_process_lines(char **lines, int lines_count);
{
    int line;
    t_dict_item *dict_items;

    dict_items = (t_dict_item *)malloc(lines_count * sizeof(t_dict_item));
    while (line < lines_count)
    {
        dict_items[line] = ft_extract_dict_item(lines[line]);
        line++;
    }
    return (dict_items);
}

t_dict_item *ft_extract_dict_item(char *str);
{
    t_dict_item *dict_item;
    int key_size;
    int num_name_size;
    int *key_p;
    int *name_p;

    key_size = 10; //obtener la información de lo que hay en la cadena antes de :
    key_p = str; //+ posición donde empieza la info en la str
    num_name_size = 10; //obtener la información de lo que hay en la cadena después de :
    name_p = str; //+ posición donde empieza la info en la str
    //reserva espacio para el item del diccionario
    dict_item = (t_dict_item *) malloc(sizeof t_dict_item);
    //obtener la información de lo que hay en la cadena antes de :
    //quitando los espacios si los hay
    //copiarlo en la memoria reservada para el key dict_item->key
    (*dict_item).key = (char *) malloc(key_size+1);
    memncpy(key_p, (*dict_item).key, key_size);
    (*dict_item).key[key_size] = 0;
    //obtener la información de lo que hay en la cadena después de :
    //quitando los espacios si los hay
    //copiarlo en la memoria reservada para el name dict_item->name
    (*dict_item).num_name = (char *) malloc(num_name_size+1);
    memncpy(name_p, (*dict_item).name, num_name_size);
    (*dict_item).num_name[num_name_size] = 0;
    
    return (dict_item);
}