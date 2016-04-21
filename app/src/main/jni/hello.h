
//Set path to SmartSlog KP Library
#include <smartslog.h>

#ifndef _GENERATED_ONTOLOGY
#define	_GENERATED_ONTOLOGY


#ifdef	__cplusplus
extern "C" {
#endif


#define INCLUDE_ALL_ONT_ENTITIES 1
#ifdef INCLUDE_ALL_ONT_ENTITIES

#define INCLUDE_PROPERTY_ISA 1
#define INCLUDE_PROPERTY_HAS 1
#define INCLUDE_CLASS_UNIVERSUM 1
#define INCLUDE_CLASS_WORLD 1
#define INCLUDE_CLASS_NOTHING 1
#define INCLUDE_CLASS_THING 1
#define INCLUDE_CLASS_PATIENT 1


#else

#define INCLUDE_PROPERTY_ISA 0
#define INCLUDE_PROPERTY_HAS 0
#define INCLUDE_CLASS_UNIVERSUM 0
#define INCLUDE_CLASS_WORLD 0
#define INCLUDE_CLASS_NOTHING 0
#define INCLUDE_CLASS_THING 0
#define INCLUDE_CLASS_PATIENT 0


#endif


#if INCLUDE_CLASS_UNIVERSUM
extern sslog_class_t *CLASS_UNIVERSUM;
#endif
#if INCLUDE_CLASS_WORLD
extern sslog_class_t *CLASS_WORLD;
#endif
#if INCLUDE_CLASS_NOTHING
extern sslog_class_t *CLASS_NOTHING;
#endif
#if INCLUDE_CLASS_THING
extern sslog_class_t *CLASS_THING;
#endif
#if INCLUDE_CLASS_PATIENT
extern  sslog_class_t *CLASS_PATIENT;
#endif


#if INCLUDE_PROPERTY_ISA
extern sslog_property_t *PROPERTY_ISA;
#endif
#if INCLUDE_PROPERTY_HAS
extern sslog_property_t *PROPERTY_HAS;
#endif



void register_ontology(sslog_node_t *node);

	
#ifdef	__cplusplus
}
#endif

#endif /* _GENERATED_ONTOLOGY */
