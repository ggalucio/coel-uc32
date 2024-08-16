/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/keyboardContainer2Base.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"
#include <AT_module.hpp>


keyboardContainer2Base::keyboardContainer2Base() :
    buttonCallback(this, &keyboardContainer2Base::buttonCallbackHandler),
    flexButtonCallback(this, &keyboardContainer2Base::flexButtonCallbackHandler),
    HideKeyboardCallback(0)
{
    setWidth(480);
    setHeight(272);
    backgroundFlexButton.setBoxWithBorderPosition(0, 0, 480, 272);
    backgroundFlexButton.setBorderSize(5);
    backgroundFlexButton.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    backgroundFlexButton.setPosition(0, 0, 480, 272);

    backgroundBox.setPosition(0, 0, 480, 272);
    backgroundBox.setColor(touchgfx::Color::getColorFromRGB(69, 69, 69));

    keyboardBox.setPosition(21, 0, 438, 272);
    keyboardBox.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    textBox.setPosition(27, 21, 426, 38);
    textBox.setColor(touchgfx::Color::getColorFromRGB(129, 129, 129));
    textBox.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textBox.setBorderSize(2);

    valTxt.setPosition(44, 21, 393, 38);
    valTxt.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    valTxt.setLinespacing(0);
    valTxtBuffer[0] = 0;
    valTxt.setWildcard(valTxtBuffer);
    valTxt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4064));

    qTxt.setXY(27, 72);
    qTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    qTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4065));
    qTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    qTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    qTxt.setAction(buttonCallback);

    wTxt.setXY(66, 72);
    wTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    wTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4066));
    wTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    wTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    wTxt.setAction(buttonCallback);

    eTxt.setXY(105, 72);
    eTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    eTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4067));
    eTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    eTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    eTxt.setAction(buttonCallback);

    rTxt.setXY(144, 72);
    rTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    rTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4068));
    rTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    rTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    rTxt.setAction(buttonCallback);

    tTxt.setXY(183, 72);
    tTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    tTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4069));
    tTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    tTxt.setAction(buttonCallback);

    yTxt.setXY(222, 72);
    yTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    yTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4070));
    yTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    yTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    yTxt.setAction(buttonCallback);

    uTxt.setXY(261, 72);
    uTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    uTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4071));
    uTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    uTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    uTxt.setAction(buttonCallback);

    iTxt.setXY(300, 72);
    iTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    iTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4072));
    iTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    iTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    iTxt.setAction(buttonCallback);

    oTxt.setXY(339, 72);
    oTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    oTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4073));
    oTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    oTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    oTxt.setAction(buttonCallback);

    pTxt.setXY(378, 72);
    pTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    pTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4074));
    pTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    pTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    pTxt.setAction(buttonCallback);

    slashTxt.setXY(417, 72);
    slashTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    slashTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4075));
    slashTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    slashTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    slashTxt.setAction(buttonCallback);

    aTxt.setXY(27, 116);
    aTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    aTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4076));
    aTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    aTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    aTxt.setAction(buttonCallback);

    sTxt.setXY(66, 116);
    sTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    sTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4077));
    sTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    sTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    sTxt.setAction(buttonCallback);

    dTxt.setXY(105, 116);
    dTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    dTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4078));
    dTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    dTxt.setAction(buttonCallback);

    fTxt.setXY(144, 116);
    fTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    fTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4079));
    fTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    fTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fTxt.setAction(buttonCallback);

    gTxt.setXY(183, 116);
    gTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    gTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4080));
    gTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    gTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    gTxt.setAction(buttonCallback);

    hTxt.setXY(222, 116);
    hTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    hTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4081));
    hTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    hTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    hTxt.setAction(buttonCallback);

    jTxt.setXY(261, 116);
    jTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    jTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4082));
    jTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    jTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    jTxt.setAction(buttonCallback);

    kTxt.setXY(300, 116);
    kTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    kTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4083));
    kTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    kTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    kTxt.setAction(buttonCallback);

    lTxt.setXY(339, 116);
    lTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    lTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4084));
    lTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    lTxt.setAction(buttonCallback);

    dotsTxt.setXY(378, 116);
    dotsTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    dotsTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4085));
    dotsTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dotsTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    dotsTxt.setAction(buttonCallback);

    dotcommaTxt.setXY(417, 116);
    dotcommaTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    dotcommaTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4086));
    dotcommaTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dotcommaTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    dotcommaTxt.setAction(buttonCallback);

    zTxt.setXY(105, 160);
    zTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    zTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4087));
    zTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    zTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    zTxt.setAction(buttonCallback);

    xTxt.setXY(144, 160);
    xTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    xTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4088));
    xTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    xTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    xTxt.setAction(buttonCallback);

    cTxt.setXY(183, 160);
    cTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    cTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4089));
    cTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    cTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    cTxt.setAction(buttonCallback);

    vTxt.setXY(222, 160);
    vTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    vTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4090));
    vTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    vTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    vTxt.setAction(buttonCallback);

    bTxt.setXY(261, 160);
    bTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    bTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4091));
    bTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    bTxt.setAction(buttonCallback);

    nTxt.setXY(300, 160);
    nTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    nTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4092));
    nTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    nTxt.setAction(buttonCallback);

    mTxt.setXY(339, 160);
    mTxt.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED_ID));
    mTxt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4093));
    mTxt.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    mTxt.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    mTxt.setAction(buttonCallback);

    keyShiftBtn.setXY(27, 160);
    keyShiftBtn.setBitmaps(touchgfx::Bitmap(BITMAP_SHIFT_RELEASED_ID), touchgfx::Bitmap(BITMAP_SHIFT_PRESSED_ID));
    keyShiftBtn.setAction(buttonCallback);

    deleteKeyBtn.setXY(378, 160);
    deleteKeyBtn.setBitmaps(touchgfx::Bitmap(BITMAP_DEL_RELEASED2_ID), touchgfx::Bitmap(BITMAP_DEL_PRESSED2_ID));
    deleteKeyBtn.setAction(buttonCallback);

    spaceKeyBtn.setXY(183, 204);
    spaceKeyBtn.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED4_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED4_ID));
    spaceKeyBtn.setAction(buttonCallback);

    okBtn.setXY(378, 204);
    okBtn.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED3_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED3_ID));
    okBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4094));
    okBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    okBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    okBtn.setAction(buttonCallback);

    cancelBtn.setXY(27, 204);
    cancelBtn.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED2_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED2_ID));
    cancelBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4095));
    cancelBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    cancelBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    cancelBtn.setAction(buttonCallback);

    keyNumBtn.setXY(105, 204);
    keyNumBtn.setBitmaps(touchgfx::Bitmap(BITMAP_KEY_RELEASED2_ID), touchgfx::Bitmap(BITMAP_KEY_PRESSED2_ID));
    keyNumBtn.setLabelText(touchgfx::TypedText(T_SINGLEUSEID4097));
    keyNumBtn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    keyNumBtn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    keyNumBtn.setAction(buttonCallback);

    add(backgroundFlexButton);
    add(backgroundBox);
    add(keyboardBox);
    add(textBox);
    add(valTxt);
    add(qTxt);
    add(wTxt);
    add(eTxt);
    add(rTxt);
    add(tTxt);
    add(yTxt);
    add(uTxt);
    add(iTxt);
    add(oTxt);
    add(pTxt);
    add(slashTxt);
    add(aTxt);
    add(sTxt);
    add(dTxt);
    add(fTxt);
    add(gTxt);
    add(hTxt);
    add(jTxt);
    add(kTxt);
    add(lTxt);
    add(dotsTxt);
    add(dotcommaTxt);
    add(zTxt);
    add(xTxt);
    add(cTxt);
    add(vTxt);
    add(bTxt);
    add(nTxt);
    add(mTxt);
    add(keyShiftBtn);
    add(deleteKeyBtn);
    add(spaceKeyBtn);
    add(okBtn);
    add(cancelBtn);
    add(keyNumBtn);
}

