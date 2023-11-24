#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)
#define s21_size_t unsigned long long

#define BUFFERSIZE 1024
#define EPSILON_VALUE 0.000001f
#define SPACE_SYM " \n\r\t\v\f"

typedef struct {
  char flag_r;
  char flag_s;
  char flag_p;
  char flag_m;
  char flag_z;
  int width;
  int accuracy;
  char length;
  char length2;
  int float_part;
  int is_negative;
  char spec;
  char unsign;
} Format;

// COPY FUNCTIONS

/**
 * @brief Function that copies n characters from src to dest.
 * @param dest string where copies
 * @param src string from copies
 * @param n quantity of characters
 * @return pointer to dest
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

/**
 * @brief Another function to copy n characters from src to dest.
 * @param dest string where copies
 * @param src string from copies
 * @param n quantity of characters
 * @return pointer to dest
 */
void *s21_memmove(void *dest, const void *src, s21_size_t n);

/**
 * @brief Copies the string pointed to, by src to dest.
 * @param dest string where copies
 * @param src string from copies
 * @return pointer to dest
 */
char *s21_strcpy(char *dest, const char *src);

/**
 * @brief Copies up to n characters from the string pointed to, by src to dest.
 * @param dest string where copies
 * @param src string from copies
 * @param n quantity of characters
 * @return pointer to dest
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// CONCATENATION FUNCTIONS

/**
 * @brief Appends the string pointed to, by src to the end of the string pointed
 * to by dest.
 * @param dest string where copies
 * @param src string from copies
 * @return pointer to dest
 */
char *s21_strcat(char *dest, const char *src);

/**
 * @brief Appends the string pointed to, by src to the end of the string pointed
 * to, by dest up to n characters long.
 * @param dest string where copies
 * @param src string from copies
 * @param n quantity of characters
 * @return pointer to dest
 */
char *s21_strncat(char *dest, const char *src, s21_size_t n);

// COMPAIRSON FUNCTIONS

/**
 * @brief Compares the first n bytes of str1 and str2.
 * @param str1 pointer to first string
 * @param str2 pointer to second string
 * @param n quantity of bytes
 * @return comparison result 0 - identical 1 - not identical
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

/**
 * @brief Compares str1 and str2.
 * @param str1 pointer to first string
 * @param str2 pointer to second string
 * @return comparison result 0 - identical 1 - not identical
 */
int s21_strcmp(const char *str1, const char *str2);

/**
 * @brief Compares at most the first n bytes of str1 and str2.
 * @param str1 pointer to first string
 * @param str2 pointer to second string
 * @param n quantity of bytes
 * @return comparison result 0 - identical 1 - not identical
 */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// SEARCH FUNCTIONS

/**
 * @brief Searches for the first occurrence of the character c (an unsigned
 * char) in the first n bytes of the string pointed to, by the argument str.
 * @param str pointer to string
 * @param c sought character
 * @param n quantity of bytes
 * @return pointer to finded character in str
 */
void *s21_memchr(const void *str, int c, s21_size_t n);

/**
 * @brief Searches for the first occurrence of the character c (an unsigned
 * char) in the string pointed to, by the argument str.
 * @param str pointer to string
 * @param c sought character
 * @return pointer to finded character in str
 */
char *s21_strchr(const char *str, int c);

/**
 * @brief Calculates the length of the initial segment of str1 which consists
 * entirely of characters not in str2.
 * @param str1 pointer to str1
 * @param str2 pointer to str1
 * @return length of the initial segment of str1 which consists
 * entirely of characters not in str2.
 */
s21_size_t s21_strcspn(const char *str1, const char *str2);

/**
 * @brief Finds the first character in the string str1 that matches any
 * character specified in str2.
 * @param str1 pointer to str1
 * @param str2 pointer to str1
 * @return pointer to the first character in the string str1 that matches any
 * character specified in str2
 */
char *s21_strpbrk(const char *str1, const char *str2);

/**
 * @brief Searches for the last occurrence of the character c (an unsigned char)
 * in the string pointed to by the argument str.
 * @param str pointer to string
 * @param c sought character
 * @return pointer to character in str or NULL if there wasn't finding
 */
char *s21_strrchr(const char *str, int c);

