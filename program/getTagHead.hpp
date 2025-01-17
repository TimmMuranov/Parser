//ДЛЯ ВВОДА ВСЕЙ СТРОКИ ИСПОЛЬЗОВАТЬ std::getline(std::cin, str);
// Принимает тег вида <some_tag>, <t id=111> (Все остальное вызывает исключение)
// При mode = 0 выводит тег без спецификаторов: <t> => <t>, <t1 id=1> => <t1>
// При mode = 1 выводит закрывающую версию тега без спецификаторов: <t> => </t>, <t1 id=1> => </t1>
#include <string>

#pragma once

using namespace std;
string getTagHead(const string fullTag, bool mode){
    string tagHead = "";
    if(fullTag[0] != '<' || fullTag[fullTag.length()-1] != '>') return "Это не тег";
    for(int x=0; x<fullTag.length(); ++x){
        if(fullTag[x] == ' '){
            tagHead = fullTag.substr(0, x);
            tagHead += ">";
            break;
        }
        else if(fullTag[x] == '>') {
            tagHead = fullTag.substr(0, x+1);
            break;
        }
    }
    if (mode == 0) return tagHead;
    string tagHead1 = "</";
    return tagHead1 + tagHead.substr(1);
}

void getTagHead(){
    string in;
    cout << "Введите тег..." << endl;
    getline(cin, in);
    cout << getTagHead(in, 0) << endl << getTagHead(in, 1) << endl;
}