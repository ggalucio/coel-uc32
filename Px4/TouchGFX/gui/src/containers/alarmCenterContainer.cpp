#include <gui/containers/alarmCenterContainer.hpp>

alarmCenterContainer::alarmCenterContainer()
{

}

void alarmCenterContainer::initialize()
{
    alarmCenterContainerBase::initialize();
}

void alarmCenterContainer::update(){
	alarmTxt.invalidate();
}