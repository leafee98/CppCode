// dma.cpp -- dma class methods
#include "dma.h"
#include <cstring>
#include <iostream>
using std::cout;

// baseDma methods
baseDMA::baseDMA(const char * l, int r) {
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs) {
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA() {
	delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & rs) {
	if (this == & rs)
		return *this;
	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return * this;
}

void baseDMA::show() {
	cout << "Label: " << label << std::endl;
	cout << "Rating: " << rating << std:: endl;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: baseDMA(l, r) {
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
	: baseDMA(rs) {
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::show() {
	baseDMA::show();
	cout << "Color: " << color << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
	: baseDMA(l, r) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char * s, const baseDMA & rs)
	: baseDMA(rs) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) 
	: baseDMA(hs) { // invoke base class copy constructor
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs) {
	if (this == &hs)
		return * this;
	baseDMA::operator=(hs);		// copy base portion
	delete [] style;			// perpare for new style
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return * this;
}
void hasDMA::show() {
	baseDMA::show();
	cout << "Style: " << style << std::endl;
}
