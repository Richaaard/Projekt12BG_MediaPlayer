#include "StdAfx.h"
#include "Track.h"


CTrack::CTrack()
{
	//Allgemeine Infos
	Title = "Unknow";				//	Name des Musikst�cks
	Artist = "Unknow";				//	Name des Interpreten
	Source = "Unkonw";				//	Ort wo die Datei liegt
	FileType = ".mp3";				//	Datentyp der Datei (.mp3, .wav, .flac, etc.)
	Genre = "Unknow";				//	Genre der Datei (Rock, Pop, etc.)
	Length = 0.0f;					//	L�nge der Datei
	Size = 0.0f;					//	Gr��e der Datei in MB

	//Album Infos
	AlbumTitle = "Unknow";			//	Name des Albums
	AlbumArtist = "Unknow";			//	Name des Interpreten des Albums
	TitleNr = 0;					//	Nummer der Datei (f�r Reihenfolge)
}

