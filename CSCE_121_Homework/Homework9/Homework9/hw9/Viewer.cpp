#include <iostream>
#include "Viewer.h"

using namespace std;

void buttonCallback(Fl_Widget* widget, void* viewerPtr) {
	cout << "Callback called" << endl;
	Viewer* viewer = static_cast<Viewer*>(viewerPtr);
	viewer->navPressed(widget);
}

Viewer::Viewer(string imageFolder, vector<string> imageFilenames, int width = 800, int height = 600) :
	Fl_Window(width, height, "Image Viewer"), imageFolder(imageFolder), imageFilenames(imageFilenames), currentIndex(0) {
  	prev = new NavButton(getPathFilename(imageFilenames.at(imageFilenames.size()-1), true),
		"Previous Button",
		borderSize,
		this->h() - borderSize - thumbnailSize - borderSize,
		thumbnailSize, imageFilenames.size() - 1);
		prev->callback(buttonCallback, static_cast<void*>(this));
	next = new NavButton(getPathFilename(imageFilenames.at(imageFilenames.size()-1), true),
		"Next Button", 
		this->w() - borderSize - thumbnailSize - borderSize,
		this->h() - borderSize - thumbnailSize - borderSize, 
		thumbnailSize, imageFilenames.size()-1);
		next->callback(buttonCallback, static_cast<void*>(this));
	cout << "Here 1" << endl;
	imageBox = new Fl_Box(borderSize, 
		borderSize, 
		this->w() - (2*borderSize), 
		this->h() - (2*borderSize) - thumbnailSize - 2*borderSize);
	//imageBox->box(FL_BORDER_BOX); // useful to see where the full size of the widget holding the images
	cout << "Here 2" << endl;

	Fl_JPEG_Image *pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());
	cout << "Here 3" << endl;
	imageBox->image(pic);
	cout << "Here 4" << endl;
	this->end();
  	cout << "Here 5" << endl;

}

string Viewer::getPathFilename(string filename, bool thumb) {
	string thumbPart = "";
	if (thumb) thumbPart = "t_";
	return imageFolder + "/" + thumbPart+ filename;
}

void Viewer::navPressed(Fl_Widget* w) {
	NavButton* obj = static_cast<NavButton*>(w);
	
	if(obj == prev) {
		if(currentIndex == 0) {
			currentIndex = imageFilenames.size() - 1;
		
		}
		else {
			currentIndex--;
		}
	}
	else if(obj == next) {
		if(currentIndex == imageFilenames.size() - 1) {
			currentIndex = 0;
		}
		else {
			currentIndex++;
		}
	}
	
	int prevOne = currentIndex + 1;
	int nextOne = currentIndex - 1;
	if(nextOne < 0) {
		nextOne = imageFilenames.size() - 1;
	}
	if(prevOne > imageFilenames.size() - 1) {
		prevOne = 0;
	}
	
	prev->setImage(getPathFilename("t_" + imageFilenames.at(nextOne)).c_str());
	next->setImage(getPathFilename("t_" + imageFilenames.at(prevOne)).c_str());
	
	Fl_JPEG_Image* pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());
	imageBox->image(pic);
	redraw();
	
}