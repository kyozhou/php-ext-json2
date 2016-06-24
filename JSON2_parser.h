/* JSON2_parser.h */

#ifndef JSON2_PARSER_H
#define JSON2_PARSER_H

#include "php.h"
#include "ext/standard/php_smart_str.h"
#include "php_json2.h"

#define JSON2_PARSER_DEFAULT_DEPTH 512

typedef struct JSON2_parser_struct {
    int state;
    int depth;
    int top;
	int error_code;
    int* stack;
    zval **the_zstack;
    zval *the_static_zstack[JSON2_PARSER_DEFAULT_DEPTH];
} * JSON2_parser;

enum error_codes {
	PHP_JSON2_ERROR_NONE = 0,
    PHP_JSON2_ERROR_DEPTH, 
    PHP_JSON2_ERROR_STATE_MISMATCH,  
    PHP_JSON2_ERROR_CTRL_CHAR,   
    PHP_JSON2_ERROR_SYNTAX,
    PHP_JSON2_ERROR_UTF8
};

extern JSON2_parser new_JSON2_parser(int depth);
extern int parse_JSON2_ex(JSON2_parser jp, zval *z, unsigned short utf16_json2[], int length, int options TSRMLS_DC);
extern int free_JSON2_parser(JSON2_parser jp);

static inline int parse_JSON2(JSON2_parser jp, zval *z, unsigned short utf16_json2[], int length, int assoc TSRMLS_DC)
{
	return parse_JSON2_ex(jp, z, utf16_json2, length, assoc ? PHP_JSON2_OBJECT_AS_ARRAY : 0 TSRMLS_CC);
}

#endif
