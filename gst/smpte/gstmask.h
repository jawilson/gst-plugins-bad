/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_MASK_H__
#define __GST_MASK_H__

#include <gst/gst.h>


typedef struct _GstMask GstMask;
typedef struct _GstMaskDefinition GstMaskDefinition;

typedef GstMask* 	(*GstMaskNewFunc)		(GstMaskDefinition *definition,
							 gint bpp, gint width, gint height);
typedef void	 	(*GstMaskDestroyFunc)		(GstMask *mask);
typedef void	 	(*GstMaskUpdateFunc)		(GstMask *mask, 
		 					 GstClockTime position, 
							 GstClockTime duration);
struct _GstMaskDefinition {
  gint 			 type;
  gchar 		*short_name;
  gchar 		*long_name;
  GstMaskNewFunc	 new_func;
  GstMaskDestroyFunc	 destroy_func;
  GstMaskUpdateFunc	 update_func;
};

struct _GstMask {
  gint 			 type;
  guint8 		*data;

  gint			 width;
  gint			 height;
  gint			 bpp;

  GstMaskUpdateFunc 	 update_func;
  GstMaskDestroyFunc 	 destroy_func;
};

void			_gst_mask_init			(void);
void			_gst_mask_register		(GstMaskDefinition *definition);

GstMask*		_gst_mask_default_new 		(GstMaskDefinition *definition,
		 					 gint bpp, gint width, gint height);
void			_gst_mask_default_destroy	(GstMask *mask);

const GList*		gst_mask_get_definitions	(void);
GstMask*		gst_mask_factory_new 		(gint type, gint bpp, gint width, gint height);
void			gst_mask_destroy		(GstMask *mask);

void			gst_mask_update 		(GstMask *mask,
							 GstClockTime position, 
							 GstClockTime duration);


#endif /* __GST_MASK_H__ */
