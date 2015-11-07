#ifndef PCDV2HISTORY_H
#define PCDV2HISTORY_H

//(*Headers(PCDV2History)
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/hyperlink.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class PCDV2History: public wxFrame
{
	public:

		PCDV2History(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~PCDV2History();

		//(*Declarations(PCDV2History)
		wxMenuItem* MenuItem1;
		wxHyperlinkCtrl* HyperlinkCtrl1;
		wxMenu* Menu1;
		wxStatusBar* StatusBar1;
		wxStaticLine* StaticLine1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxMenuBar* MenuBar1;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(PCDV2History)
		static const long ID_HYPERLINKCTRL1;
		static const long ID_STATICLINE1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATUSBAR1;
		static const long ID_MENUITEM1;
		//*)

	private:

		//(*Handlers(PCDV2History)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
