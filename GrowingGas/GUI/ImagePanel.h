#pragma once
#include <wx\wx.h>
#include "ImageData2D.h"
#include <vector>

class ImagePanel :
	public wxPanel
{
public:
	ImagePanel(wxFrame* parentFrame);
	~ImagePanel(void);

   void getImageData (ImageData2D& data);

private:
    wxImage* m_bmpImage;
    wxBitmap* m_bitmap;
    wxTimer* m_timer;
	// list of dots
	std::vector<wxPoint> m_dots;

	void OnPaint(wxPaintEvent& WXUNUSED(event));
	void OnTimer(wxTimerEvent& WXUNUSED(event));
	void OnEraseBackground(wxEraseEvent& WXUNUSED(event));

    DECLARE_EVENT_TABLE()
};
