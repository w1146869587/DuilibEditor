#include <System.h>
#include <Archives/FileSystemArchive.h>
#include <Controls/ActiveX.h>
#include <Controls/Button.h>
#include <Controls/CheckBox.h>
#include <Controls/ChildLayout.h>
#include <Controls/Combo.h>
#include <Controls/Container.h>
#include <Controls/Control.h>
#include <Controls/DateTime.h>
#include <Controls/Edit.h>
#include <Controls/GifAnim.h>
#include <Controls/HorizontalLayout.h>
#include <Controls/Label.h>
#include <Controls/List.h>
#include <Controls/ListBody.h>
#include <Controls/ListContainerElement.h>
#include <Controls/ListElement.h>
#include <Controls/ListHeader.h>
#include <Controls/ListHeaderItem.h>
#include <Controls/ListLabelElement.h>
#include <Controls/ListTextElement.h>
#include <Controls/Option.h>
#include <Controls/Progress.h>
#include <Controls/RichEdit.h>
#include <Controls/ScrollBar.h>
#include <Controls/Slider.h>
#include <Controls/TabLayout.h>
#include <Controls/Text.h>
#include <Controls/TileLayout.h>
#include <Controls/TreeNode.h>
#include <Controls/TreeView.h>
#include <Controls/WebBrowser.h>
#include "../XmlParsers/QtXmlParser.h"
#include "../RenderSystems/QtPainterRenderSystem.h"
#include "../NativeWindows/QtMainWindow.h"

namespace duilib2
{

void System::createXmlParser()
{
	mXmlParser = new QtXmlParser;
}

void System::addArchiveFactories()
{
	mArchiveManager->addArchiveFactory(new FileSystemArchiveFactory);
	//mArchiveManager->addArchiveFactory(new ZipArchiveFactory);
	//mArchiveManager->addArchiveFactory(new QtResArchiveFactory);
}

void System::addWindowFactores()
{
	mWindowManager->addWindowFactory(new QtMainWindowFactory);
	mWindowManager->addWindowFactory(new ActiveXFactory);
	mWindowManager->addWindowFactory(new ButtonFactory);
	mWindowManager->addWindowFactory(new CheckBoxFactory);
	mWindowManager->addWindowFactory(new ChildLayoutFactory);
	mWindowManager->addWindowFactory(new ComboFactory);
	mWindowManager->addWindowFactory(new ContainerFactory);
	mWindowManager->addWindowFactory(new ControlFactory);
	mWindowManager->addWindowFactory(new DateTimeFactory);
	mWindowManager->addWindowFactory(new EditFactory);
	mWindowManager->addWindowFactory(new GifAnimFactory);
	mWindowManager->addWindowFactory(new HorizontalLayoutFactory);
	mWindowManager->addWindowFactory(new LabelFactory);
	mWindowManager->addWindowFactory(new ListFactory);
	mWindowManager->addWindowFactory(new ListBodyFactory);
	mWindowManager->addWindowFactory(new ListContainerElementFactory);
	mWindowManager->addWindowFactory(new ListElementFactory);
	mWindowManager->addWindowFactory(new ListHeaderFactory);
	mWindowManager->addWindowFactory(new ListHeaderItemFactory);
	mWindowManager->addWindowFactory(new ListLabelElementFactory);
	mWindowManager->addWindowFactory(new ListTextElementFactory);
	mWindowManager->addWindowFactory(new OptionFactory);
	mWindowManager->addWindowFactory(new ProgressFactory);
	mWindowManager->addWindowFactory(new RichEditFactory);
	mWindowManager->addWindowFactory(new ScrollBarFactory);
	mWindowManager->addWindowFactory(new SliderFactory);
	mWindowManager->addWindowFactory(new TabLayoutFactory);
	mWindowManager->addWindowFactory(new TextFactory);
	mWindowManager->addWindowFactory(new TileLayoutFactory);
	mWindowManager->addWindowFactory(new TreeNodeFactory);
	mWindowManager->addWindowFactory(new TreeViewFactory);
	mWindowManager->addWindowFactory(new VerticalLayoutFactory);
	mWindowManager->addWindowFactory(new WebBrowserFactory);
}

void System::createRenderSystem()
{
	mRenderSystem = new QtPainterRenderSystem;
}

}
