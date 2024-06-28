#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

#include <AT_module.hpp>
#include <AT_module_ext.hpp>
#include <Module/Inc/ObjectData.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void changeScreen(int screenId){}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