void keyboardContainer2Base::initialize()
{

}

void keyboardContainer2Base::LaunchKeyboard()
{
    //KeyboardScreenLaunched
    //When LaunchKeyboard is called execute C++ code
    //Execute C++ code
    InitKeyboard(&valTxt, valTxtBuffer);
}

void keyboardContainer2Base::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &qTxt)
    {
        //QBtnPressed
        //When qTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('Q');
        SoundBuzzerOn(25);
    }
    else if (&src == &wTxt)
    {
        //WBtnPressed
        //When wTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('W');
        SoundBuzzerOn(25);
    }
    else if (&src == &eTxt)
    {
        //EBtnPressed
        //When eTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('E');
        SoundBuzzerOn(25);
    }
    else if (&src == &rTxt)
    {
        //RBtnPressed
        //When rTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('R');
        SoundBuzzerOn(25);
    }
    else if (&src == &tTxt)
    {
        //TBtnPressed
        //When tTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('T');
        SoundBuzzerOn(25);
    }
    else if (&src == &yTxt)
    {
        //YBtnPressed
        //When yTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('Y');
        SoundBuzzerOn(25);
    }
    else if (&src == &uTxt)
    {
        //UBtnPressed
        //When uTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('U');
        SoundBuzzerOn(25);
    }
    else if (&src == &iTxt)
    {
        //IBtnPressed
        //When iTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('I');
        SoundBuzzerOn(25);
    }
    else if (&src == &oTxt)
    {
        //OBtnPressed
        //When oTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('O');
        SoundBuzzerOn(25);
    }
    else if (&src == &pTxt)
    {
        //PBtnPressed
        //When pTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('P');
        SoundBuzzerOn(25);
    }
    else if (&src == &slashTxt)
    {
        //SlashBtnPressed
        //When slashTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('/');
        SoundBuzzerOn(25);
    }
    else if (&src == &aTxt)
    {
        //ABtnPressed
        //When aTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('A');
        SoundBuzzerOn(25);
    }
    else if (&src == &sTxt)
    {
        //SBtnPressed
        //When sTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('S');
        SoundBuzzerOn(25);
    }
    else if (&src == &dTxt)
    {
        //DBtnPressed
        //When dTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('D');
        SoundBuzzerOn(25);
    }
    else if (&src == &fTxt)
    {
        //FBtnPressed
        //When fTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('F');
        SoundBuzzerOn(25);
    }
    else if (&src == &gTxt)
    {
        //GBtnPressed
        //When gTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('G');
        SoundBuzzerOn(25);
    }
    else if (&src == &hTxt)
    {
        //HBtnPressed
        //When hTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('H');
        SoundBuzzerOn(25);
    }
    else if (&src == &jTxt)
    {
        //JBtnPressed
        //When jTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('J');
        SoundBuzzerOn(25);
    }
    else if (&src == &kTxt)
    {
        //KBtnPressed
        //When kTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('K');
        SoundBuzzerOn(25);
    }
    else if (&src == &lTxt)
    {
        //LBtnPressed
        //When lTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('L');
        SoundBuzzerOn(25);
    }
    else if (&src == &dotsTxt)
    {
        //DotsBtnPressed
        //When dotsTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed(':');
        SoundBuzzerOn(25);
    }
    else if (&src == &dotcommaTxt)
    {
        //DotCommaBtnPressed
        //When dotcommaTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed(';');
        SoundBuzzerOn(25);
    }
    else if (&src == &zTxt)
    {
        //ZBtnPressed
        //When zTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('Z');
        SoundBuzzerOn(25);
    }
    else if (&src == &xTxt)
    {
        //XBtnPressed
        //When xTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('X');
        SoundBuzzerOn(25);
    }
    else if (&src == &cTxt)
    {
        //CBtnPressed
        //When cTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('C');
        SoundBuzzerOn(25);
    }
    else if (&src == &vTxt)
    {
        //VBtnPressed
        //When vTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('V');
        SoundBuzzerOn(25);
    }
    else if (&src == &bTxt)
    {
        //BBtnPressed
        //When bTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('B');
        SoundBuzzerOn(25);
    }
    else if (&src == &nTxt)
    {
        //NBtnPressed
        //When nTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('N');
        SoundBuzzerOn(25);
    }
    else if (&src == &mTxt)
    {
        //MBtnPressed
        //When mTxt clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed('M');
        SoundBuzzerOn(25);
    }
    else if (&src == &keyShiftBtn)
    {
        //ShiftBtnPressed
        //When keyShiftBtn clicked call virtual function
        //Call shiftPressed
        shiftPressed();

        //ShBtnPressed
        //When ShiftBtnPressed completed execute C++ code
        //Execute C++ code
        KeyboardShfPressed();
        SoundBuzzerOn(25);
    }
    else if (&src == &deleteKeyBtn)
    {
        //DltBtnPressed
        //When deleteKeyBtn clicked execute C++ code
        //Execute C++ code
        KeyboardDltPressed();
        SoundBuzzerOn(25);
    }
    else if (&src == &spaceKeyBtn)
    {
        //SpaceBtnPressed
        //When spaceKeyBtn clicked execute C++ code
        //Execute C++ code
        KeyboardBtnPressed(' ');
        SoundBuzzerOn(25);
    }
    else if (&src == &okBtn)
    {
        //OkBtnPressed
        //When okBtn clicked execute C++ code
        //Execute C++ code
        UpdateKeyboardReference();

        //HideKeyboard
        //When OkBtnPressed completed emit HideKeyboard callback
        //Emit callback
        emitHideKeyboardCallback();
    }
    else if (&src == &cancelBtn)
    {
        //CancelBtnClicked
        //When cancelBtn clicked emit HideKeyboard callback
        //Emit callback
        emitHideKeyboardCallback();
    }
    else if (&src == &keyNumBtn)
    {
        //NumKeyPressed
        //When keyNumBtn clicked call virtual function
        //Call numPressed
        numPressed();

        //Interaction1
        //When NumKeyPressed completed execute C++ code
        //Execute C++ code
        KeyboardNumPressed();
    }
}

void keyboardContainer2Base::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
}

