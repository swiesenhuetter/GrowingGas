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
	wxBitmap* m_bitmap_spir{};
	wxBitmap* m_bitmap_paint{};
    wxTimer* m_timer{};
	wxButton* m_exit_button{};
	wxBoxSizer* m_layout{};
	// list of dots 
	std::vector<wxPoint> m_dots;

	void paint_spiral(wxBitmap* bmp);

	void OnPaint(wxPaintEvent& WXUNUSED(event));
	void OnTimer(wxTimerEvent& WXUNUSED(event));
	void OnEraseBackground(wxEraseEvent& WXUNUSED(event));
	void OnExit(wxCommandEvent& WXUNUSED(event));

    DECLARE_EVENT_TABLE()
};
