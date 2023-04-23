/*
 * (C) Copyright 2005- ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * In applying this licence, ECMWF does not waive the privileges and immunities granted to it by
 * virtue of its status as an intergovernmental organisation nor does it submit to any jurisdiction.
 */

/*****************************************************************
 *   Enrico Fucile
 **************************************************************/
#include "grib_api_internal.h"
/*
   This is used by make_class.pl

   START_CLASS_DEF
   CLASS      = accessor
   SUPER      = grib_accessor_class_gen
   IMPLEMENTS = init;dump
   MEMBERS    =  grib_action*          *builder
   MEMBERS   =   grib_block_of_accessors     *block;
   END_CLASS_DEF

 */

/* START_CLASS_IMP */

/*

Don't edit anything between START_CLASS_IMP and END_CLASS_IMP
Instead edit values between START_CLASS_DEF and END_CLASS_DEF
or edit "accessor.class" and rerun ./make_class.pl

*/

static void dump(grib_accessor*, grib_dumper*);
static void init(grib_accessor*, const long, grib_arguments*);
//static void init_class(grib_accessor_class*);

typedef struct grib_accessor_array
{
    grib_accessor att;
    /* Members defined in gen */
    /* Members defined in array */
    grib_action*          *builder;
    grib_block_of_accessors     *block;
} grib_accessor_array;

extern grib_accessor_class* grib_accessor_class_gen;

static grib_accessor_class _grib_accessor_class_array = {
    &grib_accessor_class_gen,                      /* super */
    "array",                      /* name */
    sizeof(grib_accessor_array),  /* size */
    0,                           /* inited */
    0,                           /* init_class */
    &init,                       /* init */
    0,                  /* post_init */
    0,                    /* free mem */
    &dump,                       /* describes himself */
    0,                /* get length of section */
    0,              /* get length of string */
    0,                /* get number of values */
    0,                 /* get number of bytes */
    0,                /* get offset to bytes */
    0,            /* get native type */
    0,                /* get sub_section */
    0,               /* grib_pack procedures long */
    0,                 /* grib_pack procedures long */
    0,                  /* grib_pack procedures long */
    0,                /* grib_unpack procedures long */
    0,                /* grib_pack procedures double */
    0,                 /* grib_pack procedures float */
    0,              /* grib_unpack procedures double */
    0,               /* grib_unpack procedures float */
    0,                /* grib_pack procedures string */
    0,              /* grib_unpack procedures string */
    0,          /* grib_pack array procedures string */
    0,        /* grib_unpack array procedures string */
    0,                 /* grib_pack procedures bytes */
    0,               /* grib_unpack procedures bytes */
    0,            /* pack_expression */
    0,              /* notify_change */
    0,                /* update_size */
    0,             /* preferred_size */
    0,                     /* resize */
    0,      /* nearest_smaller_value */
    0,                       /* next accessor */
    0,                    /* compare vs. another accessor */
    0,      /* unpack only ith value */
    0,       /* unpack only ith value */
    0,  /* unpack a given set of elements */
    0,   /* unpack a given set of elements */
    0,     /* unpack a subarray */
    0,                      /* clear */
    0,                 /* clone accessor */
};


grib_accessor_class* grib_accessor_class_array = &_grib_accessor_class_array;


//static void init_class(grib_accessor_class* c)
//{
//INIT
//}

/* END_CLASS_IMP */


static void init(grib_accessor* a, const long len, grib_arguments* arg)
{
    grib_accessor_array* self = (grib_accessor_array*)a;
    self->block               = (grib_block_of_accessors*)grib_context_malloc_clear(a->context, sizeof(grib_block_of_accessors));
    a->length                 = 0;
}

static void dump(grib_accessor* a, grib_dumper* dumper)
{
    grib_accessor_array* self = (grib_accessor_array*)a;
    grib_dump_section(dumper, a, self->block);
}
