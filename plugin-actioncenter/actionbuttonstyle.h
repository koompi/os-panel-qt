#ifndef ACTIONBUTTONSTYLE_H
#define ACTIONBUTTONSTYLE_H
#include <QString>
namespace  {
class ActionButtonStyle {
   public:
   static QString  bgButtonStyle();
   static QString  smButtonStyle();
};
QString ActionButtonStyle::bgButtonStyle(){
    return QString::fromUtf8("QToolButton{\n"
                             "color: rgb(255, 255, 255);background-color: #5b65736e;\n"
                             "border-radius:5px;\n"
                             "border-top: 0px;\n"
                             "}");
}
QString ActionButtonStyle::smButtonStyle(){
    return QString::fromUtf8("background-color:#f2f2f2;border-radius: 5px;border-top:0px;");
}
}

#endif // ACTIONBUTTONSTYLE_H
