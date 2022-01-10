#ifndef _GHRENDR_WINWINDOW_H_
#define _GHRENDR_WINWINDOW_H_
#include "../../Core/Window.h"
class WinWindow : public Window {
public:
	
	WinWindow() = default;

	void Init() override;
	void createWindow() override;

	virtual ~WinWindow();

};

#endif // _GHRENDR_WINWINDOW_H_