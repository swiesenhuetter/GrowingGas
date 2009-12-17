#pragma once
#include <wx\wx.h>

class ImagePanel :
	public wxPanel
{
public:
	ImagePanel(void);
	~ImagePanel(void);
private:
	wxBitmap image;
};
