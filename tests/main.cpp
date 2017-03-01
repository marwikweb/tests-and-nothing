#include <QCoreApplication>
#include <QtCore>
#include <QtXml>
#include <QDebug>
#include <QDomNode>



void materialsList(QDomElement root, QString tagname, QString id, QString MatType){

    QDomNodeList items = root.elementsByTagName(tagname);
    
   
     qDebug() << "Total materials = "<<items.count() ;

     for(int i =0;i<items.count();i++){

         QDomNode itemnode = items.at(i);



         if(itemnode.isElement()){

             QDomElement itemele = itemnode.toElement();
             qDebug() << itemele.attribute(MatType)<<" "<<itemele.attribute(id);
         }

     }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    //load file


   // QFile file("C:/Users/marwik15/Documents/qttesty/95/build-95-Desktop_Qt_5_7_1_MSVC2015_64bit-Debug/debug/torus/torus — kopia.xml");
    QString dirpath = qApp->applicationDirPath();
    QString dataDir = "/torus/torus — kopia.xml";


    QFile file(dirpath+dataDir);

    //qDebug() << "App path : " << qApp->applicationDirPath();

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file";
        return -1;

    }else{

        if(!document.setContent(&file)){
             qDebug() << "Failed to open document";

        }

        file.close();
    }



    QDomElement root = document.firstChildElement();


    materialsList(root,"bsdf","id","type");

    file.close();



     qDebug() << "Finished";


    return a.exec();
}
