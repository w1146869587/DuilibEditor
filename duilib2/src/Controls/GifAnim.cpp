#include <Controls/GifAnim.h>

namespace duilib2
{

static String gGifAnimProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String GifAnim::sTypeName = "GifAnim";

GifAnim::GifAnim(const String& name)
	: Control(name)
{
	String* property = &gGifAnimProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

GifAnim::~GifAnim()
{

}

String GifAnim::getType() const
{
	return sTypeName;
}

int GifAnim::getWidth() const
{
	return 0;
}

int GifAnim::getHeight() const
{
	return 0;
}

Point GifAnim::getPosition() const
{
	return Point();
}


GifAnimFactory::GifAnimFactory()
{

}

GifAnimFactory::~GifAnimFactory()
{

}

String GifAnimFactory::getType() const
{
	return String("GifAnim");
}

Window* GifAnimFactory::createInstance(const String& name)
{
	return new GifAnim(name);
}

void GifAnimFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
