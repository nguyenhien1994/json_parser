#ifndef __JSON_H_
#define __JSON_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
	JSON_UNDEFINED = 0,
	JSON_OBJECT = 1,
	JSON_ARRAY = 2,
	JSON_STRING = 3,
	JSON_PRIMITIVE = 4
} json_type_e;


enum json_error_e {
	JSON_ERROR_NOMEM = -1,
	JSON_ERROR_INVAL = -2,
	JSON_ERROR_PART = -3
};


typedef struct {
	json_type_e type;
	int start;
	int end;
	int size;
} json_tok_t;


typedef struct {
	unsigned int pos;
	unsigned int tok_next;
	int tok_super;
} json_parser_t;

void json_init(json_parser_t *parser);

int json_parse(json_parser_t *parser, const char *js, size_t len,
				json_tok_t *tokens, unsigned int num_tokens);

#ifdef __cplusplus
}
#endif



#endif // __JSON_H_
