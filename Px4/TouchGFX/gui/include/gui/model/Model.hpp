#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;
class Model
{
public:
    Model();
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }
    void tick();

protected:
    ModelListener* modelListener;
    int currScreen;
};

#endif // MODEL_HPP
