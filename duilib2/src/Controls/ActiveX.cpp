#include <Controls/ActiveX.h>

namespace duilib2
{

static String gActiveXProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String ActiveX::sTypeName = "ActiveX";

ActiveX::ActiveX(const String& name)
	: Control(name)
{
	String* property = &gActiveXProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

ActiveX::~ActiveX()
{

}

String ActiveX::getType() const
{
	return sTypeName;
}

int ActiveX::getWidth() const
{
	return 0;
}

int ActiveX::getHeight() const
{
	return 0;
}

Point ActiveX::getPosition() const
{
	return Point();
}

void ActiveX::render()
{

}


ActiveXFactory::ActiveXFactory()
{

}

ActiveXFactory::~ActiveXFactory()
{

}

String ActiveXFactory::getType() const
{
	return String("ActiveX");
}

Window* ActiveXFactory::createInstance(const String& name)
{
	return new ActiveX(name);
}

void ActiveXFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
