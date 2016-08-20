#ifndef QTXMLPARSER_H
#define QTXMLPARSER_H

#include <XmlParser.h>
#include <QDomNode>

namespace duilib2
{

class DUILIB2SHARED_EXPORT QtXmlParser : public XmlParser
{
public:
	QtXmlParser();
	virtual ~QtXmlParser();

	virtual String getIdentifierString();
	virtual void parseXml(XmlHandler& handler, const RawDataContainer& source);
	virtual void parseXmlFile(XmlHandler& handler, const String& fileName);
	virtual void parseXmlString(XmlHandler& handler, const String& source);

private:
	void parseXmlByteArray(XmlHandler& handler, const QByteArray& byteArray);
	void parseXmlElement(XmlHandler& handler, const QDomNode& node);
};

}

#endif // QTXMLPARSER_H
