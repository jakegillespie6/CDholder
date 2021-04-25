#include "CD.h"

//songs
CD::CD()
{
	artist = "(none)";
	aSong.songTitle = "(none)";
	aSong.songLength = "(none)";
}

//setters
void CD::setArtist(string a)
{
	artist = a;
}

void CD::setASongTitle(string t)
{
	aSong.songTitle = t;
}

void CD::setASongLength(string len)
{
	aSong.songLength = len;
}

void CD::setSongList()
{
	songList.appendNode(aSong);
}


//getters
string CD::getArtist() const
{
	return artist;
}

SongInfo CD::getASong() const
{
	return aSong;
}

Linked_List<SongInfo> CD::getSongList() const
{
	return songList;
}



//formatting songs
ostream& operator << (ostream& strm, const SongInfo& obj)
{
	strm << left << setw(16) << obj.songTitle
		<< left << setw(64) << obj.songLength;

	return strm;
}
//formatting cd info
ostream& operator << (ostream& strm, const CD& obj)
{
	strm << endl
		<< left << setw(16) << obj.getArtist()
		<< left << setw(16) << obj.getTitle()
		<< left << setw(16) << obj.getLength()
		<< left << setw(0) << obj.getSongList();

	return strm;
}

ostream& operator << (ostream& strm, const Linked_List<SongInfo>& obj)
{
	obj.displayList();
	return strm;
}

ostream& operator << (ostream& strm, const Linked_List<CD>& obj)
{
	obj.displayList();
	return strm;
}