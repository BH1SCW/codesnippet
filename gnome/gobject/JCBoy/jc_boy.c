 
#include "jc_boy.h"

static void jc_ihuman_interface_init (JcIhumanInterface *iface);

G_DEFINE_TYPE_WITH_CODE (JcBoy, jc_boy, JC_TYPE_BABY,//);
                        G_IMPLEMENT_INTERFACE (JC_TYPE_IHUMAN,
                        jc_ihuman_interface_init));
 
static void speak()

{
    g_print("la la la ... haha ! I'm  a boy now !\n");
}
static void
jc_ihuman_interface_init(JcIhumanInterface *iface)

{
  iface->speak =speak;
}

//////////////////////
///
static void
jc_boy_set_property (GObject      *object,
                        guint         property_id,
                        const GValue *value,
                        GParamSpec   *pspec)
{
  JcBoy *self = JC_BOY (object);
  switch (property_id)
    {
      case PROP_JC_HOBBY:
                g_free (self->priv->hobby);
                self->priv->hobby= g_value_dup_string(value);
                g_print ("my hobby is : %s\n", self->priv->hobby);  
                break;
    default:
      /* We don't have any other property... */

      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);

      break;
    }
}
static void

jc_boy_get_property (GObject    *object,
                        guint       property_id,
                        GValue     *value,
                        GParamSpec *pspec)

{
  JcBoy *self = JC_BOY (object);

  switch (property_id)
    {
      case PROP_JC_HOBBY:
          g_value_set_string (value, self->priv->hobby);
          break;
      default:
          /* We don't have any other property... */
          G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
          break;
    }
}
///
static guint jc_boy_signals[JC_BOY_LAST_SIGNAL] = { 0 };



static void grow(JcBoy *self)
{
    guint age=0;
    g_object_get(G_OBJECT(self),"age",&age,NULL);
    ++age;
    g_object_set(G_OBJECT(self),"age",age,NULL);
}

static void play(JcBoy *self)
{
    gchar *play;
    g_object_get(G_OBJECT(self),"hobby",&play,NULL);
    g_print("the boy is %s\n",play);
}

 
static void
jc_boy_dispose (GObject *gobject)
{
  JcBoy *self = JC_BOY (gobject);

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
  G_OBJECT_CLASS (jc_boy_parent_class)->dispose (gobject);
}





static void
jc_boy_finalize(GObject *gobject)
{
  JcBoy *self =JC_BOY (gobject);

  g_free (self->priv->hobby);

  g_print("boy finalized !\n");

  /* Chain up to the parent class */
  G_OBJECT_CLASS (jc_boy_parent_class)->finalize (gobject);
}


static void
jc_boy_class_init (JcBoyClass *klass)

{
    g_type_class_add_private (klass, sizeof (JcBoyPrivate));

    klass->play=play;

   jc_boy_signals[JC_BOY_PLAY] =
      g_signal_new ("play", G_TYPE_FROM_CLASS (klass), G_SIGNAL_RUN_LAST,
      G_STRUCT_OFFSET (JcBoyClass, play), NULL, NULL,
      g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);


    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
    GParamSpec *pspec;

    gobject_class->constructor;
    gobject_class->dispose=jc_boy_dispose;
    gobject_class->finalize=jc_boy_finalize;
    gobject_class->set_property = jc_boy_set_property;
    gobject_class->get_property = jc_boy_get_property;

    pspec = g_param_spec_string ("hobby",
                              "the hobby y",
                              "Set/Get  hobby",
                              "nothing" /* default value */,
                              G_PARAM_READWRITE);
   g_object_class_install_property (gobject_class,
                                   PROP_JC_HOBBY,
                                   pspec);
}

static void
jc_boy_init (JcBoy *self)
{

    g_print("a baby grow up , then become a boy !\n");

    g_object_set(G_OBJECT(self),"age",3,NULL);

    JcBoyPrivate *priv;

    self->priv = priv = JC_BOY_GET_PRIVATE(self);

    priv->hobby=g_strdup("playing basketball");

    g_object_set(G_OBJECT(self),"hobby","playing basketball",NULL);

}

void jc_boy_grow(JcBoy *self)
{
    
    g_signal_emit_by_name(self,"grow");
    guint age=0;
    g_object_get(G_OBJECT(self),"age",&age,NULL);
    if(age<3)
    {
        g_print("oh ! babyhood !\n");
    }
 
    if(age>=15)
    {
        g_print("I'm not just a boy now ,I want to be a man , a super hero !\n");
    }

}

void jc_boy_change_hobby(JcBoy *self,gchar *hobby)
{

      g_object_set(self,"hobby",hobby,NULL);
      g_print("recently I'm interested in %s\n",hobby);
}

void jc_boy_change_name(JcBoy *self,gchar *name)
{

      g_object_set(self,"name",name,NULL);
      g_print("hi, my name is changed , now my name is %s\n",name);
}
void jc_boy_play(JcBoy *self)
{
    g_signal_emit(self,jc_boy_signals[JC_BOY_PLAY],0);
}




 
 








