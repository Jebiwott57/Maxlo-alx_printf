#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BS 1024 /* Buffer Size */

/* ------get_flags.c----- */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* ------get_size.c------ */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/* _printf.c */
int _printf(const char *format, ...);

/* handler_print.c */
int handle_print(const char *fmt, int *ind,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* func_char.c */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_str.c */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_percent_sign.c */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_int.c */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_unsign_int.c */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_unsign_num.c */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_unsign_num_oct.c */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_hexadecimal.c */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_hexa_upper.c */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_hexa.c */
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* func_non_printable_char.c */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_print_pointer.c */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* get_flag.c */
int get_flags(const char *format, int *i);

/* get_width */
int get_width(const char *format, int *i, va_list list);

/* get_precision */
int get_precision(const char *format, int *i, va_list list);

/* get-size */
int get_size(const char *format, int *i);

/* func_rev_string.c */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* func_rot13.c */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* write_handler.c */
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);

int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

/* write-num.c */
int write_num(int index, char buffer[], int flags, int width, int precision,
int length, char a, char extra);

int write_unsigned_num(int is_negative, int index,
char buffer[], int flags, int width, int precision, int size);

/* write_handler_b.c */
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);

/* printable-char.c */
int is_printable(char);

/* hexadecimal.c */
int add_hexadecimal(char ascii_code, char buffer[], int s);

/* is-digit.c */
int is_digit(char);

/* num-size.c */
long int convert_size_number(long int num, int size);

/* print-num_to_size */
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
