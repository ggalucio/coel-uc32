#ifndef RECEITAS_11_EDITPRESENTER_HPP
#define RECEITAS_11_EDITPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_11_EDITView;

class Receitas_11_EDITPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_11_EDITPresenter(Receitas_11_EDITView& v);

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

    virtual ~Receitas_11_EDITPresenter() {};

private:
    Receitas_11_EDITPresenter();

    Receitas_11_EDITView& view;
};

#endif // RECEITAS_11_EDITPRESENTER_HPP
