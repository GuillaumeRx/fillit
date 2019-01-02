# Libft

> Personnal C library with usefull functions

## Compiling

**Use the command `make` to ran library compilation. You can also pair `make` with one of above rules to do various things**

`all` : Compile the library and create `libft.a`

___

`re` : Recompile the library

___

`clean` : Remove the `.o` files

___

`fclean` : Return the library to non compilated state (Remove `.o` files and `libft.a`)

___

`count` : Count the number of `.c` files and the number of functions added to libft.h / Makefile. It make sure you don't have bastard files that are not necessary

___

## Function list

### Libc functions

> Libc functions recoded for better understanding and flexability

| Name          | File          | Prototype                                                                              | Description       |
| ------------- |:-------------:|----------------------------------------------------------------------------------------|-------------------|
| ft_memset     | `ft_memset.c` | `void		*ft_memset (void *s, int c, size_t n);`                                      | `man memset`      |
| ft_bzero      | `ft_bzero.c`  | `void		ft_bzero(void *s, size_t n);`                                                | `man bzero`       |
| ft_memcpy     | `ft_memcpy.c` | `void		*ft_memcpy(void *dest, const void *src, size_t n);`                          | `man memcpy`      |
| ft_memccpy    | `ft_memccpy.c`| `void		*ft_memccpy(void *dest, const void *src, int c, size_t n);`                  | `man memccpy`     |
| ft_memmove    | `ft_memmove.c`| `void		*ft_memmove(void *dest, const void *src, size_t n);`                         | `man memmove`     |
| ft_memchr     | `ft_memchr.c` | `void		*ft_memchr(const void *s, int c, size_t n);`                                 | `man memchr`      |
| ft_memcmp     | `ft_memcmp.c` | `int		ft_memcmp(const void *s1, const void *s2, size_t n);`                        | `man memcmp`      |
| ft_strlen     | `ft_strlen.c` | `size_t	ft_strlen(const char *s);`                                                   | `man strlen`      |
| ft_strdup     | `ft_strdup.c` | `char		*ft_strdup(const char *s);`                                                  | `man strdup`      |
| ft_strcpy     | `ft_strcpy.c` | `char		*ft_strcpy(char *dest, const char *src);`                                    | `man strcpy`      |
| ft_strncpy    | `ft_strncpy.c`| `char		*ft_strncpy(char *dest, const char *src, size_t n)`                          | `man strncpy`     |
| ft_strcat     | `ft_strcat.c` | `char		*ft_strcat(char *dest, const char *src);`                                    | `man strcat`      |
| ft_strncat    | `ft_strncat.c`| `char		*ft_strncat(char *dest, const char *src, size_t n);`                         | `man strncat`     |
| ft_strlcat    | `ft_strlcat.c`| `size_t	ft_strlcat(char *dst, const char *src, size_t size);`                        | `man strlcat`     |
| ft_strchr     | `ft_strchr.c` | `char		*ft_strchr(const char *s, int c);`                                           | `man strchr`      |
| ft_strrchr    | `ft_strrchr.c`| `char 	*ft_strrchr(const char *s, int c);`                                          | `man strrchr`     |
| ft_strstr     | `ft_strstr.c` | `char		*ft_strstr(const char *haystack, const char *needle);`                       | `man strstr`      |
| ft_strnstr    | `ft_strnstr.c`| `char		*ft_strnstr(const char *haystack, const char *needle, size_t len);`          | `man strnstr`     |
| ft_strcmp     | `ft_strcmp.c` | `int		ft_strcmp(const char *s1, const char *s2);`                                  | `man strcmp`      |
| ft_strncmp    | `ft_strncmp`  | `int		ft_strncmp(const char *s1, const char *s2, size_t n);`                       | `man strncmp`     |

### Additional functions

> Some usefull functions coded to increase workflow. Some are used in Libc's functions I've made


### Bonus functions

> Functions made to handle chained-lists. Works only with the libft's generic chained-list

```c
// Libft list structure

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
```

### Personal functions

> Functions I've made that I found usefull
