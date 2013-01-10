#ifndef __JC_IHUMAN__
#define __JC_IHUMAN__

#include <gtk/gtk.h>
#include "jc_oth.h"



#define JC_TYPE_IHUMAN                 (jc_ihuman_get_type ())

#define JC_IHUMAN(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), JC_TYPE_IHUMAN, JcIhuman))

#define JC_IS_IHUMAN(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), JC_TYPE_IHUMAN))

#define JC_IHUMAN_GET_INTERFACE(inst)  (G_TYPE_INSTANCE_GET_INTERFACE ((inst), JC_TYPE_IHUMAN, JcIhumanInterface))

typedef struct _JcIhuman              JcIhuman; /* dummy object */

typedef struct _JcIhumanInterface      JcIhumanInterface;


struct _JcIhumanInterface 
{
  GTypeInterface parent_iface;

  void (*speak) ();
};


GType jc_ihuman_get_type (void);

void jc_people_talk (JcIhuman *self);




#endif
