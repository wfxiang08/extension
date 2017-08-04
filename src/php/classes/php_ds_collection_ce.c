#include "../../ds_common.h"
#include "php_ds_collection_ce.h"

zend_class_entry *php_ds_collection_ce;

#define COLLECTION_ABSTRACT_ME(name) \
    PHP_ABSTRACT_ME(Collection, name, arginfo_Collection_##name)

void php_ds_register_collection()
{
    zend_class_entry ce;

    zend_function_entry methods[] = {
        COLLECTION_ABSTRACT_ME(clear)
        COLLECTION_ABSTRACT_ME(copy)
        COLLECTION_ABSTRACT_ME(isEmpty)
        COLLECTION_ABSTRACT_ME(toArray)
        PHP_FE_END
    };

    INIT_CLASS_ENTRY(ce, PHP_DS_NS(Collection), methods);
    php_ds_collection_ce = zend_register_internal_interface(&ce);

    zend_class_implements(php_ds_collection_ce, 4,
        zend_ce_traversable,        // Traversable
        spl_ce_Countable,           // Countable
        spl_ce_ArrayAccess,         // ArrayAccess
        php_json_serializable_ce    // Serializable
    );
}