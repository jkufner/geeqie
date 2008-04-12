/*
 * Geeqie
 * (C) 2006 John Ellis
 *
 * Author: John Ellis
 *
 * This software is released under the GNU General Public License (GNU GPL).
 * Please read the included file COPYING for more information.
 * This software comes with no warranty of any kind, use at your own risk!
 */


#ifndef MAIN_H
#define MAIN_H

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#ifdef HAVE_STRVERSCMP
#  ifndef _GNU_SOURCE
#    define _GNU_SOURCE
#  endif
#endif

#include "intl.h"

/*
 *-------------------------------------
 * Standard library includes
 *-------------------------------------
 */

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

/*
 *-------------------------------------
 * includes for glib / gtk / gdk-pixbuf
 *-------------------------------------
 */

#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk-pixbuf/gdk-pixbuf-loader.h>


/*
 *----------------------------------------------------------------------------
 * defines
 *----------------------------------------------------------------------------
 */

#define GQ_APPNAME "Geeqie"
#define GQ_APPNAME_LC "geeqie"
#define GQ_WEBSITE "geeqie.sourceforge.net"
#define GQ_EMAIL_ADDRESS "geeqie-devel@lists.sourceforge.net"

#define GQ_WMCLASS GQ_APPNAME_LC

#define GQ_RC_DIR             "." GQ_APPNAME_LC
#define GQ_RC_DIR_COLLECTIONS GQ_RC_DIR"/collections"
#define GQ_RC_DIR_TRASH       GQ_RC_DIR"/trash"

#define RC_FILE_NAME GQ_APPNAME_LC "rc"

#define ZOOM_RESET_ORIGINAL 0
#define ZOOM_RESET_FIT_WINDOW 1
#define ZOOM_RESET_NONE 2

#define SCROLL_RESET_TOPLEFT 0
#define SCROLL_RESET_CENTER 1
#define SCROLL_RESET_NOCHANGE 2

#define MOUSEWHEEL_SCROLL_SIZE 20

#define GQ_EDITOR_GENERIC_SLOTS 10

#define COLOR_PROFILE_INPUTS 4

#define DEFAULT_THUMB_WIDTH	96
#define DEFAULT_THUMB_HEIGHT	72

#if 1 /* set to 0 to disable debugging code and related options */
# ifndef DEBUG
# define DEBUG 1
# endif
#endif
#ifndef DEBUG
# define debug 0
#endif

#include "typedefs.h"

/*
 *----------------------------------------------------------------------------
 * globals
 *----------------------------------------------------------------------------
 */
ConfOptions *init_options(ConfOptions *options); /* TODO: move to globals.h */

ConfOptions *options;



#ifdef DEBUG
extern gint debug;
#endif



/*
 *----------------------------------------------------------------------------
 * main.c
 *----------------------------------------------------------------------------
 */

/*
 * This also doubles as the main.c header.
 */

GtkWidget *window_new(GtkWindowType type, const gchar *name, const gchar *icon,
		      const gchar *icon_file, const gchar *subtitle);
void window_set_icon(GtkWidget *window, const gchar *icon, const gchar *file);
gint window_maximized(GtkWidget *window);

gdouble get_zoom_increment(void);

void help_window_show(const gchar *key);

void keyboard_scroll_calc(gint *x, gint *y, GdkEventKey *event);
gint key_press_cb(GtkWidget *widget, GdkEventKey *event, gpointer data);
void exit_program(void);

#define CASE_SORT(a, b) ( (options->file_sort.case_sensitive) ? strcmp((a), (b)) : strcasecmp((a), (b)) )


#endif


