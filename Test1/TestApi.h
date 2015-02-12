#pragma once

#include "FixApi.h"

class TestApi
{
public:
	TestApi(void);
	virtual ~TestApi(void);
protected:
	HANDLE_CONN m_Conn;
	void OnNew();
	void OnRun();
	void OnQuery();
	void OnInit();
	void OnUninit();
};

