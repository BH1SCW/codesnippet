#ifndef __JC_BABY__
#define __JC_BABY__

#include <gtk/gtk.h>
#include "jc_oth.h"
 


#define JC_TYPE_BABY                  (jc_baby_get_type ())

#define JC_BABY(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), JC_TYPE_BABY, JcBaby))

#define JC_IS_BABY(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), JC_TYPE_BABY))

#define JC_BABY_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), JC_TYPE_BABY, JcBabyClass))

#define JC_IS_BABY_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), JC_TYPE_BABY))

#define JC_BABY_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), JC_TYPE_BABY, JcBabyClass))

#define JC_BABY_GET_PRIVATE(obj)     (G_TYPE_INSTANCE_GET_PRIVATE ((obj), JC_TYPE_BABY, JcBabyPrivate))

typedef struct _JcBaby      JcBaby;
typedef struct _JcBabyClass   JcBabyClass;
typedef struct _JcBabyPrivate JcBabyPrivate;

/* object */
struct _JcBaby
{

    GObject parent_instance;

    /* public */ 
    //一般的成员对象尽量放在pri中
    // int public_int;

    /*< private >*/    
    JcBabyPrivate *priv;
};

/* class */
struct _JcBabyClass

{
    GObjectClass parent_class;

    /* class members */

  
    /* Virtual method or signals*/
   // void (*speak) (JcBaby *self);
    void (*born)(void);
    void (*grow)(JcBaby *self);
};

struct _JcBabyPrivate
{
  guint age;
  gchar *name;
 
};


enum { JC_BABY_BORN,JC_BABY_GROW, JC_BABY_LAST_SIGNAL };
void jc_baby_grow(JcBaby *self);
void jc_baby_give_name(JcBaby *self,gchar *name);
#endif
