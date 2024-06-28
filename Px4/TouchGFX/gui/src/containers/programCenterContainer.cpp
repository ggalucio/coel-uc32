#include <gui/containers/programCenterContainer.hpp>

extern void (*pReadJobNameAt)(int, char*);

programCenterContainer::programCenterContainer()
{

}

void programCenterContainer::initialize()
{
    programCenterContainerBase::initialize();
}

void programCenterContainer::update(int idx){
	if(pReadJobNameAt){
		char name[PROGRAMTXT_SIZE];
		(*pReadJobNameAt)(idx, name);
		touchgfx::Unicode::strncpy(programTxtBuffer, name, PROGRAMTXT_SIZE);
		programTxt.invalidate();
	}
	Unicode::snprintf(idTxtBuffer, IDTXT_SIZE, "%d", idx + 1);
	idTxt.invalidate();
}
