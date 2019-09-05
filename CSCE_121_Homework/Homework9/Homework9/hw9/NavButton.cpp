#include <iostream>
#include <fstream>
#include <string>
#include "NavButton.h"
#include "Viewer.h"
using namespace std;

NavButton::NavButton(string imageFilename, string label, int x, int y, int thumbnailsize, int imageIndex, const char *L) :
	Fl_Button(x, y, 1, 1, L), clickCount(0), label(label), thumbnailsize(thumbnailsize), imageLabel(nullptr) {
	setImage(imageFilename);
}

string NavButton::getLabel() const {
	return label;
}

void NavButton::setImage(string filename) {
	delete imageLabel;
	imageLabel = new Fl_JPEG_Image(filename.c_str());
	imageLabel->copy(thumbnailsize, thumbnailsize);
	image(imageLabel);
	this->resize(this->x(), this->y(), thumbnailsize + Viewer::borderSize, thumbnailsize + Viewer::borderSize);
}

int NavButton::handle(int event) {
	switch (event) {
	case FL_RELEASE:
			this->clickCount++;
			cout << this->label << " " << clickCount << endl;
			totalClicks += 1;
			cout << "Total clicks: " << totalClicks << endl;
            do_callback();
	default:
		//cout << fl_eventnames[event] << endl;
		return Fl_Widget::handle(event);
	}
}

int NavButton::totalClicks = 0;
