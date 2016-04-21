#include "hello.h"


#if INCLUDE_CLASS_UNIVERSUM
sslog_class_t *CLASS_UNIVERSUM;
#endif
#if INCLUDE_CLASS_PATIENT
sslog_class_t *CLASS_PATIENT;
#endif
#if INCLUDE_CLASS_WORLD
sslog_class_t *CLASS_WORLD;
#endif
#if INCLUDE_CLASS_NOTHING
sslog_class_t *CLASS_NOTHING;
#endif
#if INCLUDE_CLASS_THING
sslog_class_t *CLASS_THING;
#endif


#if INCLUDE_PROPERTY_ISA
sslog_property_t *PROPERTY_ISA;
#endif
#if INCLUDE_PROPERTY_HAS
sslog_property_t *PROPERTY_HAS;
#endif



/**
 * @brief Register ontology.
 *
 * It creates all structures, such as classes and properties. Use it firs in your propgramm.
 */
void register_ontology(sslog_node_t *node)
{    
#if INCLUDE_PROPERTY_ISA
    PROPERTY_ISA = sslog_new_property("http://X#isA", SSLOG_PROPERTY_TYPE_OBJECT);
#endif

#if INCLUDE_PROPERTY_HAS
    PROPERTY_HAS =  sslog_new_property("http://X#has", SSLOG_PROPERTY_TYPE_DATA);
#endif

#if INCLUDE_CLASS_UNIVERSUM
    CLASS_UNIVERSUM = sslog_new_class("http://X#Universum");
#endif

#if INCLUDE_CLASS_PATIENT
    CLASS_PATIENT = sslog_new_class("http://X#Patient");
#endif

#if INCLUDE_CLASS_WORLD
    CLASS_WORLD = sslog_new_class("http://X#World");
#endif

#if INCLUDE_CLASS_NOTHING
    CLASS_NOTHING = sslog_new_class("http://www.w3.org/2002/07/owl#Nothing");
#endif

#if INCLUDE_CLASS_THING
    CLASS_THING = sslog_new_class("http://www.w3.org/2002/07/owl#Thing");
#endif

}


