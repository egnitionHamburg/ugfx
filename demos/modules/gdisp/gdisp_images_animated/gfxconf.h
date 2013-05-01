/* 
 * This source code form is a part of the ChibiOS/GFX project and stands
 * under the terms of the GFX License v1.0. If a copy of the license
 * was not distributed with this file, You can obtain one at: 
 * 
 * http://chibios-gfx.com/license.html
 *
 */

/**
 * This file has a different license to the rest of the GFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

#ifndef _GFXCONF_H
#define _GFXCONF_H

/* GFX sub-systems to turn on */
#define GFX_USE_GDISP			TRUE
#define GFX_USE_GWIN			FALSE
#define GFX_USE_GEVENT			FALSE
#define GFX_USE_GTIMER			FALSE
#define GFX_USE_GINPUT			FALSE

/* Features for the GDISP sub-system. */
#define GDISP_NEED_VALIDATION		TRUE
#define GDISP_NEED_CLIP				TRUE
#define GDISP_NEED_TEXT				FALSE
#define GDISP_NEED_CIRCLE			FALSE
#define GDISP_NEED_ELLIPSE			FALSE
#define GDISP_NEED_ARC				FALSE
#define GDISP_NEED_CONVEX_POLYGON	FALSE
#define GDISP_NEED_SCROLL			FALSE
#define GDISP_NEED_PIXELREAD		FALSE
#define GDISP_NEED_CONTROL			FALSE
#define GDISP_NEED_IMAGE			TRUE
#define GDISP_NEED_MULTITHREAD		FALSE
#define GDISP_NEED_ASYNC			FALSE
#define GDISP_NEED_MSGAPI			FALSE

/* Builtin Fonts */
#define GDISP_INCLUDE_FONT_SMALL		FALSE
#define GDISP_INCLUDE_FONT_LARGER		FALSE
#define GDISP_INCLUDE_FONT_UI1			FALSE
#define GDISP_INCLUDE_FONT_UI2			FALSE
#define GDISP_INCLUDE_FONT_LARGENUMBERS	FALSE

/* GDISP image decoders */
#define GDISP_NEED_IMAGE_NATIVE		FALSE
#define GDISP_NEED_IMAGE_GIF		TRUE
#define GDISP_NEED_IMAGE_BMP		FALSE
#define GDISP_NEED_IMAGE_JPG		FALSE
#define GDISP_NEED_IMAGE_PNG		FALSE
#define GDISP_NEED_IMAGE_ACCOUNTING	FALSE

/* Features for the GWIN sub-system. */
#define GWIN_NEED_BUTTON		FALSE
#define GWIN_NEED_CONSOLE		FALSE

/* Features for the GINPUT sub-system. */
#define GINPUT_NEED_MOUSE		FALSE

#endif /* _GFXCONF_H */
