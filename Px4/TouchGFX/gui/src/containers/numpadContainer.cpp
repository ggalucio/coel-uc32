#include <gui/containers/numpadContainer.hpp>

NumpadContainerItem numpadContainerItem[20];
int nNumpadContainerItems = 0;

void AddNumpadReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t id){
	if (nNumpadContainerItems == 0)
		return;

	numpadContainerItem[id].numpad->setRange(min, max);
	numpadContainerItem[id].numpad->setInput(textBuffer, dataType, decimal);
	numpadContainerItem[id].numpad->loadInput();
}

void RemoveAllNumpad(){
	nNumpadContainerItems = 0;
}

numpadContainer::numpadContainer()
{
	numpadContainerItem[nNumpadContainerItems].numpad = this;
	nNumpadContainerItems ++;
}

void numpadContainer::initialize()
{
    numpadContainerBase::initialize();
    init();
}

bool numpadContainer::setRange(double min, double max)
{
	if (max > min){
		Update(&maxTxt, maxTxtBuffer, max, _DOUBLE_, 1);
		Update(&minTxt, minTxtBuffer, min, _DOUBLE_, 1);
		return true;
	}
	return false;
}

void numpadContainer::setInput(touchgfx::Unicode::UnicodeChar* inBuffer, DataType dataType, uint8_t decimal)
{
	if (inBuffer == NULL)
		return;

	outBuffer = inBuffer;
	this->dataType = dataType;
	this->decimal = decimal;
}

void numpadContainer::loadInput()
{
	if (outBuffer ==  NULL)
		return;

	Update(&valTxt, valTxtBuffer, GetNumberTextArea(outBuffer), dataType, decimal);
}
