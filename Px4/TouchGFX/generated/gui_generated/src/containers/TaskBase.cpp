/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/TaskBase.hpp>
#include "BitmapDatabase.hpp"

TaskBase::TaskBase() :
    callCallback(0),
    beginCallback(0)
{
    setWidth(48);
    setHeight(48);
    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_BRACKETS_BLOCK_CODEBLOCK_SCRIPT_CODING_ICON_146012_ID));

    add(image1);
}

void TaskBase::initialize()
{

}

void TaskBase::setWaitTime(uint32_t value)
{

}

void TaskBase::run()
{

}

void TaskBase::interrupt()
{

}
