#include <Controls/Slider.h>

namespace duilib2
{

static String gSliderProperties[][3] =
{
	// name              value      type
	{"thumbimage",       "",        "Image"},
	{"thumbhotimage",    "",        "Image"},
	{"thumbpushedimage", "",        "Image"},
	{"thumbsize",        "10,10",   "Size"},
	{"step",             "1",       "Int"},
	{"", "", ""}
};


String Slider::sTypeName = "Slider";

Slider::Slider(const String& name)
	: Progress(name)
{
	String* property = &gSliderProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Slider::~Slider()
{

}

String Slider::getType() const
{
	return sTypeName;
}

int Slider::getWidth() const
{
	return 0;
}

int Slider::getHeight() const
{
	return 0;
}

Point Slider::getPosition() const
{
	return Point();
}


SliderFactory::SliderFactory()
{

}

SliderFactory::~SliderFactory()
{

}

String SliderFactory::getType() const
{
	return String("Slider");
}

Window* SliderFactory::createInstance(const String& name)
{
	return new Slider(name);
}

void SliderFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
