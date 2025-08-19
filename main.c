

#include "libasm.h"

void test_ft_strlen(void)
{
    printf("\n=== Testing ft_strlen ===\n");
    char *str = "abcde";
    int len_ft_lib = ft_strlen(str);
    int len_lib_c = strlen(str);
    printf("Length_abcde => ft_strlen: %d, strlen: %d\n", len_ft_lib, len_lib_c);

    char *str_empty = "";
    int len_ft_lib2 = ft_strlen(str_empty);
    int len_lib_c2 = strlen(str_empty);
    printf("Length_empty => ft_strlen: %d, strlen: %d\n", len_ft_lib2, len_lib_c2);
}

void test_ft_read(void)
{
    printf("\n=== Testing ft_read ===\n");
    char buf1[50];
    char buf2[50];
    int fd = open("test_read.txt", O_RDONLY);
    int fd2 = open("test_read.txt", O_RDONLY);
    ssize_t result_ft = ft_read(fd, buf1, 5);
    ssize_t result_lib_c = read(fd2, buf2, 5);
    printf("result ft_read: %ld, read: %ld\n", result_ft, result_lib_c);
    printf("result ft_read: %s, read: %s\n", buf1, buf2);

    ssize_t result_ft2 = ft_read(-1, buf1, 5);
    int errno_ft2 = errno;

    ssize_t result_lib_c2 = read(-1, buf2, 5);
    int errno_std2 = errno;
    printf("result ft_read: %ld, read: %ld\n", result_ft2, result_lib_c2);
    printf("errno: %d, errno: %d\n", errno_ft2, errno_std2);


    close(fd);
    close(fd2);
}


void test_ft_write(void)
{
        // Test ft_write function
        printf("\n=== Testing ft_write ===\n");
    
        char *test_msg = "Testing write function!\n";
        ssize_t bytes_written_ft = ft_write(1, test_msg, ft_strlen(test_msg));
        ssize_t bytes_written_std = write(1, test_msg, strlen(test_msg));
        
        printf("bytes returned: ft_write %ld, write %ld\n", bytes_written_ft, bytes_written_std);
        
        // Test error case - writing to invalid file descriptor
        char *test_msg_error = "This should fail";
        ssize_t error_result = ft_write(-1, test_msg_error, ft_strlen(test_msg_error));
        int ernno_ft = errno;
    
        ssize_t error_result_std = write(-1, test_msg_error, strlen(test_msg_error));
        int errno_std = errno;
        printf("error result ft_write: %ld, errno: %d, write: %ld, errno: %d\n", error_result, ernno_ft, error_result_std, errno_std);
}

void test_ft_strcmp(void)
{
    printf("\n=== Testing ft_strcmp ===\n");
    char *str1 = "Hello, World!";
    char *str2 = "Hello, World!";
    int result_ft = ft_strcmp(str1, str2);
    int result_lib_c = strcmp(str1, str2);
    printf("result ft_strcmp: %d, strcmp: %d\n", result_ft, result_lib_c);

    char *str3 = "a";
    char *str4 = "c";
    int result_ft2 = ft_strcmp(str3, str4);
    int result_lib_c2 = strcmp(str3, str4);
    printf("result ft_strcmp: %d, strcmp: %d\n", result_ft2, result_lib_c2);


    char *str5 = "";
    char *str6 = "abc";
    int result_ft3 = ft_strcmp(str5, str6);
    int result_lib_c3 = strcmp(str5, str6);
    printf("result ft_strcmp: %d, strcmp: %d\n", result_ft3, result_lib_c3);

    char *str7 = "ac";
    char *str8 = "";
    int result_ft4 = ft_strcmp(str7, str8);
    int result_lib_c4 = strcmp(str7, str8);
    printf("result ft_strcmp: %d, strcmp: %d\n", result_ft4, result_lib_c4);
}

void test_ft_strcpy(void)
{
    printf("\n=== Testing ft_strcpy ===\n");
    char str_dest[100];
    char str_dest2[100];

    char *result_ft_empty = ft_strcpy(str_dest, "");
    char *result_lib_c_empty = strcpy(str_dest2, "");
    printf("result ft_strcpy: %s, strcpy: %s\n", result_ft_empty, result_lib_c_empty);

    char *str_src = "Hello, World!";
    char *result_ft = ft_strcpy(str_dest, str_src);
    char *result_lib_c = strcpy(str_dest2, str_src);
    printf("result ft_strcpy: %s, strcpy: %s\n", result_ft, result_lib_c);

}

void test_ft_strdup(void)
{
    printf("\n=== Testing ft_strdup ===\n");
    char *result_ft = ft_strdup("Hello, World!");
    char *result_lib_c = strdup("Hello, World!");
    printf("result ft_strdup: %s, strdup: %s\n", result_ft, result_lib_c);

    char *result_ft2 = ft_strdup("");
    char *result_lib_c2 = strdup("");
    printf("result ft_strdup: %s, strdup: %s\n", result_ft2, result_lib_c2);

    free(result_ft);
    free(result_lib_c);
}


int main(void)
{
    test_ft_strlen();
    test_ft_write();
    test_ft_read();
    test_ft_strcmp();
    test_ft_strcpy();
    test_ft_strdup();
    
    return 0;
}