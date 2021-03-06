/*
 * gst-droid
 *
 * Copyright (C) 2015 Jolla LTD.
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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_DROID_MEDIA_BUFFER_H__
#define __GST_DROID_MEDIA_BUFFER_H__

#include <gst/gst.h>
#include <gst/video/video.h>
#include "droidmedia.h"

G_BEGIN_DECLS

#define GST_ALLOCATOR_DROID_MEDIA_BUFFER                    "droidmediabuffer"
#define GST_CAPS_FEATURE_MEMORY_DROID_MEDIA_BUFFER          "memory:DroidMediaBuffer"

GstAllocator * gst_droid_media_buffer_allocator_new (void);
GstMemory    * gst_droid_media_buffer_allocator_alloc (GstAllocator * allocator,
                                                       DroidMediaBufferQueue *queue,
						       DroidMediaBufferCallbacks *cb);
GstMemory    * gst_droid_media_buffer_allocator_alloc_from_data (GstAllocator * allocator,
								 gsize w, gsize h,
								 DroidMediaData * data,
								 DroidMediaBufferCallbacks *cb);

DroidMediaBuffer * gst_droid_media_buffer_memory_get_buffer (GstMemory * mem);
gboolean       gst_is_droid_media_buffer_memory (GstMemory * mem);

G_END_DECLS

#endif /* __GST_DROID_MEDIA_BUFFER_H__ */
