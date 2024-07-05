#ifndef ALARME_EXTERNOPRESENTER_HPP
#define ALARME_EXTERNOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Alarme_externoView;

class Alarme_externoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Alarme_externoPresenter(Alarme_externoView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Alarme_externoPresenter() {};

private:
    Alarme_externoPresenter();

    Alarme_externoView& view;
};

#endif // ALARME_EXTERNOPRESENTER_HPP
