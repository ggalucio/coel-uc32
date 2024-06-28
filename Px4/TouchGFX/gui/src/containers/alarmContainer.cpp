#include <gui/containers/alarmContainer.hpp>

alarmContainer::alarmContainer()
{

}

void alarmContainer::initialize()
{
    alarmContainerBase::initialize();
}

void alarmContainer::update(int idx){
	index = idx;
	alarmTxt.invalidate();
}

void alarmContainer::setIndex(int idx){
	index = idx;
}

int* alarmContainer::getIndex(){
	return &index;
}

touchgfx::TextAreaWithOneWildcard * alarmContainer::getTxtAlarm(){
	return &alarmTxt;
}

touchgfx::Unicode::UnicodeChar* alarmContainer::getTxtAlarmBuff(){
	return alarmTxtBuffer;
}
