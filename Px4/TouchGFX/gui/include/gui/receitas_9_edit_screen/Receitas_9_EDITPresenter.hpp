#ifndef RECEITAS_9_EDITPRESENTER_HPP
#define RECEITAS_9_EDITPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_9_EDITView;

class Receitas_9_EDITPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_9_EDITPresenter(Receitas_9_EDITView& v);

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

    virtual ~Receitas_9_EDITPresenter() {};

private:
    Receitas_9_EDITPresenter();

    Receitas_9_EDITView& view;
};

#endif // RECEITAS_9_EDITPRESENTER_HPP
