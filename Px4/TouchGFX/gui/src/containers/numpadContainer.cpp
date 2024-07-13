#include <gui/containers/numpadContainer.hpp>

NumpadContainerItem numpadContainerItem[20];

int nNumpadContainerItems = 0;
int idNumpadContainer = -1;

void AddNumpadReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t id){
	if (nNumpadContainerItems == 0 || id < 0 || id >= nNumpadContainerItems)
		return;

	idNumpadContainer = id;
	numpadContainerItem[idNumpadContainer].textArea = textArea;
	numpadContainerItem[idNumpadContainer].buffer = textBuffer;
	numpadContainerItem[idNumpadContainer].dataType = dataType;
	numpadContainerItem[idNumpadContainer].decimal = decimal;

	numpadContainer *numpad = numpadContainerItem[idNumpadContainer].numpad;
	SetValueNumpadContainer(*numpad, GetNumberTextArea(textBuffer), dataType, decimal);
	SetRangeNumpadContainer(*numpad, min, max);
}

void SetRangeNumpadContainer(numpadContainer &numpad, double min, double max){
	if (max <= min)
		return;

	Update(&numpad.maxTxt, numpad.maxTxtBuffer, max, _DOUBLE_, 1);
	Update(&numpad.minTxt, numpad.minTxtBuffer, min, _DOUBLE_, 1);
}

void SetValueNumpadContainer(numpadContainer &numpad, double value, DataType dataType, uint8_t decimal){
	Update(&numpad.valTxt, numpad.valTxtBuffer, value, dataType, decimal);
}

void UpdateOutNumpad(){
	if (nNumpadContainerItems == 0 || idNumpadContainer == -1)
		return;

	double value = GetNumberTextArea(numpadContainerItem[idNumpadContainer].numpad->valTxtBuffer);
	Update(numpadContainerItem[idNumpadContainer].textArea,
			numpadContainerItem[idNumpadContainer].buffer, value,
			numpadContainerItem[idNumpadContainer].dataType,
			numpadContainerItem[idNumpadContainer].decimal);
}

void RemoveAllNumpad(){
	nNumpadContainerItems = 0;
	idNumpadContainer = -1;
}

/************************************************* numpadContainer *********************************************************/

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
