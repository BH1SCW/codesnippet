#ifndef __JC_BOY__
#define __JC_BOY__

#include <gtk/gtk.h>
#include "jc_ihuman.h"
#include "jc_baby.h"
#include "jc_oth.h"


 

enum

{
  PROP_BOY_0,

  PROP_BOY_AGE,
  PROP_BOY_NAME,
  PROP_BOY_HOBBY
 
};
 



#define JC_TYPE_BOY                  (jc_boy_get_type ())

#define JC_BOY(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), JC_TYPE_BOY, JcBoy))

#define JC_IS_BOY(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), JC_TYPE_BOY))

#define JC_BOY_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), JC_TYPE_BOY, JcBoyClass))

#define JC_IS_BOY_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), JC_TYPE_BOY))

#define JC_BOY_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), JC_TYPE_BOY, JcBoyClass))

#define JC_BOY_GET_PRIVATE(obj)     (G_TYPE_INSTANCE_GET_PRIVATE ((obj), JC_TYPE_BOY, JcBoyPrivate))

typedef struct _JcBoy      JcBoy;
typedef struct _JcBoyClass   JcBoyClass;
typedef struct _JcBoyPrivate JcBoyPrivate;

/* object */
struct _JcBoy
{

    JcBaby parent_instance;

    /* public */ 

    // int public_int;

    /*< private >*/    
    JcBoyPrivate *priv;
};

/* class */
struct _JcBoyClass

{
    JcBabyClass parent_class;

    /* class members */

  
    /* Virtual method or signals*/

    void (*play)(JcBoy *self);
};

struct _JcBoyPrivate
{
  gchar *hobby;
};



void jc_boy_grow(JcBoy *self);
void jc_boy_change_name(JcBoy *self,gchar *name);
void jc_boy_play(JcBoy *self);
enum { JC_BOY_PLAY, JC_BOY_LAST_SIGNAL };

#endif
