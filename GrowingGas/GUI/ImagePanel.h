#pragma once
#include <wx\wx.h>
#include "ImageData2D.h"

class ImagePanel :
	public wxPanel
{
public:
	ImagePanel(wxFrame* parentFrame);
	~ImagePanel(void);
private:
	wxImage			*m_bmpImage;
	wxBitmap		*m_bitmap;

	void OnPaint(wxPaintEvent& WXUNUSED(event));
	void OnEraseBackground(wxEraseEvent& WXUNUSED(event));

   ImageData2D data;

    DECLARE_EVENT_TABLE()
};
