#include <iostream>
#include <string>

#define MAX_TAG_LENGTH 20 // максимальный размер тэга

using namespace std;

string tagRemove(string text){
    int text_length = text.length();
    for(int x=0; x<text.length(); ++x){
        if(text[x] == '<'){
            for(int y=x; y<MAX_TAG_LENGTH + x; ++y){
                if(text[y] == '>'){
                    text = text.substr(0, x) + text.substr(y+1, text.length());
                    x += text_length - text.length() - 1;
                    text_length = text.length();
                    break;
                }
                else if(text[y+1] == '<'){
                    break;
                }
            }
        }
    }
    return text;
}

string tagRemove(string text, string tag){
    tag = tag.substr(0, tag.length() - 1);
    int tag_length = tag.length();
    int text_length = text.length();
    for(int x=0; x<text.length(); ++x){
        if(text.substr(x, tag_length) == tag){
            for(int y=tag_length + x; y<MAX_TAG_LENGTH + x; ++y){
                if(text[y] == '>'){
                    text = text.substr(0, x) + text.substr(y + 1, text_length);
                    x += text_length - text.length();
                    text_length = text.length();
                    break;
                }
                else if(text[y+1] == '<'){
                    break;
                }
            }
        }
    }
    return text;
}

void tagRemove(){
    string in;
    string tags = "none";
    cout << "Введите текст...\n";
    getline(cin, in);
    cout << "Введите тэг для удаления (оставить пустым для удаления всех тэгов)...\n";
    getline(cin, tags);
    if(tags != "none"){
        cout << tagRemove(in, tags) << endl;
        return;
    }
    cout << tagRemove(in) << endl;
}