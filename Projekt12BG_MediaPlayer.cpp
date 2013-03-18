// Projekt12BG_MediaPlayer.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "MediaPlayer.h"
#include "Track.h"

using namespace Projekt12BG_MediaPlayer;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew MediaPlayer());

	return 0;
}

Void MediaPlayer::ButtonPicture_change(System::Windows::Forms::Button^ obj ,String^ filename)
{
	String^ source = "C:\\Users\\Paul\\Documents\\Visual Studio 2010\\Projects\\Projekt12BG_MediaPlayer\\Projekt12BG_MediaPlayer\\Buttons\\" + filename;
	obj->BackgroundImage = Image::FromFile(source);
}

Void MediaPlayer::play_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	CTrack^ tmp = gcnew CTrack();

	if(PlayStatus == 0)// Wenn Play gedrückt wird
	{
		PlayStatus = 1; // Status ändern
		ButtonPicture_change(play_button,"Pause_Button.png");

		tmp->SetLength(title->Duration); 
		
		musik_timebar->Value = tmp->GetLength() / 10;
		title->Play();
		

	}
	else if(PlayStatus == 1) //Wenn Pause gedrückt wird
	{

		PlayStatus = 0; // Status ändern
		ButtonPicture_change(play_button,"Play_Button.png");

		title->Pause();
	}
}

Void MediaPlayer::weiterL_button_Click(System::Object^  sender, System::EventArgs^  e)
{
		
}
Void MediaPlayer::weiterR_button_Click(System::Object^  sender, System::EventArgs^  e)
{

}

Void MediaPlayer::stop_button_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if(PlayStatus == 1)
	{
		PlayStatus = 0; // Status ändern
		ButtonPicture_change(play_button,"Play_Button.png");	
		title->Stop();
	}

}

Void MediaPlayer::vollbild_button_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(WindowSizeStatus == 0) // Wenn maximiert wird
	{
		WindowSizeStatus = 1; // Status ändern
		this->Text = "";
		this->ControlBox = false;
		this->WindowState = FormWindowState::Maximized;
		ButtonPicture_change(vollbild_button,"Minimize_Button.png");
	}
	else if(WindowSizeStatus == 1) // Wenn minimiert wird
	{
		WindowSizeStatus = 0; // Status ändern
		this->Text = "MediaPlayer";
		this->ControlBox = true;
		this->WindowState = FormWindowState::Normal;
		this->Size = System::Drawing::Size(800, 500);
		ButtonPicture_change(vollbild_button,"Maximize_Button.png");	
	}

}

Void MediaPlayer::MediaPlayer_Resize(System::Object^  sender, System::EventArgs^  e)
{
		//Control Panel anpassen
	control_panel->Location = System::Drawing::Point(0, (this->Height) - (control_panel->Height) - 32);
	control_panel->Width = this->Width;
		//Button Panel anpassen
	button_panel->Location = System::Drawing::Point(20, (this->Height) - (button_panel->Height) - 45);
		//Zeitleiste anpassen
	musik_timebar->Width = this->Width - 60;
		//Vollbild Button anpassen
	vollbild_button->Location = System::Drawing::Point(this->Width - 59, 36);
		//Menü Panel anpassen
	menu_panel->Height = this->Height - 117;
		//Lautärkeregler anpassen
	volume_trackbar->Location = System::Drawing::Point(this->Width - 170,35);
	

	
}

Void MediaPlayer::volume_trackbar_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	Volume = volume_trackbar->Value;
	title->Volume = (- 5000 + Volume * 50);
	if(Volume < 5) title->Volume = -10000;
}

Void MediaPlayer::musik_timebar_Click(System::Object^  sender, System::EventArgs^  e)
{
	int CurPosX = ::Cursor::Position.X; // X Position des Cursors

	float newvalue = 0.0f; // Der neue Wert auf den die Progressgar besetzt wird; 

	newvalue = CurPosX - this->Location.X;
	newvalue = ((newvalue / musik_timebar->Width) * 100) - 3;

	this->musik_timebar->Value = newvalue;
}
