/* 
 * This source code form is a part of the ChibiOS/GFX project and stands
 * under the terms of the GFX License v1.0. If a copy of the license
 * was not distributed with this file, You can obtain one at: 
 * 
 * http://chibios-gfx.com/license.html
 *
 */

/*
 * Copyright (c) 2012, 2013, Joel Bodenmann aka Tectu <joel@unormal.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the <organization> nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "math.h"

const GGraphPoint data[5] = {
	{ -40, -40 },
	{ 70, 40 },
	{ 140, 60 },
	{ 210, 60 },
	{ 280, 200 }
};

GGraphObject	g;

GGraphStyle GraphStyle1 = {
	{ GGRAPH_POINT_DOT, 0, Blue },			// point
	{ GGRAPH_LINE_NONE, 2, Gray },			// line
	{ GGRAPH_LINE_SOLID, 0, White },		// x axis
	{ GGRAPH_LINE_SOLID, 0, White },		// y axis
	{ GGRAPH_LINE_DASH, 5, Gray, 50 },		// x grid
	{ GGRAPH_LINE_DOT, 7, Yellow, 50 },		// y grid
	GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS	// flags
};

GGraphStyle GraphStyle2 = {
	{ GGRAPH_POINT_SQUARE, 5, Red },		// point
	{ GGRAPH_LINE_DOT, 2, Pink },			// line
	{ GGRAPH_LINE_SOLID, 0, White },		// x axis
	{ GGRAPH_LINE_SOLID, 0, White },		// y axis
	{ GGRAPH_LINE_DASH, 5, Gray, 50 },		// x grid
	{ GGRAPH_LINE_DOT, 7, Yellow, 50 },		// y grid
	GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS	// flags
};

int main(void) {
	GHandle		gh;
	uint16_t 	i;
	
	halInit();
	chSysInit();

	gdispInit();
	gdispClear(Black);
	
	gh = gwinCreateGraph(&g, 0, 0, gdispGetWidth(), gdispGetHeight());

	gwinGraphSetOrigin(gh, gwinGetWidth(gh)/2, gwinGetHeight(gh)/2);
	gwinGraphSetStyle(gh, &GraphStyle1);
	gwinGraphDrawAxis(gh);
	
	for(i = 0; i < gwinGetWidth(gh); i++)
		gwinGraphDrawPoint(gh, i-gwinGetWidth(gh)/2, 80*sin(2*0.2*M_PI*i/180));

	gwinGraphStartSet(gh);
	GraphStyle1.point.color = Green;
	gwinGraphSetStyle(gh, &GraphStyle1);
	
	for(i = 0; i < gwinGetWidth(gh)*5; i++)
		gwinGraphDrawPoint(gh, i/5-gwinGetWidth(gh)/2, 95*sin(2*0.2*M_PI*i/180));

	gwinGraphStartSet(gh);
	gwinGraphSetStyle(gh, &GraphStyle2);

	gwinGraphDrawPoints(gh, data, sizeof(data)/sizeof(data[0]));

	while(TRUE) {
		chThdSleepMilliseconds(100);	
	}
}

