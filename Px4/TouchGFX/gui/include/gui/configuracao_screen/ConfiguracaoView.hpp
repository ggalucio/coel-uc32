#ifndef CONFIGURACAOVIEW_HPP
#define CONFIGURACAOVIEW_HPP

#include <gui_generated/configuracao_screen/ConfiguracaoViewBase.hpp>
#include <gui/configuracao_screen/ConfiguracaoPresenter.hpp>

class ConfiguracaoView : public ConfiguracaoViewBase
{
public:
    ConfiguracaoView();
    virtual ~ConfiguracaoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAOVIEW_HPP
