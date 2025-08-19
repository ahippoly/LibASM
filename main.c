

#include "libasm.h"



void test_ft_strlen(void)
{
    printf("\n=== Testing ft_strlen ===\n");
    char *str = "abc";
    int len_ft_lib = ft_strlen(str);
    int len_lib_c = strlen(str);
    printf("Length_hello => ft_strlen: %d, strlen: %d\n", len_ft_lib, len_lib_c);

    char *str_empty = "";
    int len_ft_lib2 = ft_strlen(str_empty);
    int len_lib_c2 = strlen(str_empty);
    printf("Length_empty => ft_strlen: %d, strlen: %d\n", len_ft_lib2, len_lib_c2);
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

    char *str3 = "caa";
    char *str4 = "caaaab";
    int result_ft2 = ft_strcmp(str3, str4);
    int result_lib_c2 = strcmp(str3, str4);
    printf("result ft_strcmp: %d, strcmp: %d\n", result_ft2, result_lib_c2);
}

void test_ft_strcpy(void)
{
    printf("\n=== Testing ft_strcpy ===\n");
    char str_dest[100];
    char str_dest2[100];
    char *str_src = "b";
    char *result_ft = ft_strcpy(str_dest, str_src);
    char *result_lib_c = strcpy(str_dest2, str_src);
    printf("result ft_strcpy: %s, strcpy: %s\n", result_ft, result_lib_c);

}

int main(void)
{
    test_ft_strlen();
    test_ft_write();
    test_ft_strcmp();
    test_ft_strcpy();
    
    return 0;
}