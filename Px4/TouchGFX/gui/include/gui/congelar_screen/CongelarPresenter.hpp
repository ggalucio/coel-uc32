#ifndef CONGELARPRESENTER_HPP
#define CONGELARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

extern int selectModeCongelar;

class CongelarView;

class CongelarPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    CongelarPresenter(CongelarView& v);

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

    virtual ~CongelarPresenter() {};

private:
    CongelarPresenter();

    CongelarView& view;
};

#endif // CONGELARPRESENTER_HPP
