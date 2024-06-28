/*
 * scroll.h
 *
 *  Created on: 23 lug 2021
 *      Author: paoloc
 */

#ifndef MODULE_INC_SCROLL_HPP_
#define MODULE_INC_SCROLL_HPP_

#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>
#include <touchgfx/containers/scrollers/ScrollWheel.hpp>
#include <touchgfx/containers/Container.hpp>

#include <gui/containers/programContainer.hpp>
#include <gui/containers/programCenterContainer.hpp>
#include <gui/containers/alarmContainer.hpp>
#include <gui/containers/alarmCenterContainer.hpp>

class Scroll
{
public:
	Scroll();
	void AddJobScroll(touchgfx::ScrollWheelWithSelectionStyle *, touchgfx::DrawableListItems<programContainer, 6> *, touchgfx::DrawableListItems<programCenterContainer, 2> *);
	void AddAlarmScroll(touchgfx::ScrollWheel *, touchgfx::DrawableListItems<alarmContainer, 5> *, touchgfx::DrawableListItems<alarmCenterContainer, 2> *);

private:
	void UpdateJobItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);
	void UpdateAlarmItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

	touchgfx::Callback<Scroll, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;
	touchgfx::DrawableListItems<programContainer, 6> *jobItems;
	touchgfx::DrawableListItems<programCenterContainer, 2> *jobSelectedItems;

	touchgfx::Callback<Scroll, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateAlarmCallback;
	touchgfx::DrawableListItems<alarmContainer, 5> *alarmItems;
};


#endif /* MODULE_INC_SCROLL_HPP_ */
