/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/programCenterContainerBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

programCenterContainerBase::programCenterContainerBase()
{
    setWidth(303);
    setHeight(40);
    programTxt.setPosition(40, 0, 263, 40);
    programTxt.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    programTxt.setLinespacing(0);
    Unicode::snprintf(programTxtBuffer, PROGRAMTXT_SIZE, "%s", touchgfx::TypedText(T_INVALID).getText());
    programTxt.setWildcard(programTxtBuffer);
    programTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3630));

    idTxt.setPosition(0, 0, 40, 40);
    idTxt.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    idTxt.setLinespacing(0);
    Unicode::snprintf(idTxtBuffer, IDTXT_SIZE, "%s", touchgfx::TypedText(T_INVALID).getText());
    idTxt.setWildcard(idTxtBuffer);
    idTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3631));

    add(programTxt);
    add(idTxt);
}

void programCenterContainerBase::initialize()
{

}

