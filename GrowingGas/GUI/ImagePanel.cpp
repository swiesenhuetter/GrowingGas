#include "StdAfx.h"
#include "ImagePanel.h"
#include <wx/dcbuffer.h>
#include "colors.h"


BEGIN_EVENT_TABLE ( ImagePanel, wxPanel )
    EVT_ERASE_BACKGROUND(ImagePanel::OnEraseBackground)
	EVT_PAINT(ImagePanel::OnPaint)
	EVT_TIMER(-1, ImagePanel::OnTimer)
	EVT_BUTTON(wxID_EXIT, ImagePanel::OnExit)
END_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parentFrame)
	:wxPanel( parentFrame, -1 ,wxPoint(0,0),wxSize(500,500))
	,m_bitmap(nullptr)
{
	m_bitmap = new wxBitmap( 500, 500, 24 );
	m_timer = new wxTimer(this);
	m_timer->Start(0);
	m_layout = new wxBoxSizer(wxVERTICAL);
	SetSizer(m_layout);
	m_exit_button = new wxButton(this, wxID_EXIT, wxT("Exit"));
	m_layout->Add(m_exit_button, 0, wxALIGN_CENTER);
}

ImagePanel::~ImagePanel(void)
{
	delete m_bitmap;
	delete m_timer;
	delete m_exit_button;
}


void ImagePanel::OnTimer(wxTimerEvent& WXUNUSED(event))
{
	// get windows size
	int w{ 0 }, h{ 0 };
	GetSize(&w, &h);
	
	// random pixel from bitmap
	int x = rand() % w;
	int y = rand() % h;
	// pixel color
	auto img = m_bitmap->ConvertToImage();
	auto red = img.GetRed(x, y);
	auto green = img.GetGreen(x, y);
	if (red < 100 && green < 100)
    {
		return;
	}
	m_dots.push_back(wxPoint(x, y));
	Refresh();
}


void ImagePanel::OnPaint(wxPaintEvent& WXUNUSED(event))
{
	wxBufferedPaintDC dc(this, *m_bitmap);

	float x{0.0f}, y{0.0f}, angle {0.0f};

	for (int i = 50; i < 1000; ++i)
    {
		angle = 0.02 * i;
		x = 250 + 10.0 * angle * cos(angle);
		y = 250 + 10.0 * angle * sin(angle);
		dc.SetBrush(wxBrush(Color::red)); // red, half transparent
		dc.SetPen(wxPen(Color::red)); // 0 = transparent)
		dc.DrawCircle(wxPoint(x,y), 5 /* radius */ );
		dc.SetBrush(wxBrush(Color::green)); // green, half transparent
		dc.SetPen(wxPen(Color::green)); // 0 = transparent)
		x = 250 + 10.0 * angle * cos(3.1416 + angle);
		y = 250 + 10.0 * angle * sin(3.1416 + angle);
		dc.DrawCircle(wxPoint(x, y), 5 /* radius */);
	}

	// paint a transparent circle
	auto img = m_bitmap->ConvertToImage();

	for (auto p : m_dots)
	{
        auto r = img.GetRed(p.x, p.y);
        auto g = img.GetGreen(p.x, p.y);
        dc.SetPen( wxPen( wxColor(r,g,0,10) ) );
		dc.SetBrush( wxBrush( wxColor(r,g,0,10) ) );
        dc.DrawCircle(p, 10 /* radius */ );
    }
}

void ImagePanel::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{

}

void ImagePanel::OnExit(wxCommandEvent& WXUNUSED(event))
{
	auto parent = dynamic_cast<wxFrame*>(GetParent());
	parent->Close(true);
	//wxGetApp().ExitMainLoop();
}
