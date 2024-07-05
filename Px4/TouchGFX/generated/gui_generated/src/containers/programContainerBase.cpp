/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/programContainerBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

programContainerBase::programContainerBase()
{
    setWidth(303);
    setHeight(40);
    programTxt.setPosition(40, 0, 263, 40);
    programTxt.setColor(touchgfx::Color::getColorFromRGB(130, 130, 130));
    programTxt.setLinespacing(0);
    Unicode::snprintf(programTxtBuffer, PROGRAMTXT_SIZE, "%s", touchgfx::TypedText(T_INVALID).getText());
    programTxt.setWildcard(programTxtBuffer);
    programTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3628));

    idTxt.setPosition(0, 0, 40, 40);
    idTxt.setColor(touchgfx::Color::getColorFromRGB(130, 130, 130));
    idTxt.setLinespacing(0);
    Unicode::snprintf(idTxtBuffer, IDTXT_SIZE, "%s", touchgfx::TypedText(T_INVALID).getText());
    idTxt.setWildcard(idTxtBuffer);
    idTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3629));

    add(programTxt);
    add(idTxt);
}

void programContainerBase::initialize()
{

}

