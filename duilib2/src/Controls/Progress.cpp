#include <Controls/Progress.h>

namespace duilib2
{

static String gProgressProperties[][3] =
{
	// name           value    type
	{"foreimage",     "",      "Image"},
	{"hor",           "true",  "Bool"},
	{"min",           "0",     "Int"},
	{"max",           "100",   "Int"},
	{"value",         "0",     "Int"},
	{"isstretchfore", "true",  "Bool"},
	{"", "", ""}
};


String Progress::sTypeName = "Progress";

Progress::Progress(const String& name)
	: Label(name)
{
	String* property = &gProgressProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

Progress::~Progress()
{

}

String Progress::getType() const
{
	return sTypeName;
}

int Progress::getWidth() const
{
	return 0;
}

int Progress::getHeight() const
{
	return 0;
}

Point Progress::getPosition() const
{
	return Point();
}


ProgressFactory::ProgressFactory()
{

}

ProgressFactory::~ProgressFactory()
{

}

String ProgressFactory::getType() const
{
	return String("Progress");
}

Window* ProgressFactory::createInstance(const String& name)
{
	return new Progress(name);
}

void ProgressFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
