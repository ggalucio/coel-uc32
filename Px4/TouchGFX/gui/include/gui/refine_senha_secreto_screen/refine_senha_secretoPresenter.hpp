#ifndef REFINE_SENHA_SECRETOPRESENTER_HPP
#define REFINE_SENHA_SECRETOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class refine_senha_secretoView;

class refine_senha_secretoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    refine_senha_secretoPresenter(refine_senha_secretoView& v);

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

    virtual ~refine_senha_secretoPresenter() {};

private:
    refine_senha_secretoPresenter();

    refine_senha_secretoView& view;
};

#endif // REFINE_SENHA_SECRETOPRESENTER_HPP
