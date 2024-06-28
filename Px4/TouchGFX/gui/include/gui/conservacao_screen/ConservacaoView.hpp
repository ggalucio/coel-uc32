#ifndef CONSERVACAOVIEW_HPP
#define CONSERVACAOVIEW_HPP

#include <gui_generated/conservacao_screen/ConservacaoViewBase.hpp>
#include <gui/conservacao_screen/ConservacaoPresenter.hpp>

class ConservacaoView : public ConservacaoViewBase
{
public:
    ConservacaoView();
    virtual ~ConservacaoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONSERVACAOVIEW_HPP
