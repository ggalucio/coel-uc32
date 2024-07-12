#ifndef HIGIENEVIEW_HPP
#define HIGIENEVIEW_HPP

#include <gui_generated/higiene_screen/HIGIENEViewBase.hpp>
#include <gui/higiene_screen/HIGIENEPresenter.hpp>

class HIGIENEView : public HIGIENEViewBase
{
public:
    HIGIENEView();
    virtual ~HIGIENEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HIGIENEVIEW_HPP
