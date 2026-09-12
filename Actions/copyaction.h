#pragma once
#pragma once
#ifndef COPY_ACTION
#define COPY_ACTION
#include "Action.h"



class COpy : public Action
{
public:
	COpy(ApplicationManager* pApp);

	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};

#endif