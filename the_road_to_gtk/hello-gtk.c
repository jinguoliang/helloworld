/*
*filename:	hello-gtk.c
*author: 	Jinux
*create:	2014年05月02日 星期五 22时47分07秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <glib-object.h>

#define MAMAN_TYPE_BAR 			(maman_bar_get_type())
#define MAMAN_BAR(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj),MAMAN_TYPE_BAR,MamanBar))
#define MAMAN_IS_BAR(obj) 		(G_TYPE_CHECK_INSTANCE_TYPE ((obj),MAMAN_TYPE_BAR))
#define MAMAN_BAR_CLASS(kclass)	(G_TYPE_CHECK_CLASS_CAST((kclass),MAMAN_TYPE_BAR,MamanBarClass))
#define MAMAN_IS_BAR_CLASS(kclass) (G_TYPE_CHECK_CLASS_TYPE ((kclass),MAMAN_TYPE_BAR))
#define MAMAN_BAR_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS((obj),MAMAN_TYPE_BAR,MamanBarClass))

typedef struct _MamanBar MamanBar;
typedef struct _MamanBarClass MamanBarClass;

struct _MamanBar{
	GObject  parent_instance;

};

struct _MamanBarClass {
	GObjectClass parent_class;

};

GType maman_bar_get_type(void);


int main(int argc,char *argv[])
{


	return 0;
}

