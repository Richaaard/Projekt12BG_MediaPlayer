#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	BG12DV2 - Projekt - © Richard, Corvin, Paul - 18.02.2013
////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

#include "stdafx.h"
#include <string.h>
#include <Windows.h>

namespace Projekt12BG_MediaPlayer {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::DirectX::AudioVideoPlayback;
	using namespace Microsoft::DirectX;
	using namespace Microsoft::DirectX::Direct3D;



	/// <summary>
	/// Zusammenfassung für MediaPlayer
	/// </summary>
	public ref class MediaPlayer : public System::Windows::Forms::Form
	{

	public:

		Audio^ title; // Musik
		bool PlayStatus; // Play oder Pause
		bool WindowSizeStatus; // Maximize oder Minimize
		int Volume; // Lautstärke
		float TrackPosition; // Akktuelle position im Titel

		MediaPlayer(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
				
				PlayStatus = 0; // 0 = Musik aus
				WindowSizeStatus = 0; // 0 = minimiert
				Volume = 0; // -10000 = Ton aus	0 = Volle Lautstärke
				title = gcnew Audio("C:\\Users\\Paul\\Downloads\\Peter Fox - Stadtaffe\\09 - Stadtaffe.mp3"); // Pfad zum Titel
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MediaPlayer()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ProgressBar^  musik_timebar;
	private: System::Windows::Forms::Button^  vollbild_button;
	private: System::Windows::Forms::Panel^  control_panel;
	private: System::Windows::Forms::Button^  play_button;
	private: System::Windows::Forms::Button^  weiterR_button;
	private: System::Windows::Forms::Button^  weiterL_button;
	private: System::Windows::Forms::Button^  stop_button;
	private: System::Windows::Forms::Panel^  button_panel;
	private: System::Windows::Forms::Panel^  menu_panel;
	private: System::Windows::Forms::TrackBar^  volume_trackbar;


		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MediaPlayer::typeid));
			this->musik_timebar = (gcnew System::Windows::Forms::ProgressBar());
			this->vollbild_button = (gcnew System::Windows::Forms::Button());
			this->control_panel = (gcnew System::Windows::Forms::Panel());
			this->volume_trackbar = (gcnew System::Windows::Forms::TrackBar());
			this->play_button = (gcnew System::Windows::Forms::Button());
			this->weiterR_button = (gcnew System::Windows::Forms::Button());
			this->weiterL_button = (gcnew System::Windows::Forms::Button());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->button_panel = (gcnew System::Windows::Forms::Panel());
			this->menu_panel = (gcnew System::Windows::Forms::Panel());
			this->control_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->volume_trackbar))->BeginInit();
			this->button_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// musik_timebar
			// 
			this->musik_timebar->BackColor = System::Drawing::SystemColors::HotTrack;
			this->musik_timebar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->musik_timebar->Location = System::Drawing::Point(20, 12);
			this->musik_timebar->Name = L"musik_timebar";
			this->musik_timebar->Size = System::Drawing::Size(740, 5);
			this->musik_timebar->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->musik_timebar->TabIndex = 3;
			this->musik_timebar->Click += gcnew System::EventHandler(this, &MediaPlayer::musik_timebar_Click);
			// 
			// vollbild_button
			// 
			this->vollbild_button->BackColor = System::Drawing::SystemColors::Control;
			this->vollbild_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vollbild_button.BackgroundImage")));
			this->vollbild_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->vollbild_button->FlatAppearance->BorderSize = 0;
			this->vollbild_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
			this->vollbild_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->vollbild_button->Location = System::Drawing::Point(741, 36);
			this->vollbild_button->Name = L"vollbild_button";
			this->vollbild_button->Size = System::Drawing::Size(40, 40);
			this->vollbild_button->TabIndex = 6;
			this->vollbild_button->UseVisualStyleBackColor = false;
			this->vollbild_button->Click += gcnew System::EventHandler(this, &MediaPlayer::vollbild_button_Click);
			// 
			// control_panel
			// 
			this->control_panel->BackColor = System::Drawing::Color::RoyalBlue;
			this->control_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->control_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->control_panel->Controls->Add(this->volume_trackbar);
			this->control_panel->Controls->Add(this->vollbild_button);
			this->control_panel->Controls->Add(this->musik_timebar);
			this->control_panel->Location = System::Drawing::Point(0, 383);
			this->control_panel->Name = L"control_panel";
			this->control_panel->Size = System::Drawing::Size(785, 85);
			this->control_panel->TabIndex = 7;
			// 
			// volume_trackbar
			// 
			this->volume_trackbar->Cursor = System::Windows::Forms::Cursors::Default;
			this->volume_trackbar->Location = System::Drawing::Point(630, 35);
			this->volume_trackbar->Maximum = 100;
			this->volume_trackbar->Name = L"volume_trackbar";
			this->volume_trackbar->Size = System::Drawing::Size(100, 45);
			this->volume_trackbar->TabIndex = 7;
			this->volume_trackbar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->volume_trackbar->Value = 100;
			this->volume_trackbar->Scroll += gcnew System::EventHandler(this, &MediaPlayer::volume_trackbar_Scroll);
			// 
			// play_button
			// 
			this->play_button->BackColor = System::Drawing::SystemColors::Control;
			this->play_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"play_button.BackgroundImage")));
			this->play_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->play_button->FlatAppearance->BorderSize = 0;
			this->play_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
			this->play_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->play_button->Location = System::Drawing::Point(56, 0);
			this->play_button->Name = L"play_button";
			this->play_button->Size = System::Drawing::Size(50, 50);
			this->play_button->TabIndex = 0;
			this->play_button->UseVisualStyleBackColor = false;
			this->play_button->Click += gcnew System::EventHandler(this, &MediaPlayer::play_button_Click);
			// 
			// weiterR_button
			// 
			this->weiterR_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"weiterR_button.BackgroundImage")));
			this->weiterR_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->weiterR_button->FlatAppearance->BorderSize = 0;
			this->weiterR_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->weiterR_button->Location = System::Drawing::Point(168, 0);
			this->weiterR_button->Name = L"weiterR_button";
			this->weiterR_button->Size = System::Drawing::Size(50, 50);
			this->weiterR_button->TabIndex = 1;
			this->weiterR_button->UseVisualStyleBackColor = true;
			this->weiterR_button->Click += gcnew System::EventHandler(this, &MediaPlayer::weiterR_button_Click);
			// 
			// weiterL_button
			// 
			this->weiterL_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"weiterL_button.BackgroundImage")));
			this->weiterL_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->weiterL_button->FlatAppearance->BorderSize = 0;
			this->weiterL_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->weiterL_button->Location = System::Drawing::Point(112, 0);
			this->weiterL_button->Name = L"weiterL_button";
			this->weiterL_button->Size = System::Drawing::Size(50, 50);
			this->weiterL_button->TabIndex = 2;
			this->weiterL_button->UseVisualStyleBackColor = true;
			this->weiterL_button->Click += gcnew System::EventHandler(this, &MediaPlayer::weiterL_button_Click);
			// 
			// stop_button
			// 
			this->stop_button->BackColor = System::Drawing::SystemColors::Control;
			this->stop_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"stop_button.BackgroundImage")));
			this->stop_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->stop_button->FlatAppearance->BorderSize = 0;
			this->stop_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGray;
			this->stop_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->stop_button->Location = System::Drawing::Point(0, 0);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(50, 50);
			this->stop_button->TabIndex = 5;
			this->stop_button->UseVisualStyleBackColor = false;
			this->stop_button->Click += gcnew System::EventHandler(this, &MediaPlayer::stop_button_Click);
			// 
			// button_panel
			// 
			this->button_panel->BackColor = System::Drawing::Color::RoyalBlue;
			this->button_panel->Controls->Add(this->weiterR_button);
			this->button_panel->Controls->Add(this->stop_button);
			this->button_panel->Controls->Add(this->play_button);
			this->button_panel->Controls->Add(this->weiterL_button);
			this->button_panel->Location = System::Drawing::Point(20, 405);
			this->button_panel->Name = L"button_panel";
			this->button_panel->Size = System::Drawing::Size(215, 50);
			this->button_panel->TabIndex = 8;
			// 
			// menu_panel
			// 
			this->menu_panel->AllowDrop = true;
			this->menu_panel->BackColor = System::Drawing::Color::White;
			this->menu_panel->Location = System::Drawing::Point(0, 0);
			this->menu_panel->Name = L"menu_panel";
			this->menu_panel->Size = System::Drawing::Size(200, 383);
			this->menu_panel->TabIndex = 9;
			// 
			// MediaPlayer
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumBlue;
			this->ClientSize = System::Drawing::Size(784, 462);
			this->Controls->Add(this->menu_panel);
			this->Controls->Add(this->button_panel);
			this->Controls->Add(this->control_panel);
			this->MinimumSize = System::Drawing::Size(400, 117);
			this->Name = L"MediaPlayer";
			this->ShowIcon = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Media Player";
			this->Resize += gcnew System::EventHandler(this, &MediaPlayer::MediaPlayer_Resize);
			this->control_panel->ResumeLayout(false);
			this->control_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->volume_trackbar))->EndInit();
			this->button_panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}


