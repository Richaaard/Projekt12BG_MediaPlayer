#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Die Klasse verwaltet alle Informationen eines Musikstücks
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace System;

ref class CTrack
{
private:

	//Allgemeine Infos
	String^	Title;					//	Name des Musikstücks
	String^ Artist;					//	Name des Interpreten
	String^ Source;					//	Ort wo die Datei liegt
	String^ FileType;				//	Datentyp der Datei (.mp3, .wav, .flac, etc.)
	String^ Genre;					//	Genre der Datei (Rock, Pop, etc.)
	float	Length;					//	Länge der Datei
	float	Size;					//	Größe der Datei in MB

	//Album Infos
	String^ AlbumTitle;				//	Name des Albums
	String^ AlbumArtist;			//	Name des Interpreten des Albums
	int		TitleNr;				//	Nummer der Datei (für Reihenfolge)

	

public:

	//Konstruktor 
	CTrack();

	//Get Methoden
	String^	GetTitle(void)				{	return Title;		}
	String^	GetArtist(void)				{	return Artist;		}
	String^	GetSource(void)				{	return Source;		}
	String^	GetFileType(void)			{	return FileType;	}
	String^ GetGenre(void)				{	return Genre;		}
	float	GetLength(void)				{	return Length;		}
	float	GetSize(void)				{	return Size;		}
	String^ GetAlbumTitle(void)			{	return AlbumTitle;	}
	String^ GetAlbumArtist(void)		{	return AlbumArtist;	}
	int		GetTitleNr(void)			{	return TitleNr;		}

	//Set Mehtonden
	void SetTitle(String^ init)			{	Title = init;		}
	void SetArtist(String^ init)		{	Artist = init;		}
	void SetSource(String^ init)		{	Source = init;		}
	void SetFileType(String^ init)		{	FileType = init;	}
	void SetGenre(String^ init)			{	Genre = init;		}
	void SetLength(float init)			{	Length = init;		}
	void SetSize(float init)			{	Size = init;		}
	void SetAlbumTitle(String^ init)	{	AlbumTitle = init;	}
	void SetAlbumArtist(String^ init)	{	AlbumArtist = init;	}
	void SetTitleNr(int init)			{	TitleNr = init;		}
};

