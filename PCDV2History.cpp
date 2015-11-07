#include "PCDV2History.h"

//(*InternalHeaders(PCDV2History)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PCDV2History)
const long PCDV2History::ID_HYPERLINKCTRL1 = wxNewId();
const long PCDV2History::ID_STATICLINE1 = wxNewId();
const long PCDV2History::ID_TEXTCTRL1 = wxNewId();
const long PCDV2History::ID_TEXTCTRL2 = wxNewId();
const long PCDV2History::ID_TEXTCTRL3 = wxNewId();
const long PCDV2History::ID_STATUSBAR1 = wxNewId();
const long PCDV2History::ID_MENUITEM1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PCDV2History,wxFrame)
	//(*EventTable(PCDV2History)
	//*)
END_EVENT_TABLE()

PCDV2History::PCDV2History(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(PCDV2History)
	wxGridBagSizer* GridBagSizer1;

	Create(parent, id, _("History"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	HyperlinkCtrl1 = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("web.hiraishin.com"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
	GridBagSizer1->Add(HyperlinkCtrl1, wxGBPosition(0, 0), wxGBSpan(1, 5), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	GridBagSizer1->Add(StaticLine1, wxGBPosition(1, 0), wxGBSpan(1, 5), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridBagSizer1->Add(TextCtrl1, wxGBPosition(2, 0), wxGBSpan(1, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	GridBagSizer1->Add(TextCtrl2, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	GridBagSizer1->Add(TextCtrl3, wxGBPosition(2, 3), wxGBSpan(1, 2), wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridBagSizer1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("1\tAlt-F4"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar1->Append(Menu1, _("1"));
	SetMenuBar(MenuBar1);
	GridBagSizer1->Fit(this);
	GridBagSizer1->SetSizeHints(this);

	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PCDV2History::OnQuit);
	//*)
}

PCDV2History::~PCDV2History()
{
	//(*Destroy(PCDV2History)
	//*)
}


void PCDV2History::OnQuit(wxCommandEvent& event)
{
    Close();
}
