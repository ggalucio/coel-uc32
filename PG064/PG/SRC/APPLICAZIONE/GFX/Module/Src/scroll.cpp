/*
 * scroll.c
 *
 *  Created on: 23 lug 2021
 *      Author: paoloc
 */

#include "../Inc/scroll.hpp"
#include "../Inc/GraphicItems.hpp"
#include "Utils/utils.h"

Scroll::Scroll() :
updateItemCallback(this, &Scroll::UpdateJobItemCallbackHandler),
updateAlarmCallback(this, &Scroll::UpdateAlarmItemCallbackHandler)
{

}

void Scroll::UpdateAlarmItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex){
	if (items == alarmItems)
	{
		touchgfx::Drawable* d = items->getDrawable(containerIndex);
		alarmContainer* cc = (alarmContainer*)d;
		(*cc).update(itemIndex);
	}
}

void Scroll::UpdateJobItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex){
	 if (items == jobItems)
	{
		touchgfx::Drawable* d = items->getDrawable(containerIndex);
		programContainer* cc = (programContainer*)d;
		(*cc).update(itemIndex);
	}
	else if (items == jobSelectedItems)
	{
		touchgfx::Drawable* d = items->getDrawable(containerIndex);
		programCenterContainer* cc = (programCenterContainer*)d;
		(*cc).update(itemIndex);

		JOB_SELECTED_ADDRESS = itemIndex - 1;
		/*if(pSelectJob)
			(*pSelectJob)(itemIndex - 1);*/
	}
}

void Scroll::AddJobScroll(touchgfx::ScrollWheelWithSelectionStyle* jobWheel, touchgfx::DrawableListItems<programContainer, 6> *jobWheelItems, touchgfx::DrawableListItems<programCenterContainer, 2> *jobWheelSelectedItems){
	if(jobWheel){
		jobItems 			= jobWheelItems;
		jobSelectedItems 	= jobWheelSelectedItems;
		jobWheel->setDrawables(*jobWheelItems, updateItemCallback,
				*jobWheelSelectedItems, updateItemCallback);

	}
}

void Scroll::AddAlarmScroll(touchgfx::ScrollWheel *alarmWheel, touchgfx::DrawableListItems<alarmContainer, 5> *alarm, touchgfx::DrawableListItems<alarmCenterContainer, 2> *alarmSelected){
	if(alarmWheel){
		alarmItems 			= alarm;
		alarmWheel->setDrawables(*alarm, updateAlarmCallback);

		int i;
		for(i = 0; i < alarmItems->getNumberOfDrawables(); i++){
			touchgfx::Drawable* d = alarmItems->getDrawable(i);
			alarmContainer* cc = (alarmContainer*)d;
			(*cc).setIndex(i);
			int *ptrIdx = (*cc).getIndex();
			AddScrollAlarmItem((*cc).getTxtAlarm(), (*cc).getTxtAlarmBuff(), ptrIdx);
		}
	}
}

