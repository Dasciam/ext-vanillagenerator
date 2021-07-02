#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

extern "C" {
#include "php.h"
#include "ext/standard/info.h"
#include "php_extnoise.h"
}

#include "src/RandomImpl.h"
#include "src/Noise.h"
#include "src/OverworldGeneratorImpl.h"

PHP_MINIT_FUNCTION (extnoise) {
  register_internal_randoms();
  register_noise_function();
  register_overworld_generator();
  return SUCCESS;
}

PHP_MINFO_FUNCTION (extnoise) {
  php_info_print_table_start();
  php_info_print_table_header(2, "extnoise support", "enabled");
  php_info_print_table_end();
}

zend_module_entry extnoise_module_entry = {
    STANDARD_MODULE_HEADER,
    "extnoise",
    NULL,
    PHP_MINIT(extnoise),
    NULL,
    NULL,
    NULL,
    PHP_MINFO(extnoise),
    PHP_EXTNOISE_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_EXTNOISE
extern "C" {
#ifdef ZTS
     ZEND_TSRMLS_CACHE_DEFINE()
#endif
     ZEND_GET_MODULE(extnoise)
}
#endif