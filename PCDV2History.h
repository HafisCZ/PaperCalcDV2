#ifndef PCDV2HISTORY_H
#define PCDV2HISTORY_H

//(*Headers(PCDV2History)
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
//*)

class PCDV2History: public wxFrame
{
	public:

		PCDV2History(wxWindow* parent,wxWindowID id=wxID_ANY,wxString historyArray[10][9]=NULL);
		virtual ~PCDV2History();

		//(*Declarations(PCDV2History)
		wxStaticText* StaticText10;
		wxStaticText* StaticText22;
		wxStaticText* StaticText9;
		wxStaticText* StaticText53;
		wxStaticText* StaticText20;
		wxStaticText* StaticText83;
		wxStaticText* StaticText45;
		wxStaticText* StaticText74;
		wxStaticText* StaticText75;
		wxStaticText* StaticText80;
		wxStaticText* StaticText29;
		wxStaticText* StaticText78;
		wxStaticText* StaticText76;
		wxStaticText* StaticText37;
		wxStaticText* StaticText82;
		wxStaticText* StaticText33;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText30;
		wxStaticText* StaticText14;
		wxStaticText* StaticText26;
		wxStaticText* StaticText6;
		wxStaticText* StaticText65;
		wxStaticText* StaticText64;
		wxStaticText* StaticText87;
		wxStaticText* StaticText40;
		wxStaticText* StaticText81;
		wxStaticText* StaticText90;
		wxStaticText* StaticText42;
		wxStaticText* StaticText73;
		wxStaticText* StaticText32;
		wxStaticText* StaticText19;
		wxStaticText* StaticText38;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxStaticText* StaticText62;
		wxStaticText* StaticText84;
		wxStaticText* StaticText18;
		wxStaticText* StaticText50;
		wxStaticText* StaticText31;
		wxStaticText* StaticText1;
		wxStaticText* StaticText58;
		wxStaticText* StaticText27;
		wxStaticText* StaticText3;
		wxStaticText* StaticText86;
		wxStaticText* StaticText54;
		wxStaticText* StaticText94;
		wxStaticText* StaticText67;
		wxStaticText* StaticText44;
		wxStaticText* StaticText56;
		wxStaticText* StaticText39;
		wxStaticText* StaticText21;
		wxStaticText* StaticText55;
		wxStaticText* StaticText23;
		wxStaticText* StaticText24;
		wxStaticText* StaticText72;
		wxStaticText* StaticText49;
		wxStaticText* StaticText98;
		wxStaticText* StaticText91;
		wxStaticText* StaticText69;
		wxStaticText* StaticText71;
		wxStaticText* StaticText34;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* StaticText93;
		wxStaticText* StaticText95;
		wxStaticText* StaticText57;
		wxStaticText* StaticText61;
		wxStaticText* StaticText47;
		wxStaticLine* StaticLine1;
		wxStaticText* StaticText70;
		wxStaticText* StaticText96;
		wxStaticText* StaticText52;
		wxStaticText* StaticText28;
		wxStaticText* StaticText85;
		wxStaticText* StaticText43;
		wxStaticText* StaticText41;
		wxStaticText* StaticText15;
		wxStaticText* StaticText92;
		wxStaticText* StaticText12;
		wxStaticText* StaticText88;
		wxStaticText* StaticText68;
		wxStaticText* StaticText35;
		wxStaticText* StaticText60;
		wxStaticText* StaticText59;
		wxStaticText* StaticText25;
		wxStaticText* StaticText66;
		wxStaticText* StaticText89;
		wxStaticText* StaticText63;
		wxStaticText* StaticText36;
		wxStaticText* StaticText17;
		wxStaticText* StaticText4;
		wxStaticText* StaticText48;
		wxStaticText* StaticText97;
		wxStaticText* StaticText99;
		wxStaticText* StaticText16;
		wxStaticText* StaticText79;
		wxStaticText* StaticText46;
		wxStaticText* StaticText51;
		wxStaticText* StaticText77;
		//*)

	protected:

		//(*Identifiers(PCDV2History)
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT18;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT20;
		static const long ID_STATICTEXT21;
		static const long ID_STATICTEXT22;
		static const long ID_STATICTEXT23;
		static const long ID_STATICTEXT24;
		static const long ID_STATICTEXT30;
		static const long ID_STATICTEXT25;
		static const long ID_STATICTEXT26;
		static const long ID_STATICTEXT27;
		static const long ID_STATICTEXT28;
		static const long ID_STATICTEXT29;
		static const long ID_STATICTEXT31;
		static const long ID_STATICTEXT32;
		static const long ID_STATICTEXT51;
		static const long ID_STATICTEXT73;
		static const long ID_STATICTEXT53;
		static const long ID_STATICTEXT33;
		static const long ID_STATICTEXT34;
		static const long ID_STATICTEXT52;
		static const long ID_STATICTEXT35;
		static const long ID_STATICTEXT36;
		static const long ID_STATICTEXT37;
		static const long ID_STATICTEXT38;
		static const long ID_STATICTEXT39;
		static const long ID_STATICTEXT40;
		static const long ID_STATICTEXT41;
		static const long ID_STATICTEXT42;
		static const long ID_STATICTEXT43;
		static const long ID_STATICTEXT60;
		static const long ID_STATICTEXT44;
		static const long ID_STATICTEXT45;
		static const long ID_STATICTEXT46;
		static const long ID_STATICTEXT47;
		static const long ID_STATICTEXT48;
		static const long ID_STATICTEXT49;
		static const long ID_STATICTEXT82;
		static const long ID_STATICTEXT62;
		static const long ID_STATICTEXT50;
		static const long ID_STATICTEXT54;
		static const long ID_STATICTEXT55;
		static const long ID_STATICTEXT56;
		static const long ID_STATICTEXT57;
		static const long ID_STATICTEXT58;
		static const long ID_STATICTEXT59;
		static const long ID_STATICTEXT61;
		static const long ID_STATICTEXT80;
		static const long ID_STATICTEXT63;
		static const long ID_STATICTEXT64;
		static const long ID_STATICTEXT65;
		static const long ID_STATICTEXT66;
		static const long ID_STATICTEXT67;
		static const long ID_STATICTEXT68;
		static const long ID_STATICTEXT77;
		static const long ID_STATICTEXT69;
		static const long ID_STATICTEXT70;
		static const long ID_STATICTEXT85;
		static const long ID_STATICTEXT71;
		static const long ID_STATICTEXT72;
		static const long ID_STATICTEXT74;
		static const long ID_STATICTEXT75;
		static const long ID_STATICTEXT76;
		static const long ID_STATICTEXT78;
		static const long ID_STATICTEXT79;
		static const long ID_STATICTEXT81;
		static const long ID_STATICTEXT83;
		static const long ID_STATICTEXT84;
		static const long ID_STATICTEXT86;
		static const long ID_STATICTEXT87;
		static const long ID_STATICTEXT88;
		static const long ID_STATICTEXT89;
		static const long ID_STATICTEXT90;
		static const long ID_STATICTEXT91;
		static const long ID_STATICTEXT92;
		static const long ID_STATICTEXT93;
		static const long ID_STATICTEXT94;
		static const long ID_STATICTEXT95;
		static const long ID_STATICTEXT96;
		static const long ID_STATICTEXT97;
		static const long ID_STATICTEXT98;
		static const long ID_STATICTEXT99;
		//*)

	private:

	    int selectedLanguage;

		//(*Handlers(PCDV2History)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
