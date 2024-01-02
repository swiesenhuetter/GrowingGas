#include "StdAfx.h"
#include "ImagePanel.h"

BEGIN_EVENT_TABLE ( ImagePanel, wxPanel )
    EVT_ERASE_BACKGROUND(ImagePanel::OnEraseBackground)
	EVT_PAINT(ImagePanel::OnPaint)
	EVT_TIMER(-1, ImagePanel::OnTimer)
END_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parentFrame)
	:wxPanel( parentFrame, -1 ,wxPoint(0,0),wxSize(500,500))
	,m_bitmap(0)
	,m_bmpImage(0)
{
	const wxString filename = _T("..\\data\\pattern2.bmp";
	m_bmpImage  = new wxImage(0,0);	// Create an empty Image. Size does NOT matter...
	if (m_bmpImage->LoadFile(filename), wxBITMAP_TYPE_BMP))
	{
		m_bitmap = new wxBitmap( *m_bmpImage );
	}
	m_timer = new wxTimer(this);
	m_timer->Start(0);
}

ImagePanel::~ImagePanel(void)
{
	delete m_bitmap;
	delete m_bmpImage;
	delete m_timer;
}


void ImagePanel::OnTimer(wxTimerEvent& WXUNUSED(event))
{
	// random pixel from bitmap
	int x = rand() % m_bmpImage->GetWidth();
	int y = rand() % m_bmpImage->GetHeight();
	// if white do nothing
	if (m_bmpImage->GetGreen(x, y) == 255)
        return;
	m_dots.push_back(wxPoint(x,y));
	Refresh();
}


void ImagePanel::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	wxPaintDC dc( this );
	// dc.DrawBitmap( *m_bitmap, 0, 0, true /* use mask */ );
	// paint a transparent circle
	dc.SetBrush( wxBrush( wxColor(0,0,255,0) ) ); // 128 = half transparent blue
    dc.SetPen( wxPen( wxColor(0,0,0,100) ) ); // 0 = transparent
	for (auto p : m_dots)
	{
		auto r = m_bmpImage->GetRed(p.x, p.y);
		auto b = m_bmpImage->GetBlue(p.x, p.y);
        dc.SetBrush( wxBrush( wxColor(r,0,b,10) ) ); // 128 = half transparent blue
		dc.DrawCircle(p, 10 /* radius */ );
    }
}

void ImagePanel::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{
	
}