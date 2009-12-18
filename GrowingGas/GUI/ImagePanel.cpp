#include "StdAfx.h"
#include "ImagePanel.h"

BEGIN_EVENT_TABLE ( ImagePanel, wxPanel )
    EVT_ERASE_BACKGROUND(ImagePanel::OnEraseBackground)
	EVT_PAINT(ImagePanel::OnPaint)
END_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parentFrame)
	:wxPanel( this, -1 ,wxPoint(0,200),wxSize(320,200))
{
	//const wxString filename = _T("..\\data\\pattern1.bmp";
	//m_bmpImage  = new wxImage(0,0);	// Create an empty Image. Size does NOT matter...
	//if (m_bmpImage->LoadFile(filename), wxBITMAP_TYPE_BMP))
	//{
	//	m_bitmap = new wxBitmap( *m_bmpImage );
	//}
}

ImagePanel::~ImagePanel(void)
{
}

void ImagePanel::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	//wxPaintDC dc( this );
	//dc.DrawBitmap( *m_bitmap, 0, 0, true /* use mask */ );
}

void ImagePanel::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{
	
}