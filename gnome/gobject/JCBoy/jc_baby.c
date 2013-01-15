#include "jc_ihuman.h"
#include "jc_baby.h"

static void jc_ihuman_interface_init (JcIhumanInterface *iface);

 G_DEFINE_TYPE_WITH_CODE (JcBaby, jc_baby, G_TYPE_OBJECT,
                          G_IMPLEMENT_INTERFACE (JC_TYPE_IHUMAN,
                         jc_ihuman_interface_init));


 
 
static void speak()

{
    g_print("ne na nai ....suppose that I can talk now ! hi ! I'm just a baby !\n");

}
static void
jc_ihuman_interface_init(JcIhumanInterface *iface)

{
  iface->speak =speak;
}

//////////////////////
///
static void
jc_baby_set_property (GObject      *object, 
                        guint         property_id,
                        const GValue *value,
                        GParamSpec   *pspec)
{
  JcBaby *self = JC_BABY (object);


  switch (property_id)
    {
      case PROP_JC_AGE:
               self->priv->age = g_value_get_uint (value);
               g_print ("age : %d\n", self->priv->age);
               break;
      case PROP_JC_NAME:
          g_free (self->priv->name);
          self->priv->name= g_value_dup_string(value);
          g_print ("name : %s\n", self->priv->name);  
          break;
    default:
      /* We don't have any other property... */

      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);

      break;
    }
}
static void

jc_baby_get_property (GObject    *object,
                        guint       property_id,
                        GValue     *value,
                        GParamSpec *pspec)

{
  JcBaby *self = JC_BABY (object);


  switch (property_id)
    {
      case PROP_JC_AGE:
          g_value_set_uint (value, self->priv->age);
          break;
      case PROP_JC_NAME:
          g_value_set_string (value, self->priv->name);
          break;
      default:
          /* We don't have any other property... */
          G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
          break;
    }
}
///
static guint jc_baby_signals[JC_BABY_LAST_SIGNAL] = { 0 };



static void born(void)
{
	g_print("a baby was  born.\n");
}


static void grow(JcBaby *self)
{
    guint age=0;
    g_object_get(G_OBJECT(self),"age",&age,NULL);
    ++age;
    g_object_set(G_OBJECT(self),"age",age,NULL);


}



static void
jc_baby_dispose (GObject *gobject)
{
  JcBaby *self = JC_BABY (gobject);

  /* 
   * In dispose, you are supposed to free all types referenced from this
   * object which might themselves hold a reference to self. Generally,
   * the most simple solution is to unref all members on which you own a 
   * reference.
   */

  /* dispose might be called multiple times, so we must guard against
   * calling g_object_unref() on an invalid GObject.
   */
/////////////////
///如果私有部分包括有GObject对象，那么要将其unref一下
/////////////////
  // if (self->priv->an_object)
  //  {
  //   g_object_unref (self->priv->an_object);

  //   self->priv->an_object = NULL;
  // }

  /* Chain up to the parent class */
  G_OBJECT_CLASS (jc_baby_parent_class)->dispose (gobject);
}





static void
jc_baby_finalize(GObject *gobject)
{
  JcBaby *self =JC_BABY (gobject);

  g_free (self->priv->name);

  g_print("baby finalized !\n");

  /* Chain up to the parent class */
  G_OBJECT_CLASS (jc_baby_parent_class)->finalize (gobject);
}

 



static void
jc_baby_class_init (JcBabyClass *klass)

{
    g_type_class_add_private (klass, sizeof (JcBabyPrivate));

    klass->born = born;
    klass->grow=grow;

    jc_baby_signals[JC_BABY_BORN] =
      g_signal_new ("born", G_TYPE_FROM_CLASS (klass), G_SIGNAL_RUN_LAST,
      G_STRUCT_OFFSET (JcBabyClass, born), NULL, NULL,
      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
    jc_baby_signals[JC_BABY_GROW] =
      g_signal_new ("grow", G_TYPE_FROM_CLASS (klass), G_SIGNAL_RUN_LAST,
      G_STRUCT_OFFSET (JcBabyClass, grow), NULL, NULL,
      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);


    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
    GParamSpec *pspec;

    gobject_class->dispose=jc_baby_dispose;
    gobject_class->finalize=jc_baby_finalize;
    gobject_class->set_property = jc_baby_set_property;
    gobject_class->get_property = jc_baby_get_property;

    pspec = g_param_spec_uint ("age",
                              "the age ",
                              "Set/Get  age",
                              0  /* minimum value */,
                              150 /* maximum value */,
                              0  /* default value */,
                              G_PARAM_READWRITE);
   g_object_class_install_property (gobject_class,
                                   PROP_JC_AGE,
                                   pspec);



    pspec = g_param_spec_string ("name",
                              "the name ",
                              "Set/Get name",
                              "no-name-set" /* default value */,
                              G_PARAM_READWRITE);
   g_object_class_install_property (gobject_class,
                                   PROP_JC_NAME,
                                   pspec);


}


static void

jc_baby_init (JcBaby *self)
{

    /* Initialize all public and private members to reasonable default values. */
    
    /* Initialize public fields */

    //self->public_int = 100;

    //g_print("  initializing public_int to %d\n", self->public_int);

 

    /* Initialize private fields */

    g_signal_emit(self,jc_baby_signals[JC_BABY_BORN],0);

 

    JcBabyPrivate *priv;

    self->priv = priv = JC_BABY_GET_PRIVATE(self);

    priv->age=0;

    priv->name=g_strdup("no-name");

    g_object_set(G_OBJECT(self),"age",0,"name","no-name",NULL);

}


void jc_baby_grow(JcBaby *self)
{
    
    g_signal_emit(self,jc_baby_signals[JC_BABY_GROW],0);
    guint age=0;
    g_object_get(G_OBJECT(self),"age",&age,NULL);
    if(age>=3)
    {
        g_print("I'm not a baby now ,I want to grow up !\n");
    }
     
}

void jc_baby_give_name(JcBaby *self,gchar *name)
{
      g_object_set(G_OBJECT(self),"name",name,NULL);
      g_print("hi, my name is %s\n",name);
}



 









