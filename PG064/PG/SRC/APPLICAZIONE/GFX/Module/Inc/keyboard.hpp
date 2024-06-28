/*
 * keyboard.hpp
 *
 *  Created on: 9 lug 2021
 *      Author: paoloc
 */

#ifndef MODULE_INC_KEYBOARD_HPP_
#define MODULE_INC_KEYBOARD_HPP_

#include <touchgfx/widgets/TextArea.hpp>

void AddTxtKeyboardRef(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer);
void InitTxtKeyboard(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer);
void UpdateTxtKeyboard();
void keyboardBtnPressed(char val);
void keyboardDltPressed(void);
void keyboardShfPressed(void);
void keyboardNumPressed(void);

#endif /* MODULE_INC_KEYBOARD_HPP_ */
