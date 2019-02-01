#include <stdio.h>
#include <time.h>
#include <libwordcompression.h>

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_wordcompression.h"
#include "zend_exceptions.h"


/* {{{ string wordcompression_decode( [ string $var ] )
 */
PHP_FUNCTION(wordcompression_decode)
{

    char *dictionary_var;
    char *file_var;
	char *ret;
	short error;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "ps", &dictionary_var, &file_var) == FAILURE) {
        RETURN_FALSE;
    }

	ret = word_decompressor_string(dictionary_var, file_var, &error);
	if (error) {
		RETURN_NULL();
		return;
	}
	RETURN_STRING(ret);
}
/* }}}*/

/* {{{ string wordcompression_encode( [ string $var ] )
 */
PHP_FUNCTION(wordcompression_encode)
{

    char *dictionary_var;
    char *file_var;
	char *ret;
	short error;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "ps", &dictionary_var, &file_var) == FAILURE) {
        RETURN_FALSE;
    }

	ret = word_compressor_string(dictionary_var, file_var, &error);
	if (error) {
		RETURN_NULL();
		return;
	}
	RETURN_STRING(ret);
}
/* }}}*/

/* {{{ string wordcompression_error( [ string $var ] )
 */
PHP_FUNCTION(wordcompression_error)
{
	RETURN_STRING(word_compression_last_error());
}
/* }}}*/



/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(wordcompression)
{
#if defined(ZTS) && defined(COMPILE_DL_WORDCOMPRESSION)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */



/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(wordcompression)
{

    

	

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(wordcompression)
{
	

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(wordcompression)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "wordcompression support", "enabled");
	php_info_print_table_end();
	
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_wordcompression_decode, 0)
    ZEND_ARG_INFO(0, _dictionary)
    ZEND_ARG_INFO(0, _file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_wordcompression_encode, 0)
    ZEND_ARG_INFO(0, _dictionary)
    ZEND_ARG_INFO(0, _file)
ZEND_END_ARG_INFO()

/* }}} */

/* {{{ wordcompression_functions[]
 */
const zend_function_entry wordcompression_functions[] = {
    PHP_FE(wordcompression_decode, arginfo_wordcompression_decode)
    PHP_FE(wordcompression_encode, arginfo_wordcompression_encode)
    PHP_FE(wordcompression_error, NULL)
	PHP_FE_END
};

/* }}} */

/* {{{ wordcompression_module_entry
 */
zend_module_entry wordcompression_module_entry = {
	STANDARD_MODULE_HEADER,
	"wordcompression",						/* Extension name */
	wordcompression_functions,				/* zend_function_entry */
	PHP_MINIT(wordcompression),		/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(wordcompression),	/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(wordcompression),				/* PHP_RINIT - Request initialization */
	NULL,								/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(wordcompression),				/* PHP_MINFO - Module info */
	PHP_WORDCOMPRESSION_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_WORDCOMPRESSION
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(wordcompression)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */