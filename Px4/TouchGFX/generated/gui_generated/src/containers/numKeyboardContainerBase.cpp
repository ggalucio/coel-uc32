/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/numKeyboardContainerBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"
#include <AT_module.hpp>


numKeyboardContainerBase::numKeyboardContainerBase() :
    buttonCallback(this, &numKeyboardContainerBase::buttonCallbackHandler),
    flexButtonCallback(this, &numKeyboardContainerBase::flexButtonCallbackHandler),
    HideKeypadTriggerCallback(0),
    OutOfRangeCallback(0),
    ValidRangeCallback(0),
    EnterCallback(0)
{
    setWidth(480);
    setHeight(272);
    backgroundFlexButton.setBoxWithBorderPosition(0, 0, 480, 272);
    backgroundFlexButton.setBorderSize(5);
    backgroundFlexButton.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    backgroundFlexButton.setPosition(0, 0, 480, 272);

    backgroundBox.setPosition(0, 0, 480, 272);
    backgroundBox.setColor(touchgfx::Color::getColorFromRGB(69, 69, 69));

    keyboardBox.setPosition(35, 0, 410, 272);
    keyboardBox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    textBox.setPosition(144, 11, 192, 38);
    textBox.setColor(touchgfx::Color::getColorFromRGB(129, 129, 129));
    textBox.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textBox.setBorderSize(2);

    valTxt.setPosition(144, 11, 192, 38);
    valTxt.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    valTxt.setLinespacing(0);
    Unicode::snprintf(valTxtBuffer, VALTXT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4).getText());
    valTxt.setWildcard(valTxtBuffer);
    valTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3));

    dotBtn.setXY(43, 218);
    dotBtn.setBitmaps(touchgfx::Bitmap(BITMAP_DOT_RELEASED_ID), touchgfx::Bitmap(BITMAP_DOT_PRESSED_ID));
    dotBtn.setAction(buttonCallback);

    delBtn.setXY(245, 218);
    delBtn.setBitmaps(touchgfx::Bitmap(BITMAP_DEL_RELEASED_ID), touchgfx::Bitmap(BITMAP_DEL_PRESSED_ID));
    delBtn.setAction(buttonCallback);

    zeroBtn.setXY(144, 218);
    zeroBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    zeroBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID33));
    zeroBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    zeroBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    zeroBtn.setAction(buttonCallback);

    oneBtn.setXY(43, 58);
    oneBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    oneBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID34));
    oneBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    oneBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    oneBtn.setAction(buttonCallback);

    twoBtn.setXY(144, 58);
    twoBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    twoBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID35));
    twoBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    twoBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    twoBtn.setAction(buttonCallback);

    threeBtn.setXY(245, 58);
    threeBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    threeBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID36));
    threeBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    threeBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    threeBtn.setAction(buttonCallback);

    fourBtn.setXY(43, 113);
    fourBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    fourBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID37));
    fourBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fourBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fourBtn.setAction(buttonCallback);

    fiveBtn.setXY(144, 113);
    fiveBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    fiveBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID38));
    fiveBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fiveBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fiveBtn.setAction(buttonCallback);

    sixBtn.setXY(245, 113);
    sixBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    sixBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID39));
    sixBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    sixBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    sixBtn.setAction(buttonCallback);

    sevenBtn.setXY(43, 166);
    sevenBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    sevenBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID40));
    sevenBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    sevenBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    sevenBtn.setAction(buttonCallback);

    eightBtn.setXY(144, 166);
    eightBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    eightBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID41));
    eightBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    eightBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    eightBtn.setAction(buttonCallback);

    nineBtn.setXY(245, 166);
    nineBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    nineBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID42));
    nineBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nineBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    nineBtn.setAction(buttonCallback);

    cancelBtn.setXY(346, 166);
    cancelBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    cancelBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID108));
    cancelBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    cancelBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    cancelBtn.setAction(buttonCallback);

    okBtn.setXY(346, 218);
    okBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    okBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID109));
    okBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    okBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    okBtn.setAction(buttonCallback);

    signBtn.setXY(346, 58);
    signBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    signBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID110));
    signBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    signBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    signBtn.setAction(buttonCallback);

    clearBtn.setXY(346, 113);
    clearBtn.setBitmaps(touchgfx::Bitmap(BITMAP_NUMKEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_NUMKEY_PRESSED_ID));
    clearBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID111));
    clearBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    clearBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    clearBtn.setAction(buttonCallback);

    minBox.setPosition(43, 23, 91, 26);
    minBox.setColor(touchgfx::Color::getColorFromRGB(129, 129, 129));
    minBox.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    minBox.setBorderSize(2);

    maxBox.setPosition(346, 23, 91, 26);
    maxBox.setColor(touchgfx::Color::getColorFromRGB(129, 129, 129));
    maxBox.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    maxBox.setBorderSize(2);

    minLbl.setXY(75, 4);
    minLbl.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    minLbl.setLinespacing(0);
    minLbl.setTypedText(touchgfx::TypedText(T_SINGLEUSEID520));

    maxLbl.setXY(378, 4);
    maxLbl.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    maxLbl.setLinespacing(0);
    maxLbl.setTypedText(touchgfx::TypedText(T_SINGLEUSEID521));

    minTxt.setPosition(43, 23, 91, 26);
    minTxt.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    minTxt.setLinespacing(0);
    Unicode::snprintf(minTxtBuffer, MINTXT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID523).getText());
    minTxt.setWildcard(minTxtBuffer);
    minTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID522));

    maxTxt.setPosition(346, 23, 91, 26);
    maxTxt.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    maxTxt.setLinespacing(0);
    Unicode::snprintf(maxTxtBuffer, MAXTXT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID525).getText());
    maxTxt.setWildcard(maxTxtBuffer);
    maxTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID524));

    errTxt.setPosition(144, 17, 192, 26);
    errTxt.setVisible(false);
    errTxt.setColor(touchgfx::Color::getColorFromRGB(180, 22, 22));
    errTxt.setLinespacing(0);
    errTxt.setTypedText(touchgfx::TypedText(T_RESOURCEOUTOFRANGEID));

    add(backgroundFlexButton);
    add(backgroundBox);
    add(keyboardBox);
    add(textBox);
    add(valTxt);
    add(dotBtn);
    add(delBtn);
    add(zeroBtn);
    add(oneBtn);
    add(twoBtn);
    add(threeBtn);
    add(fourBtn);
    add(fiveBtn);
    add(sixBtn);
    add(sevenBtn);
    add(eightBtn);
    add(nineBtn);
    add(cancelBtn);
    add(okBtn);
    add(signBtn);
    add(clearBtn);
    add(minBox);
    add(maxBox);
    add(minLbl);
    add(maxLbl);
    add(minTxt);
    add(maxTxt);
    add(errTxt);
}

void numKeyboardContainerBase::initialize()
{

}

void numKeyboardContainerBase::LaunchNumericalKeyboard()
{
    //ContainerIsEntered
    //When LaunchNumericalKeyboard is called execute C++ code
    //Execute C++ code
    VisibilityTextArea(&errTxt, false);
    VisibilityTextArea(&valTxt, true);
    InitNumKeyboard(&valTxt, valTxtBuffer, &minTxt, minTxtBuffer, &maxTxt, maxTxtBuffer, 10, &errTxt);
}

void numKeyboardContainerBase::OutOfRangeMsg()
{
    //OutOfRangeFired
    //When OutOfRangeMsg is called execute C++ code
    //Execute C++ code
    VisibilityTextArea(&errTxt, true);
    VisibilityTextArea(&valTxt, false);
}

void numKeyboardContainerBase::InputValidRange()
{
    //ValidRangeFired
    //When InputValidRange is called emit HideKeypadTrigger callback
    //Emit callback
    emitHideKeypadTriggerCallback();
}

void numKeyboardContainerBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &dotBtn)
    {
        //DotBtnClicked
        //When dotBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('.');
        SoundBuzzerOn(25);
    }
    else if (&src == &delBtn)
    {
        //DeleteBtnClicked
        //When delBtn clicked execute C++ code
        //Execute C++ code
        RemoveNumKeyboard();
        SoundBuzzerOn(25);
    }
    else if (&src == &zeroBtn)
    {
        //ZeroBtnClicked
        //When zeroBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('0');
        SoundBuzzerOn(25);
    }
    else if (&src == &oneBtn)
    {
        //OneBtnClicked
        //When oneBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('1');
        SoundBuzzerOn(25);
    }
    else if (&src == &twoBtn)
    {
        //TwoBtnClicked
        //When twoBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('2');
        SoundBuzzerOn(25);
    }
    else if (&src == &threeBtn)
    {
        //ThreeBtnClicked
        //When threeBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('3');
        SoundBuzzerOn(25);
    }
    else if (&src == &fourBtn)
    {
        //FourBtnClicked
        //When fourBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('4');
        SoundBuzzerOn(25);
    }
    else if (&src == &fiveBtn)
    {
        //FiveBtnClicked
        //When fiveBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('5');
        SoundBuzzerOn(25);
    }
    else if (&src == &sixBtn)
    {
        //SixBtnClicked
        //When sixBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('6');
        SoundBuzzerOn(25);
    }
    else if (&src == &sevenBtn)
    {
        //SevenBtnClicked
        //When sevenBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('7');
        SoundBuzzerOn(25);
    }
    else if (&src == &eightBtn)
    {
        //EightBtnClicked
        //When eightBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('8');
        SoundBuzzerOn(25);
    }
    else if (&src == &nineBtn)
    {
        //NineBtnClicked
        //When nineBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('9');
        SoundBuzzerOn(25);
    }
    else if (&src == &cancelBtn)
    {
        //CancelBtnClicked
        //When cancelBtn clicked emit HideKeypadTrigger callback
        //Emit callback
        emitHideKeypadTriggerCallback();
    }
    else if (&src == &okBtn)
    {
        //OkBtnClicked
        //When okBtn clicked execute C++ code
        //Execute C++ code
        UpdateNumKeyboardReference(ValidRangeCallback, OutOfRangeCallback);
        SoundBuzzerOn(25);

        //EmitEnter
        //When OkBtnClicked completed execute C++ code
        //Execute C++ code
        if (!(this->isVisible())) emitEnterCallback();
    }
    else if (&src == &signBtn)
    {
        //SignBtnPressed
        //When signBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('+');
        SoundBuzzerOn(25);
    }
    else if (&src == &clearBtn)
    {
        //ClearBtnPressed
        //When clearBtn clicked execute C++ code
        //Execute C++ code
        AddNumKeyboard('<');
        SoundBuzzerOn(25);
    }
}

void numKeyboardContainerBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
}