/**
 * @brief Calculates the length of the initial segment of str1 which consists
 * entirely of characters in str2.
 * @param str1 pointer to str1
 * @param str2 pointer to str1
 * @return length of the initial segment of str1 which consists
 * entirely of characters in str2
 */
s21_size_t s21_strspn(const char *str1, const char *str2);

/**
 * @brief Finds the first occurrence of the entire string needle (not including
 * the terminating null character) which appears in the string haystack.
 * @param haystack pointer to string haystack
 * @param needle pointer to string needle
 * @return pointer to first occurrence in haystack string
 */
char *s21_strstr(const char *haystack, const char *needle);

/**
 * @brief Breaks string str into a series of tokens separated by delim.
 * @param pointer to string
 * @param delim pointer to delim
 * @return pointer to the first character of the found substring in str
 */
char *s21_strtok(char *str, const char *delim);

// OTHER FUNCTIONS

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str
void *s21_memset(void *str, int c, s21_size_t n);
// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив
char *s21_strerror(int errnum);
// Вычисляет длину строки str, не включая завершающий нулевой символ
s21_size_t s21_strlen(const char *str);

// отправляет форматированный вывод в строку, на которую указывает str
int s21_sprintf(char *str, const char *format, ...);

// Возвращает копию строки (str), преобразованной в верхний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str);
// Возвращает копию строки (str), преобразованной в нижний регистр. В случае
// какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str);
// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars);

// clear buff for tests

void clear_buffs(char **buffer, char **buffer2);

// SPECIAL FUNCTIONS

int s21_parse_flags(const char *format, s21_size_t *i, Format *form);
int s21_parse_width(va_list *ap, const char *format, s21_size_t *i,
                    Format *form);
int s21_parse_accuracy(va_list *ap, const char *format, s21_size_t *i,
                       Format *form);
// парсинг L, h, l
int s21_parse_length(const char *format, s21_size_t *i, Format *form);
char *s21_switch_spec(va_list *ap, s21_size_t j, Format *form);
// %n
char *s21_process_spec_n(va_list *ap, s21_size_t j);
char *s21_process_spec_id(va_list *ap, Format *form);
// работа с х, Х, о и unsigned
char *s21_process_spec_xuo(va_list *ap, Format *form);
char *s21_process_spec_p(va_list *ap, Format *form);
char *s21_process_spec_f(va_list *ap, Format *form);
char *s21_process_spec_e(va_list *ap, Format *form);
char *s21_process_spec_g(va_list *ap, Format *form);
char *s21_process_spec_c(va_list *ap, Format *form);
char *s21_process_spec_s(va_list *ap, Format *form);
void s21_reverse(char str[], int len);
void s21_process_flags(char *str, Format *form);
char *s21_itoa(long long num, int base, Format *form);
long long s21_atoi(char *str);
char *s21_ftoa(long double f, int acc, Format *form);
// убирает нули в конце числа
void s21_delete_zero(char *str);
char *s21_ftoexp(long double f, Format *form);
char *s21_ftog(long double f, Format *form);

#if defined(__APPLE__)
#define N 106
#define LIST_ERRORS                                                            \
  {                                                                            \
    "Undefined error: 0", "Operation not permitted",                           \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full"                                       \
  }

#elif defined(__linux__)
#define N 133
#define LIST_ERRORS                                                            \
  {                                                                            \
    "Success", "Operation not permitted", "No such file or directory",         \
        "No such process", "Interrupted system call", "Input/output error",    \
        "No such device or address", "Argument list too long",                 \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource temporarily unavailable", "Cannot allocate memory",          \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Invalid cross-device link", \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "Too many open files in system",                   \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain",                     \
        "Numerical result out of range", "Resource deadlock avoided",          \
        "File name too long", "No locks available",                            \
        "Function not implemented", "Directory not empty",                     \
        "Too many levels of symbolic links", "Unknown error 41",               \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Unknown error 58", "Bad font file format", "Device not a stream",     \
        "No data available", "Timer expired", "Out of streams resources",      \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Bad message",             \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly",                               \
        "Invalid or incomplete multibyte or wide character",                   \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable", "Network dropped connection on reset",       \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale file handle", "Structure needs cleaning",                       \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Disk quota exceeded",     \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill",      \
        "Memory page has hardware error"                                       \
  }
#endif

#endif