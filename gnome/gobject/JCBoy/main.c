#include <stdio.h>
#include "jc_ihuman.h"
#include "jc_baby.h"
#include "jc_boy.h"
int main (int argc, char *argv[])
{
  g_print("********************************\n");
  g_print("******init the type system******\n");
  g_print("********************************\n");
  g_type_init();
  g_print(">>>>>>>>>init completed<<<<<<<<<\n");


  g_print("********************************\n");
  g_print("******test the baby object******\n");
  g_print("********************************\n");
  JcBaby *baby = g_object_new (JC_TYPE_BABY, NULL);
  jc_baby_give_name(baby,"Tom");
  
  jc_people_talk(baby);

  jc_baby_grow(baby);
  jc_baby_grow(baby);
  jc_baby_grow(baby);
  jc_baby_grow(baby);

  


  g_print("*******************************\n");
  g_print("******test the boy object******\n");
  g_print("*******************************\n");
  
 

 
  JcBoy *boy = g_object_new (JC_TYPE_BOY, NULL);
  jc_baby_give_name(boy,"Mike");
  jc_people_talk(boy);

  jc_boy_grow(boy);

  jc_boy_play(boy);

  jc_boy_grow(boy);

  jc_boy_change_hobby(boy,"playing football");
  jc_boy_play(boy);

  jc_boy_change_name(boy,"Mac");

  g_print("*******************************\n");
  g_print("******test the trans func******\n");
  g_print("*******************************\n");

  jc_people_talk(JC_BABY(boy));


  //should see the warning : GLib-GObject-WARNING **: invalid cast from `JcBaby' to `JcBoy'
  jc_people_talk(JC_BOY(baby));


  g_print("*******************************\n");
  g_print("******test the unref func******\n");
  g_print("*******************************\n");

  g_print(">>unref a baby<<\n");
  g_object_unref(baby);
  g_print(">>unref a boy<<\n");
  g_object_unref(boy);
  return(0);
}

