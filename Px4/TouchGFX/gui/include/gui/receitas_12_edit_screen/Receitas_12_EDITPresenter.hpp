#ifndef RECEITAS_12_EDITPRESENTER_HPP
#define RECEITAS_12_EDITPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_12_EDITView;

class Receitas_12_EDITPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_12_EDITPresenter(Receitas_12_EDITView& v);

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

    virtual ~Receitas_12_EDITPresenter() {};

private:
    Receitas_12_EDITPresenter();

    Receitas_12_EDITView& view;
};

#endif // RECEITAS_12_EDITPRESENTER_HPP
