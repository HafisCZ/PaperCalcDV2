#ifndef PCDV2HISTORY_H
#define PCDV2HISTORY_H

//(*Headers(PCDV2History)
#include <wx/menu.h>
#include <wx/gbsizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class PCDV2History: public wxFrame
{
	public:

		PCDV2History(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~PCDV2History();

		//(*Declarations(PCDV2History)
		wxButton* Button1;
		wxMenuItem* MenuItem1;
		wxMenu* Menu1;
		wxStatusBar* StatusBar1;
		wxMenuBar* MenuBar1;
		//*)

	protected:

		//(*Identifiers(PCDV2History)
		static const long ID_BUTTON1;
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
