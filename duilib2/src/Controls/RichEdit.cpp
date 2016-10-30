#include <Controls/RichEdit.h>

namespace duilib2
{

static String gRichEditProperties[][3] =
{
	// name              value         type
	{"", "", ""}
};


String RichEdit::sTypeName = "RichEdit";

RichEdit::RichEdit(const String& name)
	: Container(name)
{
	String* property = &gRichEditProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

RichEdit::~RichEdit()
{

}

String RichEdit::getType() const
{
	return sTypeName;
}

int RichEdit::getWidth() const
{
	return 0;
}

int RichEdit::getHeight() const
{
	return 0;
}

Point RichEdit::getPosition() const
{
	return Point();
}

void RichEdit::render(RenderTarget* renderTarget)
{

}


RichEditFactory::RichEditFactory()
{

}

RichEditFactory::~RichEditFactory()
{

}

String RichEditFactory::getType() const
{
	return String("RichEdit");
}

Window* RichEditFactory::createInstance(const String& name)
{
	return new RichEdit(name);
}

void RichEditFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
