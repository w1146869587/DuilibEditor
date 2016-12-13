#include <Controls/TileLayout.h>

namespace duilib2
{

static String gTileLayoutProperties[][3] =
{
	// name      value  type
	{"columns",  "1",   "Int"},
	{"itemsize", "0,0", "Size"},
	{"", "", ""}
};


String TileLayout::sTypeName = "TileLayout";

TileLayout::TileLayout(const String& name)
	: Container(name)
{
	String* property = &gTileLayoutProperties[0][0];
	while (!property->isEmpty())
	{
		addProperty(property[0], property[1], property[2]);
		property += 3;
	}
}

TileLayout::~TileLayout()
{

}

String TileLayout::getType() const
{
	return sTypeName;
}

int TileLayout::getWidth() const
{
	return 0;
}

int TileLayout::getHeight() const
{
	return 0;
}

Point TileLayout::getPosition() const
{
	return Point();
}


TileLayoutFactory::TileLayoutFactory()
{

}

TileLayoutFactory::~TileLayoutFactory()
{

}

String TileLayoutFactory::getType() const
{
	return String("TileLayout");
}

Window* TileLayoutFactory::createInstance(const String& name)
{
	return new TileLayout(name);
}

void TileLayoutFactory::destroyInstance(Window* window)
{
	delete window;
}

} // namespace duilib2
