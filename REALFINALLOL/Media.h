#ifndef MEDIA_H
#define MEDIA_H

#include "Linked_List.h"

#include <string>
using namespace std;
//base class containing title and legnth
class Media
{
private:
	string title;
	string length;

public:
	Media();

	void setTitle(string);
	void setLength(string);

	string getTitle() const;
	string getLength() const;
};
#endif