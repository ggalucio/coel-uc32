#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <AT_module.hpp>
#include <AT_module_ext.hpp>

extern void TickRefreshTimers(void);

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	TickElapsed();
	TickElapsedOthers();

	TickRefreshTimers();
}
