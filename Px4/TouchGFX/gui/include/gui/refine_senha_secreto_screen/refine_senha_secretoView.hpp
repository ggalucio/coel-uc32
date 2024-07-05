#ifndef REFINE_SENHA_SECRETOVIEW_HPP
#define REFINE_SENHA_SECRETOVIEW_HPP

#include <gui_generated/refine_senha_secreto_screen/refine_senha_secretoViewBase.hpp>
#include <gui/refine_senha_secreto_screen/refine_senha_secretoPresenter.hpp>

class refine_senha_secretoView : public refine_senha_secretoViewBase
{
public:
    refine_senha_secretoView();
    virtual ~refine_senha_secretoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // REFINE_SENHA_SECRETOVIEW_HPP
