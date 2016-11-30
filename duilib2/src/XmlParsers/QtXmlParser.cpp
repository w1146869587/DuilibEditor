#include <ResourceManager.h>
#include <QDomDocument>
#include "QtXmlParser.h"

namespace duilib2
{

QtXmlParser::QtXmlParser()
{

}

QtXmlParser::~QtXmlParser()
{

}

String QtXmlParser::getIdentifierString()
{
	return String("QtXmlParser");
}

void QtXmlParser::parseXml(XmlHandler& handler, const RawDataContainer& source)
{
	QByteArray byteArray((const char*)source.getData(), source.getSize());
	parseXmlByteArray(handler, byteArray);
}

void QtXmlParser::parseXmlFile(XmlHandler& handler, const String& fileName)
{
	RawDataContainerPtr rawData = ResourceManager::getSingleton().getFileRawData(fileName);
	parseXml(handler, *rawData.get());
}

void QtXmlParser::parseXmlString(XmlHandler& handler, const String& source)
{
	parseXmlByteArray(handler, source.toUtf8());
}

void QtXmlParser::parseXmlByteArray(XmlHandler& handler, const QByteArray& byteArray)
{
	QDomDocument doc;
	doc.setContent(byteArray);
	parseXmlElement(handler, doc.firstChildElement());
}

void QtXmlParser::parseXmlElement(XmlHandler& handler, const QDomNode& node)
{
	if (node.isText())
	{
		// 处理文字节点
		handler.text(node.nodeValue());
	}
	else if (node.isElement())
	{
		// 处理当前节点
		XmlAttributes attributes;
		QDomNamedNodeMap attrs = node.attributes();
		int attrCount = attrs.length();
		for (int i=0; i<attrCount; ++i)
		{
			attributes.add(attrs.item(i).nodeName(), attrs.item(i).nodeValue());
		}
		handler.elementStart(node.nodeName(), attributes);

		// 处理当前节点的所有子节点
		for (QDomNode n = node.firstChild(); !n.isNull(); n = n.nextSibling())
		{
			parseXmlElement(handler, n);
		}

		// 结束当前节点
		handler.elementEnd(node.nodeName());
	}
}

} // namespace duilib2
