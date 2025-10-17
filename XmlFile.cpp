#include "XmlFile.h"

string XmlFile::getFileName(){
    return FILE_NAME;
}

bool XmlFile::isFileEmpty(){
    CMarkup xml;
    bool loaded = xml.Load(getFileName());
    if (!xml.FindElem())
        return true;

    return false;
}
