/**
 * @file triple.h
 * @author Aleksandr A. Lomov <lomov@cs.karelia.ru>
 * @date   03 March, 2015
 * @brief  Describe triple.
 *
 *
 * @section LICENSE
 *
 * SmartSlog KP Library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * SmartSlog KP Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartSlog KP Library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 *
 * @section DESCRIPTION
 *
 * Describe triple to store RDF content.
 * This file is part of SmartSlog KP Library.
 *
 * Copyright (C) 2009 PetrSU (SmartSlog team). All rights reserved.
 *
 */

#include "ckpi/ckpi.h"



#ifndef _SSLOG_TRIPLE_H
#define	_SSLOG_TRIPLE_H

#include "utils/bool.h"


#if !defined(SSLOG_EXTERN)
#if defined(SSLOG_EXPORT)
#define SSLOG_EXTERN __declspec(dllexport)
#elif defined (SSLOG_IMPORT)
#define SSLOG_EXTERN __declspec(dllimport)
#else
#define SSLOG_EXTERN
#endif
#endif



typedef struct sslog_triple_s
{
    char *subject;
    char *predicate;
    char *object;
    int subject_type;
    int object_type;
} sslog_triple_t;



/** @brief Types for triple elements. */
typedef enum sslog_rdf_type_e {
    SSLOG_RDF_TYPE_INCORRECT = -1,               /**< Incorrect type. */
    SSLOG_RDF_TYPE_URI = SS_RDF_TYPE_URI,        /**< URI to some resource (subject, object). */
    SSLOG_RDF_TYPE_LIT = SS_RDF_TYPE_LIT,        /**< Specific value (only for object). */
    SSLOG_RDF_TYPE_BNODE = SS_RDF_TYPE_BNODE,    /**< Blank node (subject, object). */
    SSLOG_RDF_TYPE_UNBOUND                       /**< For SPARQL. */
} sslog_rdf_type;


/**
 * Defines 'any value' for triple-template.
 * Triple-templates are used to query, remove triples from smart space
 * or for subscription operations.
 * A triple-template a regular triple, but elements of the triple
 * (subject, predicate, object) can be set with mask as '*' ('any value').
 */
#define SSLOG_TRIPLE_ANY SS_RDF_SIB_ANY
#define SSLOG_TRIPLE_ANY_LEN 50

#define SSLOG_TRIPLE_URI_LEN 500

#define SSLOG_TRIPLE_SUBJECT_LEN (SS_SUBJECT_MAX_LEN - 1)
#define SSLOG_TRIPLE_OBJECT_LEN (SS_OBJECT_MAX_LEN - 1)
#define SSLOG_TRIPLE_PREDICATE_LEN (SS_PREDICATE_MAX_LEN - 1)

#define SSLOG_TRIPLE_RDF_NAMESPACE "http://www.w3.org/1999/02/22-rdf-syntax-ns#"
#define SSLOG_TRIPLE_RDFS_NAMESPACE "http://www.w3.org/2000/01/rdf-schema#"

#define SSLOG_TRIPLE_RDF_TYPE SSLOG_TRIPLE_RDF_NAMESPACE"type"
#define SSLOG_TRIPLE_RDF_TYPE_LEN 50

#define SSLOG_TRIPLE_RDF_PROPERTY SSLOG_TRIPLE_RDF_NAMESPACE"Property"
#define SSLOG_TRIPLE_RDF_PROPERTY_LEN 50

#define SSLOG_TRIPLE_RDFS_CLASS SSLOG_TRIPLE_RDFS_NAMESPACE"Class"
#define SSLOG_TRIPLE_RDFS_CLASS_LEN 50

#define sslog_free_triples(triples_list) list_free_with_nodes(triples_list, LIST_CAST_TO_FREE_FUNC sslog_free_triple);


#ifdef	__cplusplus
extern "C" {
#endif

SSLOG_EXTERN bool sslog_triple_is_type(sslog_triple_t *triple);
SSLOG_EXTERN bool sslog_triple_is_individual(sslog_triple_t *triple);
SSLOG_EXTERN bool sslog_triple_is_class(sslog_triple_t *triple);
SSLOG_EXTERN bool sslog_triple_is_property(sslog_triple_t *triple);

/**
 * @brief Checks that a triple represents a value for individual property (object or literal).
 * @param[in] triple. Triple to check.
 * @return true if triple is a value of individual property or false otherwise.
 */
SSLOG_EXTERN bool sslog_triple_is_property_value(sslog_triple_t *triple);


SSLOG_EXTERN sslog_triple_t *sslog_triple_copy(sslog_triple_t *triple);

#ifdef	__cplusplus
}
#endif


#endif	/* _SSLOG_TRIPLE_H */