#pragma endregion

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////*********************************EIGENE FUNKTIONEN***********************************////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Funktion zum Button Bilder ändern
	System::Void ButtonPicture_change(System::Windows::Forms::Button^ obj ,String^ filename);
	// Starten & pausieren der Musik
	System::Void play_button_Click(System::Object^  sender, System::EventArgs^  e);
	// Voherigen Musiktitel abspielen
	System::Void weiterL_button_Click(System::Object^  sender, System::EventArgs^  e);
	// Nächsten Musiktitel abspielen
	System::Void weiterR_button_Click(System::Object^  sender, System::EventArgs^  e);
	// Musik stoppen
	System::Void stop_button_Click(System::Object^  sender, System::EventArgs^  e);
	// Player maximieren & minimieren
	System::Void vollbild_button_Click(System::Object^  sender, System::EventArgs^  e);
	// Panels an veränderte Fenstergröße anpassen	 
	System::Void MediaPlayer_Resize(System::Object^  sender, System::EventArgs^  e);
	// Im Musiktitel zu einem bestimmten Zeitpunkt springen
	System::Void musik_timebar_Click(System::Object^  sender, System::EventArgs^  e);
	// Lautstärke ändern	 
	System::Void volume_trackbar_Scroll(System::Object^  sender, System::EventArgs^  e);
		
	
};
}

