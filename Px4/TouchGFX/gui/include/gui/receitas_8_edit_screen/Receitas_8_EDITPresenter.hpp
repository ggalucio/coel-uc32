#ifndef RECEITAS_8_EDITPRESENTER_HPP
#define RECEITAS_8_EDITPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_8_EDITView;

class Receitas_8_EDITPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_8_EDITPresenter(Receitas_8_EDITView& v);

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

    virtual ~Receitas_8_EDITPresenter() {};

private:
    Receitas_8_EDITPresenter();

    Receitas_8_EDITView& view;
};

#endif // RECEITAS_8_EDITPRESENTER_HPP
