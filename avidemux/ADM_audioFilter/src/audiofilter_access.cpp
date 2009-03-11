/***************************************************************************
            \file audiofilter_access.cpp
            \brief convert audiofilter to audioaccess (used for playback for example)
            (C) Mean 2009 fixounet@free.fr
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "ADM_default.h"
#include <math.h>

#include "ADM_audioFilter.h"
#include "audiofilter_access.h"
/**
    \fn ADMAudioFilter_Access
*/
ADMAudioFilter_Access::ADMAudioFilter_Access(AUDMAudioFilter *incoming,uint64_t timeUs)
{
    filter=incoming;
    ADM_assert(filter);
    startTimeUs=timeUs;
    memcpy(&header,incoming->getInfo(),sizeof(header));
    
    printf("[FilterAccess] Created, starting at %"LU" ms\n",(uint32_t)(timeUs/1000));
}
/**
    \fn ~ADMAudioFilter_Access
*/
ADMAudioFilter_Access::~ADMAudioFilter_Access()
{
    printf("[FilterAccess] Destroyed\n");
}
/**
    \fn setPos
    \brief only goto 0 is allowed
*/
bool      ADMAudioFilter_Access::setPos(uint64_t pos)
{
    return filter->rewind();
}
/**
    \fn getPos
*/
              
uint64_t  ADMAudioFilter_Access::getPos(void)
{
    return 0;
}
           
/**
    \fn getPacket
*/                
bool    ADMAudioFilter_Access::getPacket(uint8_t *buffer, uint32_t *size, uint32_t maxSize,uint64_t *dts)
{

}
//EOF
